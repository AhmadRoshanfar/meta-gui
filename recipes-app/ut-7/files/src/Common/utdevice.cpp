#include "utdevice.h"
#include "Helpers/constants.h"
#include "Calculations/chartscalculations.h"
#include <QPointF>
#include <QtMath>
#include <QDebug>
#include <QDateTime>
QVector<QPointF> UTDevice::_signalData;

UTDevice::UTDevice(QObject *parent) : QObject(parent)
{

}
//int iii=0;
void UTDevice::newSignalData(const QVector<uint16_t>& data){
    IFSyncAdaptor::calc();
    double axisXStep = ChartsCalculations::mmLengthEplison();
    double axisXStart =  ChartsCalculations::lengthFromIndex(0) /*- ChartsCalculations::lengthFromTime(_qmlIntegrator.probeDelay())*//*-_ifSyncAdaptor.trackingOffset()*/;
//    qDebug()<<axisXStart;
    double coef = Constants::FILTER_COEF[_qmlIntegrator.digitalFilter()];

    int rejection = _qmlIntegrator.rejection();

    _signalData.clear();
    for (int i=0; i< data.count(); i++) {
        int16_t d = data.at(i);
        qreal adc = d*100.0/2047.0;
        qreal x = i * axisXStep + axisXStart;
        qreal sig = (adc*coef);
        if(_qmlIntegrator.gateAEnabled() && x>=_qmlIntegrator.gateAStart()&&x<=_qmlIntegrator.gateAStart()+_qmlIntegrator.gateAWidth()){
            sig *= qPow(10.0,_qmlIntegrator.gateAGain()/20.0);
        }
        else if(_qmlIntegrator.gateBEnabled() && x>=_qmlIntegrator.gateBStart()&&x<=_qmlIntegrator.gateBStart()+_qmlIntegrator.gateBWidth()){
            sig *= qPow(10.0,_qmlIntegrator.gateBGain()/20.0);
        }
        if(sig> 100.0)
            sig = 100.0;
        else if (sig< -100.0)
            sig = -100.0;
        if(sig<rejection&&sig>-rejection)
            sig = 0;
//        if(iii == i)
//            sig = 100;
        _signalData.append(QPointF(x,sig));
    }
//    iii = (iii+1)%100+600;
}


