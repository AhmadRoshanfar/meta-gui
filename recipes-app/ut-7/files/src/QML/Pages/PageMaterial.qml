import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0


import "../Views"


PageBase {
    id: _page_material
    itemsList: [_param_materialType,_param_thickness,_param_pipeDiameter,_param_empty]


    Binding{target: qmlIntegrator;      property:"shape";           value:_param_materialType.value}
    Binding{target: _param_materialType;property:"value";           value:qmlIntegrator.shape}


    Binding{target: _param_thickness;    property:"value";           value:getLengthWithUnit(qmlIntegrator.thickness)}


    Binding{target: _param_pipeDiameter;    property:"value";           value:getLengthWithUnit(qmlIntegrator.pipeDiameter)}

    Binding{target: _param_thickness; property:"stepIndex";      value:qmlIntegrator.classStep2}

    Binding{target: _param_pipeDiameter; property:"stepIndex";      value:qmlIntegrator.classStep2}
    Binding{target: qmlIntegrator; property:"classStep2";       value:_param_pipeDiameter.stepIndex}


    Binding{target: _param_pipeDiameter; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}
    Binding{target: _param_thickness; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}


    ParamEnum {
        id: _param_materialType
        name: "Type"
        Layout.topMargin: 5
        dictionary:{"Pipe":Enums.SHAPE_PIPE,"Plate":Enums.SHAPE_PLATE}


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamDouble {
        id: _param_thickness
        name: "Thickness"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: getLengthWithUnit(300)
        unit:"mm"
        stepsList: classSteps2


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        onValueChanged: qmlIntegrator.thickness = getLengthMM(_param_thickness.value);

    }

    ParamDouble {
        id: _param_pipeDiameter
        name: "Diameter"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: getLengthWithUnit(700)
        unit:"mm"
        stepsList: classSteps2


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        onValueChanged: qmlIntegrator.pipeDiameter = getLengthMM(_param_pipeDiameter.value);

    }

    ParamBase{
        id:_param_empty
        Layout.topMargin: 5
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
    }

}
