import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0
import SettingsAdaptor 1.0
import Qt.labs.settings 1.0

import "../Views"


PageBase {
    id: _page_memory

    itemsList: [_param_fileName,_param_description,_param_save,_param_recall, _param_defaults,_param_empty1,_param_empty2,_param_empty3/*,_param_list*/]
    //    TODO: Add bindings and functions
    //    Binding{target: settings;      property:"latestSettings";      value:_param_fileName.value}
//    Binding{target: _param_fileName;   property:"value";           value:settings.latestSettings}
    Binding{target: qmlIntegrator;          property:"memoryFilename";          value:_param_fileName.value}
    Binding{target: _param_fileName;        property:"value";                   value:qmlIntegrator.memoryFilename}

    Binding{target: subqmlIntegrator;       property:"memoryDescription";       value:_param_description.text}
    Binding{target: _param_description;     property:"text";                    value:subqmlIntegrator.memoryDescription}

    Component.onCompleted: {
        filenameChanged()
    }


    function filenameChanged(){
        checkAvailability();
        qmlIntegrator.memoryFilename =  _param_fileName.value
        _param_description.reset()
        _settingsAdaptor.loadDescription()
        _param_description.setTextChars()
        _param_fileName.sure =false
    }

//    Connections{
//        target: qmlIntegrator
//        onMemoryDescriptionChanged{

//        }
//    }

    function checkAvailability(){
        if(_settingsAdaptor.fileExists(_param_fileName.value))
            _param_fileName.unit = "*"
        else
            _param_fileName.unit = ""
    }

    SettingsAdaptor{
        id:_settingsAdaptor
    }

    ParamInt {
        id: _param_fileName
        name: sure?"Delete?":"File Name"
        property bool sure: false
        Layout.topMargin: 5

        minValue: 0
        maxValue: 100

        function onEnterPressed(){
            if(sure){
                _settingsAdaptor.remove();
                unit = "";
                sure = false;
            }

        }
        function onDeletePressed(){
            sure = true
        }



        onSelectedChanged: sure = false
        onValueChanged: {
            filenameChanged()
        }



        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }


    ParamTextInput {
        id: _param_description
        name: "Description"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamButton {
        id: _param_save
        name: "Save"
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
                _settingsAdaptor.setLatest();
                _settingsAdaptor.save();
                checkAvailability();
                sure = false
            }
            else{
                sure = true;
            }
        }
    }

    ParamButton {
        id: _param_recall
        name: "Recall"
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
                _settingsAdaptor.setLatest();
                _settingsAdaptor.recall();
                sure = false
            }
            else{
                sure = true;
            }
        }
    }





    ParamButton {
        id: _param_defaults
        name: "Defaults"
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
                _settingsAdaptor.loadDefaults();
                sure = false
            }
            else{
                sure = true;
            }
        }
    }

    ParamBase{
        id:_param_empty1
        Layout.topMargin: 5
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
    }

    ParamBase{
        id:_param_empty2
        Layout.topMargin: 5
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
    }

    ParamBase{
        id:_param_empty3
        Layout.topMargin: 5
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
    }
    //    ParamButton {
    //        id: _param_list
    //        name: "List"
    //
    //        Layout.fillHeight: true
    //        Layout.preferredHeight: 20
    //        Layout.maximumHeight: 1000
    //        Layout.fillWidth: true
    //        Layout.minimumHeight: 20

    //        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    //    }


}
