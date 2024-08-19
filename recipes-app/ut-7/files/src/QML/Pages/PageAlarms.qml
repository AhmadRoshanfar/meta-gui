import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"


PageBase {
    id: _page_alarms

    itemsList: [_param_alarmA,_param_alarmB,_param_evalLevel,_param_horn]

    Binding{target: qmlIntegrator;      property:"alarmAEnable";           value:_param_alarmA.value}
    Binding{target: _param_alarmA; property:"value";         value:qmlIntegrator.alarmAEnable}
    Binding{target: qmlIntegrator;      property:"alarmBEnable";           value:_param_alarmB.value}
    Binding{target: _param_alarmB; property:"value";         value:qmlIntegrator.alarmBEnable}
//    Binding{target: qmlIntegrator;      property:"alarmDAC";           value:_chb_DACAlarm.value}
//    Binding{target: _param_alarmA; property:"value";         value:qmlIntegrator.alarmA}
    Binding{target: qmlIntegrator;      property:"dacAlarmLevel";           value:_param_evalLevel.value}
    Binding{target: _param_evalLevel; property:"value";         value:qmlIntegrator.dacAlarmLevel}
    Binding{target: qmlIntegrator;      property:"horn";           value:_param_horn.value}
    Binding{target: _param_horn; property:"value";         value:qmlIntegrator.horn}





    ParamBool {
        id: _param_alarmA
        name: "Gate A"
        Layout.topMargin: 5


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamBool {
        id: _param_alarmB
        name: "Gate B"
        Layout.topMargin: 5


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamEnum {
        id: _param_evalLevel
        name: "Eval"
        Layout.topMargin: 5
        dictionary:{"100":Enums.DA_100,"50":Enums.DA_50,"20":Enums.DA_20}
        unit : "%"


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
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }


}
