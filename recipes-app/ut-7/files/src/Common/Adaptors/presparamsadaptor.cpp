#include "presparamsadaptor.h"
#include "../Calculations/chartscalculations.h"
#include "../Helpers/constants.h"
#include <QDebug>
PresParamsAdaptor::PresParamsAdaptor(QObject *parent) : QObject(parent)
{

}
//int i;
Enums::Unit _lastUnit;
void PresParamsAdaptor::refresh(){
//    if(_qmlIntegrator.unitIsChanging())
//        return;


    _qmlIntegrator.setDisplayDelayMin(-_qmlIntegrator.velocity()*Constants::RANGE_OFFSET/2000.0);
    _qmlIntegrator.setDisplayDelayMax(_qmlIntegrator.velocity()*Constants::RANGE_BASE/2000.0-1.0);
    _qmlIntegrator.setUIDisplayDelay(ChartsCalculations::lengthWithUnit(_qmlIntegrator.displayDelay()));
    _qmlIntegrator.setUIDisplayDelayMin(ChartsCalculations::lengthWithUnit(_qmlIntegrator.displayDelayMin()));
    _qmlIntegrator.setUIDisplayDelayMax(ChartsCalculations::lengthWithUnit(_qmlIntegrator.displayDelayMax()));
    _qmlIntegrator.setRangeMax((_qmlIntegrator.displayDelayMax()- _qmlIntegrator.displayDelay() +1.0)*0.5/_qmlIntegrator.soundPathMultiplier());
    if(_qmlIntegrator.unit() != _lastUnit){
        if(_lastUnit == Enums::Unit::UNIT_MM){
            _qmlIntegrator.setUIRange(ChartsCalculations::lengthWithUnit(_qmlIntegrator.range()));
            _qmlIntegrator.setUIRangeMax(ChartsCalculations::lengthWithUnit(_qmlIntegrator.rangeMax()));
        }
        else if(_lastUnit == Enums::Unit::UNIT_INCH){
//            _qmlIntegrator.setRangeMax(_qmlIntegrator.displayDelayMax()- _qmlIntegrator.displayDelay() +1.0);
            _qmlIntegrator.setUIRangeMax(ChartsCalculations::lengthWithUnit(_qmlIntegrator.rangeMax()));
            _qmlIntegrator.setUIRange(ChartsCalculations::lengthWithUnit(_qmlIntegrator.range()));
        }
        else if(_lastUnit == Enums::Unit::UNIT_US){
//            _qmlIntegrator.setRangeMax(_qmlIntegrator.displayDelayMax()- _qmlIntegrator.displayDelay() +1.0);
            _qmlIntegrator.setUIRangeMax(ChartsCalculations::lengthWithUnit(_qmlIntegrator.rangeMax()));
            _qmlIntegrator.setUIRange(ChartsCalculations::lengthWithUnit(_qmlIntegrator.range()));
        }
        _lastUnit = _qmlIntegrator.unit() ;
    }
    else{
        _qmlIntegrator.setUIRange(ChartsCalculations::lengthWithUnit(_qmlIntegrator.range()));
//        _qmlIntegrator.setRangeMax(_qmlIntegrator.displayDelayMax()- _qmlIntegrator.displayDelay() +1.0);
        _qmlIntegrator.setUIRangeMax(ChartsCalculations::lengthWithUnit(_qmlIntegrator.rangeMax()));
    }


    _qmlIntegrator.setUISpath1(ChartsCalculations::lengthWithUnit(_qmlIntegrator.spath1()));
    _qmlIntegrator.setUISpath2(ChartsCalculations::lengthWithUnit(_qmlIntegrator.spath2()));

    _qmlIntegrator.setUIGateAStart(ChartsCalculations::lengthWithUnit(_qmlIntegrator.gateAStart()));
    _qmlIntegrator.setUIGateAWidth(ChartsCalculations::lengthWithUnit(_qmlIntegrator.gateAWidth()));
    _qmlIntegrator.setUIGateBStart(ChartsCalculations::lengthWithUnit(_qmlIntegrator.gateBStart()));
    _qmlIntegrator.setUIGateBWidth(ChartsCalculations::lengthWithUnit(_qmlIntegrator.gateBWidth()));
    _qmlIntegrator.setAScanAxisXMin(ChartsCalculations::lengthWithUnit(_qmlIntegrator.displayDelay()));
    _qmlIntegrator.setAScanAxisXMax(ChartsCalculations::lengthWithUnit(_qmlIntegrator.displayDelay()+_qmlIntegrator.range()));
}

void PresParamsAdaptor::declareQML() {
    qmlRegisterType<PresParamsAdaptor>("PresParamsAdaptor", 1, 0, "PresParamsAdaptor");
}
