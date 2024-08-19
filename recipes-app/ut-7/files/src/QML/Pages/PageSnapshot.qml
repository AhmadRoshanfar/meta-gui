//import Qt.labs.folderlistmodel 2.2
import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0
import SnapshotAdaptor 1.0

import "../Views"


PageBase {
    id: _page_alarms

    itemsList: [/*_param_list,*/_param_snapshotNo,_param_copy,_param_empty1,_param_empty2]

//        Binding{target: qmlIntegrator;  property:"snapshotList";          value:_param_snapshotNo.model}
//        Binding{target: _param_snapshotNo;  property:"model";               value:qmlIntegrator.snapshotList}

    Binding{target: qmlIntegrator;      property:"currentSnapshot";             value:_param_snapshotNo.model[_param_snapshotNo.value]}
    //    Binding{target: _param_snapshotNo;          property:"value";           value:qmlIntegrator.currentSnapshot}

    Connections{
        target: qmlIntegrator
        onFreezedChanged:{
            if(qmlIntegrator.freezed)
                loadList()
        }
    }


    function    loadList() {
//        var temp = [];
//        console.log(_folderModel.folder)
//        for(var i=0;i<_folderModel.count;i++)
//            temp.unshift(_folderModel.get(i,"fileName").replace(".png",""));
//        _param_snapshotNo.model = temp;
        _param_snapshotNo.model = _snapshotAdaptor.list()
    }

    function    clearList() {
        _param_snapshotNo.model = []
    }

    Component.onCompleted: loadList()

    Timer {
        id: timer
        function setTimeout(cb, delayTime) {
            timer.interval = delayTime;
            timer.repeat = false;
            timer.triggered.connect(cb);
            timer.triggered.connect(function release () {
                timer.triggered.disconnect(cb); // This is important
                timer.triggered.disconnect(release); // This is important as well
            });
            timer.start();
        }
    }



//    FolderListModel {
//        id: _folderModel
//        folder:  "file:///" + qmlIntegrator.applicationDirPath +"/snapshots/"
//        nameFilters: ["*.png"]
//        showFiles: true
//        showDirs: false
//    }

    SnapshotAdaptor{
        id:_snapshotAdaptor
    }

//    ParamButton {
//        id: _param_list
//        name: "List"
//        Layout.topMargin: 5

//        Layout.fillHeight: true
//        Layout.preferredHeight: 20
//        Layout.maximumHeight: 1000
//        Layout.fillWidth: true
//        Layout.minimumHeight: 20

//        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
//        function onEnterPressed() {
//            loadList();
//        }
//    }

    ParamList {
        id: _param_snapshotNo
        name: sure?"Delete?":"No."
        property bool sure: false
        Layout.topMargin: 5


        //        model:qmlIntegrator.snapshotList

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20



        function onEnterPressed(){
            if(sure){//Delete Pressed
                if(_param_snapshotNo.model.length === 0)
                    return;
                clearList()
                _snapshotAdaptor.remove();
                timer.setTimeout(function(){
                    loadList();
                },200);
                sure = false;
            }
            else//Enter Pressed
                if(_param_snapshotNo.model.length > 0){
                    qmlIntegrator.callShowSnapshot = !qmlIntegrator.callShowSnapshot;
//                    window.showSnapshot("file:///" + qmlIntegrator.applicationDirPath +"/snapshots/"+model[value]+".png");
                }

        }
        function onDeletePressed(){
            if(_param_snapshotNo.model.length > 0)
                sure = true
        }
        onValueChanged:  sure =false

        onSelectedChanged: {
            sure = false
            if(!selected)
                qmlIntegrator.callHideSnapshot = !qmlIntegrator.callHideSnapshot;
        }



        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamButton {
        id: _param_copy
        twoStepMode: true
        name: "Copy"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        function onEnterPressed(){
            if(_param_copy.sure){
                _snapshotAdaptor.copyFiles();
                _param_copy.sure = false;
            }
            else{
                _param_copy.sure = true;
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
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamBase{
        id:_param_empty2
        Layout.topMargin: 5
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

}
