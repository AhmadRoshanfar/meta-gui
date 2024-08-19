#ifndef ENUMS_H
#define ENUMS_H
#include <QObject>
#include <QQmlEngine>
class Enums : public QObject
{
    Q_GADGET
public:
    enum class Polarity{POL_RF=0,POL_PHW=1,POL_NHW=2,POL_FW=3};
    enum class ProbeType{PT_NORMAL=0,PT_ANGULAR=1,PT_TR=2, PT_TRANSMISSION = 3};
    enum class PeakMethod{PM_PEAK=0,PM_FLANK=1,PM_JFLANK=2,PM_UW=3,PM_DW=4};
    enum class EvaluationMode{EVAL_NORMAL=0,EVAL_CALIBRATION=1,EVAL_DAC=2,EVAL_TCG=3,EVAL_AWS=4,EVAL_DGS = 5};
    enum class DigitalFilter{NOFILTER=0,FILTER05TO4=1,FILTER05TO11=2,FILTER2TO8=3,FILTER4TO11=4,FILTER05TO2=5,FILTER8TO11=6};
    enum class Damping{DAMP500=0, DAMP200=1, DAMP50=2, DAMP36=3, DAMP25=4, DAMP20 = 5, DAMP17 = 6, DAMP15 =	7};
    enum class AScanSeries{AS_MAIN = 0, AS_OVERLAY_A = 1,AS_OVERLAY_B = 2, AS_GATE_A = 3, AS_GATE_B = 4, AS_ENV = 5};
    enum class AWSClass{AWSC_NONE = 0, AWSC_A = 1, AWSC_B = 2,AWSC_C = 3, AWSC_D = 4};
    enum class Shape{SHAPE_PIPE = 0, SHAPE_PLATE = 1};
    enum class Unit{UNIT_MM = 0,UNIT_INCH = 1, UNIT_US = 2};
    enum class EnvelopeType{ENV_ON = 0, ENV_OFF = 1, ENV_BACKGROUND = 2};
    enum class AWSTable{AT_M1 = 0, AT_M2 = 1};
    enum class DACAlarm{DA_100 = 0, DA_50 = 1, DA_20 = 2};
    enum class ParamType{PARTYP_ENUM = 0, PARTYP_DOUBLE = 1, PARTYP_INT = 2, PARTYP_BOOL = 3, PARTYP_BTN = 4, PARTYP_LIST = 5, PARTYPE_DATE = 6, PARTYP_TIME = 7};
    enum class PulserType{PULTY_SPIKE = 0, PULTY_SQUARE = 1};
    enum class OffOn{OFFON_OFF = 0, OFFON_ON = 1};
    enum class PosNeg{PN_POS = 0, PN_NEG = 1};
    enum class SyncType{SYNC_IP = 0, SYNC_IF = 1};
    enum class DualType{DUAL_SINGLE = 0, DUAL_DUAL = 1, DUAL_TRANSMISSION = 2};
    enum class PulseAmplitude{PA_LO = 0, PA_MED = 1, PA_HI = 2};
    enum class RightLeft{RL_NONE = 0, RL_LEFT = 1, RL_RIGHT = 2};
    enum class TextOnChart{TOC_NONE = 0, TOC_D = 1, TOC_Da = 2, TOC_d = 3, TOC_S = 4, TOC_H = 5};
//    enum class Frequency{FRE_BROADBAND=0,FRE_03TO15=1,FRE_1T4=2,FRE_2T8=3,FRE_4T15=4,FRE_10TO20=5};
    enum class Gate{GATE_A = 0, GATE_B = 1};
    Q_ENUM(Polarity)
    Q_ENUM(ProbeType)
    Q_ENUM(PeakMethod)
    Q_ENUM(EvaluationMode)
    Q_ENUM(DigitalFilter)
    Q_ENUM(Damping)
    Q_ENUM(AWSClass)
    Q_ENUM(Shape)
    Q_ENUM(Unit)
    Q_ENUM(EnvelopeType)
    Q_ENUM(AWSTable)
    Q_ENUM(DACAlarm)
    Q_ENUM(ParamType)
    Q_ENUM(PulserType)
    Q_ENUM(DualType)
    Q_ENUM(PosNeg)
    Q_ENUM(SyncType)
//    Q_ENUM(Frequency)
    Q_ENUM(Gate)
    Q_ENUM(PulseAmplitude)
    Q_ENUM(RightLeft)
    Q_ENUM(TextOnChart)
    static void declareQML() {
        qmlRegisterType<Enums>("Enums", 1, 0, "Enums");
    }
};
#endif // ENUMS_H
