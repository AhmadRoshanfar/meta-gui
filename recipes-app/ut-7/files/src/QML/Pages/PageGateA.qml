import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"


PageBase {
    id: _page_gateA

    itemsList: [_param_gateAMode,_param_gateAStart,_param_gateAWidth,_param_gateALevel,_param_gateAGain,_param_gateATof,_param_gateALogic,_param_gateASync]

    Binding{target: qmlIntegrator; property:"gateALevel";   value:_param_gateALevel.value}
    Binding{target: _param_gateALevel; property:"value";          value:qmlIntegrator.gateALevel}

    //    Binding{target: qmlIntegrator; property:"gateAStart";   value:_param_gateAStart.value}
    Binding{target: _param_gateAStart; property:"value";          value:qmlIntegrator.UIGateAStart}

    //    Binding{target: qmlIntegrator; property:"gateAWidth";   value:_param_gateAWidth.value}
    Binding{target: _param_gateAWidth; property:"value";          value:qmlIntegrator.UIGateAWidth}


    Binding{target: qmlIntegrator; property:"gateAGain";    value:_param_gateAGain.value}
    Binding{target: _param_gateAGain; property:"value";           value:qmlIntegrator.gateAGain}


    Binding{target: qmlIntegrator; property:"gateAEnabled"; value:_param_gateAMode.value}
    Binding{target: _param_gateAMode; property:"value";        value:qmlIntegrator.gateAEnabled}

    Binding{target: qmlIntegrator; property:"gateALogic";    value:_param_gateALogic.value}
    Binding{target: _param_gateALogic; property:"value";        value:qmlIntegrator.gateALogic}

    Binding{target: _param_gateATof; property:"value";      value:qmlIntegrator.peakMethodA}
    Binding{target: qmlIntegrator; property:"peakMethodA";       value:_param_gateATof.value}

    Binding{target: _param_gateASync; property:"value";      value:qmlIntegrator.gateASync}
    Binding{target: qmlIntegrator; property:"gateASync";       value:_param_gateASync.value}


    Binding{target: _param_gateAStart; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}
    Binding{target: _param_gateAWidth; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}

    Binding{target: _param_gateAStart; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_gateAStart.stepIndex}

    Binding{target: _param_gateAWidth; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_gateAWidth.stepIndex}

    Binding{target: _param_gateAGain; property:"stepIndex";      value:qmlIntegrator.classStep3}
    Binding{target: qmlIntegrator; property:"classStep3";       value:_param_gateAGain.stepIndex}

    ParamBool {
        id: _param_gateAMode
        name: "Mode"
        Layout.topMargin: 5

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
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: qmlIntegrator.UIDisplayDelayMax
        stepsList: classSteps1


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        onValueChanged: {
            if(qmlIntegrator.envelope === Enums.ENV_ON)
                _ascanAdaptor.resetEnvelope(getLengthMM(_param_gateAStart.value),getLengthMM(_param_gateAWidth.value));
//            qmlIntegrator.gateAWidth= getLengthMM(_param_gateAWidth.value);
            qmlIntegrator.gateAStart = getLengthMM(_param_gateAStart.value);
        }
    }

    ParamDouble {
        id: _param_gateAWidth
        name: "Width"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: qmlIntegrator.UIDisplayDelayMax
        stepsList: classSteps1


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        onValueChanged: {
            if(qmlIntegrator.envelope === Enums.ENV_ON)
                _ascanAdaptor.resetEnvelope(getLengthMM(_param_gateAStart.value),getLengthMM(_param_gateAWidth.value));
            qmlIntegrator.gateAWidth= getLengthMM(_param_gateAWidth.value);
//            qmlIntegrator.gateAStart = getLengthMM(_param_gateAStart.value);

        }
    }

    ParamInt {
        id: _param_gateALevel
        name: "Level"
        Layout.topMargin: 5
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
        Layout.topMargin: 5
        minValue: 0
        maxValue: 60
        unit:"dB"
        stepsList: classSteps3


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
        Layout.topMargin: 5
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
        Layout.topMargin: 5
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
        Layout.topMargin: 5
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


}
