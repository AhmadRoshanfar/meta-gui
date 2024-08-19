import QtQuick 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Universal 2.2
import QtQuick.Controls.Material 2.0
import QtQuick.Window 2.0
import Qt.labs.settings 1.0
import Enums 1.0
import KeyboardAdaptor 1.0

import "Views"
import "Pages"


Rectangle {
    id: _pane_right
    width: qmlIntegrator.fullscreen?0:205
    height: 364  + (subqmlIntegrator.topbarVisible?0:53)
//    padding: 0

//    background: Rectangle{
//        color:  THEME.appBg
//    }
    color:  THEME.appBg

    property int selectedPageIndex: subqmlIntegrator.bottomIndex%_common.cBTM_ITEMS_PER_PAGE

    property var classSteps1: [0.01,0.1,1,10,100]
    property var classSteps2: [0.01,0.1,1,10]
    property var classSteps3: [0.25,0.5,1,10]
    readonly property var pagesList: [_page_basic,_page_pulser,_page_receiver,_page_gateA,_page_gateB,_page_material,_page_probe,_page_autocal,_page_eval,_page_display,_page_alarms,_page_memory,_page_misc,_page_settings,_page_snapshot]
    property int rightPage: 0
//    Themes{
//        id:_themes
//    }

    KeyboardAdaptor{
        id: _keyboardAdaptor
    }

    Common{
        id: _common
    }
    Binding{target: _frm_options;   property:  "currentIndex";  value: subqmlIntegrator.bottomIndex}
    Binding{target: subqmlIntegrator;  property:  "bottomIndex";   value:_frm_options.currentIndex }





    function getLengthWithUnit(length){
        switch(qmlIntegrator.unit){
        case Enums.UNIT_MM:return length;
        case Enums.UNIT_INCH:return length/qmlIntegrator.inchToMm;
        case Enums.UNIT_US:return length/qmlIntegrator.usToMm;
        }
    }

    function getLengthMM(length){
        switch(qmlIntegrator.unit){
        case Enums.UNIT_MM:return length;
        case Enums.UNIT_INCH:return length*qmlIntegrator.inchToMm;
        case Enums.UNIT_US:return length*qmlIntegrator.usToMm;
        }
    }

    function isUndefined(obj){
        return (typeof obj === 'undefined')
    }

    function selectPage(idx){
        selectParam(-1);
        subqmlIntegrator.rightPage = 0;
        subqmlIntegrator.bottomIndex = subqmlIntegrator.bottomPage*_common.cBTM_ITEMS_PER_PAGE + idx
        _frm_options.currentIndex = subqmlIntegrator.bottomIndex;
        firstPage();
    }

    function selectParam(idx){

        pagesList[subqmlIntegrator.bottomIndex].selectParam(idx);
        var current = pagesList[subqmlIntegrator.bottomIndex].itemsList[idx+4*pagesList[subqmlIntegrator.bottomIndex].pageNo];
        if(!isUndefined(current)){
            if(idx === subqmlIntegrator.rightIndex)
                current.onReselect();
           qmlIntegrator.paramStep = current.step;
        }
        else
            qmlIntegrator.paramStep = 0;
        subqmlIntegrator.rightIndex = idx;
    }

    function down(){
        pagesList[subqmlIntegrator.bottomIndex].down();
    }

    function up(){
        pagesList[subqmlIntegrator.bottomIndex].up();
    }

    function firstPage(){
        selectParam(-1);
        pagesList[subqmlIntegrator.bottomIndex].firstPage();
    }

    function nextPage(){
        selectParam(-1);
        pagesList[subqmlIntegrator.bottomIndex].nextPage();
    }


    function nextParamStep(){
        pagesList[subqmlIntegrator.bottomIndex].nextParamStep();
//        _lbl_step.text = qmlIntegrator.paramStep;
    }

    function fullscreen(){
        if(qmlIntegrator.fullscreen){
            _pane_right.visible = false;
            _pane_right.width = 0;


        }
        else{
            _pane_right.visible = true;
            _pane_right.width = 205;

        }
    }

    Connections{
        target: _keyboardAdaptor
        onKeyChanged:{
            if(_keyboardAdaptor.key === -1)
                return
            switch(_keyboardAdaptor.key&0xFF8FFFFF){
            case 0x00002000:pagesList[subqmlIntegrator.bottomIndex].onEnterPressed();
                break;
            case 0x00040000:pagesList[subqmlIntegrator.bottomIndex].onDeletePressed();
                break;
            case 0x00001000:selectPage(0);
                break;
            case 0x00000080:selectPage(1);
                break;
            case 0x00000004:selectPage(2);
                break;
            case 0x00010000:selectPage(3);
                break;
            case 0x00000800:selectPage(4);
                break;
                //            case 0x00020000:                bottomPage = (bottomPage-1)%(_common.cBTM_PAGE_CNT);
                //              break;
            case 0x00020000:                subqmlIntegrator.bottomPage = (subqmlIntegrator.bottomPage+1)%(_common.cBTM_PAGE_CNT);
                break;
            case 0x00000040:                nextPage();
                break;
            case 0x00000020:                selectParam(0);

                break;
            case 0x00000400:                selectParam(1);

                break;
            case 0x00008000:                selectParam(2);

                break;
            case 0x00000002:                selectParam(3);

                break;
            case 0x01000000:                up();

                break;
            case 0x02000000:                down();

                break;
            case 0x10000000:
                qmlIntegrator.gain = Math.min(qmlIntegrator.gain + qmlIntegrator.gainStep,75);
                break;
            case 0x20000000:
                qmlIntegrator.gain = Math.max(qmlIntegrator.gain - qmlIntegrator.gainStep, 0);
                break;
//            case 0x00000200:
//                qmlIntegrator.freezed = !qmlIntegrator.freezed;
//                if(qmlIntegrator.freezed === true)
//                    saveChart();
//                break;
//            case 0x00000100:
//                qmlIntegrator.zoomed = !qmlIntegrator.zoomed;
//                _ascanAdaptor.zoom(qmlIntegrator.zoomed);
//                break;
                //        case Qt.Key_E:
                //            qmlIntegrator.enveloped = qmlIntegrator.enveloped===Enums.ENV_ON ? Enums.ENV_OFF :Enums.ENV_ON;
                //            _ascanAdaptor.newEnveloped(qmlIntegrator.enveloped===Enums.ENV_ON);
                //            break;
            case 0x00000008:
                qmlIntegrator.fullscreen= !qmlIntegrator.fullscreen;
                fullscreen();
                break;
                //        case Qt.Key_P:
                //            saveSettings();
                //            break;
            case 0x00000010:
                nextGainStep();
                break;
            case 0x00000001:
                nextParamStep();
                break;
                //                case 23:
                //                    _settingsAdaptor.recall();
                //                    break;

            }
            _keyboardAdaptor.reset()
        }
    }

//    Item{
//        id:_keyboard
//        focus: true
//        Keys.onReturnPressed: {
//            _keyboardAdaptor.keyPress(0x00002000)
//        }

//        Keys.onDeletePressed: {
//            _keyboardAdaptor.keyPress(0x00040000)
//        }

//        property var lastPressed;
//        property int count : 0;


//        Keys.onPressed: {
//            //        console.log("pressed");
//            if(lastPressed === event.key)
//                count++;
//            else
//                count = 0;
//            lastPressed =event.key;
//            //        console.log(count);
//            if(count ==10){
//                switch(event.key){
//                case Qt.Key_0:
//                    longPressed(0);
//                    break;
//                case Qt.Key_1:
//                    longPressed(1);
//                    break;
//                case Qt.Key_2:
//                    longPressed(2);
//                    break;
//                case Qt.Key_3:
//                    longPressed(3);
//                    break;
//                }
//            }
//            switch(event.key){
//            case Qt.Key_F1:
//                _keyboardAdaptor.keyPress(0x00001000)
//                break;
//            case Qt.Key_F2:
//                _keyboardAdaptor.keyPress(0x00000080)
//                break;
//            case Qt.Key_F3:
//                _keyboardAdaptor.keyPress(0x00000004)
//                break;
//            case Qt.Key_F4:
//                _keyboardAdaptor.keyPress(0x00010000)
//                break;
//            case Qt.Key_F5:
//                _keyboardAdaptor.keyPress(0x00000800)
//                break;
//            case Qt.Key_Left:
//                _keyboardAdaptor.keyPress(0x00020000)
//                break;
//            case Qt.Key_Right:
//                _keyboardAdaptor.keyPress(0x00020000)
//                break;
//                //        case Qt.Key_Up:
//                //            nextPage();
//                //            break;
//            case Qt.Key_Down:
//                _keyboardAdaptor.keyPress(0x00000040)
//                break;
//            case Qt.Key_0:
//                _keyboardAdaptor.keyPress(0x00000020)
//                break;
//            case Qt.Key_1:
//                _keyboardAdaptor.keyPress(0x00000400)
//                break;
//            case Qt.Key_2:
//                _keyboardAdaptor.keyPress(0x00008000)
//                break;
//            case Qt.Key_3:
//                _keyboardAdaptor.keyPress(0x00000002)
//                break;
//            case Qt.Key_Plus:
//                _keyboardAdaptor.keyPress(0x01000000)
//                break;
//            case Qt.Key_Minus:
//                _keyboardAdaptor.keyPress(0x02000000)
//                break;
//            case Qt.Key_PageUp:
//                _keyboardAdaptor.keyPress(0x10000000)
//                break;
//            case Qt.Key_PageDown:
//                _keyboardAdaptor.keyPress(0x20000000)
//                break;
//            case Qt.Key_F:
//                _keyboardAdaptor.keyPress(0x00000200)
//                break;
//            case Qt.Key_Z:
//                _keyboardAdaptor.keyPress(0x00000100)
//                break;
//                //        case Qt.Key_E:
//                //            qmlIntegrator.enveloped = qmlIntegrator.enveloped===Enums.ENV_ON ? Enums.ENV_OFF :Enums.ENV_ON;
//                //            _ascanAdaptor.newEnveloped(qmlIntegrator.enveloped===Enums.ENV_ON);
//                //            break;
//            case Qt.Key_S:
//                _keyboardAdaptor.keyPress(0x00000008)
//                break;
//                //        case Qt.Key_P:
//                //            saveSettings();
//                //            break;
//            case Qt.Key_Tab:
//                _keyboardAdaptor.keyPress(0x00000010)
//                break;
//            case Qt.Key_Home:
//                _keyboardAdaptor.keyPress(0x00000001)
//                break;
//                //            case Qt.Key_F12:
//                //                _keyboardAdaptor.keyPress(23)
//                //                break;
//            }
//            //        event.accepted = true;
//        }
//    }




    StackLayout {
        id: _frm_options
        anchors.topMargin: -5
        anchors.bottomMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right


        PageBasic{
            id:_page_basic
        }
        PagePulser{
            id:_page_pulser
        }
        PageReceiver{
            id:_page_receiver
        }
        PageGateA{
            id:_page_gateA
        }
        PageGateB{
            id:_page_gateB
        }
        PageMaterial{
            id:_page_material
        }
        PageProbe{
            id:_page_probe
        }
        PageAutoCal{
            id:_page_autocal
        }
        PageEval{
            id:_page_eval
        }
        PageDisplay{
            id:_page_display
        }
        PageAlarms{
            id:_page_alarms
        }



        PageMemory{
            id:_page_memory
        }
        PageMisc{
            id:_page_misc
        }
        PageSettings{
            id:_page_settings
        }
        PageSnapshot{
            id:_page_snapshot
        }

    }
    Label{
        id: _lbl_downInd
        width: 29
        z: 2
        height: 29
        color: THEME.downArrowFg
        text: "\u25be"
        anchors.left: parent.left
        anchors.leftMargin: 8
        font.pointSize: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        visible: pagesList[subqmlIntegrator.bottomIndex].itemsList.length > 4 ? true:false;

        background: Rectangle {
            color: THEME.downArrowBg
            border.width: 0
            border.color: THEME.paramName
        }
    }
}











/*##^## Designer {
    D{i:9;anchors_width:200;anchors_x:0}
}
 ##^##*/
