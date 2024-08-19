#include "connectionhub.h"
#include "../Common/Helpers/devicehelper.h"
ConnectionHub::ConnectionHub(QObject *parent) : QObject(parent)
{

    connect(&_qmlIntegrator,&QmlIntegrator::onGainChanged,&DeviceHelper::instance(),&DeviceHelper::sendGain);
    connect(&_qmlIntegrator,&QmlIntegrator::onTcorrChanged,&DeviceHelper::instance(),&DeviceHelper::sendGain);
    connect(&_qmlIntegrator,&QmlIntegrator::onActivatedChanged,&DeviceHelper::instance(),&DeviceHelper::sendGain);

    connect(&_qmlIntegrator,&QmlIntegrator::onPulseAmplitudeChanged,&DeviceHelper::instance(),&DeviceHelper::sendPulseAmp);
    connect(&_qmlIntegrator,&QmlIntegrator::onDampingChanged,&DeviceHelper::instance(),&DeviceHelper::sendFilterDampDual);
    connect(&_qmlIntegrator,&QmlIntegrator::onDigitalFilterChanged,&DeviceHelper::instance(),&DeviceHelper::sendFilterDampDual);
    connect(&_qmlIntegrator,&QmlIntegrator::onDualNotSingleChanged,&DeviceHelper::instance(),&DeviceHelper::sendFilterDampDual);
    connect(&_qmlIntegrator,&QmlIntegrator::onAlarmAActiveChanged,&DeviceHelper::instance(),&DeviceHelper::sendAlarmActive);
    connect(&_qmlIntegrator,&QmlIntegrator::onAlarmBActiveChanged,&DeviceHelper::instance(),&DeviceHelper::sendAlarmActive);
    connect(&_qmlIntegrator,&QmlIntegrator::onAlarmDACActiveChanged,&DeviceHelper::instance(),&DeviceHelper::sendAlarmActive);
    connect(&_qmlIntegrator,&QmlIntegrator::onHornChanged,&DeviceHelper::instance(),&DeviceHelper::sendAlarmActive);

    connect(&_qmlIntegrator,&QmlIntegrator::onPrfChanged,&DeviceHelper::instance(),&DeviceHelper::sendPRF);
    connect(&_qmlIntegrator,&QmlIntegrator::onBrightnessChanged,&DeviceHelper::instance(),&DeviceHelper::sendBrightness);
    connect(&_qmlIntegrator,&QmlIntegrator::onStartedChanged,&DeviceHelper::instance(),&DeviceHelper::newStarted);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateAStartChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateA);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateAWidthChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateA);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateALevelChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateLevelA);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateBStartChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateB);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateBWidthChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateB);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateBLevelChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateLevelB);
    connect(&_qmlIntegrator,&QmlIntegrator::onProbeDelayChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateA);
    connect(&_qmlIntegrator,&QmlIntegrator::onSoundPathMultiplierChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateA);
    connect(&_qmlIntegrator,&QmlIntegrator::onProbeDelayChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateLevelA);
    connect(&_qmlIntegrator,&QmlIntegrator::onProbeDelayChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateB);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateBSyncChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateA);//if sync changed sends gateA
    connect(&_qmlIntegrator,&QmlIntegrator::onSoundPathMultiplierChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateB);
    connect(&_qmlIntegrator,&QmlIntegrator::onProbeDelayChanged,&DeviceHelper::instance(),&DeviceHelper::sendGateLevelB);

    connect(&_qmlIntegrator,&QmlIntegrator::onProbeTypeChanged,this,&ConnectionHub::refreshSoundPathMultiplier);
    connect(&_qmlIntegrator,&QmlIntegrator::onUnitChanged,this,&ConnectionHub::refreshSoundPathMultiplier);



    connect(&_qmlIntegrator,&QmlIntegrator::onVelocityChanged,this,&ConnectionHub::refreshUsToMm);

	connect(&_qmlIntegrator,&QmlIntegrator::onProbeTypeChanged,this,&ConnectionHub::refreshSingleDual);

    connect(&DeviceHelper::instance(),&DeviceHelper::signalDataReady,   &utd,&UTDevice::newSignalData);


//    connect(&_qmlIntegrator,SIGNAL(onZoomedChanged()),&data::instance(),SLOT(zoom()));
}

void ConnectionHub::refreshUsToMm(){
    _qmlIntegrator.setUsToMm(_qmlIntegrator.velocity()/1000.0);
}

void ConnectionHub::refreshSoundPathMultiplier(){
    if(_qmlIntegrator.probeType()==Enums::ProbeType::PT_TRANSMISSION||_qmlIntegrator.unit() == Enums::Unit::UNIT_US)
        _qmlIntegrator.setSoundPathMultiplier(1.0);
    else{
        _qmlIntegrator.setSoundPathMultiplier(0.5);
    }
}

void ConnectionHub::refreshSingleDual(){
    if(_qmlIntegrator.probeType()==Enums::ProbeType::PT_TRANSMISSION || _qmlIntegrator.probeType()==Enums::ProbeType::PT_TR)
        _qmlIntegrator.setDualNotSingle(Enums::DualType::DUAL_DUAL);
    else{
        _qmlIntegrator.setDualNotSingle(Enums::DualType::DUAL_SINGLE);
    }
}
