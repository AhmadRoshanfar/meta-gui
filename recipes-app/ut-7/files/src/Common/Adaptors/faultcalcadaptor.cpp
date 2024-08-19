#include "faultcalcadaptor.h"
#include "../Common/Models/enums.h"
#include "QtMath"
FaultCalcAdaptor::FaultCalcAdaptor(QObject *parent) : QObject(parent)
{

}

void FaultCalcAdaptor::calc(){
    calcFaultFeature();
    if(_qmlIntegrator.evaluationMode() == Enums::EvaluationMode::EVAL_AWS && _qmlIntegrator.activated())
        calcAWS();
}

void FaultCalcAdaptor::calcFaultFeature(){
    if(_qmlIntegrator.freezed())
        return;
    auto res = _faultCalc.calc(_qmlIntegrator.soundPathMultiplier(),_qmlIntegrator.currentMarkerA().x(),_qmlIntegrator.pipeDiameter(),_qmlIntegrator.shape(),_qmlIntegrator.probeType(),_qmlIntegrator.unit());
    _qmlIntegrator.setResD(TwoDecimals(res.D));
    _qmlIntegrator.setResDa(TwoDecimals(res.Da));
    _qmlIntegrator.setResS(TwoDecimals(res.S));
    _qmlIntegrator.setResOneLeg(TwoDecimals(res.leg));
}

void FaultCalcAdaptor::calcAWS(){
    int table = _qmlIntegrator.awsTable() == Enums::AWSTable::AT_M1 ?0:1;
    auto [a,c,d] = _awsCalc.calc(_qmlIntegrator.currentMarkerA().y(),_qmlIntegrator.gain(),_qmlIntegrator.currentMarkerA().x());
    auto awsClass = _awsCalc.findClass(d,_qmlIntegrator.probeAngle(),table,_qmlIntegrator.thickness());
    _qmlIntegrator.setAwsd(TwoDecimals(d));
    _qmlIntegrator.setAwsa(TwoDecimals(a));
    _qmlIntegrator.setAwsc(TwoDecimals(c));
    _qmlIntegrator.setAwsClass(awsClass);
}

void FaultCalcAdaptor::declareQML() {
    qmlRegisterType<FaultCalcAdaptor>("FaultCalcAdaptor", 1, 0, "FaultCalcAdaptor");
}

double FaultCalcAdaptor::TwoDecimals(double d){
    if(d != d)
        return qQNaN();
    return qFloor(d*100)/100.0;
}
