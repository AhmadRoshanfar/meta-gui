import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"


PageBase {
    id: _page_probe

    itemsList: [_param_probeType,_param_probeIndex,_param_probeDiameter,_param_probeAngle, _param_leg, _param_empty, _param_empty1, _param_empty2]

    Binding{target: qmlIntegrator; property:"probeAngle";    value:_param_probeAngle.value}
    Binding{target: _param_probeAngle; property:"value";     value:qmlIntegrator.probeAngle}


    Binding{target: _param_probeIndex; property:"value";     value:getLengthWithUnit(qmlIntegrator.probeIndex)}

    Binding{target: _param_probeDiameter; property:"value";          value:getLengthWithUnit(qmlIntegrator.probeDiameter)}

    Binding{target: qmlIntegrator; property:"probeType";        value:_param_probeType.value}
    Binding{target: _param_probeType; property:"value";       value:qmlIntegrator.probeType}


    Binding{target: _param_probeAngle; property:"stepIndex";      value:qmlIntegrator.classStep2}
    Binding{target: qmlIntegrator; property:"classStep2";       value:_param_probeAngle.stepIndex}

    Binding{target: _param_probeIndex; property:"stepIndex";      value:qmlIntegrator.classStep2}
    Binding{target: qmlIntegrator; property:"classStep2";       value:_param_probeIndex.stepIndex}

    Binding{target: _param_probeDiameter; property:"stepIndex";      value:qmlIntegrator.classStep2}
    Binding{target: qmlIntegrator; property:"classStep2";       value:_param_probeDiameter.stepIndex}

    Binding{target: qmlIntegrator;      property:"legEnable";            value:_param_leg.value}
    Binding{target: _param_leg;          property:"value";           value:qmlIntegrator.legEnable}

    Binding{target: _param_probeIndex; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}
    Binding{target: _param_probeDiameter; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}


//    Component.onCompleted: setProbeAngleVisible()

//    function setProbeAngleVisible(){
//        if(_param_probeType.value === Enums.PT_ANGULAR && pageNo == 1){
//            _param_probeAngle.visible = true

//        }
//        else{
//            _param_probeAngle.visible = false
//        }

//    }


    ParamEnum {
        id: _param_probeType
        name: "Type"
        Layout.topMargin: 5
        dictionary:{"Straight":Enums.PT_NORMAL,"Angular":Enums.PT_ANGULAR,"T/R":Enums.PT_TR, "Transmission":Enums.PT_TRANSMISSION}

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//        onValueChanged: {
//            setProbeAngleVisible()
//        }
    }


    ParamDouble {
        id: _param_probeIndex
        name: "Index"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: getLengthWithUnit(50)
        unit:"mm"
        stepsList: classSteps2


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

        onValueChanged: qmlIntegrator.probeIndex = getLengthMM(_param_probeIndex.value);
    }

    ParamDouble {
        id: _param_probeDiameter
        name: "Diameter"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(1)
        maxValue: getLengthWithUnit(50)
        unit:"mm"
        stepsList: classSteps2
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        onValueChanged: qmlIntegrator.probeDiameter = getLengthMM(_param_probeDiameter.value);
    }

    ParamDouble {
        id: _param_probeAngle
        name:  "Angle"
        Layout.topMargin: 5
        minValue: 0
        maxValue: 90
        unit:"°"
        defaultValues: [35,45,60,70]
        stepsList: classSteps2
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//        onVisibleChanged: setProbeAngleVisible()
//        visible: {return _param_probeType.value == Enums.PT_ANGULAR}
    }


    ParamBool {
        id: _param_leg
        name: "Leg"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamBase{
        id: _param_empty
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamBase{
        id: _param_empty1
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamBase{
        id: _param_empty2
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

//    ParamBase{
//        id: _param_empty3
//        Layout.topMargin: 5

//        Layout.fillHeight: true
//        Layout.preferredHeight: 20
//        Layout.maximumHeight: 1000
//        Layout.fillWidth: true
//        Layout.minimumHeight: 20

//        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//    }

}
