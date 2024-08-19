import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0
import DateAdaptor 1.0
import "../Views"


PageBase {
    id: _page_misc

    itemsList: [_param_date, _param_time, _param_unit, _param_version]
    Binding{target: qmlIntegrator;      property:"unit";            value:_param_unit.value}
    Binding{target: _param_unit;          property:"value";           value:qmlIntegrator.unit}

    //    TODO: Add bindings;Date and Time format;Leg functionality

    onVisibleChanged: {
        if(visible){
            _param_date.reset()
            _param_time.reset()
        }
    }

    Component.onCompleted: _dateAdaptor.init()
    DateAdaptor{
        id:_dateAdaptor
    }

    function setDateTime(){
        _dateAdaptor.setDateTime(_param_date.year,_param_date.mon,_param_date.day,_param_time.hour,_param_time.min,_param_time.sec, true)
    }

    ParamDate {
        id: _param_date
        name: "Date"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop


    }

    ParamTime {
        id: _param_time
        name: "Time"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

    }

    ParamEnum {
        id: _param_unit
        name: "Unit"
        Layout.topMargin: 5
        dictionary:{
            "mm":Enums.UNIT_MM,
            "inch":Enums.UNIT_INCH,
            "µS":Enums.UNIT_US
        }

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamEnum {
        id: _param_version
        name: "Version"
        Layout.topMargin: 5
        dictionary:{
            "240502":Enums.UNIT_MM
        }

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
