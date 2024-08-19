import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0
import Enums 1.0

Item {
    width: 800
    height: 480
    function getLengthWithUnit(length){
        return qmlIntegrator.unit === Enums.UNIT_INCH ?length/qmlIntegrator.inchToMm:length;
    }
    Rectangle{
        color: THEME.appBg
        anchors.fill: parent
        border.width: 0



        Binding{target: _param_velocity; property:"value";         value:qmlIntegrator.velocity}
        Binding{target: _param_probeDelay;   property:"value";           value:qmlIntegrator.probeDelay}
        Binding{target: _param_gain;   property:"value";           value:qmlIntegrator.gain}
        Binding{target: _param_displayDelay; property:"value";      value:getLengthWithUnit(qmlIntegrator.displayDelay)}
        Binding{target: _param_range; property:"value";           value:getLengthWithUnit(qmlIntegrator.range)}
        //        Binding{target: _param_envelope;   property:"value";           value:qmlIntegrator.envelope}
        Binding{target: _param_grid;   property:"value";           value:qmlIntegrator.grid}
        Binding{target: _param_evalMode; property:"value";  value:qmlIntegrator.evaluationMode}
        Binding{target: _param_tcorr; property:"value";        value:qmlIntegrator.tcorr}
        Binding{target: _param_gateALevel; property:"value";          value:qmlIntegrator.gateALevel}
        Binding{target: _param_gateAStart; property:"value";          value:getLengthWithUnit(qmlIntegrator.gateAStart)}
        Binding{target: _param_gateAWidth; property:"value";          value:getLengthWithUnit(qmlIntegrator.gateAWidth)}
        Binding{target: _param_gateAGain; property:"value";           value:qmlIntegrator.gateAGain}
        Binding{target: _param_gateAMode; property:"value";        value:qmlIntegrator.gateAEnabled}
        Binding{target: _param_gateATof; property:"value";      value:qmlIntegrator.peakMethodA}
        Binding{target: _param_gateALogic; property:"value";        value:qmlIntegrator.gateALogic}
        Binding{target: _param_gateASync; property:"value";      value:qmlIntegrator.gateASync}

        Binding{target: _param_gateBLevel; property:"value";          value:qmlIntegrator.gateBLevel}
        Binding{target: _param_gateBStart; property:"value";          value:getLengthWithUnit(qmlIntegrator.gateBStart)}
        Binding{target: _param_gateBWidth; property:"value";          value:getLengthWithUnit(qmlIntegrator.gateBWidth)}
        Binding{target: _param_gateBGain; property:"value";           value:qmlIntegrator.gateBGain}
        Binding{target: _param_gateBMode; property:"value";        value:qmlIntegrator.gateBEnabled}
        Binding{target: _param_gateBTof; property:"value";      value:qmlIntegrator.peakMethodB}
        Binding{target: _param_gateBLogic; property:"value";        value:qmlIntegrator.gateBLogic}
        Binding{target: _param_gateBSync; property:"value";      value:qmlIntegrator.gateBSync}


        Binding{target: _param_alarmA; property:"value";         value:qmlIntegrator.alarmAEnable}
        Binding{target: _param_alarmB; property:"value";         value:qmlIntegrator.alarmBEnable}
        Binding{target: _param_evalLevel; property:"value";         value:qmlIntegrator.dacAlarmLevel}
        Binding{target: _param_horn; property:"value";         value:qmlIntegrator.horn}


        //        Binding{target: _param_materialType;property:"value";           value:qmlIntegrator.shape}
        //        Binding{target: _param_thickness;    property:"value";           value:qmlIntegrator.thickness}
        Binding{target: _param_pipeDiameter;    property:"value";           value:getLengthWithUnit(qmlIntegrator.pipeDiameter)}
        //        Binding{target: _param_unit;          property:"value";           value:qmlIntegrator.unit}
        Binding{target: _param_probeAngle; property:"value";     value:qmlIntegrator.probeAngle}
        Binding{target: _param_probeIndex; property:"value";     value:getLengthWithUnit(qmlIntegrator.probeIndex)}
        Binding{target: _param_probeDiameter; property:"value";          value:getLengthWithUnit(qmlIntegrator.probeDiameter)}
        Binding{target: _param_probeType; property:"value";       value:qmlIntegrator.probeType}
        Binding{target: _param_prf;          property:"value";           value:qmlIntegrator.prf}
        Binding{target: _param_power; property:"value";  value:qmlIntegrator.pulseAmplitude}
        //        Binding{target: _param_pulserType; property:"value";  value:qmlIntegrator.pulserType}
        Binding{target: _param_damping; property:"value";            value:qmlIntegrator.damping}
        Binding{target: _param_rectify; property:"value";        value:qmlIntegrator.polarity}
        Binding{target: _param_frequency; property:"value";   value:qmlIntegrator.digitalFilter}
        Binding{target: _param_reject; property:"value";        value:qmlIntegrator.rejection}
        Binding{target: _param_theme; property:"value";        value:qmlIntegrator.theme}

        Binding{target: _param_range; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        Binding{target: _param_displayDelay; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        Binding{target: _param_gateAStart; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        Binding{target: _param_gateAWidth; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        Binding{target: _param_gateBStart; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        Binding{target: _param_gateBWidth; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        Binding{target: _param_probeIndex; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        Binding{target: _param_probeDiameter; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        Binding{target: _param_pipeDiameter; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}



        //        Binding{target: _param_spath1; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}
        //        Binding{target: _param_spath2; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":"mm"}

        GridLayout {
            id: gridLayout
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            rowSpacing: 5
            rows: 8
            columns: 6
            flow: GridLayout.TopToBottom
            anchors.fill: parent





            ParamDouble {
                id: _param_range
                name: "Range"
                unit: "mm"

                Layout.columnSpan: 2
                Layout.rowSpan: 1
                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                //            Component.onCompleted: {
                //                value = settings.range;
                //            }
            }



            ParamDouble {

                id: _param_probeDelay
                name: "Probe Delay"
                unit: "μs"
                minValue: 0
                maxValue: 1000

                Layout.columnSpan: 2
                Layout.rowSpan: 1
                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }


            ParamDouble {
                id: _param_displayDelay
                name: "Display Delay"
                unit: "mm"
                minValue: 0
                maxValue: 1000
                defaultValues: [25,50,100,200,300,500,1000,2000,5000 ]

                Layout.columnSpan: 2
                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }



            ParamDouble {
                id: _param_gain
                name: "Gain"
                unit: "dB"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                //            Component.onCompleted: {
                //                value = settings.range;
                //            }
            }

            ParamInt {
                id: _param_velocity
                name: "Velocity"
                unit: "m/s"
                defaultValues: [1480,2700,3200,4660,5920,6300]
                minValue: 0
                maxValue: 10000

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_probeType
                name: "Probe Type"
                dictionary:{"Str.":Enums.PT_NORMAL,"Ang.":Enums.PT_ANGULAR,"T/R":Enums.PT_TR}

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_probeAngle
                name: "Probe Angle"
                minValue: 0
                maxValue: 90
                unit:"°"
                defaultValues: [35,45,60,70]

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_probeIndex
                name: "Probe Index"
                minValue: 0
                maxValue: 1000
                unit:"mm"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_power
                name: "Power"
                dictionary: {"LOW":Enums.PA_LO,"MED":Enums.PA_MED, "HIGH":Enums.PA_HI}

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_probeDiameter
                name: "Probe Diameter"
                minValue: 0
                maxValue: 1000
                unit:"mm"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_pipeDiameter
                name: "Mat. Diameter"
                minValue: 0
                maxValue: 1000
                unit:"mm"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamInt {
                id: _param_reject
                name: "Reject"
                unit: "%"
                minValue: 0
                maxValue: 100

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_damping
                name: "Damping"
                unit: "Ohm"
                dictionary:{"50":Enums.DAMP50,"200":Enums.DAMP200,"500":Enums.DAMP500}

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamBool {
                id: _param_gateAMode
                name: "Gate A"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }


            ParamDouble {
                id: _param_gateAStart
                name: "Start"
                minValue: 0
                maxValue: 2500
                unit:"mm"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

            }


            ParamDouble {
                id: _param_gateAWidth
                name: "Width"
                minValue: 0
                maxValue: 2500
                unit:"mm"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

            }


            ParamInt {
                id: _param_gateALevel
                name: "Level"
                minValue: 0
                maxValue: 100
                unit:"%"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_gateAGain
                name: "Gain"
                minValue: 0
                maxValue: 60
                unit:"dB"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_gateATof
                name: "TOF"
                dictionary: {"Peak":Enums.PM_PEAK,
                    "Flank":Enums.PM_FLANK,
                    "JFlank":Enums.PM_JFLANK
                }

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_gateALogic
                name: "Logic"
                dictionary: {"Pos":Enums.PN_POS,
                    "Neg":Enums.PN_NEG
                }

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_gateASync
                name: "Sync"
                dictionary: {"IP":Enums.SYNC_IP,
                    "IF":Enums.SYNC_IF
                }

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamBool {
                id: _param_gateBMode
                name: "Gate B"


                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20

                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_gateBStart
                name: "Start"
                minValue: 0
                maxValue: 2500
                unit:"mm"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_gateBWidth
                name: "Width"
                minValue: 0
                maxValue: 2500
                unit:"mm"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamInt {
                id: _param_gateBLevel
                name: "Level"
                minValue: 0
                maxValue: 100
                unit:"%"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_gateBGain
                name: "Gain"
                minValue: 0
                maxValue: 60
                unit:"dB"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_gateBTof
                name: "TOF"
                dictionary: {"Peak":Enums.PM_PEAK,
                    "Flank":Enums.PM_FLANK,
                    "JFlank":Enums.PM_JFLANK
                }

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }


            ParamEnum {
                id: _param_gateBLogic
                name: "Logic"
                dictionary: {"Pos":Enums.PN_POS,
                    "Neg":Enums.PN_NEG
                }
                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_gateBSync
                name: "Sync"
                dictionary: {"IP":Enums.SYNC_IP,
                    "IF":Enums.SYNC_IF
                }

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }


            //            ParamEnum {
            //                id: _param_dual
            //                name: "Dual"
            //                dictionary:{"Single":Enums.DUAL_SINGLE,"Dual":Enums.DUAL_DUAL,"Transmission":Enums.DUAL_TRANSMISSION}


            //
            //                Layout.fillHeight: true
            //                Layout.preferredHeight: 20
            //                Layout.maximumHeight: 1000
            //                Layout.fillWidth: true
            //                Layout.minimumHeight: 20

            //                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            //            }


            ParamBool {
                id: _param_alarmA
                name: "Alarm A"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamBool {
                id: _param_alarmB
                name: "Alarm B"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_evalLevel
                name: "Alarm Eval"
                dictionary:{"100":Enums.DA_100,"50":Enums.DA_50,"20":Enums.DA_20}
                unit : "%"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamEnum {
                id: _param_evalMode
                name: "Eval"
                dictionary:{"DAC":Enums.EVAL_DAC,"TCG":Enums.EVAL_TCG,"AWS":Enums.EVAL_AWS/*,"DGS":Enums.EVAL_DGS*/}

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            ParamDouble {
                id: _param_tcorr
                name: "T.Corr"
                minValue: 0
                maxValue: 60
                unit: "dB"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            //            ParamEnum {
            //                id: _param_pulserType
            //                name: "Pulser Type"
            //                dictionary: {"Spike":Enums.PULTY_SPIKE,"Square":Enums.PULTY_SQUARE}
            //


            //                Layout.fillHeight: true
            //                Layout.preferredHeight: 20
            //                Layout.maximumHeight: 1000
            //                Layout.fillWidth: true
            //                Layout.minimumHeight: 20

            //                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            //            }




            ParamInt {
                id: _param_prf
                name: "PRF"
                unit: "Hz"
                defaultValues: [50,100,200,500,750, 1000 ]

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }




            ParamEnum {
                id: _param_rectify
                name: "Rectify"
                dictionary:{"RF":Enums.POL_RF,"PHW":Enums.POL_PHW,"NHW":Enums.POL_NHW,"FW":Enums.POL_FW}

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }




            ParamEnum {
                id: _param_frequency
                name: "Frequency"
                unit: "MHz"
                dictionary:{"0-∞":Enums.NOFILTER,
                    "0.5-4":Enums.FILTER05TO4,
                    "0.5-11":Enums.FILTER05TO11,
                    "2-8":Enums.FILTER2TO8,
                    "4-11":Enums.FILTER4TO11,
                    "0.5-2":Enums.FILTER05T02
                }

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }




            ParamBool {
                id: _param_horn
                name: "Horn"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }




            ParamBool {
                id: _param_grid
                name: "Grid"

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }


            ParamInt {
                id: _param_theme
                name: "Theme"
                minValue: 1
                maxValue: 10

                Layout.fillHeight: true
                Layout.preferredHeight: 20
                Layout.maximumHeight: 1000
                Layout.fillWidth: true
                Layout.minimumHeight: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }
        }


    }
}












