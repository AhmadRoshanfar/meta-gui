import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"
import ".."


PageBase {
    id: _page_display


    itemsList: [_param_theme,_param_envelope,_param_grid,/*_param_fill,*/_param_topBar,_param_bottomBar,_param_brightness,_param_textOnChart,_param_empty]

    Binding{target: qmlIntegrator;      property:"theme";      value:_param_theme.value}
    Binding{target: _param_theme;   property:"value";           value:qmlIntegrator.theme}

    Binding{target: subqmlIntegrator;property:"topbarVisible";      value:_param_topBar.value}
    Binding{target: _param_topBar;   property:"value";           value:subqmlIntegrator.topbarVisible}

    Binding{target: subqmlIntegrator;   property:"bottombarVisible";      value:_param_bottomBar.value}
    Binding{target: _param_bottomBar;   property:"value";           value:subqmlIntegrator.bottombarVisible}

    Binding{target: qmlIntegrator;      property:"grid";      value:_param_grid.value}
    Binding{target: _param_grid;   property:"value";           value:qmlIntegrator.grid}

    Binding{target: qmlIntegrator;      property:"envelope";      value:_param_envelope.value}
    Binding{target: _param_envelope;   property:"value";           value:qmlIntegrator.envelope}

//    Binding{target: qmlIntegrator;      property:"fill";      value:_param_fill.value}
//    Binding{target: _param_fill;   property:"value";           value:qmlIntegrator.fill}

    Binding{target: qmlIntegrator;      property:"brightness";      value:_param_brightness.value}
    Binding{target: _param_brightness;   property:"value";           value:qmlIntegrator.brightness}

    Binding{target: qmlIntegrator;      property:"textOnChart";      value:_param_textOnChart.value}
    Binding{target: _param_textOnChart;   property:"value";           value:qmlIntegrator.textOnChart}

    ParamInt {
        id: _param_theme
        name: "Theme"
        Layout.topMargin: 5
        minValue: 1
        maxValue: 7


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//        onValueChanged: {
//            theme = themeList[value-1]
//        }
    }

    ParamEnum {
        id: _param_envelope
        name: "Envelope"
        Layout.topMargin: 5
        dictionary:{"on":Enums.ENV_ON,"background":Enums.ENV_BACKGROUND,"off":Enums.ENV_OFF}


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//        function down(){}
//        onValueChanged: {
//            if(value === Enums.ENV_ON)
//                _ascanAdaptor.newEnveloped(true);
//            else if(value === Enums.ENV_OFF)

//                _ascanAdaptor.newEnveloped(false);
//        }
    }

    ParamBool {
        id: _param_grid
        name: "Grid"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

//    ParamBool {
//        id: _param_fill
//        name: "Fill"

//
//        Layout.fillHeight: true
//        Layout.preferredHeight: 20
//        Layout.maximumHeight: 1000
//        Layout.fillWidth: true
//        Layout.minimumHeight: 20

//        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//    }

    ParamBool {
        id: _param_topBar
        name: "Top Bar"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }
    ParamBool {
        id: _param_bottomBar
        name: "Bottom Bar"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }


    ParamInt {
        id: _param_brightness
        name: "Brightness"
        Layout.topMargin: 5
        minValue: 0
        maxValue: 7



        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamEnum{
        id: _param_textOnChart
        name: "On Chart Text"
        Layout.topMargin: 5
        dictionary:{"none":Enums.TOC_NONE,"S":Enums.TOC_S,"D":Enums.TOC_D, "Da":Enums.TOC_Da, "d":Enums.TOC_d, "H":Enums.TOC_H}


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

//    ParamBase{
//        id: _param_empty1
//        Layout.topMargin: 5

//        Layout.fillHeight: true
//        Layout.preferredHeight: 20
//        Layout.maximumHeight: 1000
//        Layout.fillWidth: true
//        Layout.minimumHeight: 20

//        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//    }


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
}











/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
