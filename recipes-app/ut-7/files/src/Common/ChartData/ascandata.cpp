#include "ascandata.h"
#include "../Calculations/chartscalculations.h"
#include "../Helpers/constants.h"
#include <QtMath>
#include <QDebug>
#include "../utdevice.h"
#include "../gatedata.h"
#include "../Adaptors/ifsyncadaptor.h"

QVector<double> AScanData::vkAscanMain,AScanData::vvAscanMain;
QVector<double> AScanData::vkAscanOA, AScanData::vvAscanOA;
QVector<double> AScanData::vkAscanOB, AScanData::vvAscanOB;
//QVector<double> AScanData::vkAscanGA, AScanData::vvAscanGA;
//QVector<double> AScanData::vkAscanGB, AScanData::vvAscanGB;
//     QVector<double> vAscanFillL;
QVector<double> AScanData::vkAscanEnv, AScanData::vvAscanEnv;
QVector<double> AScanData::vkAscanCurrentMarker, AScanData::vvAscanCurrentMarker;
QVector<double> AScanData::vkAscanEvaluationMarkers, AScanData::vvAscanEvaluationMarkers;
QVector<double> AScanData::vkAscanLeg, AScanData::vvAscanLeg;
QVector<double> AScanData::vkAscanDac100, AScanData::vkAscanDac50, AScanData::vkAscanDac20, AScanData::vvAscanDac100, AScanData::vvAscanDac50, AScanData::vvAscanDac20;

AScanData::AScanData(QObject *parent) : QObject(parent)
{

}


/********************************************************************/
void AScanData::generateData(Enums::EnvelopeType enveloped)
{
    /********************************************************************/
    _lastInMain =true;
    nonNANCnt = -1;
    nonNANIndex = 100000;
    //    double start = qMin(_qmlIntegrator.gateAEnabled()?_qmlIntegrator.gateAStart():100000,_qmlIntegrator.gateBEnabled()?_qmlIntegrator.gateBStart():100000);
    //    start = qMin(start,double(_qmlIntegrator.displayDelay()));
    double start = _qmlIntegrator.displayDelay();
    //    double end = qMax(_qmlIntegrator.gateAEnabled()?_qmlIntegrator.gateAStart() + _qmlIntegrator.gateAWidth():-100000,_qmlIntegrator.gateBEnabled()?_qmlIntegrator.gateBStart()+ _qmlIntegrator.gateBWidth():-100000);
    //    end = qMax(end,double(_qmlIntegrator.range() + _qmlIntegrator.displayDelay()));
    double end = _qmlIntegrator.range() + _qmlIntegrator.displayDelay();
    int minIdx = qMax(qFloor(ChartsCalculations::indexFromLength(start)),0);
    //    int minIdx = 0;
    int maxIdx = qMin(qCeil(ChartsCalculations::indexFromLength(end)),Constants::RANGE_SIZE);
    //    int maxIdx = Constants::RANGE_SIZE;
    /********************************************************************/
    //    _AScanPoints.clear();
    vvAscanMain.clear();
//    vvAscanGA.clear();
//    vvAscanGB.clear();
    vvAscanOA.clear();
    vvAscanOB.clear();
    vkAscanMain.clear();
//    vkAscanGA.clear();
//    vkAscanGB.clear();
    vkAscanOA.clear();
    vkAscanOB.clear();

    //    if(_qmlIntegrator.envelope() == Enums::EnvelopeType::ENV_OFF)
    //        vAscanEnvU.clear();

    //    vAscanFillL.clear();
    vkAscanCurrentMarker.clear();
    vvAscanCurrentMarker.clear();

    vkAscanLeg.clear();
    vvAscanLeg.clear();

    /********************************************************************/
    // Append the new data depending on the type

    double step = qMax(double(maxIdx-minIdx)/Constants::DISP_POINTS_CNT,1.0);
    for (double j = minIdx; j < maxIdx; j+=step){


        int indexS = int(j);
        int indexE = int(j+step);
        if(indexE>=UTDevice::_signalData.count())
            break;
        double min = UTDevice::_signalData.at(indexS).y();
        double max = UTDevice::_signalData.at(indexS).y();
        int minI = indexS;
        int maxI = indexS;
        for(int i = indexS;i < indexE;i++){
            double val = UTDevice::_signalData.at(i).y();
            if(val < min){
                minI = i;
                min = val;
            }
            if(val > max){
                maxI = i;
                max = val;
            }
        }
        //        if(minI != maxI){
        addByIndex(qMin(minI,maxI));
        addByIndex(qMax(minI,maxI));
        //        }
        //        else{
        //            addByIndex(minI);
        //        }

    }


    if(_qmlIntegrator.gateAEnabled() && _qmlIntegrator.gateBEnabled() &&
            !vkAscanOA.empty() && !vkAscanOB.empty() &&
            (_qmlIntegrator.gateAStart()>=_qmlIntegrator.gateBStart() &&
             _qmlIntegrator.gateAStart() <= _qmlIntegrator.gateBStart()+_qmlIntegrator.gateBWidth())&&nonNANIndex!= -1){
        vkAscanOB.insert(qMin(nonNANIndex, 2*nonNANCnt+1),vkAscanOA.first());
        vvAscanOB.insert(qMin(nonNANIndex, 2*nonNANCnt+1),vvAscanOA.first());

    }

//    if(_qmlIntegrator.gateAEnabled()){
//        vkAscanGA.append(ChartsCalculations::lengthWithUnit(_qmlIntegrator.gateAStart()));
//        vvAscanGA.append(_qmlIntegrator.gateALevel());
//        vkAscanGA.append(ChartsCalculations::lengthWithUnit(_qmlIntegrator.gateAStart()));
//        vvAscanGA.append(_qmlIntegrator.gateALevel());
//    }
//    if(_qmlIntegrator.gateBEnabled()){
//        vkAscanGB.append(ChartsCalculations::lengthWithUnit(_qmlIntegrator.gateBStart()));
//        vvAscanGB.append(_qmlIntegrator.gateBLevel());
//        vkAscanGB.append(ChartsCalculations::lengthWithUnit(_qmlIntegrator.gateBStart()+_qmlIntegrator.gateBWidth()));
//        vvAscanGB.append(_qmlIntegrator.gateBLevel());

//    }

    if(enveloped == Enums::EnvelopeType::ENV_ON){
        //                        qDebug()<<vAscanOA.count();
        for(int i = 0;i<GateData::_gateA.count();i++){
            auto val = ChartsCalculations::pointBasedOnPolarity(GateData::_gateA[i]);
            int sign = val.y()>=0?1:-1;
            //            if(val.y() >= 0){
            //                if(vAscanOA.contains())
            if(vkAscanEnv.count()>i){
                vkAscanEnv.replace(i,ChartsCalculations::lengthWithUnit(val.x()));
                vvAscanEnv.replace(i,sign*qMax(qAbs(val.y()),qAbs(vvAscanEnv[i])));
            }
            //            }
            //            else{
            //                vAscanEnvU.replace(i,QPointF(ChartsCalculations::lengthWithUnit(val.x()),qMin(val.y(),vAscanEnvU[i].y())));
            //            }
        }
    }
//    if(enveloped != Enums::EnvelopeType::ENV_OFF){
//        if(vkAscanEnvU.count()!=0){
//            vkAscanEnvL.append(vkAscanEnvU.first());
//            vvAscanEnvL.append(0.0);
//            vkAscanEnvL.append(vkAscanEnvU.last());
//            vvAscanEnvL.append(0.0);
//        }
//    }
    //    if(_qmlIntegrator.fill()){
    //        if(vAscanMain.count()!=0){
    //            vAscanFillL.append(QPointF(vAscanMain.first().x(),0.0));
    //            vAscanFillL.append(QPointF(vAscanMain.last().x(),0.0));
    //        }
    //    }


    vkAscanCurrentMarker.append(ChartsCalculations::lengthWithUnit(_qmlIntegrator.currentMarkerA().x()));
    vvAscanCurrentMarker.append(ChartsCalculations::pointBasedOnPolarity(QPointF(ChartsCalculations::lengthWithUnit(_qmlIntegrator.currentMarkerA().x()),_qmlIntegrator.currentMarkerA().y())).y());
    if(_qmlIntegrator.legEnable()&&_qmlIntegrator.probeType() == Enums::ProbeType::PT_ANGULAR){
        for(int i = 0;i < 8;i++){
            double xi = i*_qmlIntegrator.resOneLeg();
            double xip1 = (i+1)*_qmlIntegrator.resOneLeg();
            if(i%2 == 0){
                //                vAscanLeg.append(QPointF(ChartsCalculations::lengthWithUnit(xi),-101));
                //                vAscanLeg.append(QPointF(ChartsCalculations::lengthWithUnit(xi),101));
                //                vAscanLeg.append(QPointF(ChartsCalculations::lengthWithUnit(xip1),101));
                vkAscanLeg.append(ChartsCalculations::lengthWithUnit(xi));
                vvAscanLeg.append(100);
                vkAscanLeg.append(ChartsCalculations::lengthWithUnit(xip1));
                vvAscanLeg.append(80);

            }
            //            else {

            ////                vAscanLeg.append(QPointF(ChartsCalculations::lengthWithUnit(xip1),-101));
            //                vAscanLeg.append(QPointF(ChartsCalculations::lengthWithUnit(xip1),80));
            //                vAscanLeg.append(QPointF(ChartsCalculations::lengthWithUnit(xi),100));
            //            }

        }
    }
}

void AScanData::addByIndex(int index){
    QPointF point =UTDevice::_signalData.at(index);
    //    double offset = 0;
    //    double ignoreLength = ChartsCalculations::lengthFromTime(Constants::IGNORE_IFSYNC_US);
    //    if(_qmlIntegrator.gateBSync() == Enums::SyncType::SYNC_IF){
    //        offset = IFSyncAdaptor::trackingOffset();
    //        if(point.x()>ignoreLength && point.x() < ignoreLength-offset){
    //            qDebug()<<point;
    //            return;
    //        }
    //        if(point.x()<ignoreLength)
    //            offset = 0;
    //    }
    //    qreal x = point.x();
    //    qreal y, sig = point.y();
    point.setX(point.x()/*+offset*/);
    QPointF sigPoint =  ChartsCalculations::pointBasedOnPolarity(point);
    qreal x = sigPoint.x();
    qreal y = sigPoint.y();

    bool isNan = false;
    if(_qmlIntegrator.gateAEnabled()){
        if(x>=_qmlIntegrator.gateAStart()&&x<=_qmlIntegrator.gateAStart()+_qmlIntegrator.gateAWidth()){
            vkAscanOA.append(ChartsCalculations::lengthWithUnit(x));
            vvAscanOA.append(y);

            isNan = true;
            //                if(x==_qmlIntegrator.gateAstart||x==_qmlIntegrator.gateAstart+_qmlIntegrator.gateAwidth)
        }
    }
    if(_qmlIntegrator.gateBEnabled()){
        if(x>=_qmlIntegrator.gateBStart()&&x<=_qmlIntegrator.gateBStart()+_qmlIntegrator.gateBWidth()){
            if(!isNan){
                if(!_lastInMain){
                    vkAscanOB.append(_lastPoint.x());
                    vvAscanOB.append(_lastPoint.y());
                }
                vkAscanOB.append(ChartsCalculations::lengthWithUnit(x));
                vvAscanOB.append(y);

                nonNANCnt++;
                isNan = true;
                //                if(x==_qmlIntegrator.gateBstart||x==_qmlIntegrator.gateBstart+_qmlIntegrator.gateBwidth)
            }
            else {
                vkAscanOB.append(ChartsCalculations::lengthWithUnit(x));
                vvAscanOB.append(qQNaN());
                nonNANIndex = 2*nonNANCnt+1;
            }
        }
    }



    if(!isNan && !_lastInMain){
        vkAscanMain.append(_lastPoint.x());
        vvAscanMain.append(_lastPoint.y());
    }
    _lastPoint = QPointF(ChartsCalculations::lengthWithUnit(x),y);
    if(isNan && !_lastInMain){
        y = qQNaN();
        if(vkAscanMain.count()!= 0 && vvAscanMain.last() == vvAscanMain.last()){
            vkAscanMain.append(ChartsCalculations::lengthWithUnit(x));
            vvAscanMain.append(y);
        }
    }
    else{
        vkAscanMain.append(ChartsCalculations::lengthWithUnit(x));
        vvAscanMain.append(y);
    }
    _lastInMain = !isNan;
}




