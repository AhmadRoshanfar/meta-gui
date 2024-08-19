#include "chartscalculations.h"
#include "../Helpers/constants.h"
#include "../Helpers/qmlintegrator.h"
#include "../Common/Adaptors/ifsyncadaptor.h"
QmlIntegrator& ChartsCalculations::_qmlIntegrator = QmlIntegrator::instance();
ChartsCalculations::ChartsCalculations()
{

}
/********************************************************************/
double ChartsCalculations::indexFromLength(double length_mm){
    return (Constants::SAMPLING_RATE/1000.0)*(((length_mm+IFSyncAdaptor::trackingOffset())/_qmlIntegrator.soundPathMultiplier())/_qmlIntegrator.velocity()+Constants::RANGE_OFFSET/1000.0+_qmlIntegrator.probeDelay()/(1000.0/**_qmlIntegrator.soundPathMultiplier()*/)) ;
}

double ChartsCalculations::indexFromLengthWithoutProbeDelay(double length_mm){
    return (Constants::SAMPLING_RATE/1000.0)*((length_mm/_qmlIntegrator.soundPathMultiplier())/_qmlIntegrator.velocity()+Constants::RANGE_OFFSET/1000.0) ;
}


double ChartsCalculations::lengthFromIndex(int idx){
    return /*lengthWithUnit*/((_qmlIntegrator.velocity()*_qmlIntegrator.soundPathMultiplier())*(((1000.0*idx)/Constants::SAMPLING_RATE)-(Constants::RANGE_OFFSET/1000.0)-_qmlIntegrator.probeDelay()/(1000.0/**_qmlIntegrator.soundPathMultiplier()*/)))-IFSyncAdaptor::trackingOffset();
}


double ChartsCalculations::lengthFromIndexWithoutProbeDelay(int idx){
    return /*lengthWithUnit*/((_qmlIntegrator.velocity()*_qmlIntegrator.soundPathMultiplier())*(((1000.0*idx)/Constants::SAMPLING_RATE)-(Constants::RANGE_OFFSET/1000.0)));
}


double ChartsCalculations::lengthEplison(){
    return lengthWithUnit((_qmlIntegrator.velocity()*(1000.0*_qmlIntegrator.soundPathMultiplier()))/Constants::SAMPLING_RATE);
}

double ChartsCalculations::mmLengthEplison(){
    return ((_qmlIntegrator.velocity()*(1000.0*_qmlIntegrator.soundPathMultiplier()))/Constants::SAMPLING_RATE);
}

double ChartsCalculations::lengthFromTime(double microsec){
    return /*lengthWithUnit*/(_qmlIntegrator.velocity()*microsec/1000.0);
}

double ChartsCalculations::timeuSFromLength(double mm){
    return /*lengthWithUnit*/(mm/_qmlIntegrator.velocity()*1000.0);
}

QPointF ChartsCalculations::pointBasedOnPolarity(QPointF p){
    Enums::Polarity polarity    = _qmlIntegrator.polarity();
    qreal y;
    switch(polarity){
    case Enums::Polarity::POL_NHW:
        y = p.y()<0?qAbs(p.y()):0;
        break;
    case Enums::Polarity::POL_PHW:
        y = p.y()>0?p.y():0;
        break;
    case Enums::Polarity::POL_FW:
        y = qAbs(p.y());
        break;
    case Enums::Polarity::POL_RF:
        y = p.y();
        break;
    }
    return QPointF(p.x(),y);
}



double ChartsCalculations::lengthWithUnit(double lenght){
    double coef = 1;
    switch (_qmlIntegrator.unit()) {
    case Enums::Unit::UNIT_US:coef = _qmlIntegrator.usToMm();
        break;
    case Enums::Unit::UNIT_INCH:coef = Constants::INCH_TO_MM;
        break;
    }
    return lenght / coef;
}


