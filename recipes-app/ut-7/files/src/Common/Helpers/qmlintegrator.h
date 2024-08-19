#ifndef QMLINTEGRATOR_H
#define QMLINTEGRATOR_H

#include <QObject>
#include <QSettings>
#include "../Models/enums.h"
#include <QPointF>
class QmlIntegrator : public QObject
{
    Q_OBJECT
QmlIntegrator(QObject *parent = nullptr);
Q_PROPERTY(	double gain READ gain WRITE setGain NOTIFY onGainChanged)
Q_PROPERTY(	Enums::PulseAmplitude pulseAmplitude READ pulseAmplitude WRITE setPulseAmplitude NOTIFY onPulseAmplitudeChanged)
Q_PROPERTY(	double gainStep READ gainStep WRITE setGainStep NOTIFY onGainStepChanged)
Q_PROPERTY(	double paramStep READ paramStep WRITE setParamStep NOTIFY onParamStepChanged)
Q_PROPERTY(	double refGain READ refGain WRITE setRefGain NOTIFY onRefGainChanged)
Q_PROPERTY(	bool legEnable READ legEnable WRITE setLegEnable NOTIFY onLegEnableChanged)
Q_PROPERTY(	double range READ range WRITE setRange NOTIFY onRangeChanged)
Q_PROPERTY(	double rangeMax READ rangeMax WRITE setRangeMax NOTIFY onRangeMaxChanged)
Q_PROPERTY(	double displayDelay READ displayDelay WRITE setDisplayDelay NOTIFY onDisplayDelayChanged)
Q_PROPERTY(	double displayDelayMin READ displayDelayMin WRITE setDisplayDelayMin NOTIFY onDisplayDelayMinChanged)
Q_PROPERTY(	double displayDelayMax READ displayDelayMax WRITE setDisplayDelayMax NOTIFY onDisplayDelayMaxChanged)
Q_PROPERTY(	double UIRange READ UIRange WRITE setUIRange NOTIFY onUIRangeChanged)
Q_PROPERTY(	double UIRangeMax READ UIRangeMax WRITE setUIRangeMax NOTIFY onUIRangeMaxChanged)
Q_PROPERTY(	double UIDisplayDelay READ UIDisplayDelay WRITE setUIDisplayDelay NOTIFY onUIDisplayDelayChanged)
Q_PROPERTY(	double UIDisplayDelayMin READ UIDisplayDelayMin WRITE setUIDisplayDelayMin NOTIFY onUIDisplayDelayMinChanged)
Q_PROPERTY(	double UIDisplayDelayMax READ UIDisplayDelayMax WRITE setUIDisplayDelayMax NOTIFY onUIDisplayDelayMaxChanged)
Q_PROPERTY(	double UISpath1 READ UISpath1 WRITE setUISpath1 NOTIFY onUISpath1Changed)
Q_PROPERTY(	double UISpath2 READ UISpath2 WRITE setUISpath2 NOTIFY onUISpath2Changed)
Q_PROPERTY(	double UIGateAStart READ UIGateAStart WRITE setUIGateAStart NOTIFY onUIGateAStartChanged)
Q_PROPERTY(	double UIGateAWidth READ UIGateAWidth WRITE setUIGateAWidth NOTIFY onUIGateAWidthChanged)
Q_PROPERTY(	double UIGateBStart READ UIGateBStart WRITE setUIGateBStart NOTIFY onUIGateBStartChanged)
Q_PROPERTY(	double UIGateBWidth READ UIGateBWidth WRITE setUIGateBWidth NOTIFY onUIGateBWidthChanged)
Q_PROPERTY(	int velocity READ velocity WRITE setVelocity NOTIFY onVelocityChanged)
Q_PROPERTY(	int rejection READ rejection WRITE setRejection NOTIFY onRejectionChanged)
Q_PROPERTY(	bool zoomed READ zoomed WRITE setZoomed NOTIFY onZoomedChanged)
Q_PROPERTY(	double gateAStart READ gateAStart WRITE setGateAStart NOTIFY onGateAStartChanged)
Q_PROPERTY(	double gateAWidth READ gateAWidth WRITE setGateAWidth NOTIFY onGateAWidthChanged)
Q_PROPERTY(	int gateALevel READ gateALevel WRITE setGateALevel NOTIFY onGateALevelChanged)
Q_PROPERTY(	double gateAGain READ gateAGain WRITE setGateAGain NOTIFY onGateAGainChanged)
Q_PROPERTY(	Enums::SyncType gateASync READ gateASync WRITE setGateASync NOTIFY onGateASyncChanged)
Q_PROPERTY(	Enums::TextOnChart textOnChart READ textOnChart WRITE setTextOnChart NOTIFY onTextOnChartChanged)
Q_PROPERTY(	Enums::PosNeg gateALogic READ gateALogic WRITE setGateALogic NOTIFY onGateALogicChanged)
Q_PROPERTY(	double gateBStart READ gateBStart WRITE setGateBStart NOTIFY onGateBStartChanged)
Q_PROPERTY(	double gateBWidth READ gateBWidth WRITE setGateBWidth NOTIFY onGateBWidthChanged)
Q_PROPERTY(	int gateBLevel READ gateBLevel WRITE setGateBLevel NOTIFY onGateBLevelChanged)
Q_PROPERTY(	double gateBGain READ gateBGain WRITE setGateBGain NOTIFY onGateBGainChanged)
Q_PROPERTY(	Enums::SyncType gateBSync READ gateBSync WRITE setGateBSync NOTIFY onGateBSyncChanged)
Q_PROPERTY(	Enums::PosNeg gateBLogic READ gateBLogic WRITE setGateBLogic NOTIFY onGateBLogicChanged)
Q_PROPERTY(	double probeIndex READ probeIndex WRITE setProbeIndex NOTIFY onProbeIndexChanged)
Q_PROPERTY(	double probeAngle READ probeAngle WRITE setProbeAngle NOTIFY onProbeAngleChanged)
Q_PROPERTY(	double stripAxisXMin READ stripAxisXMin WRITE setStripAxisXMin NOTIFY onStripAxisXMinChanged)
Q_PROPERTY(	double stripAxisXMax READ stripAxisXMax WRITE setStripAxisXMax NOTIFY onStripAxisXMaxChanged)
Q_PROPERTY(	double aScanAxisXMin READ aScanAxisXMin WRITE setAScanAxisXMin NOTIFY onAScanAxisXMinChanged)
Q_PROPERTY(	double aScanAxisXMax READ aScanAxisXMax WRITE setAScanAxisXMax NOTIFY onAScanAxisXMaxChanged)
Q_PROPERTY(	double aScanAxisYMin READ aScanAxisYMin WRITE setAScanAxisYMin NOTIFY onAScanAxisYMinChanged)
Q_PROPERTY(	double aScanAxisYMax READ aScanAxisYMax WRITE setAScanAxisYMax NOTIFY onAScanAxisYMaxChanged)
Q_PROPERTY(	int stripTime READ stripTime WRITE setStripTime NOTIFY onStripTimeChanged)
Q_PROPERTY(	int prf READ prf WRITE setPrf NOTIFY onPrfChanged)
Q_PROPERTY(	double probeDelay READ probeDelay WRITE setProbeDelay NOTIFY onProbeDelayChanged)
Q_PROPERTY(	double thickness READ thickness WRITE setThickness NOTIFY onThicknessChanged)
Q_PROPERTY(	double probeDiameter READ probeDiameter WRITE setProbeDiameter NOTIFY onProbeDiameterChanged)
Q_PROPERTY(	int lineSpeed READ lineSpeed WRITE setLineSpeed NOTIFY onLineSpeedChanged)
Q_PROPERTY(	Enums::Polarity polarity READ polarity WRITE setPolarity NOTIFY onPolarityChanged)
Q_PROPERTY(	Enums::ProbeType probeType READ probeType WRITE setProbeType NOTIFY onProbeTypeChanged)
Q_PROPERTY(	Enums::PeakMethod peakMethodA READ peakMethodA WRITE setPeakMethodA NOTIFY onPeakMethodAChanged)
Q_PROPERTY(	Enums::PeakMethod peakMethodB READ peakMethodB WRITE setPeakMethodB NOTIFY onPeakMethodBChanged)
Q_PROPERTY(	Enums::EvaluationMode evaluationMode READ evaluationMode WRITE setEvaluationMode NOTIFY onEvaluationModeChanged)
Q_PROPERTY(	Enums::DigitalFilter digitalFilter READ digitalFilter WRITE setDigitalFilter NOTIFY onDigitalFilterChanged)
Q_PROPERTY(	Enums::Damping damping READ damping WRITE setDamping NOTIFY onDampingChanged)
Q_PROPERTY(	Enums::DualType dualNotSingle READ dualNotSingle WRITE setDualNotSingle NOTIFY onDualNotSingleChanged)
Q_PROPERTY(	Enums::EnvelopeType envelope READ envelope WRITE setEnvelope NOTIFY onEnvelopeChanged)
Q_PROPERTY(	bool freezed READ freezed WRITE setFreezed NOTIFY onFreezedChanged)
Q_PROPERTY(	QPointF currentPeakA READ currentPeakA WRITE setCurrentPeakA NOTIFY onCurrentPeakAChanged)
Q_PROPERTY(	QPointF currentFlankA READ currentFlankA WRITE setCurrentFlankA NOTIFY onCurrentFlankAChanged)
Q_PROPERTY(	QPointF currentJFlankA READ currentJFlankA WRITE setCurrentJFlankA NOTIFY onCurrentJFlankAChanged)
Q_PROPERTY(	QPointF currentMarkerA READ currentMarkerA WRITE setCurrentMarkerA NOTIFY onCurrentMarkerAChanged)
Q_PROPERTY(	QPointF currentUpwardA READ currentUpwardA WRITE setCurrentUpwardA NOTIFY onCurrentUpwardAChanged)
Q_PROPERTY(	QPointF currentDownwardA READ currentDownwardA WRITE setCurrentDownwardA NOTIFY onCurrentDownwardAChanged)
Q_PROPERTY(	QPointF currentPeakB READ currentPeakB WRITE setCurrentPeakB NOTIFY onCurrentPeakBChanged)
Q_PROPERTY(	QPointF currentFlankB READ currentFlankB WRITE setCurrentFlankB NOTIFY onCurrentFlankBChanged)
Q_PROPERTY(	QPointF currentJFlankB READ currentJFlankB WRITE setCurrentJFlankB NOTIFY onCurrentJFlankBChanged)
Q_PROPERTY(	QPointF currentMarkerB READ currentMarkerB WRITE setCurrentMarkerB NOTIFY onCurrentMarkerBChanged)
Q_PROPERTY(	QPointF currentUpwardB READ currentUpwardB WRITE setCurrentUpwardB NOTIFY onCurrentUpwardBChanged)
Q_PROPERTY(	QPointF currentDownwardB READ currentDownwardB WRITE setCurrentDownwardB NOTIFY onCurrentDownwardBChanged)
Q_PROPERTY(	int calibrationPointIndex READ calibrationPointIndex WRITE setCalibrationPointIndex NOTIFY onCalibrationPointIndexChanged)
Q_PROPERTY(	int evaluationPointIndex READ evaluationPointIndex WRITE setEvaluationPointIndex NOTIFY onEvaluationPointIndexChanged)
Q_PROPERTY(	QStringList evaluationPoints READ evaluationPoints WRITE setEvaluationPoints NOTIFY onEvaluationPointsChanged)
Q_PROPERTY(	QStringList calibrationPoints READ calibrationPoints WRITE setCalibrationPoints NOTIFY onCalibrationPointsChanged)
Q_PROPERTY(	bool activated READ activated WRITE setActivated NOTIFY onActivatedChanged)
Q_PROPERTY(	double spath1 READ spath1 WRITE setSpath1 NOTIFY onSpath1Changed)
Q_PROPERTY(	double spath2 READ spath2 WRITE setSpath2 NOTIFY onSpath2Changed)
Q_PROPERTY(	double resD READ resD WRITE setResD NOTIFY onResDChanged)
Q_PROPERTY(	double resDa READ resDa WRITE setResDa NOTIFY onResDaChanged)
Q_PROPERTY(	double resS READ resS WRITE setResS NOTIFY onResSChanged)
Q_PROPERTY(	double resOneLeg READ resOneLeg WRITE setResOneLeg NOTIFY onResOneLegChanged)
Q_PROPERTY(	double awsa READ awsa WRITE setAwsa NOTIFY onAwsaChanged)
Q_PROPERTY(	double awsc READ awsc WRITE setAwsc NOTIFY onAwscChanged)
Q_PROPERTY(	double awsd READ awsd WRITE setAwsd NOTIFY onAwsdChanged)
Q_PROPERTY(	Enums::AWSClass awsClass READ awsClass WRITE setAwsClass NOTIFY onAwsClassChanged)
Q_PROPERTY(	Enums::AWSTable awsTable READ awsTable WRITE setAwsTable NOTIFY onAwsTableChanged)
Q_PROPERTY(	Enums::Shape shape READ shape WRITE setShape NOTIFY onShapeChanged)
Q_PROPERTY(	Enums::Unit unit READ unit WRITE setUnit NOTIFY onUnitChanged)
Q_PROPERTY(	double pipeDiameter READ pipeDiameter WRITE setPipeDiameter NOTIFY onPipeDiameterChanged)
Q_PROPERTY(	Enums::DACAlarm dacAlarmLevel READ dacAlarmLevel WRITE setDacAlarmLevel NOTIFY onDacAlarmLevelChanged)
Q_PROPERTY(	Enums::PulserType pulserType READ pulserType WRITE setPulserType NOTIFY onPulserTypeChanged)
Q_PROPERTY(	bool horn READ horn WRITE setHorn NOTIFY onHornChanged)
Q_PROPERTY(	bool grid READ grid WRITE setGrid NOTIFY onGridChanged)
Q_PROPERTY(	bool fullscreen READ fullscreen WRITE setFullscreen NOTIFY onFullscreenChanged)
Q_PROPERTY(	bool fill READ fill WRITE setFill NOTIFY onFillChanged)
Q_PROPERTY(	int theme READ theme WRITE setTheme NOTIFY onThemeChanged)
Q_PROPERTY(	int brightness READ brightness WRITE setBrightness NOTIFY onBrightnessChanged)
Q_PROPERTY(	int saveFile READ saveFile WRITE setSaveFile NOTIFY onSaveFileChanged)
Q_PROPERTY(	QString memoryFilename READ memoryFilename WRITE setMemoryFilename NOTIFY onMemoryFilenameChanged)
Q_PROPERTY(	double tcorr READ tcorr WRITE setTcorr NOTIFY onTcorrChanged)
Q_PROPERTY(	QStringList snapshotList READ snapshotList WRITE setSnapshotList NOTIFY onSnapshotListChanged)
Q_PROPERTY(	QString currentSnapshot READ currentSnapshot WRITE setCurrentSnapshot NOTIFY onCurrentSnapshotChanged)
Q_PROPERTY(	QString applicationDirPath READ applicationDirPath WRITE setApplicationDirPath NOTIFY onApplicationDirPathChanged)
Q_PROPERTY(	double inchToMm READ inchToMm WRITE setInchToMm NOTIFY onInchToMmChanged)
Q_PROPERTY(	double usToMm READ usToMm WRITE setUsToMm NOTIFY onUsToMmChanged)
Q_PROPERTY(	double soundPathMultiplier READ soundPathMultiplier WRITE setSoundPathMultiplier NOTIFY onSoundPathMultiplierChanged)
Q_PROPERTY(	double iFSyncRef READ iFSyncRef WRITE setIFSyncRef NOTIFY onIFSyncRefChanged)
Q_PROPERTY(	int velocityStep READ velocityStep WRITE setVelocityStep NOTIFY onVelocityStepChanged)
Q_PROPERTY(	int prfStep READ prfStep WRITE setPrfStep NOTIFY onPrfStepChanged)
Q_PROPERTY(	int spathStep READ spathStep WRITE setSpathStep NOTIFY onSpathStepChanged)
Q_PROPERTY(	int classStep1 READ classStep1 WRITE setClassStep1 NOTIFY onClassStep1Changed)
Q_PROPERTY(	int classStep2 READ classStep2 WRITE setClassStep2 NOTIFY onClassStep2Changed)
Q_PROPERTY(	int classStep3 READ classStep3 WRITE setClassStep3 NOTIFY onClassStep3Changed)
Q_PROPERTY(	int batteryLevel READ batteryLevel WRITE setBatteryLevel NOTIFY onBatteryLevelChanged)
Q_PROPERTY(	int fsh READ fsh WRITE setFsh NOTIFY onFshChanged)
Q_PROPERTY(	bool callShowSnapshot READ callShowSnapshot WRITE setCallShowSnapshot NOTIFY onCallShowSnapshotChanged)
Q_PROPERTY(	bool callHideSnapshot READ callHideSnapshot WRITE setCallHideSnapshot NOTIFY onCallHideSnapshotChanged)
Q_PROPERTY(	bool menuUpEnabled READ menuUpEnabled WRITE setMenuUpEnabled NOTIFY onMenuUpEnabledChanged)
Q_PROPERTY(	bool menuDownEnabled READ menuDownEnabled WRITE setMenuDownEnabled NOTIFY onMenuDownEnabledChanged)
Q_PROPERTY(	bool started READ started WRITE setStarted NOTIFY onStartedChanged)
Q_PROPERTY(	bool batteryCharging READ batteryCharging WRITE setBatteryCharging NOTIFY onBatteryChargingChanged)
Q_PROPERTY(	bool stripAEnabled READ stripAEnabled WRITE setStripAEnabled NOTIFY onStripAEnabledChanged)
Q_PROPERTY(	bool stripBEnabled READ stripBEnabled WRITE setStripBEnabled NOTIFY onStripBEnabledChanged)
Q_PROPERTY(	bool stripDACEnabled READ stripDACEnabled WRITE setStripDACEnabled NOTIFY onStripDACEnabledChanged)
Q_PROPERTY(	bool usbConnected READ usbConnected WRITE setUsbConnected NOTIFY onUsbConnectedChanged)
Q_PROPERTY(	bool alarmAActive READ alarmAActive WRITE setAlarmAActive NOTIFY onAlarmAActiveChanged)
Q_PROPERTY(	bool alarmBActive READ alarmBActive WRITE setAlarmBActive NOTIFY onAlarmBActiveChanged)
Q_PROPERTY(	bool alarmAEnable READ alarmAEnable WRITE setAlarmAEnable NOTIFY onAlarmAEnableChanged)
Q_PROPERTY(	bool alarmBEnable READ alarmBEnable WRITE setAlarmBEnable NOTIFY onAlarmBEnableChanged)
Q_PROPERTY(	bool alarmDACActive READ alarmDACActive WRITE setAlarmDACActive NOTIFY onAlarmDACActiveChanged)
Q_PROPERTY(	bool gateAEnabled READ gateAEnabled WRITE setGateAEnabled NOTIFY onGateAEnabledChanged)
Q_PROPERTY(	bool gateBEnabled READ gateBEnabled WRITE setGateBEnabled NOTIFY onGateBEnabledChanged)


	 	double _gain;
	 	Enums::PulseAmplitude _pulseAmplitude;
	 	double _gainStep = 1;
	 	double _paramStep = 1;
	 	double _refGain = 0;
	 	bool _legEnable = false;
	 	double _range;
	 	double _rangeMax = 10000;
	 	double _displayDelay;
	 	double _displayDelayMin = -10000;
	 	double _displayDelayMax = 10000;
	 	double _UIRange;
	 	double _UIRangeMax = 10000;
	 	double _UIDisplayDelay;
	 	double _UIDisplayDelayMin = -10000;
	 	double _UIDisplayDelayMax = 10000;
	 	double _UISpath1;
	 	double _UISpath2;
	 	double _UIGateAStart = 0;
	 	double _UIGateAWidth = 0;
	 	double _UIGateBStart = 0;
	 	double _UIGateBWidth = 0;
	 	int _velocity;
	 	int _rejection;
	 	bool _zoomed = false;
	 	double _gateAStart = 0;
	 	double _gateAWidth = 0;
	 	int _gateALevel = 0;
	 	double _gateAGain = 0;
	 	Enums::SyncType _gateASync;
	 	Enums::TextOnChart _textOnChart;
	 	Enums::PosNeg _gateALogic;
	 	double _gateBStart = 0;
	 	double _gateBWidth = 0;
	 	int _gateBLevel = 0;
	 	double _gateBGain = 0;
	 	Enums::SyncType _gateBSync;
	 	Enums::PosNeg _gateBLogic;
	 	double _probeIndex;
	 	double _probeAngle;
	 	double _stripAxisXMin = 0;
	 	double _stripAxisXMax = 10;
	 	double _aScanAxisXMin = 0;
	 	double _aScanAxisXMax = 1000;
	 	double _aScanAxisYMin = 0;
	 	double _aScanAxisYMax = 100;
	 	int _stripTime;
	 	int _prf = 50;
	 	double _probeDelay;
	 	double _thickness;
	 	double _probeDiameter;
	 	int _lineSpeed;
	 	Enums::Polarity _polarity;
	 	Enums::ProbeType _probeType;
	 	Enums::PeakMethod _peakMethodA;
	 	Enums::PeakMethod _peakMethodB;
	 	Enums::EvaluationMode _evaluationMode;
	 	Enums::DigitalFilter _digitalFilter;
	 	Enums::Damping _damping;
	 	Enums::DualType _dualNotSingle;
	 	Enums::EnvelopeType _envelope = Enums::EnvelopeType::ENV_OFF;
	 	bool _freezed = false;
	 	QPointF _currentPeakA;
	 	QPointF _currentFlankA;
	 	QPointF _currentJFlankA;
	 	QPointF _currentMarkerA;
	 	QPointF _currentUpwardA;
	 	QPointF _currentDownwardA;
	 	QPointF _currentPeakB;
	 	QPointF _currentFlankB;
	 	QPointF _currentJFlankB;
	 	QPointF _currentMarkerB;
	 	QPointF _currentUpwardB;
	 	QPointF _currentDownwardB;
	 	int _calibrationPointIndex;
	 	int _evaluationPointIndex;
	 	QStringList _evaluationPoints;
	 	QStringList _calibrationPoints;
	 	bool _activated = false;
	 	double _spath1;
	 	double _spath2;
	 	double _resD;
	 	double _resDa;
	 	double _resS;
	 	double _resOneLeg;
	 	double _awsa;
	 	double _awsc;
	 	double _awsd;
	 	Enums::AWSClass _awsClass;
	 	Enums::AWSTable _awsTable;
	 	Enums::Shape _shape;
	 	Enums::Unit _unit = Enums::Unit::UNIT_MM;
	 	double _pipeDiameter;
	 	Enums::DACAlarm _dacAlarmLevel;
	 	Enums::PulserType _pulserType;
	 	bool _horn = false;
	 	bool _grid = true;
	 	bool _fullscreen = false;
	 	bool _fill = false;
	 	int _theme = 1;
	 	int _brightness = 0;
	 	int _saveFile = 0;
	 	QString _memoryFilename;
	 	double _tcorr;
	 	QStringList _snapshotList;
	 	QString _currentSnapshot;
	 	QString _applicationDirPath;
	 	double _inchToMm = 25.4;
	 	double _usToMm;
	 	double _soundPathMultiplier = 0.5;
	 	double _iFSyncRef = 0;
	 	int _velocityStep = 2;
	 	int _prfStep = 2;
	 	int _spathStep = 0;
	 	int _classStep1 = 2;
	 	int _classStep2 = 2;
	 	int _classStep3 = 0;
	 	int _batteryLevel = 0;
	 	int _fsh = 0;
	 	bool _callShowSnapshot = false;
	 	bool _callHideSnapshot = false;
	 	bool _menuUpEnabled;
	 	bool _menuDownEnabled;
	 	bool _started = false;
	 	bool _batteryCharging = false;
	 	bool _stripAEnabled = true;
	 	bool _stripBEnabled = true;
	 	bool _stripDACEnabled = true;
	 	bool _usbConnected = false;
	 	bool _alarmAActive = false;
	 	bool _alarmBActive = false;
	 	bool _alarmAEnable = false;
	 	bool _alarmBEnable = false;
	 	bool _alarmDACActive = false;
	 	bool _gateAEnabled = true;
	 	bool _gateBEnabled = true;


public:
    QmlIntegrator(const QmlIntegrator&) = delete;
    QmlIntegrator & operator= (const QmlIntegrator &) = delete;
            QmlIntegrator(QmlIntegrator &&) = delete;
            QmlIntegrator & operator= (QmlIntegrator &&) = delete;
            static auto&instance(){
                static QmlIntegrator test;
                return test;
            }
            	double gain();
void setGain(const 	double&val); 
	Enums::PulseAmplitude pulseAmplitude();
void setPulseAmplitude(const 	Enums::PulseAmplitude&val); 
	double gainStep();
void setGainStep(const 	double&val); 
	double paramStep();
void setParamStep(const 	double&val); 
	double refGain();
void setRefGain(const 	double&val); 
	bool legEnable();
void setLegEnable(const 	bool&val); 
	double range();
void setRange(const 	double&val); 
	double rangeMax();
void setRangeMax(const 	double&val); 
	double displayDelay();
void setDisplayDelay(const 	double&val); 
	double displayDelayMin();
void setDisplayDelayMin(const 	double&val); 
	double displayDelayMax();
void setDisplayDelayMax(const 	double&val); 
	double UIRange();
void setUIRange(const 	double&val); 
	double UIRangeMax();
void setUIRangeMax(const 	double&val); 
	double UIDisplayDelay();
void setUIDisplayDelay(const 	double&val); 
	double UIDisplayDelayMin();
void setUIDisplayDelayMin(const 	double&val); 
	double UIDisplayDelayMax();
void setUIDisplayDelayMax(const 	double&val); 
	double UISpath1();
void setUISpath1(const 	double&val); 
	double UISpath2();
void setUISpath2(const 	double&val); 
	double UIGateAStart();
void setUIGateAStart(const 	double&val); 
	double UIGateAWidth();
void setUIGateAWidth(const 	double&val); 
	double UIGateBStart();
void setUIGateBStart(const 	double&val); 
	double UIGateBWidth();
void setUIGateBWidth(const 	double&val); 
	int velocity();
void setVelocity(const 	int&val); 
	int rejection();
void setRejection(const 	int&val); 
	bool zoomed();
void setZoomed(const 	bool&val); 
	double gateAStart();
void setGateAStart(const 	double&val); 
	double gateAWidth();
void setGateAWidth(const 	double&val); 
	int gateALevel();
void setGateALevel(const 	int&val); 
	double gateAGain();
void setGateAGain(const 	double&val); 
	Enums::SyncType gateASync();
void setGateASync(const 	Enums::SyncType&val); 
	Enums::TextOnChart textOnChart();
void setTextOnChart(const 	Enums::TextOnChart&val); 
	Enums::PosNeg gateALogic();
void setGateALogic(const 	Enums::PosNeg&val); 
	double gateBStart();
void setGateBStart(const 	double&val); 
	double gateBWidth();
void setGateBWidth(const 	double&val); 
	int gateBLevel();
void setGateBLevel(const 	int&val); 
	double gateBGain();
void setGateBGain(const 	double&val); 
	Enums::SyncType gateBSync();
void setGateBSync(const 	Enums::SyncType&val); 
	Enums::PosNeg gateBLogic();
void setGateBLogic(const 	Enums::PosNeg&val); 
	double probeIndex();
void setProbeIndex(const 	double&val); 
	double probeAngle();
void setProbeAngle(const 	double&val); 
	double stripAxisXMin();
void setStripAxisXMin(const 	double&val); 
	double stripAxisXMax();
void setStripAxisXMax(const 	double&val); 
	double aScanAxisXMin();
void setAScanAxisXMin(const 	double&val); 
	double aScanAxisXMax();
void setAScanAxisXMax(const 	double&val); 
	double aScanAxisYMin();
void setAScanAxisYMin(const 	double&val); 
	double aScanAxisYMax();
void setAScanAxisYMax(const 	double&val); 
	int stripTime();
void setStripTime(const 	int&val); 
	int prf();
void setPrf(const 	int&val); 
	double probeDelay();
void setProbeDelay(const 	double&val); 
	double thickness();
void setThickness(const 	double&val); 
	double probeDiameter();
void setProbeDiameter(const 	double&val); 
	int lineSpeed();
void setLineSpeed(const 	int&val); 
	Enums::Polarity polarity();
void setPolarity(const 	Enums::Polarity&val); 
	Enums::ProbeType probeType();
void setProbeType(const 	Enums::ProbeType&val); 
	Enums::PeakMethod peakMethodA();
void setPeakMethodA(const 	Enums::PeakMethod&val); 
	Enums::PeakMethod peakMethodB();
void setPeakMethodB(const 	Enums::PeakMethod&val); 
	Enums::EvaluationMode evaluationMode();
void setEvaluationMode(const 	Enums::EvaluationMode&val); 
	Enums::DigitalFilter digitalFilter();
void setDigitalFilter(const 	Enums::DigitalFilter&val); 
	Enums::Damping damping();
void setDamping(const 	Enums::Damping&val); 
	Enums::DualType dualNotSingle();
void setDualNotSingle(const 	Enums::DualType&val); 
	Enums::EnvelopeType envelope();
void setEnvelope(const 	Enums::EnvelopeType&val); 
	bool freezed();
void setFreezed(const 	bool&val); 
	QPointF currentPeakA();
void setCurrentPeakA(const 	QPointF&val); 
	QPointF currentFlankA();
void setCurrentFlankA(const 	QPointF&val); 
	QPointF currentJFlankA();
void setCurrentJFlankA(const 	QPointF&val); 
	QPointF currentMarkerA();
void setCurrentMarkerA(const 	QPointF&val); 
	QPointF currentUpwardA();
void setCurrentUpwardA(const 	QPointF&val); 
	QPointF currentDownwardA();
void setCurrentDownwardA(const 	QPointF&val); 
	QPointF currentPeakB();
void setCurrentPeakB(const 	QPointF&val); 
	QPointF currentFlankB();
void setCurrentFlankB(const 	QPointF&val); 
	QPointF currentJFlankB();
void setCurrentJFlankB(const 	QPointF&val); 
	QPointF currentMarkerB();
void setCurrentMarkerB(const 	QPointF&val); 
	QPointF currentUpwardB();
void setCurrentUpwardB(const 	QPointF&val); 
	QPointF currentDownwardB();
void setCurrentDownwardB(const 	QPointF&val); 
	int calibrationPointIndex();
void setCalibrationPointIndex(const 	int&val); 
	int evaluationPointIndex();
void setEvaluationPointIndex(const 	int&val); 
	QStringList evaluationPoints();
void setEvaluationPoints(const 	QStringList&val); 
	QStringList calibrationPoints();
void setCalibrationPoints(const 	QStringList&val); 
	bool activated();
void setActivated(const 	bool&val); 
	double spath1();
void setSpath1(const 	double&val); 
	double spath2();
void setSpath2(const 	double&val); 
	double resD();
void setResD(const 	double&val); 
	double resDa();
void setResDa(const 	double&val); 
	double resS();
void setResS(const 	double&val); 
	double resOneLeg();
void setResOneLeg(const 	double&val); 
	double awsa();
void setAwsa(const 	double&val); 
	double awsc();
void setAwsc(const 	double&val); 
	double awsd();
void setAwsd(const 	double&val); 
	Enums::AWSClass awsClass();
void setAwsClass(const 	Enums::AWSClass&val); 
	Enums::AWSTable awsTable();
void setAwsTable(const 	Enums::AWSTable&val); 
	Enums::Shape shape();
void setShape(const 	Enums::Shape&val); 
	Enums::Unit unit();
void setUnit(const 	Enums::Unit&val); 
	double pipeDiameter();
void setPipeDiameter(const 	double&val); 
	Enums::DACAlarm dacAlarmLevel();
void setDacAlarmLevel(const 	Enums::DACAlarm&val); 
	Enums::PulserType pulserType();
void setPulserType(const 	Enums::PulserType&val); 
	bool horn();
void setHorn(const 	bool&val); 
	bool grid();
void setGrid(const 	bool&val); 
	bool fullscreen();
void setFullscreen(const 	bool&val); 
	bool fill();
void setFill(const 	bool&val); 
	int theme();
void setTheme(const 	int&val); 
	int brightness();
void setBrightness(const 	int&val); 
	int saveFile();
void setSaveFile(const 	int&val); 
	QString memoryFilename();
void setMemoryFilename(const 	QString&val); 
	double tcorr();
void setTcorr(const 	double&val); 
	QStringList snapshotList();
void setSnapshotList(const 	QStringList&val); 
	QString currentSnapshot();
void setCurrentSnapshot(const 	QString&val); 
	QString applicationDirPath();
void setApplicationDirPath(const 	QString&val); 
	double inchToMm();
void setInchToMm(const 	double&val); 
	double usToMm();
void setUsToMm(const 	double&val); 
	double soundPathMultiplier();
void setSoundPathMultiplier(const 	double&val); 
	double iFSyncRef();
void setIFSyncRef(const 	double&val); 
	int velocityStep();
void setVelocityStep(const 	int&val); 
	int prfStep();
void setPrfStep(const 	int&val); 
	int spathStep();
void setSpathStep(const 	int&val); 
	int classStep1();
void setClassStep1(const 	int&val); 
	int classStep2();
void setClassStep2(const 	int&val); 
	int classStep3();
void setClassStep3(const 	int&val); 
	int batteryLevel();
void setBatteryLevel(const 	int&val); 
	int fsh();
void setFsh(const 	int&val); 
	bool callShowSnapshot();
void setCallShowSnapshot(const 	bool&val); 
	bool callHideSnapshot();
void setCallHideSnapshot(const 	bool&val); 
	bool menuUpEnabled();
void setMenuUpEnabled(const 	bool&val); 
	bool menuDownEnabled();
void setMenuDownEnabled(const 	bool&val); 
	bool started();
void setStarted(const 	bool&val); 
	bool batteryCharging();
void setBatteryCharging(const 	bool&val); 
	bool stripAEnabled();
void setStripAEnabled(const 	bool&val); 
	bool stripBEnabled();
void setStripBEnabled(const 	bool&val); 
	bool stripDACEnabled();
void setStripDACEnabled(const 	bool&val); 
	bool usbConnected();
void setUsbConnected(const 	bool&val); 
	bool alarmAActive();
void setAlarmAActive(const 	bool&val); 
	bool alarmBActive();
void setAlarmBActive(const 	bool&val); 
	bool alarmAEnable();
void setAlarmAEnable(const 	bool&val); 
	bool alarmBEnable();
void setAlarmBEnable(const 	bool&val); 
	bool alarmDACActive();
void setAlarmDACActive(const 	bool&val); 
	bool gateAEnabled();
void setGateAEnabled(const 	bool&val); 
	bool gateBEnabled();
void setGateBEnabled(const 	bool&val); 

signals:

void onGainChanged();
void onPulseAmplitudeChanged();
void onGainStepChanged();
void onParamStepChanged();
void onRefGainChanged();
void onLegEnableChanged();
void onRangeChanged();
void onRangeMaxChanged();
void onDisplayDelayChanged();
void onDisplayDelayMinChanged();
void onDisplayDelayMaxChanged();
void onUIRangeChanged();
void onUIRangeMaxChanged();
void onUIDisplayDelayChanged();
void onUIDisplayDelayMinChanged();
void onUIDisplayDelayMaxChanged();
void onUISpath1Changed();
void onUISpath2Changed();
void onUIGateAStartChanged();
void onUIGateAWidthChanged();
void onUIGateBStartChanged();
void onUIGateBWidthChanged();
void onVelocityChanged();
void onRejectionChanged();
void onZoomedChanged();
void onGateAStartChanged();
void onGateAWidthChanged();
void onGateALevelChanged();
void onGateAGainChanged();
void onGateASyncChanged();
void onTextOnChartChanged();
void onGateALogicChanged();
void onGateBStartChanged();
void onGateBWidthChanged();
void onGateBLevelChanged();
void onGateBGainChanged();
void onGateBSyncChanged();
void onGateBLogicChanged();
void onProbeIndexChanged();
void onProbeAngleChanged();
void onStripAxisXMinChanged();
void onStripAxisXMaxChanged();
void onAScanAxisXMinChanged();
void onAScanAxisXMaxChanged();
void onAScanAxisYMinChanged();
void onAScanAxisYMaxChanged();
void onStripTimeChanged();
void onPrfChanged();
void onProbeDelayChanged();
void onThicknessChanged();
void onProbeDiameterChanged();
void onLineSpeedChanged();
void onPolarityChanged();
void onProbeTypeChanged();
void onPeakMethodAChanged();
void onPeakMethodBChanged();
void onEvaluationModeChanged();
void onDigitalFilterChanged();
void onDampingChanged();
void onDualNotSingleChanged();
void onEnvelopeChanged();
void onFreezedChanged();
void onCurrentPeakAChanged();
void onCurrentFlankAChanged();
void onCurrentJFlankAChanged();
void onCurrentMarkerAChanged();
void onCurrentUpwardAChanged();
void onCurrentDownwardAChanged();
void onCurrentPeakBChanged();
void onCurrentFlankBChanged();
void onCurrentJFlankBChanged();
void onCurrentMarkerBChanged();
void onCurrentUpwardBChanged();
void onCurrentDownwardBChanged();
void onCalibrationPointIndexChanged();
void onEvaluationPointIndexChanged();
void onEvaluationPointsChanged();
void onCalibrationPointsChanged();
void onActivatedChanged();
void onSpath1Changed();
void onSpath2Changed();
void onResDChanged();
void onResDaChanged();
void onResSChanged();
void onResOneLegChanged();
void onAwsaChanged();
void onAwscChanged();
void onAwsdChanged();
void onAwsClassChanged();
void onAwsTableChanged();
void onShapeChanged();
void onUnitChanged();
void onPipeDiameterChanged();
void onDacAlarmLevelChanged();
void onPulserTypeChanged();
void onHornChanged();
void onGridChanged();
void onFullscreenChanged();
void onFillChanged();
void onThemeChanged();
void onBrightnessChanged();
void onSaveFileChanged();
void onMemoryFilenameChanged();
void onTcorrChanged();
void onSnapshotListChanged();
void onCurrentSnapshotChanged();
void onApplicationDirPathChanged();
void onInchToMmChanged();
void onUsToMmChanged();
void onSoundPathMultiplierChanged();
void onIFSyncRefChanged();
void onVelocityStepChanged();
void onPrfStepChanged();
void onSpathStepChanged();
void onClassStep1Changed();
void onClassStep2Changed();
void onClassStep3Changed();
void onBatteryLevelChanged();
void onFshChanged();
void onCallShowSnapshotChanged();
void onCallHideSnapshotChanged();
void onMenuUpEnabledChanged();
void onMenuDownEnabledChanged();
void onStartedChanged();
void onBatteryChargingChanged();
void onStripAEnabledChanged();
void onStripBEnabledChanged();
void onStripDACEnabledChanged();
void onUsbConnectedChanged();
void onAlarmAActiveChanged();
void onAlarmBActiveChanged();
void onAlarmAEnableChanged();
void onAlarmBEnableChanged();
void onAlarmDACActiveChanged();
void onGateAEnabledChanged();
void onGateBEnabledChanged();
};
#endif // QMLINTEGRATOR_H
