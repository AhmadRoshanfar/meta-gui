#include "settingshelper.h"
#include <QSettings>

#include "../Common/Models/evalmethod.h"
#include "../Common/Adaptors/evaluationadaptor.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

Q_DECLARE_METATYPE(QVector<QPointF>)

SettingsHelper::SettingsHelper(QObject *parent) : QObject(parent)
{

}

bool SettingsHelper::save(QString filename,QString desc){
    QJsonObject obj;
//    qRegisterMetaTypeStreamOperators<QVector<QPointF>>("QVector<QPointF>");
    obj.insert("gain",_qmlIntegrator.gain());
    obj.insert("range",_qmlIntegrator.range());
    obj.insert("probeDelay",_qmlIntegrator.probeDelay());
    obj.insert("displayDelay",_qmlIntegrator.displayDelay());
    obj.insert("velocity",_qmlIntegrator.velocity());
    obj.insert("prf",_qmlIntegrator.prf());
    obj.insert("power",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.pulseAmplitude()))));
    obj.insert("pulserType",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.pulserType()))));

    obj.insert("damping",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.damping()))));
    obj.insert("rectify",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.polarity()))));
    obj.insert("dual",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.dualNotSingle()))));
    obj.insert("digitalFilter",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.digitalFilter()))));
    obj.insert("reject",_qmlIntegrator.rejection());
    obj.insert("gateAMode",_qmlIntegrator.gateAEnabled());
    obj.insert("gateAStart",_qmlIntegrator.gateAStart());
    obj.insert("gateAWidth",_qmlIntegrator.gateAWidth());
    obj.insert("gateALevel",_qmlIntegrator.gateALevel());
    obj.insert("gateAGain",_qmlIntegrator.gateAGain());
    obj.insert("gateATOF",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.peakMethodA()))));
    obj.insert("gateALogic",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.gateALogic()))));
    obj.insert("gateBMode",_qmlIntegrator.gateBEnabled());
    obj.insert("gateBStart",_qmlIntegrator.gateBStart());
    obj.insert("gateBWidth",_qmlIntegrator.gateBWidth());
    obj.insert("gateBLevel",_qmlIntegrator.gateBLevel());
    obj.insert("gateBGain",_qmlIntegrator.gateBGain());
    obj.insert("gateBTOF",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.peakMethodA()))));
    obj.insert("gateBLogic",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.gateBLogic()))));
    obj.insert("materialType",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.shape()))));
    obj.insert("thickness",_qmlIntegrator.thickness());
    obj.insert("materialDiameter",_qmlIntegrator.pipeDiameter());
    obj.insert("probeType",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.probeType()))));
    obj.insert("probeAngle",_qmlIntegrator.probeAngle());
    obj.insert("probeIndex",_qmlIntegrator.probeIndex());
    obj.insert("probeDiameter",_qmlIntegrator.probeDiameter());
    obj.insert("spath1",_qmlIntegrator.spath1());
    obj.insert("spath2",_qmlIntegrator.spath2());
    obj.insert("theme",_qmlIntegrator.theme());
    obj.insert("envelope",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.envelope()))));
    obj.insert("grid",_qmlIntegrator.grid());
    obj.insert("tcorr",_qmlIntegrator.tcorr());
    obj.insert("fill",_qmlIntegrator.fill());
    obj.insert("topbar",_subqmlIntegrator.topbarVisible());
    obj.insert("bottombar",_subqmlIntegrator.bottombarVisible());
    obj.insert("brightness",_qmlIntegrator.brightness());
    obj.insert("alarmAEnable",_qmlIntegrator.alarmAEnable());
    obj.insert("alarmBEnable",_qmlIntegrator.alarmBEnable());
    obj.insert("alarmEval",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.dacAlarmLevel()))));
    obj.insert("horn",_qmlIntegrator.horn());
    obj.insert("unit",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.unit()))));
    obj.insert("legEnable",_qmlIntegrator.legEnable());
    obj.insert("evaluationMode",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.evaluationMode()))));
    obj.insert("activated",_qmlIntegrator.activated());
    obj.insert("gainRef",_qmlIntegrator.refGain());
    obj.insert("classStep1",_qmlIntegrator.classStep1());
    obj.insert("classStep2",_qmlIntegrator.classStep2());
    obj.insert("classStep3",_qmlIntegrator.classStep3());
    obj.insert("spathStep",_qmlIntegrator.spathStep());
    obj.insert("prfStep",_qmlIntegrator.prfStep());
    obj.insert("velocityStep",_qmlIntegrator.velocityStep());
    obj.insert("textOnChart",QJsonValue::fromVariant(QVariant::fromValue(static_cast<uint>(_qmlIntegrator.textOnChart()))));
    QJsonArray a = _jsonFileHelper.toJson(evalAdap._map[Enums::EvaluationMode::EVAL_DAC].points);
    obj.insert("DacPoints",a);
    a = _jsonFileHelper.toJson(evalAdap._map[Enums::EvaluationMode::EVAL_AWS].points);
    obj.insert("AwsPoints",a);
    a = _jsonFileHelper.toJson(evalAdap._map[Enums::EvaluationMode::EVAL_TCG].points);
    obj.insert("TcgPoints",a);
    a = _jsonFileHelper.toJson(evalAdap._DACGains);
    obj.insert("DacGains",a);
    return _dbHelper.insertSettings(filename,desc,obj);
}





bool SettingsHelper::read(QString filename)
{
    QJsonObject obj = _dbHelper.getSettings(filename);
    if(obj.keys().count() == 0)
        return false;
    if(obj.contains("gain"))  _qmlIntegrator.setGain(obj.value("gain").toDouble());
    if(obj.contains("velocity")) _qmlIntegrator.setVelocity(obj.value("velocity").toInt());
    if(obj.contains("probeDelay"))_qmlIntegrator.setProbeDelay(obj.value("probeDelay").toDouble());
    if(obj.contains("displayDelay"))_qmlIntegrator.setDisplayDelay(obj.value("displayDelay").toDouble());
    if(obj.contains("range"))_qmlIntegrator.setRange(obj.value("range").toDouble());

    if(obj.contains("prf"))_qmlIntegrator.setPrf(obj.value("prf").toInt());
    if(obj.contains("power"))_qmlIntegrator.setPulseAmplitude(static_cast<Enums::PulseAmplitude>(obj.value("power").toInt()));

    if(obj.contains("pulserType"))_qmlIntegrator.setPulserType(static_cast<Enums::PulserType>(obj.value("pulserType").toInt()));
    if(obj.contains("damping"))_qmlIntegrator.setDamping(static_cast<Enums::Damping>(obj.value("damping").toInt()));
    if(obj.contains("rectify"))_qmlIntegrator.setPolarity(static_cast<Enums::Polarity>(obj.value("rectify").toInt()));
    if(obj.contains("digitalFilter"))_qmlIntegrator.setDigitalFilter(static_cast<Enums::DigitalFilter>(obj.value("digitalFilter").toInt()));
    if(obj.contains("reject"))_qmlIntegrator.setRejection(obj.value("reject").toInt());
    if(obj.contains("gateAMode"))_qmlIntegrator.setGateAEnabled(obj.value("gateAMode").toBool());
    if(obj.contains("gateAStart"))_qmlIntegrator.setGateAStart(obj.value("gateAStart").toDouble());
    if(obj.contains("gateAWidth"))_qmlIntegrator.setGateAWidth(obj.value("gateAWidth").toDouble());
    if(obj.contains("gateALevel"))_qmlIntegrator.setGateALevel(obj.value("gateALevel").toInt());
    if(obj.contains("gateAGain"))_qmlIntegrator.setGateAGain(obj.value("gateAGain").toInt());
    if(obj.contains("gateATOF"))_qmlIntegrator.setPeakMethodA(static_cast<Enums::PeakMethod>(obj.value("gateATOF").toInt()));
    if(obj.contains("gateALogic"))_qmlIntegrator.setGateALogic(static_cast<Enums::PosNeg>(obj.value("gateALogic").toInt()));
    if(obj.contains("gateBMode"))_qmlIntegrator.setGateBEnabled(obj.value("gateBMode").toBool());
    if(obj.contains("gateBStart"))_qmlIntegrator.setGateBStart(obj.value("gateBStart").toDouble());
    if(obj.contains("gateBWidth"))_qmlIntegrator.setGateBWidth(obj.value("gateBWidth").toDouble());
    if(obj.contains("gateBLevel"))_qmlIntegrator.setGateBLevel(obj.value("gateBLevel").toInt());
    if(obj.contains("gateBGain"))_qmlIntegrator.setGateBGain(obj.value("gateBGain").toDouble());
    if(obj.contains("gateBTOF"))_qmlIntegrator.setPeakMethodB(static_cast<Enums::PeakMethod>(obj.value("gateBTOF").toInt()));
    if(obj.contains("gateBLogic"))_qmlIntegrator.setGateBLogic(static_cast<Enums::PosNeg>(obj.value("gateBLogic").toInt()));
    if(obj.contains("materialType"))_qmlIntegrator.setShape(static_cast<Enums::Shape>(obj.value("materialType").toInt()));
    if(obj.contains("thickness"))_qmlIntegrator.setThickness(obj.value("thickness").toDouble());
    if(obj.contains("materialDiameter"))_qmlIntegrator.setPipeDiameter(obj.value("materialDiameter").toDouble());
    if(obj.contains("probeType"))_qmlIntegrator.setProbeType(static_cast<Enums::ProbeType>(obj.value("probeType").toInt()));
    if(obj.contains("probeAngle"))_qmlIntegrator.setProbeAngle(obj.value("probeAngle").toDouble());
    if(obj.contains("probeIndex"))_qmlIntegrator.setProbeIndex(obj.value("probeIndex").toDouble());
    if(obj.contains("probeDiameter"))_qmlIntegrator.setProbeDiameter(obj.value("probeDiameter").toDouble());
    if(obj.contains("spath1"))_qmlIntegrator.setSpath1(obj.value("spath1").toDouble());
    if(obj.contains("spath2"))_qmlIntegrator.setSpath2(obj.value("spath2").toDouble());
    if(obj.contains("theme"))_qmlIntegrator.setTheme(obj.value("theme").toInt());
    if(obj.contains("envelope"))_qmlIntegrator.setEnvelope(static_cast<Enums::EnvelopeType>(obj.value("envelope").toInt()));
    if(obj.contains("grid"))_qmlIntegrator.setGrid(obj.value("grid").toBool());
    if(obj.contains("tcorr"))_qmlIntegrator.setTcorr(obj.value("tcorr").toDouble());
    if(obj.contains("topbar"))_subqmlIntegrator.setTopbarVisible(obj.value("topbar").toBool());
    if(obj.contains("bottombar"))_subqmlIntegrator.setBottombarVisible(obj.value("bottombar").toBool());
    if(obj.contains("brightness"))_qmlIntegrator.setBrightness(obj.value("brightness").toInt());
    if(obj.contains("alarmAEnable"))_qmlIntegrator.setAlarmAEnable(obj.value("alarmAEnable").toBool());
    if(obj.contains("alarmBEnable"))_qmlIntegrator.setAlarmBEnable(obj.value("alarmBEnable").toBool());
    if(obj.contains("alarmEval"))_qmlIntegrator.setDacAlarmLevel(static_cast<Enums::DACAlarm>(obj.value("alarmEval").toInt()));
    if(obj.contains("horn"))_qmlIntegrator.setHorn(obj.value("horn").toBool());
    if(obj.contains("unit"))_qmlIntegrator.setUnit(static_cast<Enums::Unit>(obj.value("unit").toInt()));
    if(obj.contains("legEnable"))_qmlIntegrator.setLegEnable(obj.value("legEnable").toBool());

    if(obj.contains("classStep1"))_qmlIntegrator.setClassStep1(obj.value("classStep1").toInt());
    if(obj.contains("classStep2"))_qmlIntegrator.setClassStep2(obj.value("classStep2").toInt());
    if(obj.contains("classStep3"))_qmlIntegrator.setClassStep3(obj.value("classStep3").toInt());
    if(obj.contains("spathStep"))_qmlIntegrator.setSpathStep(obj.value("spathStep").toInt());
    if(obj.contains("velocityStep"))_qmlIntegrator.setVelocityStep(obj.value("velocityStep").toInt());

    if(obj.contains("textOnChart"))_qmlIntegrator.setTextOnChart(static_cast<Enums::TextOnChart>(obj.value("textOnChart").toInt()));


    QJsonArray a = obj.value("AwsPoints").toArray();
    evalAdap._map[Enums::EvaluationMode::EVAL_AWS].points=_jsonFileHelper.fromJsonQVectorQPointF(a);
    a = obj.value("DacPoints").toArray();
    evalAdap._map[Enums::EvaluationMode::EVAL_DAC].points=_jsonFileHelper.fromJsonQVectorQPointF(a);
    a = obj.value("DacGains").toArray();
    evalAdap._DACGains=_jsonFileHelper.fromJsonQVectorDouble(a);
    a = obj.value("TcgPoints").toArray();
    evalAdap._map[Enums::EvaluationMode::EVAL_TCG].points=_jsonFileHelper.fromJsonQVectorQPointF(a);
    if(obj.contains("evaluationMode")) _qmlIntegrator.setEvaluationMode(static_cast<Enums::EvaluationMode>(obj.value("evaluationMode").toInt()));
    if(obj.contains("gainRef")) _qmlIntegrator.setRefGain(obj.value("gainRef").toDouble());
    evalAdap.refreshPoints();
    _qmlIntegrator.setActivated(false);
    if(obj.contains("activated")) _qmlIntegrator.setActivated(obj.value("activated").toBool());
    //    qDebug()<<obj.value("DacPoints").value<QVector<QPointF>>()[0].x();
	return true;
}

void SettingsHelper::loadDefaults()
{
    _qmlIntegrator.setGain(10.0);
    _qmlIntegrator.setVelocity(5920);
    _qmlIntegrator.setProbeDelay(0);
    _qmlIntegrator.setDisplayDelay(0);
    _qmlIntegrator.setRange(100.0);
    _qmlIntegrator.setPrf(50);
    _qmlIntegrator.setPulseAmplitude(Enums::PulseAmplitude::PA_MED);
    _qmlIntegrator.setPulserType(Enums::PulserType::PULTY_SPIKE);
    _qmlIntegrator.setDamping(Enums::Damping::DAMP200);
    _qmlIntegrator.setPolarity(Enums::Polarity::POL_RF);
    _qmlIntegrator.setDigitalFilter(Enums::DigitalFilter::NOFILTER);
    _qmlIntegrator.setRejection(0);
    _qmlIntegrator.setGateAEnabled(true);
    _qmlIntegrator.setGateAStart(10);
    _qmlIntegrator.setGateAWidth(10);
    _qmlIntegrator.setGateALevel(10);
    _qmlIntegrator.setGateAGain(0);
    _qmlIntegrator.setPeakMethodA(Enums::PeakMethod::PM_PEAK);
    _qmlIntegrator.setGateALogic(Enums::PosNeg::PN_POS);
    _qmlIntegrator.setGateBEnabled(true);
    _qmlIntegrator.setGateBStart(40);
    _qmlIntegrator.setGateBWidth(10);
    _qmlIntegrator.setGateBLevel(50);
    _qmlIntegrator.setGateBGain(0);
    _qmlIntegrator.setPeakMethodB(Enums::PeakMethod::PM_PEAK);
    _qmlIntegrator.setGateBLogic(Enums::PosNeg::PN_POS);
    _qmlIntegrator.setShape(Enums::Shape::SHAPE_PLATE);
    _qmlIntegrator.setThickness(0);
    _qmlIntegrator.setPipeDiameter(0);
    _qmlIntegrator.setProbeType(Enums::ProbeType::PT_NORMAL);
    _qmlIntegrator.setProbeAngle(0);
    _qmlIntegrator.setProbeIndex(0);
    _qmlIntegrator.setProbeDiameter(10);
    _qmlIntegrator.setSpath1(10);
    _qmlIntegrator.setSpath2(20);
    _qmlIntegrator.setTheme(1);
    _qmlIntegrator.setEnvelope(Enums::EnvelopeType::ENV_OFF);
    _qmlIntegrator.setGrid(true);
    _qmlIntegrator.setTcorr(0);
//    qDebug()<<obj.value("grid");
//    obj.insert("fill",_qmlIntegrator.fill());
    _subqmlIntegrator.setTopbarVisible(true);
    _subqmlIntegrator.setBottombarVisible(true);
    _qmlIntegrator.setBrightness(4);
    _qmlIntegrator.setAlarmAEnable(false);
    _qmlIntegrator.setAlarmBEnable(false);
    _qmlIntegrator.setDacAlarmLevel(Enums::DACAlarm::DA_20);
    _qmlIntegrator.setHorn(false);
    _qmlIntegrator.setUnit(Enums::Unit::UNIT_MM);
    _qmlIntegrator.setLegEnable(false);

    _qmlIntegrator.setClassStep1(1);
    _qmlIntegrator.setClassStep2(1);
    _qmlIntegrator.setClassStep3(1);
    _qmlIntegrator.setSpathStep(1);
    _qmlIntegrator.setVelocityStep(0);

    _qmlIntegrator.setTextOnChart(Enums::TextOnChart::TOC_NONE);

    QJsonArray a;
    evalAdap._map[Enums::EvaluationMode::EVAL_AWS].points=_jsonFileHelper.fromJsonQVectorQPointF(a);
    evalAdap._map[Enums::EvaluationMode::EVAL_DAC].points=_jsonFileHelper.fromJsonQVectorQPointF(a);
    evalAdap._map[Enums::EvaluationMode::EVAL_TCG].points=_jsonFileHelper.fromJsonQVectorQPointF(a);
    _qmlIntegrator.setEvaluationMode(Enums::EvaluationMode::EVAL_NORMAL);
    _qmlIntegrator.setRefGain(0);

    _qmlIntegrator.setActivated(false);
    evalAdap._DACGains.clear();
    //    qDebug()<<obj.value("DacPoints").value<QVector<QPointF>>()[0].x();
}
