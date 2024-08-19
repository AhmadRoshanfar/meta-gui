#include "alarmadaptor.h"
//#include <QtQml>
#include "../gatedata.h"
#include "../ChartData/ascandata.h"
#include "../Helpers/qmlintegrator.h"
#include <QDebug>
AlarmAdaptor::AlarmAdaptor(QObject *parent) : QObject(parent)
{

}


void AlarmAdaptor::declareQML() {
    qmlRegisterType<AlarmAdaptor>("AlarmAdaptor", 1, 0, "AlarmAdaptor");
}

void AlarmAdaptor::checkAlarms(){
    bool alarmA , alarmB, alarmDAC = false;

    alarmA =(_qmlIntegrator.gateAEnabled() && _qmlIntegrator.alarmAEnable()) &&
            !((qAbs(_qmlIntegrator.currentPeakA().y())>= _qmlIntegrator.gateALevel())
              ^ (_qmlIntegrator.gateALogic()==Enums::PosNeg::PN_POS));
    alarmB =(_qmlIntegrator.gateBEnabled() &&_qmlIntegrator.alarmBEnable()) &&
            !((qAbs(_qmlIntegrator.currentPeakB().y())>= _qmlIntegrator.gateBLevel())
              ^ (_qmlIntegrator.gateBLogic()==Enums::PosNeg::PN_POS));
    if(_qmlIntegrator.activated()&& _qmlIntegrator.evaluationMode() == Enums::EvaluationMode::EVAL_DAC){
        auto& gate = GateData::_gateDAC;
        QVector<double> *vdac, *kdac;
        switch(_qmlIntegrator.dacAlarmLevel()){
        case Enums::DACAlarm::DA_100:
            vdac = &AScanData::vvAscanDac100;
            kdac = &AScanData::vkAscanDac100;
            break;
        case Enums::DACAlarm::DA_50:
            vdac = &AScanData::vvAscanDac50;
            kdac = &AScanData::vkAscanDac50;
            break;
        case Enums::DACAlarm::DA_20:
            vdac = &AScanData::vvAscanDac20;
            kdac = &AScanData::vkAscanDac20;
            break;
        }
        for(int i = 0;i<gate.length();i++){
            if(i<gate.count() &&i<vdac->count()&& qAbs(gate.at(i).y())>vdac->at(i)){
                alarmDAC = true;
                break;
            }
        }
    }


    if(alarmA != _qmlIntegrator.alarmAActive())
        _qmlIntegrator.setAlarmAActive(alarmA);
    if(alarmB != _qmlIntegrator.alarmBActive())
        _qmlIntegrator.setAlarmBActive(alarmB);
    if(alarmDAC != _qmlIntegrator.alarmDACActive())
        _qmlIntegrator.setAlarmDACActive(alarmDAC);


}
