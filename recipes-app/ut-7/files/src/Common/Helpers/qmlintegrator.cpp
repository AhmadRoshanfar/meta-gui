#include "qmlintegrator.h"

QmlIntegrator::QmlIntegrator( QObject *parent) :
    QObject(parent)
{
            }

	double QmlIntegrator::gain(){
	return _gain;
}
void QmlIntegrator::setGain(const 	double &val){
	if (val == _gain)
		return;
	_gain = val;
	emit onGainChanged();
}
 
	Enums::PulseAmplitude QmlIntegrator::pulseAmplitude(){
	return _pulseAmplitude;
}
void QmlIntegrator::setPulseAmplitude(const 	Enums::PulseAmplitude &val){
	if (val == _pulseAmplitude)
		return;
	_pulseAmplitude = val;
	emit onPulseAmplitudeChanged();
}
 
	double QmlIntegrator::gainStep(){
	return _gainStep;
}
void QmlIntegrator::setGainStep(const 	double &val){
	if (val == _gainStep)
		return;
	_gainStep = val;
	emit onGainStepChanged();
}
 
	double QmlIntegrator::paramStep(){
	return _paramStep;
}
void QmlIntegrator::setParamStep(const 	double &val){
	if (val == _paramStep)
		return;
	_paramStep = val;
	emit onParamStepChanged();
}
 
	double QmlIntegrator::refGain(){
	return _refGain;
}
void QmlIntegrator::setRefGain(const 	double &val){
	if (val == _refGain)
		return;
	_refGain = val;
	emit onRefGainChanged();
}
 
	bool QmlIntegrator::legEnable(){
	return _legEnable;
}
void QmlIntegrator::setLegEnable(const 	bool &val){
	if (val == _legEnable)
		return;
	_legEnable = val;
	emit onLegEnableChanged();
}
 
	double QmlIntegrator::range(){
	return _range;
}
void QmlIntegrator::setRange(const 	double &val){
	if (val == _range)
		return;
	_range = val;
	emit onRangeChanged();
}
 
	double QmlIntegrator::rangeMax(){
	return _rangeMax;
}
void QmlIntegrator::setRangeMax(const 	double &val){
	if (val == _rangeMax)
		return;
	_rangeMax = val;
	emit onRangeMaxChanged();
}
 
	double QmlIntegrator::displayDelay(){
	return _displayDelay;
}
void QmlIntegrator::setDisplayDelay(const 	double &val){
	if (val == _displayDelay)
		return;
	_displayDelay = val;
	emit onDisplayDelayChanged();
}
 
	double QmlIntegrator::displayDelayMin(){
	return _displayDelayMin;
}
void QmlIntegrator::setDisplayDelayMin(const 	double &val){
	if (val == _displayDelayMin)
		return;
	_displayDelayMin = val;
	emit onDisplayDelayMinChanged();
}
 
	double QmlIntegrator::displayDelayMax(){
	return _displayDelayMax;
}
void QmlIntegrator::setDisplayDelayMax(const 	double &val){
	if (val == _displayDelayMax)
		return;
	_displayDelayMax = val;
	emit onDisplayDelayMaxChanged();
}
 
	double QmlIntegrator::UIRange(){
	return _UIRange;
}
void QmlIntegrator::setUIRange(const 	double &val){
	if (val == _UIRange)
		return;
	_UIRange = val;
	emit onUIRangeChanged();
}
 
	double QmlIntegrator::UIRangeMax(){
	return _UIRangeMax;
}
void QmlIntegrator::setUIRangeMax(const 	double &val){
	if (val == _UIRangeMax)
		return;
	_UIRangeMax = val;
	emit onUIRangeMaxChanged();
}
 
	double QmlIntegrator::UIDisplayDelay(){
	return _UIDisplayDelay;
}
void QmlIntegrator::setUIDisplayDelay(const 	double &val){
	if (val == _UIDisplayDelay)
		return;
	_UIDisplayDelay = val;
	emit onUIDisplayDelayChanged();
}
 
	double QmlIntegrator::UIDisplayDelayMin(){
	return _UIDisplayDelayMin;
}
void QmlIntegrator::setUIDisplayDelayMin(const 	double &val){
	if (val == _UIDisplayDelayMin)
		return;
	_UIDisplayDelayMin = val;
	emit onUIDisplayDelayMinChanged();
}
 
	double QmlIntegrator::UIDisplayDelayMax(){
	return _UIDisplayDelayMax;
}
void QmlIntegrator::setUIDisplayDelayMax(const 	double &val){
	if (val == _UIDisplayDelayMax)
		return;
	_UIDisplayDelayMax = val;
	emit onUIDisplayDelayMaxChanged();
}
 
	double QmlIntegrator::UISpath1(){
	return _UISpath1;
}
void QmlIntegrator::setUISpath1(const 	double &val){
	if (val == _UISpath1)
		return;
	_UISpath1 = val;
	emit onUISpath1Changed();
}
 
	double QmlIntegrator::UISpath2(){
	return _UISpath2;
}
void QmlIntegrator::setUISpath2(const 	double &val){
	if (val == _UISpath2)
		return;
	_UISpath2 = val;
	emit onUISpath2Changed();
}
 
	double QmlIntegrator::UIGateAStart(){
	return _UIGateAStart;
}
void QmlIntegrator::setUIGateAStart(const 	double &val){
	if (val == _UIGateAStart)
		return;
	_UIGateAStart = val;
	emit onUIGateAStartChanged();
}
 
	double QmlIntegrator::UIGateAWidth(){
	return _UIGateAWidth;
}
void QmlIntegrator::setUIGateAWidth(const 	double &val){
	if (val == _UIGateAWidth)
		return;
	_UIGateAWidth = val;
	emit onUIGateAWidthChanged();
}
 
	double QmlIntegrator::UIGateBStart(){
	return _UIGateBStart;
}
void QmlIntegrator::setUIGateBStart(const 	double &val){
	if (val == _UIGateBStart)
		return;
	_UIGateBStart = val;
	emit onUIGateBStartChanged();
}
 
	double QmlIntegrator::UIGateBWidth(){
	return _UIGateBWidth;
}
void QmlIntegrator::setUIGateBWidth(const 	double &val){
	if (val == _UIGateBWidth)
		return;
	_UIGateBWidth = val;
	emit onUIGateBWidthChanged();
}
 
	int QmlIntegrator::velocity(){
	return _velocity;
}
void QmlIntegrator::setVelocity(const 	int &val){
	if (val == _velocity)
		return;
	_velocity = val;
	emit onVelocityChanged();
}
 
	int QmlIntegrator::rejection(){
	return _rejection;
}
void QmlIntegrator::setRejection(const 	int &val){
	if (val == _rejection)
		return;
	_rejection = val;
	emit onRejectionChanged();
}
 
	bool QmlIntegrator::zoomed(){
	return _zoomed;
}
void QmlIntegrator::setZoomed(const 	bool &val){
	if (val == _zoomed)
		return;
	_zoomed = val;
	emit onZoomedChanged();
}
 
	double QmlIntegrator::gateAStart(){
	return _gateAStart;
}
void QmlIntegrator::setGateAStart(const 	double &val){
	if (val == _gateAStart)
		return;
	_gateAStart = val;
	emit onGateAStartChanged();
}
 
	double QmlIntegrator::gateAWidth(){
	return _gateAWidth;
}
void QmlIntegrator::setGateAWidth(const 	double &val){
	if (val == _gateAWidth)
		return;
	_gateAWidth = val;
	emit onGateAWidthChanged();
}
 
	int QmlIntegrator::gateALevel(){
	return _gateALevel;
}
void QmlIntegrator::setGateALevel(const 	int &val){
	if (val == _gateALevel)
		return;
	_gateALevel = val;
	emit onGateALevelChanged();
}
 
	double QmlIntegrator::gateAGain(){
	return _gateAGain;
}
void QmlIntegrator::setGateAGain(const 	double &val){
	if (val == _gateAGain)
		return;
	_gateAGain = val;
	emit onGateAGainChanged();
}
 
	Enums::SyncType QmlIntegrator::gateASync(){
	return _gateASync;
}
void QmlIntegrator::setGateASync(const 	Enums::SyncType &val){
	if (val == _gateASync)
		return;
	_gateASync = val;
	emit onGateASyncChanged();
}
 
	Enums::TextOnChart QmlIntegrator::textOnChart(){
	return _textOnChart;
}
void QmlIntegrator::setTextOnChart(const 	Enums::TextOnChart &val){
	if (val == _textOnChart)
		return;
	_textOnChart = val;
	emit onTextOnChartChanged();
}
 
	Enums::PosNeg QmlIntegrator::gateALogic(){
	return _gateALogic;
}
void QmlIntegrator::setGateALogic(const 	Enums::PosNeg &val){
	if (val == _gateALogic)
		return;
	_gateALogic = val;
	emit onGateALogicChanged();
}
 
	double QmlIntegrator::gateBStart(){
	return _gateBStart;
}
void QmlIntegrator::setGateBStart(const 	double &val){
	if (val == _gateBStart)
		return;
	_gateBStart = val;
	emit onGateBStartChanged();
}
 
	double QmlIntegrator::gateBWidth(){
	return _gateBWidth;
}
void QmlIntegrator::setGateBWidth(const 	double &val){
	if (val == _gateBWidth)
		return;
	_gateBWidth = val;
	emit onGateBWidthChanged();
}
 
	int QmlIntegrator::gateBLevel(){
	return _gateBLevel;
}
void QmlIntegrator::setGateBLevel(const 	int &val){
	if (val == _gateBLevel)
		return;
	_gateBLevel = val;
	emit onGateBLevelChanged();
}
 
	double QmlIntegrator::gateBGain(){
	return _gateBGain;
}
void QmlIntegrator::setGateBGain(const 	double &val){
	if (val == _gateBGain)
		return;
	_gateBGain = val;
	emit onGateBGainChanged();
}
 
	Enums::SyncType QmlIntegrator::gateBSync(){
	return _gateBSync;
}
void QmlIntegrator::setGateBSync(const 	Enums::SyncType &val){
	if (val == _gateBSync)
		return;
	_gateBSync = val;
	emit onGateBSyncChanged();
}
 
	Enums::PosNeg QmlIntegrator::gateBLogic(){
	return _gateBLogic;
}
void QmlIntegrator::setGateBLogic(const 	Enums::PosNeg &val){
	if (val == _gateBLogic)
		return;
	_gateBLogic = val;
	emit onGateBLogicChanged();
}
 
	double QmlIntegrator::probeIndex(){
	return _probeIndex;
}
void QmlIntegrator::setProbeIndex(const 	double &val){
	if (val == _probeIndex)
		return;
	_probeIndex = val;
	emit onProbeIndexChanged();
}
 
	double QmlIntegrator::probeAngle(){
	return _probeAngle;
}
void QmlIntegrator::setProbeAngle(const 	double &val){
	if (val == _probeAngle)
		return;
	_probeAngle = val;
	emit onProbeAngleChanged();
}
 
	double QmlIntegrator::stripAxisXMin(){
	return _stripAxisXMin;
}
void QmlIntegrator::setStripAxisXMin(const 	double &val){
	if (val == _stripAxisXMin)
		return;
	_stripAxisXMin = val;
	emit onStripAxisXMinChanged();
}
 
	double QmlIntegrator::stripAxisXMax(){
	return _stripAxisXMax;
}
void QmlIntegrator::setStripAxisXMax(const 	double &val){
	if (val == _stripAxisXMax)
		return;
	_stripAxisXMax = val;
	emit onStripAxisXMaxChanged();
}
 
	double QmlIntegrator::aScanAxisXMin(){
	return _aScanAxisXMin;
}
void QmlIntegrator::setAScanAxisXMin(const 	double &val){
	if (val == _aScanAxisXMin)
		return;
	_aScanAxisXMin = val;
	emit onAScanAxisXMinChanged();
}
 
	double QmlIntegrator::aScanAxisXMax(){
	return _aScanAxisXMax;
}
void QmlIntegrator::setAScanAxisXMax(const 	double &val){
	if (val == _aScanAxisXMax)
		return;
	_aScanAxisXMax = val;
	emit onAScanAxisXMaxChanged();
}
 
	double QmlIntegrator::aScanAxisYMin(){
	return _aScanAxisYMin;
}
void QmlIntegrator::setAScanAxisYMin(const 	double &val){
	if (val == _aScanAxisYMin)
		return;
	_aScanAxisYMin = val;
	emit onAScanAxisYMinChanged();
}
 
	double QmlIntegrator::aScanAxisYMax(){
	return _aScanAxisYMax;
}
void QmlIntegrator::setAScanAxisYMax(const 	double &val){
	if (val == _aScanAxisYMax)
		return;
	_aScanAxisYMax = val;
	emit onAScanAxisYMaxChanged();
}
 
	int QmlIntegrator::stripTime(){
	return _stripTime;
}
void QmlIntegrator::setStripTime(const 	int &val){
	if (val == _stripTime)
		return;
	_stripTime = val;
	emit onStripTimeChanged();
}
 
	int QmlIntegrator::prf(){
	return _prf;
}
void QmlIntegrator::setPrf(const 	int &val){
	if (val == _prf)
		return;
	_prf = val;
	emit onPrfChanged();
}
 
	double QmlIntegrator::probeDelay(){
	return _probeDelay;
}
void QmlIntegrator::setProbeDelay(const 	double &val){
	if (val == _probeDelay)
		return;
	_probeDelay = val;
	emit onProbeDelayChanged();
}
 
	double QmlIntegrator::thickness(){
	return _thickness;
}
void QmlIntegrator::setThickness(const 	double &val){
	if (val == _thickness)
		return;
	_thickness = val;
	emit onThicknessChanged();
}
 
	double QmlIntegrator::probeDiameter(){
	return _probeDiameter;
}
void QmlIntegrator::setProbeDiameter(const 	double &val){
	if (val == _probeDiameter)
		return;
	_probeDiameter = val;
	emit onProbeDiameterChanged();
}
 
	int QmlIntegrator::lineSpeed(){
	return _lineSpeed;
}
void QmlIntegrator::setLineSpeed(const 	int &val){
	if (val == _lineSpeed)
		return;
	_lineSpeed = val;
	emit onLineSpeedChanged();
}
 
	Enums::Polarity QmlIntegrator::polarity(){
	return _polarity;
}
void QmlIntegrator::setPolarity(const 	Enums::Polarity &val){
	if (val == _polarity)
		return;
	_polarity = val;
	emit onPolarityChanged();
}
 
	Enums::ProbeType QmlIntegrator::probeType(){
	return _probeType;
}
void QmlIntegrator::setProbeType(const 	Enums::ProbeType &val){
	if (val == _probeType)
		return;
	_probeType = val;
	emit onProbeTypeChanged();
}
 
	Enums::PeakMethod QmlIntegrator::peakMethodA(){
	return _peakMethodA;
}
void QmlIntegrator::setPeakMethodA(const 	Enums::PeakMethod &val){
	if (val == _peakMethodA)
		return;
	_peakMethodA = val;
	emit onPeakMethodAChanged();
}
 
	Enums::PeakMethod QmlIntegrator::peakMethodB(){
	return _peakMethodB;
}
void QmlIntegrator::setPeakMethodB(const 	Enums::PeakMethod &val){
	if (val == _peakMethodB)
		return;
	_peakMethodB = val;
	emit onPeakMethodBChanged();
}
 
	Enums::EvaluationMode QmlIntegrator::evaluationMode(){
	return _evaluationMode;
}
void QmlIntegrator::setEvaluationMode(const 	Enums::EvaluationMode &val){
	if (val == _evaluationMode)
		return;
	_evaluationMode = val;
	emit onEvaluationModeChanged();
}
 
	Enums::DigitalFilter QmlIntegrator::digitalFilter(){
	return _digitalFilter;
}
void QmlIntegrator::setDigitalFilter(const 	Enums::DigitalFilter &val){
	if (val == _digitalFilter)
		return;
	_digitalFilter = val;
	emit onDigitalFilterChanged();
}
 
	Enums::Damping QmlIntegrator::damping(){
	return _damping;
}
void QmlIntegrator::setDamping(const 	Enums::Damping &val){
	if (val == _damping)
		return;
	_damping = val;
	emit onDampingChanged();
}
 
	Enums::DualType QmlIntegrator::dualNotSingle(){
	return _dualNotSingle;
}
void QmlIntegrator::setDualNotSingle(const 	Enums::DualType &val){
	if (val == _dualNotSingle)
		return;
	_dualNotSingle = val;
	emit onDualNotSingleChanged();
}
 
	Enums::EnvelopeType QmlIntegrator::envelope(){
	return _envelope;
}
void QmlIntegrator::setEnvelope(const 	Enums::EnvelopeType &val){
	if (val == _envelope)
		return;
	_envelope = val;
	emit onEnvelopeChanged();
}
 
	bool QmlIntegrator::freezed(){
	return _freezed;
}
void QmlIntegrator::setFreezed(const 	bool &val){
	if (val == _freezed)
		return;
	_freezed = val;
	emit onFreezedChanged();
}
 
	QPointF QmlIntegrator::currentPeakA(){
	return _currentPeakA;
}
void QmlIntegrator::setCurrentPeakA(const 	QPointF &val){
	if (val == _currentPeakA)
		return;
	_currentPeakA = val;
	emit onCurrentPeakAChanged();
}
 
	QPointF QmlIntegrator::currentFlankA(){
	return _currentFlankA;
}
void QmlIntegrator::setCurrentFlankA(const 	QPointF &val){
	if (val == _currentFlankA)
		return;
	_currentFlankA = val;
	emit onCurrentFlankAChanged();
}
 
	QPointF QmlIntegrator::currentJFlankA(){
	return _currentJFlankA;
}
void QmlIntegrator::setCurrentJFlankA(const 	QPointF &val){
	if (val == _currentJFlankA)
		return;
	_currentJFlankA = val;
	emit onCurrentJFlankAChanged();
}
 
	QPointF QmlIntegrator::currentMarkerA(){
	return _currentMarkerA;
}
void QmlIntegrator::setCurrentMarkerA(const 	QPointF &val){
	if (val == _currentMarkerA)
		return;
	_currentMarkerA = val;
	emit onCurrentMarkerAChanged();
}
 
	QPointF QmlIntegrator::currentUpwardA(){
	return _currentUpwardA;
}
void QmlIntegrator::setCurrentUpwardA(const 	QPointF &val){
	if (val == _currentUpwardA)
		return;
	_currentUpwardA = val;
	emit onCurrentUpwardAChanged();
}
 
	QPointF QmlIntegrator::currentDownwardA(){
	return _currentDownwardA;
}
void QmlIntegrator::setCurrentDownwardA(const 	QPointF &val){
	if (val == _currentDownwardA)
		return;
	_currentDownwardA = val;
	emit onCurrentDownwardAChanged();
}
 
	QPointF QmlIntegrator::currentPeakB(){
	return _currentPeakB;
}
void QmlIntegrator::setCurrentPeakB(const 	QPointF &val){
	if (val == _currentPeakB)
		return;
	_currentPeakB = val;
	emit onCurrentPeakBChanged();
}
 
	QPointF QmlIntegrator::currentFlankB(){
	return _currentFlankB;
}
void QmlIntegrator::setCurrentFlankB(const 	QPointF &val){
	if (val == _currentFlankB)
		return;
	_currentFlankB = val;
	emit onCurrentFlankBChanged();
}
 
	QPointF QmlIntegrator::currentJFlankB(){
	return _currentJFlankB;
}
void QmlIntegrator::setCurrentJFlankB(const 	QPointF &val){
	if (val == _currentJFlankB)
		return;
	_currentJFlankB = val;
	emit onCurrentJFlankBChanged();
}
 
	QPointF QmlIntegrator::currentMarkerB(){
	return _currentMarkerB;
}
void QmlIntegrator::setCurrentMarkerB(const 	QPointF &val){
	if (val == _currentMarkerB)
		return;
	_currentMarkerB = val;
	emit onCurrentMarkerBChanged();
}
 
	QPointF QmlIntegrator::currentUpwardB(){
	return _currentUpwardB;
}
void QmlIntegrator::setCurrentUpwardB(const 	QPointF &val){
	if (val == _currentUpwardB)
		return;
	_currentUpwardB = val;
	emit onCurrentUpwardBChanged();
}
 
	QPointF QmlIntegrator::currentDownwardB(){
	return _currentDownwardB;
}
void QmlIntegrator::setCurrentDownwardB(const 	QPointF &val){
	if (val == _currentDownwardB)
		return;
	_currentDownwardB = val;
	emit onCurrentDownwardBChanged();
}
 
	int QmlIntegrator::calibrationPointIndex(){
	return _calibrationPointIndex;
}
void QmlIntegrator::setCalibrationPointIndex(const 	int &val){
	if (val == _calibrationPointIndex)
		return;
	_calibrationPointIndex = val;
	emit onCalibrationPointIndexChanged();
}
 
	int QmlIntegrator::evaluationPointIndex(){
	return _evaluationPointIndex;
}
void QmlIntegrator::setEvaluationPointIndex(const 	int &val){
	if (val == _evaluationPointIndex)
		return;
	_evaluationPointIndex = val;
	emit onEvaluationPointIndexChanged();
}
 
	QStringList QmlIntegrator::evaluationPoints(){
	return _evaluationPoints;
}
void QmlIntegrator::setEvaluationPoints(const 	QStringList &val){
	if (val == _evaluationPoints)
		return;
	_evaluationPoints = val;
	emit onEvaluationPointsChanged();
}
 
	QStringList QmlIntegrator::calibrationPoints(){
	return _calibrationPoints;
}
void QmlIntegrator::setCalibrationPoints(const 	QStringList &val){
	if (val == _calibrationPoints)
		return;
	_calibrationPoints = val;
	emit onCalibrationPointsChanged();
}
 
	bool QmlIntegrator::activated(){
	return _activated;
}
void QmlIntegrator::setActivated(const 	bool &val){
	if (val == _activated)
		return;
	_activated = val;
	emit onActivatedChanged();
}
 
	double QmlIntegrator::spath1(){
	return _spath1;
}
void QmlIntegrator::setSpath1(const 	double &val){
	if (val == _spath1)
		return;
	_spath1 = val;
	emit onSpath1Changed();
}
 
	double QmlIntegrator::spath2(){
	return _spath2;
}
void QmlIntegrator::setSpath2(const 	double &val){
	if (val == _spath2)
		return;
	_spath2 = val;
	emit onSpath2Changed();
}
 
	double QmlIntegrator::resD(){
	return _resD;
}
void QmlIntegrator::setResD(const 	double &val){
	if (val == _resD)
		return;
	_resD = val;
	emit onResDChanged();
}
 
	double QmlIntegrator::resDa(){
	return _resDa;
}
void QmlIntegrator::setResDa(const 	double &val){
	if (val == _resDa)
		return;
	_resDa = val;
	emit onResDaChanged();
}
 
	double QmlIntegrator::resS(){
	return _resS;
}
void QmlIntegrator::setResS(const 	double &val){
	if (val == _resS)
		return;
	_resS = val;
	emit onResSChanged();
}
 
	double QmlIntegrator::resOneLeg(){
	return _resOneLeg;
}
void QmlIntegrator::setResOneLeg(const 	double &val){
	if (val == _resOneLeg)
		return;
	_resOneLeg = val;
	emit onResOneLegChanged();
}
 
	double QmlIntegrator::awsa(){
	return _awsa;
}
void QmlIntegrator::setAwsa(const 	double &val){
	if (val == _awsa)
		return;
	_awsa = val;
	emit onAwsaChanged();
}
 
	double QmlIntegrator::awsc(){
	return _awsc;
}
void QmlIntegrator::setAwsc(const 	double &val){
	if (val == _awsc)
		return;
	_awsc = val;
	emit onAwscChanged();
}
 
	double QmlIntegrator::awsd(){
	return _awsd;
}
void QmlIntegrator::setAwsd(const 	double &val){
	if (val == _awsd)
		return;
	_awsd = val;
	emit onAwsdChanged();
}
 
	Enums::AWSClass QmlIntegrator::awsClass(){
	return _awsClass;
}
void QmlIntegrator::setAwsClass(const 	Enums::AWSClass &val){
	if (val == _awsClass)
		return;
	_awsClass = val;
	emit onAwsClassChanged();
}
 
	Enums::AWSTable QmlIntegrator::awsTable(){
	return _awsTable;
}
void QmlIntegrator::setAwsTable(const 	Enums::AWSTable &val){
	if (val == _awsTable)
		return;
	_awsTable = val;
	emit onAwsTableChanged();
}
 
	Enums::Shape QmlIntegrator::shape(){
	return _shape;
}
void QmlIntegrator::setShape(const 	Enums::Shape &val){
	if (val == _shape)
		return;
	_shape = val;
	emit onShapeChanged();
}
 
	Enums::Unit QmlIntegrator::unit(){
	return _unit;
}
void QmlIntegrator::setUnit(const 	Enums::Unit &val){
	if (val == _unit)
		return;
	_unit = val;
	emit onUnitChanged();
}
 
	double QmlIntegrator::pipeDiameter(){
	return _pipeDiameter;
}
void QmlIntegrator::setPipeDiameter(const 	double &val){
	if (val == _pipeDiameter)
		return;
	_pipeDiameter = val;
	emit onPipeDiameterChanged();
}
 
	Enums::DACAlarm QmlIntegrator::dacAlarmLevel(){
	return _dacAlarmLevel;
}
void QmlIntegrator::setDacAlarmLevel(const 	Enums::DACAlarm &val){
	if (val == _dacAlarmLevel)
		return;
	_dacAlarmLevel = val;
	emit onDacAlarmLevelChanged();
}
 
	Enums::PulserType QmlIntegrator::pulserType(){
	return _pulserType;
}
void QmlIntegrator::setPulserType(const 	Enums::PulserType &val){
	if (val == _pulserType)
		return;
	_pulserType = val;
	emit onPulserTypeChanged();
}
 
	bool QmlIntegrator::horn(){
	return _horn;
}
void QmlIntegrator::setHorn(const 	bool &val){
	if (val == _horn)
		return;
	_horn = val;
	emit onHornChanged();
}
 
	bool QmlIntegrator::grid(){
	return _grid;
}
void QmlIntegrator::setGrid(const 	bool &val){
	if (val == _grid)
		return;
	_grid = val;
	emit onGridChanged();
}
 
	bool QmlIntegrator::fullscreen(){
	return _fullscreen;
}
void QmlIntegrator::setFullscreen(const 	bool &val){
	if (val == _fullscreen)
		return;
	_fullscreen = val;
	emit onFullscreenChanged();
}
 
	bool QmlIntegrator::fill(){
	return _fill;
}
void QmlIntegrator::setFill(const 	bool &val){
	if (val == _fill)
		return;
	_fill = val;
	emit onFillChanged();
}
 
	int QmlIntegrator::theme(){
	return _theme;
}
void QmlIntegrator::setTheme(const 	int &val){
	if (val == _theme)
		return;
	_theme = val;
	emit onThemeChanged();
}
 
	int QmlIntegrator::brightness(){
	return _brightness;
}
void QmlIntegrator::setBrightness(const 	int &val){
	if (val == _brightness)
		return;
	_brightness = val;
	emit onBrightnessChanged();
}
 
	int QmlIntegrator::saveFile(){
	return _saveFile;
}
void QmlIntegrator::setSaveFile(const 	int &val){
	if (val == _saveFile)
		return;
	_saveFile = val;
	emit onSaveFileChanged();
}
 
	QString QmlIntegrator::memoryFilename(){
	return _memoryFilename;
}
void QmlIntegrator::setMemoryFilename(const 	QString &val){
	if (val == _memoryFilename)
		return;
	_memoryFilename = val;
	emit onMemoryFilenameChanged();
}
 
	double QmlIntegrator::tcorr(){
	return _tcorr;
}
void QmlIntegrator::setTcorr(const 	double &val){
	if (val == _tcorr)
		return;
	_tcorr = val;
	emit onTcorrChanged();
}
 
	QStringList QmlIntegrator::snapshotList(){
	return _snapshotList;
}
void QmlIntegrator::setSnapshotList(const 	QStringList &val){
	if (val == _snapshotList)
		return;
	_snapshotList = val;
	emit onSnapshotListChanged();
}
 
	QString QmlIntegrator::currentSnapshot(){
	return _currentSnapshot;
}
void QmlIntegrator::setCurrentSnapshot(const 	QString &val){
	if (val == _currentSnapshot)
		return;
	_currentSnapshot = val;
	emit onCurrentSnapshotChanged();
}
 
	QString QmlIntegrator::applicationDirPath(){
	return _applicationDirPath;
}
void QmlIntegrator::setApplicationDirPath(const 	QString &val){
	if (val == _applicationDirPath)
		return;
	_applicationDirPath = val;
	emit onApplicationDirPathChanged();
}
 
	double QmlIntegrator::inchToMm(){
	return _inchToMm;
}
void QmlIntegrator::setInchToMm(const 	double &val){
	if (val == _inchToMm)
		return;
	_inchToMm = val;
	emit onInchToMmChanged();
}
 
	double QmlIntegrator::usToMm(){
	return _usToMm;
}
void QmlIntegrator::setUsToMm(const 	double &val){
	if (val == _usToMm)
		return;
	_usToMm = val;
	emit onUsToMmChanged();
}
 
	double QmlIntegrator::soundPathMultiplier(){
	return _soundPathMultiplier;
}
void QmlIntegrator::setSoundPathMultiplier(const 	double &val){
	if (val == _soundPathMultiplier)
		return;
	_soundPathMultiplier = val;
	emit onSoundPathMultiplierChanged();
}
 
	double QmlIntegrator::iFSyncRef(){
	return _iFSyncRef;
}
void QmlIntegrator::setIFSyncRef(const 	double &val){
	if (val == _iFSyncRef)
		return;
	_iFSyncRef = val;
	emit onIFSyncRefChanged();
}
 
	int QmlIntegrator::velocityStep(){
	return _velocityStep;
}
void QmlIntegrator::setVelocityStep(const 	int &val){
	if (val == _velocityStep)
		return;
	_velocityStep = val;
	emit onVelocityStepChanged();
}
 
	int QmlIntegrator::prfStep(){
	return _prfStep;
}
void QmlIntegrator::setPrfStep(const 	int &val){
	if (val == _prfStep)
		return;
	_prfStep = val;
	emit onPrfStepChanged();
}
 
	int QmlIntegrator::spathStep(){
	return _spathStep;
}
void QmlIntegrator::setSpathStep(const 	int &val){
	if (val == _spathStep)
		return;
	_spathStep = val;
	emit onSpathStepChanged();
}
 
	int QmlIntegrator::classStep1(){
	return _classStep1;
}
void QmlIntegrator::setClassStep1(const 	int &val){
	if (val == _classStep1)
		return;
	_classStep1 = val;
	emit onClassStep1Changed();
}
 
	int QmlIntegrator::classStep2(){
	return _classStep2;
}
void QmlIntegrator::setClassStep2(const 	int &val){
	if (val == _classStep2)
		return;
	_classStep2 = val;
	emit onClassStep2Changed();
}
 
	int QmlIntegrator::classStep3(){
	return _classStep3;
}
void QmlIntegrator::setClassStep3(const 	int &val){
	if (val == _classStep3)
		return;
	_classStep3 = val;
	emit onClassStep3Changed();
}
 
	int QmlIntegrator::batteryLevel(){
	return _batteryLevel;
}
void QmlIntegrator::setBatteryLevel(const 	int &val){
	if (val == _batteryLevel)
		return;
	_batteryLevel = val;
	emit onBatteryLevelChanged();
}
 
	int QmlIntegrator::fsh(){
	return _fsh;
}
void QmlIntegrator::setFsh(const 	int &val){
	if (val == _fsh)
		return;
	_fsh = val;
	emit onFshChanged();
}
 
	bool QmlIntegrator::callShowSnapshot(){
	return _callShowSnapshot;
}
void QmlIntegrator::setCallShowSnapshot(const 	bool &val){
	if (val == _callShowSnapshot)
		return;
	_callShowSnapshot = val;
	emit onCallShowSnapshotChanged();
}
 
	bool QmlIntegrator::callHideSnapshot(){
	return _callHideSnapshot;
}
void QmlIntegrator::setCallHideSnapshot(const 	bool &val){
	if (val == _callHideSnapshot)
		return;
	_callHideSnapshot = val;
	emit onCallHideSnapshotChanged();
}
 
	bool QmlIntegrator::menuUpEnabled(){
	return _menuUpEnabled;
}
void QmlIntegrator::setMenuUpEnabled(const 	bool &val){
	if (val == _menuUpEnabled)
		return;
	_menuUpEnabled = val;
	emit onMenuUpEnabledChanged();
}
 
	bool QmlIntegrator::menuDownEnabled(){
	return _menuDownEnabled;
}
void QmlIntegrator::setMenuDownEnabled(const 	bool &val){
	if (val == _menuDownEnabled)
		return;
	_menuDownEnabled = val;
	emit onMenuDownEnabledChanged();
}
 
	bool QmlIntegrator::started(){
	return _started;
}
void QmlIntegrator::setStarted(const 	bool &val){
	if (val == _started)
		return;
	_started = val;
	emit onStartedChanged();
}
 
	bool QmlIntegrator::batteryCharging(){
	return _batteryCharging;
}
void QmlIntegrator::setBatteryCharging(const 	bool &val){
	if (val == _batteryCharging)
		return;
	_batteryCharging = val;
	emit onBatteryChargingChanged();
}
 
	bool QmlIntegrator::stripAEnabled(){
	return _stripAEnabled;
}
void QmlIntegrator::setStripAEnabled(const 	bool &val){
	if (val == _stripAEnabled)
		return;
	_stripAEnabled = val;
	emit onStripAEnabledChanged();
}
 
	bool QmlIntegrator::stripBEnabled(){
	return _stripBEnabled;
}
void QmlIntegrator::setStripBEnabled(const 	bool &val){
	if (val == _stripBEnabled)
		return;
	_stripBEnabled = val;
	emit onStripBEnabledChanged();
}
 
	bool QmlIntegrator::stripDACEnabled(){
	return _stripDACEnabled;
}
void QmlIntegrator::setStripDACEnabled(const 	bool &val){
	if (val == _stripDACEnabled)
		return;
	_stripDACEnabled = val;
	emit onStripDACEnabledChanged();
}
 
	bool QmlIntegrator::usbConnected(){
	return _usbConnected;
}
void QmlIntegrator::setUsbConnected(const 	bool &val){
	if (val == _usbConnected)
		return;
	_usbConnected = val;
	emit onUsbConnectedChanged();
}
 
	bool QmlIntegrator::alarmAActive(){
	return _alarmAActive;
}
void QmlIntegrator::setAlarmAActive(const 	bool &val){
	if (val == _alarmAActive)
		return;
	_alarmAActive = val;
	emit onAlarmAActiveChanged();
}
 
	bool QmlIntegrator::alarmBActive(){
	return _alarmBActive;
}
void QmlIntegrator::setAlarmBActive(const 	bool &val){
	if (val == _alarmBActive)
		return;
	_alarmBActive = val;
	emit onAlarmBActiveChanged();
}
 
	bool QmlIntegrator::alarmAEnable(){
	return _alarmAEnable;
}
void QmlIntegrator::setAlarmAEnable(const 	bool &val){
	if (val == _alarmAEnable)
		return;
	_alarmAEnable = val;
	emit onAlarmAEnableChanged();
}
 
	bool QmlIntegrator::alarmBEnable(){
	return _alarmBEnable;
}
void QmlIntegrator::setAlarmBEnable(const 	bool &val){
	if (val == _alarmBEnable)
		return;
	_alarmBEnable = val;
	emit onAlarmBEnableChanged();
}
 
	bool QmlIntegrator::alarmDACActive(){
	return _alarmDACActive;
}
void QmlIntegrator::setAlarmDACActive(const 	bool &val){
	if (val == _alarmDACActive)
		return;
	_alarmDACActive = val;
	emit onAlarmDACActiveChanged();
}
 
	bool QmlIntegrator::gateAEnabled(){
	return _gateAEnabled;
}
void QmlIntegrator::setGateAEnabled(const 	bool &val){
	if (val == _gateAEnabled)
		return;
	_gateAEnabled = val;
	emit onGateAEnabledChanged();
}
 
	bool QmlIntegrator::gateBEnabled(){
	return _gateBEnabled;
}
void QmlIntegrator::setGateBEnabled(const 	bool &val){
	if (val == _gateBEnabled)
		return;
	_gateBEnabled = val;
	emit onGateBEnabledChanged();
}
 
