#ifndef UDP
#include "udpdevicehelper.h"
#include <QtNetwork>
#include "../Models/enums.h"
#include "../gaintable.h"
#include "../Calculations/chartscalculations.h"
#include "../Helpers/currentip.h"

//#define _qmlIntegrator QmlIntegrator::instance()


DeviceHelper::DeviceHelper(QObject *parent) : QObject(parent),
    pAScan(new UDPAScan),
#ifdef STRIP_CHART
    pStrip(new UDPStrip),
#endif
    pTCPCommands(new TCPCommands)
{
    connect(pAScan,&UDPAScan::signalDataReady,this,&DeviceHelper::signalDataReady);
    connect(pAScan,&UDPAScan::signalPeaksReady,this,&DeviceHelper::signalPeaksReady);
    connect(pTCPCommands,&TCPCommands::signalKeyPress,  this,&DeviceHelper::signalKeyPress);
    connect(pTCPCommands,&TCPCommands::signalBattery,   this,&DeviceHelper::signalBattery);
    pTCPCommands->deviceConnect();

#ifdef STRIP_CHART
    connect(pStrip,&UDPStrip::signalStripReady,this,&DeviceHelper::signalStripReady);
#endif
}


/*************************************************************/
void DeviceHelper::newStarted(){
    if(_qmlIntegrator.started()){
        deviceConnect();
        sendStop();
        CurrentIP ip;
        sendIP(ip.getIP());
        sendPRF();
        sendRange();
        sendAScanRefreshRate();
        sendPulseAmp();
        sendGain();
        sendFilterDampDual();
        sendGateA();
        sendGateB();
        sendGateLevelA();
        sendGateLevelB();
        sendStart();
        sendBrightness();
    }
    else{
        sendStop();
        deviceDisconnect();
    }
}
/*************************************************************/
void DeviceHelper::sendGain(){
    quint32 data = GainTable::getCode(_qmlIntegrator.gain()+(
                                          (_qmlIntegrator.evaluationMode() == Enums::EvaluationMode::EVAL_DAC
                                           && _qmlIntegrator.activated())?_qmlIntegrator.tcorr():0));
    //    quint32 data = GainTable::getCode(_qmlIntegrator.gain());
    sendCommand(char(0x07),data);
}
/*************************************************************/
void DeviceHelper::sendPulseAmp(){
    quint32 level = 16383;
    switch(_qmlIntegrator.pulseAmplitude()){
    case Enums::PulseAmplitude::PA_LO: level = 1638;
        break;
    case Enums::PulseAmplitude::PA_MED: level = 1638*2;
        break;
    case Enums::PulseAmplitude::PA_HI: level = 16383;
        break;
    }
    quint32 data = quint32(level);
    sendCommand(char(0x08),data);
}
/*************************************************************/
void DeviceHelper::sendStart(){
    sendCommand(char(0x10),0x0000010F);
}
/*************************************************************/
void DeviceHelper::sendStop(){
    sendCommand(char(0x10),0x00000100);
}
/*************************************************************/
void DeviceHelper::sendPRF() {
    sendStop();
    quint32 data = Constants::SAMPLING_RATE/(qMax(_qmlIntegrator.prf(),50));
    sendCommand(char(0x01), data);
    sendStart();
}
/*************************************************************/
void DeviceHelper::sendRange() {
    quint32 data = Constants::RANGE_SIZE;
    sendCommand(char(0x06), data);
}
/*************************************************************/
void DeviceHelper::sendAScanRefreshRate() {
    quint32 data = _qmlIntegrator.prf()/Constants::ASCAN_REF_RATE;
    sendCommand(char(0x09), data);
}
/*************************************************************/
void DeviceHelper::sendGate(quint8 gate, bool ifsync, double start,double finish){
    quint16 address = quint16(ChartsCalculations::indexFromLength(start));
//    qDebug()<<start<<":"<<finish<<":"<<address<<":"<<ChartsCalculations::lengthFromTime(Constants::RANGE_OFFSET)*_qmlIntegrator.soundPathMultiplier();
    quint32 data = quint32(gate)<<22|(ifsync?(1<<21):0)|address;
    //    qDebug()<<data;
    sendCommand(char(0x03),data);
    address = quint16(ChartsCalculations::indexFromLength(finish));
    data = quint32(gate)<<22|address;
    sendCommand(char(0x0A),data);
}

void DeviceHelper::sendGateLevel(quint8 gate, double level){
    double gain = gate == 0?_qmlIntegrator.gateAGain(): _qmlIntegrator.gateBGain();
    quint16 val = 2047.0/100.0*level/Constants::FILTER_COEF[_qmlIntegrator.digitalFilter()]/*/qPow(10.0,gain/20.0)*/;
    quint32 data = 0|quint32(gate)<<22|val;
    sendCommand(char(0x04),data);
}

void DeviceHelper::sendGateA(){
    if( _qmlIntegrator.gateBSync()==Enums::SyncType::SYNC_IF)
        sendGate(0, true,
             _qmlIntegrator.gateAStart()-_qmlIntegrator.iFSyncRef()-ChartsCalculations::lengthFromTime(Constants::RANGE_OFFSET)*_qmlIntegrator.soundPathMultiplier(),
             _qmlIntegrator.gateAStart()+_qmlIntegrator.gateAWidth()-_qmlIntegrator.iFSyncRef()-ChartsCalculations::lengthFromTime(Constants::RANGE_OFFSET)*_qmlIntegrator.soundPathMultiplier());
    else {
            sendGate(0, false,
                 _qmlIntegrator.gateAStart(),
                 _qmlIntegrator.gateAStart()+_qmlIntegrator.gateAWidth());
    }
}

void DeviceHelper::sendGateB(){
    sendGate(1, false,
             _qmlIntegrator.gateBStart(),
             _qmlIntegrator.gateBStart()+_qmlIntegrator.gateBWidth());
}

void DeviceHelper::sendGateLevelA(){
    sendGateLevel(0,_qmlIntegrator.gateALevel());
}

void DeviceHelper::sendGateLevelB(){
    sendGateLevel(1,_qmlIntegrator.gateBLevel());
}



void DeviceHelper::sendAlarmActive(){
    uint32_t data = 0;
    data |= _qmlIntegrator.alarmAActive()?0x00000001:0;
    data |= _qmlIntegrator.alarmBActive()?0x00000004:0;
    data |= _qmlIntegrator.alarmDACActive()?0x00000002:0;
    data |= _qmlIntegrator.horn()?0x00000008:0;
    sendCommand(char(0x31),data);
}

void DeviceHelper::sendKeyPress(char key){
    sendCommand(char(0x0F), quint32(key)<<24);
}

void DeviceHelper::sendIP(quint8 ip){
    sendCommand(char(0x2F), quint32(ip));
}
void DeviceHelper::sendBrightness(){
    sendCommand(char(0x3F), quint32(_qmlIntegrator.brightness()));
}
/*************************************************************/
void DeviceHelper::sendFilterDampDual() {
    quint32 damping = 0;
    switch(_qmlIntegrator.damping()){
    case Enums::Damping::DAMP500: damping = 0x00000000; break;
    case Enums::Damping::DAMP200: damping = 0x00000010; break;
    case Enums::Damping::DAMP50: damping = 0x00000020; break;
    case Enums::Damping::DAMP36: damping = 0x00000030; break;
    case Enums::Damping::DAMP25: damping = 0x00000040; break;
    case Enums::Damping::DAMP20: damping = 0x00000050; break;
    case Enums::Damping::DAMP17: damping = 0x00000060; break;
    case Enums::Damping::DAMP15: damping = 0x00000070; break;
    }
    quint32 filter = 0;
    switch (_qmlIntegrator.digitalFilter()) {
    case Enums::DigitalFilter::NOFILTER: filter = 0x00000000; break;
    case Enums::DigitalFilter::FILTER05TO2: filter = 0x00000100; break;
    case Enums::DigitalFilter::FILTER05TO4: filter = 0x00000200; break;
    case Enums::DigitalFilter::FILTER05TO11: filter = 0x00000300; break;
    case Enums::DigitalFilter::FILTER2TO8: filter = 0x00000400; break;
    case Enums::DigitalFilter::FILTER4TO11: filter = 0x00000500; break;

        /*    switch (_qmlIntegrator.digitalFilter()) {
    case Enums::DigitalFilter::NOFILTER: filter = 0x00000000; break;
    case Enums::DigitalFilter::FILTER05TO4: filter = 0x00000400; break;
    case Enums::DigitalFilter::FILTER05TO11: filter = 0x00000500; break;
    case Enums::DigitalFilter::FILTER2TO8: filter = 0x00000600; break;
    case Enums::DigitalFilter::FILTER8TO11: filter = 0x00000700; break;
*/
    }
    quint32 dual = (_qmlIntegrator.dualNotSingle()==Enums::DualType::DUAL_DUAL)?0x0000000001:0;
    quint32 data = dual|filter|damping;
    sendCommand(char(0x02), data);
}

/*************************************************************/
void DeviceHelper::sendTCGPoints(uint32_t startIndex , uint32_t finishIndex,QVector<quint16> codes){
    sendStop();
    sendCommand(char(0x0D),0x00008000);//TCG Mode Enable
    sendCommand(char(0x0E),0x1FFFFFFF&startIndex);
    sendCommand(char(0x0E),0x20000000|finishIndex);
    for(int i = 0; i <codes.length();i++){
        quint16 code = codes.at(i);
        sendCommand(char(0x0C),(uint32_t(startIndex/8+i)<<16)|code);
        //        QThread::msleep(50);
    }
    sendStart();
}

void DeviceHelper::sendTCGDisable(){
    sendCommand(char(0x0D),0x00000000);//TCG Mode Enable
}

void DeviceHelper::deviceConnect(){
//    pTCPCommands->deviceConnect();
    pAScan->deviceConnect();
#ifdef STRIP_CHART
    pStrip->deviceConnect();
#endif
}

void DeviceHelper::deviceDisconnect(){
//    pTCPCommands->deviceDisconnect();
    pAScan->deviceDisconnect();
#ifdef STRIP_CHART
    pStrip->deviceDisconnect();
#endif
}

void DeviceHelper::sendCommand(char reg, quint32 data){
    pTCPCommands->sendCommand(reg,data);
}
#endif
