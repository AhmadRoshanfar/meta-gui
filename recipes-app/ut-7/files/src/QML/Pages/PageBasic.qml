import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"


PageBase {
    id: _page_base


    itemsList: [_param_range,_param_probeDelay,_param_displayDelay,_param_velocity]


    Binding{target:_param_range ;       property: "maxValue";       value: qmlIntegrator.UIRangeMax}
//    Binding{target: _param_range; property:"value";           value:getLengthWithUnit(qmlIntegrator.range)}
    Binding{target: _param_range; property:"value";           value:qmlIntegrator.UIRange}
    Binding{target: _param_range; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}


    Binding{target: _param_displayDelay; property:"minValue";   value:qmlIntegrator.UIDisplayDelayMin}
    Binding{target: _param_displayDelay; property:"maxValue";   value:qmlIntegrator.UIDisplayDelayMax}
    Binding{target: _param_displayDelay; property:"value";      value:qmlIntegrator.UIDisplayDelay}
    Binding{target: _param_displayDelay; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}

    Binding{target: qmlIntegrator; property:"velocity";      value:_param_velocity.value}
    Binding{target: _param_velocity; property:"value";         value:qmlIntegrator.velocity}


    Binding{target: qmlIntegrator;      property:"probeDelay";      value:_param_probeDelay.value}
    Binding{target: _param_probeDelay;   property:"value";           value:qmlIntegrator.probeDelay}


    Binding{target: _param_velocity; property:"stepIndex";      value:qmlIntegrator.velocityStep}
    Binding{target: qmlIntegrator; property:"velocityStep";       value:_param_velocity.stepIndex}

    Binding{target: _param_range; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_range.stepIndex}

    Binding{target: _param_probeDelay; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_probeDelay.stepIndex}

    Binding{target: _param_displayDelay; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_displayDelay.stepIndex}

    ParamDouble {
        id: _param_range
        name: "Range"
        Layout.topMargin: 5
        minValue: 1
        defaultValues: [25,50,100,200,300,500,1000/*,2000,5000*/]
        stepsList: classSteps1
//
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
//        onMaxValueChanged: refresh()////////////
        onValueChanged: {
            qmlIntegrator.range =  getLengthMM(_param_range.value);///////////////
        }

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//        onUnitChanged: _param_range.value = getLengthWithUnit(_param_range.value)//////////
        Component.onCompleted: {
            value = qmlIntegrator.range;
        }
    }
    ParamDouble {
        id: _param_probeDelay
        name: "Probe Delay"
        Layout.topMargin: 5
        unit: "μs"
        minValue: 0
        maxValue: 1000
        stepsList: classSteps1
//
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
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: getLengthWithUnit(1000)
//        onMaxValueChanged: window.refresh()////////////
//        onMinValueChanged: window.refresh()/////////////
        onValueChanged:  {
            qmlIntegrator.displayDelay = getLengthMM(_param_displayDelay.value)
//            window.refresh()////////////
        }
//        onUnitChanged: _param_displayDelay.value = getLengthWithUnit(_param_displayDelay.value)////////

        stepsList: classSteps1
//
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        onUnitChanged: _param_displayDelay.value = getLengthWithUnit(_param_displayDelay.value)////////


        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }



    ParamInt {
        id: _param_velocity
        name: "Velocity"
        Layout.topMargin: 5
        unit: "m/s"
        defaultValues: [1480,2700,3200,4660,5920,6300]
        minValue: 0
        maxValue: 10000
        stepsList: [1,10,100,1000]
//
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
//        onValueChanged:  refresh()
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

}
