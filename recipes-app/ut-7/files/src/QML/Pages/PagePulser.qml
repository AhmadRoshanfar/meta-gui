import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"


PageBase {
    id: _page_pulser

    itemsList: [_param_prf,_param_setPRF,_param_power,/*_param_pulserType,*/_param_damping]

//    Binding{target: settings;           property:"prf";             value:_param_prf.value}
//    Binding{target: _param_prf;          property:"value";           value:settings.prf}
//    Binding{target: qmlIntegrator;      property:"prf";             value:_param_prf.value}
    Binding{target: _param_prf;          property:"value";           value:qmlIntegrator.prf}

//    Binding{target: settings; property:"pulseAmp";      value:_param_power.value}
//    Binding{target: _param_power; property:"value";value:settings.pulseAmp}
    Binding{target: qmlIntegrator; property:"pulseAmplitude";   value:_param_power.value}
    Binding{target: _param_power; property:"value";  value:qmlIntegrator.pulseAmplitude}

//    Binding{target: settings; property:"pulserType";      value:_param_pulserType.value}
//    Binding{target: _param_pulserType; property:"value";value:settings.pulserType}
//    Binding{target: qmlIntegrator; property:"pulserType";   value:_param_pulserType.value}
//    Binding{target: _param_pulserType; property:"value";  value:qmlIntegrator.pulserType}

    Binding{target: qmlIntegrator; property:"damping";          value:_param_damping.value}
    Binding{target: _param_damping; property:"value";            value:qmlIntegrator.damping}

    Binding{target: _param_prf; property:"stepIndex";      value:qmlIntegrator.prfStep}
    Binding{target: qmlIntegrator; property:"prfStep";       value:_param_prf.stepIndex}




    ParamInt {
        id: _param_prf
        name: "PRF"
        Layout.topMargin: 5
        unit: "Hz"
        minValue: 50
        maxValue: 1000
        defaultValues: [50,100,200,500,750, 1000 ]
        stepsList: [1,10,100]

//
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }


    ParamButton {
        id: _param_setPRF
        name: "Set PRF"
        Layout.topMargin: 5
        twoStepMode: true

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        function onEnterPressed(){
            if(sure){
                qmlIntegrator.prf = _param_prf.value
                sure = false
            }
            else{
                sure = true;
            }
        }
    }

    ParamEnum {
        id: _param_power
        name: "Power"
        Layout.topMargin: 5
        dictionary: {"LOW":Enums.PA_LO,"MED":Enums.PA_MED, "HIGH":Enums.PA_HI}


//
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

//    ParamEnum {
//        id: _param_pulserType
//        name: "Pulser Type"
//        Layout.topMargin: 5
//        dictionary: {"Spike":Enums.PULTY_SPIKE,"Square":Enums.PULTY_SQUARE}

////
//        Layout.fillHeight: true
//        Layout.preferredHeight: 20
//        Layout.maximumHeight: 1000
//        Layout.fillWidth: true
//        Layout.minimumHeight: 20

//        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//    }



    ParamEnum {
        id: _param_damping
        name: "Damping"
        Layout.topMargin: 5
        unit: "Ohm"
        dictionary:{"50":Enums.DAMP50,"200":Enums.DAMP200,"500":Enums.DAMP500}

//
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

//    ParamBase{
//        id: _param_empty
//        Layout.topMargin: 5

//        Layout.fillHeight: true
//        Layout.preferredHeight: 20
//        Layout.maximumHeight: 1000
//        Layout.fillWidth: true
//        Layout.minimumHeight: 20

//        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//    }

}
