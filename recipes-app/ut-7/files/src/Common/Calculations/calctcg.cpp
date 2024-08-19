#include "calctcg.h"
#include "../gaintable.h"
#include "../Calculations/chartscalculations.h"
#include <QtMath>
#include "../utdevice.h"
#include "qdebug.h"
CalcTCG::CalcTCG(QObject *parent) : QObject(parent)
{

}


//std::tuple<uint16_t, uint16_t, QVector<bool>> CalcTCG::calc(double gain,QVector<QPointF> points){
//    QVector<bool> codeArray;
//    sort(points);
//    int gainCode = GainTable::getCode(gain);
//    auto firstPoint = points.first();
//    auto lastPoint = points.last();
//    for(int i = 0; i<points.length()-1; i++){
//        auto p0 = points.at(i);
//        auto p1 = points.at(i+1);
//        double slope = (p1.y() - p0.y()) / (p1.x() - p0.x());
//        double y_intercept = p0.y() - slope * p0.x();
//        int startIdx = qCeil(ChartsCalculations::indexFromLength(p0.x()));
//        int endIdx = qFloor(ChartsCalculations::indexFromLength(p1.x()));
//        if(p1.x() == lastPoint.x())//to add lastpoint gain
//            endIdx++;
//        for(int j = startIdx;j < endIdx; j++){
//            auto  currPoOnMain = UTDevice::_signalData.at(j);
//            QPointF currPo(currPoOnMain.x(),slope * currPoOnMain.x() + y_intercept);
//            double deltaGain = 20* log10(firstPoint.y()/currPo.y());
//            int deltaGainCode = GainTable::getCode(deltaGain+gain) - gainCode;
//            if(deltaGainCode>0){
//                codeArray.append(true);
//                gainCode++;
//            }
//            else {
//                codeArray.append(false);
//            }
//        }
//    }
//    uint16_t firstIdx = static_cast<uint16_t>(qCeil(ChartsCalculations::indexFromLength(firstPoint.x())));
//    uint16_t lastIdx = static_cast<uint16_t>(qFloor(ChartsCalculations::indexFromLength(lastPoint.x())));
//    return {firstIdx,lastIdx,codeArray};
//}


std::tuple<uint16_t, uint16_t, QVector<quint16>> CalcTCG::calc(double gain,QVector<QPointF> points){
    QVector<quint16> codeArray;
    codeArray.append(GainTable::getCode(gain));
    sort(points);
    double eps = ChartsCalculations::lengthEplison();
    auto firstPoint = points.first();
    auto lastPoint = points.last();
    double lastGain = gain;
    for(int i = 0; i<points.length()-1; i++){
        auto p0 = points.at(i);
        auto p1 = points.at(i+1);
        double slope = (p1.y() - p0.y()) / (p1.x() - p0.x());
        double y_step = eps*slope;
//        double y_intercept = p0.y() - slope * p0.x();
        int startIdx = qCeil(ChartsCalculations::indexFromLength(p0.x()));
        int endIdx = qFloor(ChartsCalculations::indexFromLength(p1.x()));
        if(p1.x() == lastPoint.x())//to add lastpoint gain
            endIdx++;
        double currentGain = 0;
        for(int j = startIdx;j < endIdx; j+=8){
//            auto  currPoOnMain = UTDevice::_signalData.at(j);
//            QPointF currPo(currPoOnMain.x(),slope * currPoOnMain.x() + p0.y());
            double y = slope*(j-startIdx)*eps+p0.y();
            currentGain = -20* log10( y/firstPoint.y());
            //qDebug()<<y<<currentGain<<y/firstPoint.y();
            codeArray.append(GainTable::getCode(currentGain));
//            double deltaGain = 20* log10(firstPoint.y()/currPo.y());
//            int deltaGainCode = GainTable::getCode(deltaGain+gain) - gainCode;
//            if(deltaGainCode>0){
//                codeArray.append(true);
//                gainCode++;
//            }
//            else {
//                codeArray.append(false);
//            }
        }
        lastGain = currentGain;

    }
    uint16_t firstIdx = static_cast<uint16_t>(qCeil(ChartsCalculations::indexFromLength(firstPoint.x())));
    uint16_t lastIdx = static_cast<uint16_t>(qFloor(ChartsCalculations::indexFromLength(lastPoint.x())));
    return {firstIdx,lastIdx,codeArray};
}



void CalcTCG::sort(QVector<QPointF> &dacPoints){
    std::sort(dacPoints.begin(), dacPoints.end(),
            [](const QPointF& a, const QPointF& b)
            {
                return a.x() < b.x();
            });
}
