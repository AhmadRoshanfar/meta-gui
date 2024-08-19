import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"


PageBase {
    id: _page_receiver

    itemsList: [_param_rectify,/*_param_dual,*/_param_frequency,_param_reject,_param_empty]


    Binding{target: qmlIntegrator; property:"polarity";         value:_param_rectify.value}
    Binding{target: _param_rectify; property:"value";        value:qmlIntegrator.polarity}

//    Binding{target: _param_dual; property:"value";   value:qmlIntegrator.dualNotSingle}
//    Binding{target: qmlIntegrator; property:"dualNotSingle";    value:_param_dual.value}

    Binding{target: qmlIntegrator; property:"digitalFilter";    value:_param_frequency.value}
    Binding{target: _param_frequency; property:"value";   value:qmlIntegrator.digitalFilter}

//    Binding{target: settings; property:"rejection";     value:_param_reject.value}
//    Binding{target: _param_reject; property:"value";    value:settings.rejection}
    Binding{target: qmlIntegrator; property:"rejection";     value:_param_reject.value}
    Binding{target: _param_reject; property:"value";        value:qmlIntegrator.rejection}

    Binding{target:qmlIntegrator ;       property: "aScanAxisYMin";       value: (_param_rectify.value === Enums.POL_RF)?-100:0 }



    ParamEnum {
        id: _param_rectify
        name: "Rectify"
        Layout.topMargin: 5
        dictionary:{"RF":Enums.POL_RF,"PHW":Enums.POL_PHW,"NHW":Enums.POL_NHW,"FW":Enums.POL_FW}


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

//    ParamEnum {
//        id: _param_dual
//        name: "Dual"
//        dictionary:{"Single":Enums.DUAL_SINGLE,"Dual":Enums.DUAL_DUAL,"Transmission":Enums.DUAL_TRANSMISSION}


//        color: "#ffffff"
//        Layout.fillHeight: true
//        Layout.preferredHeight: 20
//        Layout.maximumHeight: 1000
//        Layout.fillWidth: true
//        Layout.minimumHeight: 20

//        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//    }

    ParamEnum {
        id: _param_frequency
        name: "Frequency"
        Layout.topMargin: 5
        dictionary:{"Broadband":Enums.NOFILTER,
            "0.5-4 MHz":Enums.FILTER05TO4,
            "0.5-11 MHz":Enums.FILTER05TO11,
            "2-8 MHz":Enums.FILTER2TO8,
            "4-11 MHz":Enums.FILTER4TO11,
            "0.5-2 MHz":Enums.FILTER05T02
        }

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
        Layout.topMargin: 5
        unit: "%"
        minValue: 0
        maxValue: 50

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
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
