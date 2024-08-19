import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0
import CalibrationAdaptor 1.0

import "../Views"


PageBase {
    id: _page_autocal

    itemsList: [_param_spath1,_param_spath2,_param_astart,_param_points]

    Binding{target: _param_spath1;  property:"value";               value:getLengthWithUnit(qmlIntegrator.spath1)}
    Binding{target: _param_spath2;  property:"value";               value:getLengthWithUnit(qmlIntegrator.spath2)}


    Binding{target: _param_astart;  property:"value";               value:getLengthWithUnit(qmlIntegrator.gateAStart)}

    Binding{target: qmlIntegrator;  property:"calibrationPointIndex";value:_param_points.value}
    Binding{target: _param_points;  property:"value";               value:qmlIntegrator.calibrationPointIndex}

    Binding{target: qmlIntegrator;  property:"calibrationPoints";          value:_param_points.model}
    Binding{target: _param_points;  property:"model";               value:qmlIntegrator.calibrationPoints}

    Binding{target: _param_astart; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}
    Binding{target: _param_spath1; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}
    Binding{target: _param_spath2; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}

    Binding{target: _param_astart; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_astart.stepIndex}

    Binding{target: _param_spath1; property:"stepIndex";      value:qmlIntegrator.spathStep}
    Binding{target: qmlIntegrator; property:"spathStep";       value:_param_spath1.stepIndex}

    Binding{target: _param_spath2; property:"stepIndex";      value:qmlIntegrator.spathStep}
    Binding{target: qmlIntegrator; property:"spathStep";       value:_param_spath2.stepIndex}

    CalibrationAdaptor{
        id:_calibrationAdaptor
    }

    ParamDouble {
        id: _param_spath1
        name: "S.Path1"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: getLengthWithUnit(5000)
        unit:"mm"
        stepsList: [0.01,0.1,1,10,100]
        onValueChanged: {
            qmlIntegrator.spath1 = getLengthMM(_param_spath1.value);
        }


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamDouble {
        id: _param_spath2
        name: "S.Path2"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: getLengthWithUnit(5000)
        unit:"mm"
        stepsList: [0.01,0.1,1,10,100]
        onValueChanged: {
            qmlIntegrator.spath2 = getLengthMM(_param_spath2.value);
        }

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamDouble {
        id: _param_astart
        name: "A-Start"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: qmlIntegrator.UIRangeMax
        unit:"mm"
        stepsList: classSteps1
        onValueChanged: {
            qmlIntegrator.gateAStart = getLengthMM(_param_astart.value);
        }

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }


    ParamList {
        id: _param_points
        name: "Points"
        Layout.topMargin: 5
        model:["1","2"]

        function onEnterPressed(){
            _calibrationAdaptor.getPosition();
        }


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

//    ParamBool {
//        id: _param_evalActive
//        name: "Active"
//
//        Layout.fillHeight: true
//        Layout.preferredHeight: 20
//        Layout.maximumHeight: 1000
//        Layout.fillWidth: true
//        Layout.minimumHeight: 20
//        
//        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//    }


}
