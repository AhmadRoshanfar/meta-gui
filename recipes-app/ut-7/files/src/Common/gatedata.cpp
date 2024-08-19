#include "gatedata.h"
#include "utdevice.h"
#include <QtMath>
#include <QDebug>
#include "Adaptors/evaluationadaptor.h"
QVector<QPointF> GateData::_gateA;
QVector<QPointF> GateData::_gateB;
QVector<QPointF> GateData::_gateDAC;
GateData::GateData()
{

}
void GateData::setAllGates(){
    if(_qmlIntegrator.gateAEnabled())
        GateData::_gateA = setGate(_qmlIntegrator.gateAStart(),_qmlIntegrator.gateAWidth());
    else {
        GateData::_gateA = QVector<QPointF>();
    }
    if(_qmlIntegrator.gateBEnabled())
        GateData::_gateB = setGate(_qmlIntegrator.gateBStart(),_qmlIntegrator.gateBWidth());
    else {
        GateData::_gateB = QVector<QPointF>();
    }
//    qDebug()<<EvaluationAdaptor::_map[Enums::EvaluationMode::EVAL_DAC].points;
    auto dac = EvaluationAdaptor::instance()._map[Enums::EvaluationMode::EVAL_DAC];
    if(_qmlIntegrator.evaluationMode() == Enums::EvaluationMode::EVAL_DAC && _qmlIntegrator.activated()&&dac.points.length()>0)
        GateData::_gateDAC = setGate(dac.points.first().x(),
                dac.points.last().x()-dac.points.first().x());
    else {
        GateData::_gateDAC = QVector<QPointF>();
    }
}

QVector<QPointF> GateData::setGate( double start, double width){
    auto ret = QVector<QPointF>();
    int startIdx = qCeil(ChartsCalculations::indexFromLength(start));
    int endIdx = qMin(UTDevice::_signalData.length(),qFloor(ChartsCalculations::indexFromLength(start+width)));
    for (int i = startIdx;i<endIdx;i++) {
//        if(UTDevice::_signalData.count()>i+1)
            ret.append(UTDevice::_signalData[i]);
//        else
//            ret.append(QPointF(i,0));
    }
    return ret;
}
