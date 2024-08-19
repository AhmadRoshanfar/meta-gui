import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0
import IFSyncAdaptor 1.0

import "../Views"



PageBase {
    id: _page_gateB

    itemsList: [_param_gateBMode,_param_gateBStart,_param_gateBWidth,_param_gateBLevel,_param_gateBGain,_param_gateBTof,_param_gateBLogic,_param_gateBSync]



    Binding{target: qmlIntegrator; property:"gateBLevel";   value:_param_gateBLevel.value}
    Binding{target: _param_gateBLevel; property:"value";          value:qmlIntegrator.gateBLevel}

    //    Binding{target: qmlIntegrator; property:"gateBStart";   value:_param_gateBStart.value}
    Binding{target: _param_gateBStart; property:"value";          value:qmlIntegrator.UIGateBStart}

    //    Binding{target: qmlIntegrator; property:"gateBWidth";   value:_param_gateBWidth.value}
    Binding{target: _param_gateBWidth; property:"value";          value:qmlIntegrator.UIGateBWidth}

    Binding{target: qmlIntegrator; property:"gateBGain";    value:_param_gateBGain.value}
    Binding{target: _param_gateBGain; property:"value";           value:qmlIntegrator.gateBGain}

    Binding{target: qmlIntegrator; property:"gateBEnabled"; value:_param_gateBMode.value}
    Binding{target: _param_gateBMode; property:"value";        value:qmlIntegrator.gateBEnabled}

    Binding{target: qmlIntegrator; property:"gateBLogic";    value:_param_gateBLogic.value}
    Binding{target: _param_gateBLogic; property:"value";        value:qmlIntegrator.gateBLogic}

    Binding{target: _param_gateBTof; property:"value";      value:qmlIntegrator.peakMethodB}
    Binding{target: qmlIntegrator; property:"peakMethodB";       value:_param_gateBTof.value}

    Binding{target: _param_gateBSync; property:"value";      value:qmlIntegrator.gateBSync}
    Binding{target: qmlIntegrator; property:"gateBSync";       value:_param_gateBSync.value}

    Binding{target: _param_gateBStart; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}
    Binding{target: _param_gateBWidth; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}

    Binding{target: _param_gateBStart; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_gateBStart.stepIndex}

    Binding{target: _param_gateBWidth; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_gateBWidth.stepIndex}

    Binding{target: _param_gateBGain; property:"stepIndex";      value:qmlIntegrator.classStep3}
    Binding{target: qmlIntegrator; property:"classStep3";       value:_param_gateBGain.stepIndex}

    IFSyncAdaptor{
        id:_iFSyncAdaptor
    }

    ParamBool {
        id: _param_gateBMode
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
        id: _param_gateBStart
        name: "Start"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue:qmlIntegrator.UIDisplayDelayMax
        stepsList: classSteps1


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        onValueChanged: {
//            if(qmlIntegrator.envelope === Enums.ENV_ON)
//                _ascanAdaptor.resetEnvelope(_param_gateBStart.value,_param_gateBWidth.value);
            qmlIntegrator.gateBStart = getLengthMM(_param_gateBStart.value);

        }
    }

    ParamDouble {
        id: _param_gateBWidth
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
//            if(qmlIntegrator.envelope === Enums.ENV_ON)
//                _ascanAdaptor.resetEnvelope(_param_gateBStart.value,_param_gateBWidth.value);
            qmlIntegrator.gateBWidth= getLengthMM(_param_gateBWidth.value);

        }
    }

    ParamInt {
        id: _param_gateBLevel
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
        id: _param_gateBGain
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
        id: _param_gateBTof
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
        id: _param_gateBLogic
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
        id: _param_gateBSync
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
        onValueChanged: {
            if(value === Enums.SYNC_IF)
                _iFSyncAdaptor.setRefPoint();
        }

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }


}
