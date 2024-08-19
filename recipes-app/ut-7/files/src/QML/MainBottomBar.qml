
import QtQuick 2.2
import QtQuick.Layouts 1.2
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
    id: rectangle
    width: qmlIntegrator.fullscreen?800:597
    height: subqmlIntegrator.bottombarVisible?50:0
    color:THEME.appBg
    KeyboardAdaptor{
        id: _keyboardAdaptor
    }
    //    Loader{
    //        source: "main.qml"
    //    }
    property int selectedPageIndex: qmlIntegrator.bottomIndex%_common.cBTM_ITEMS_PER_PAGE

    //    property int qmlIntegrator.bottomPage: qmlIntegrator.bottomIndex/_common.cBTM_ITEMS_PER_PAGE
    Common{
        id: _common
    }
    property var cGAIN_STEP:[0.25,0.5,1,2,6,12,0]
    property int gainStepIndex : 0;

    Binding{target: qmlIntegrator;  property:"gain";            value:_lbl_gain.text}
    Binding{target: _lbl_gain;      property:"text";            value:qmlIntegrator.gain}
    Binding{target: _lbl_AWSd;      property:"text";            value:qmlIntegrator.awsd}
    Binding{target: _lbl_Class;     property:"value";           value:qmlIntegrator.awsClass}
    //    Binding{target: _lbl_prevPageInd; property:  "enabled";     value: (qmlIntegrator.bottomPage == 0)?false: true}
    Binding{target: _lbl_gainStep;  property:  "text";          value: qmlIntegrator.gainStep}
    Binding{target: _lbl_ref;       property:  "text";          value: qmlIntegrator.refGain}
    Binding{target: qmlIntegrator;  property:  "gainStep";      value: cGAIN_STEP[gainStepIndex]}
    //    Binding{target: _lbl_prevPageInd; property:  "enabled";     value: (qmlIntegrator.bottomPage == 0)?false: true}
    //    Binding{target: _lbl_nextPageInd; property:  "enabled";     value: (qmlIntegrator.bottomPage == _common.cBTM_PAGE_CNT-1)?false: true}

    Binding{target: _pane_bottom;   property:"visible";         value:subqmlIntegrator.bottombarVisible}
    Binding{target: _pane_bottom;   property:"height";         value:subqmlIntegrator.bottombarVisible?40:0}

//    Themes{
//        id:_themes
//    }




    function nextGainStep(){
        gainStepIndex = (gainStepIndex+1)%cGAIN_STEP.length;
    }



    Connections{
        target: _keyboardAdaptor
        onKeyChanged:{
            if(_keyboardAdaptor.key === -1)
                return
            switch(_keyboardAdaptor.key&0xFF8FFFFF){
                //            case 0x00002000:pagesList[qmlIntegrator.bottomIndex].onEnterPressed();
                //                break;
                //            case 0x00040000:pagesList[qmlIntegrator.bottomIndex].onDeletePressed();
                //                break;
                //            case 0x00001000:selectPage(0);
                //                break;
                //            case 0x00000080:selectPage(1);
                //                break;
                //            case 0x00000004:selectPage(2);
                //                break;
                //            case 0x00010000:selectPage(3);
                //                break;
                //            case 0x00000800:selectPage(4);
                //                break;
                //            case 0x00020000:                qmlIntegrator.bottomPage = (qmlIntegrator.bottomPage-1)%(_common.cBTM_PAGE_CNT);
                //              break;
                //            case 0x00020000:                qmlIntegrator.bottomPage = (qmlIntegrator.bottomPage+1)%(_common.cBTM_PAGE_CNT);
                //                break;
                //            case 0x00000040:                nextPage();
                //                break;
                //            case 0x00000020:                selectParam(0);

                //                break;
                //            case 0x00000400:                selectParam(1);

                //                break;
                //            case 0x00008000:                selectParam(2);

                //                break;
                //            case 0x00000002:                selectParam(3);

                //                break;
                //            case 0x01000000:                up();

                //                break;
                //            case 0x02000000:                down();

                //                break;
                //            case 0x10000000:
                //                qmlIntegrator.gain = Math.min(qmlIntegrator.gain + qmlIntegrator.gainStep,75);
                //                break;
                //            case 0x20000000:
                //                qmlIntegrator.gain = Math.max(qmlIntegrator.gain - qmlIntegrator.gainStep, 0);
                //                break;
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
//            case 0x00000008:
//                qmlIntegrator.fullscreen= !qmlIntegrator.fullscreen;
////                fullscreen();
//                break;
                //        case Qt.Key_P:
                //            saveSettings();
                //            break;
            case 0x00000010:
                nextGainStep();
                break;
                //            case 0x00000001:
                //                nextParamStep();
                //                break;
                //                case 23:
                //                    _settingsAdaptor.recall();
                //                    break;

            }
            _keyboardAdaptor.reset()
        }
    }


    ElevatedPane {
        id: _pane_bottom
        anchors.top: parent.top
        anchors.topMargin: 5
        //        bottomPadding: 0
        //        topPadding: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        //        padding: 0
        Layout.fillWidth: true
        Material.background: THEME.bottomBarBg
        Material.elevation: 2
        hoverEnabled: false
        Label {
            id: label16
            width: 35
            color: THEME.botResName
            text: qsTr("ref:")
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 5
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }

        TextBox {
            id: _lbl_ref
            x: 50
            width: 60
            color: THEME.botResValue
            text: qsTr("0")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -29
            anchors.top: parent.top
            anchors.topMargin: -29
            font.family: "Digital-7 Mono"
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 16
            horizontalAlignment: Text.AlignHCenter
        }

        Label {
            id: label13
            width: 35
            height: 41
            color: THEME.botResName
            text: qsTr("step:")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: _lbl_ref.right
            anchors.leftMargin: 0

            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
            horizontalAlignment: Text.AlignLeft
        }

        TextBox {
            id: _lbl_gainStep
            x: 1*parent.width/5+50
            width: 60
            height: 39
            color: THEME.botResValue
            text: qsTr("0")
            anchors.verticalCenter: parent.verticalCenter
            font.family: "Digital-7 Mono"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 16
            opacity: 1
        }

        Label {
            id: label20
            y: 8
            width: 35
            height: 41
            color: THEME.botResName
            text: qsTr("Gain:")
            anchors.left: _lbl_gainStep.right
            anchors.leftMargin: 5
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.topMargin: 0
            anchors.bottom: _lbl_gain.bottom
            anchors.bottomMargin: 0
            font.pointSize: 12
            anchors.top: _lbl_gain.top
        }

        TextBox {
            id: _lbl_gain
            x: 2*parent.width/5+50
            y: -3
            enabled: false
            width: 70
            height: 39
            color: THEME.botResValue
            text: qsTr("0")
            font.family: "Digital-7 Mono"
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: 0
            font.pointSize: 18
            horizontalAlignment: Text.AlignHCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
        }

        Label {
            id: label10
            width: 26
            height: 41
            text: qsTr("dB")
            font.italic: true
            verticalAlignment: Text.AlignVCenter
            anchors.left: _lbl_gain.right
            anchors.leftMargin: 5
            color:THEME.botResValue
            font.pointSize: 12
            horizontalAlignment: Text.AlignLeft
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
        }

        Label {
            id: label12
            x: 237
            y: -7
            width: 56
            height: 25
            color: THEME.botResName
            text: qsTr("d:")
            anchors.right: _lbl_AWSd.left
            anchors.rightMargin: 0
            horizontalAlignment: Text.AlignRight
            anchors.verticalCenterOffset: 0
            verticalAlignment: Text.AlignVCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            font.pointSize: 14
        }

        TextBox {
            id: _lbl_AWSd
            x: 3*parent.width/5+50
            width: 70
            height: 25
            color: THEME.botResValue
            text: qsTr("0")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            font.family: "Digital-7 Mono"
            font.pointSize: 16
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            opacity: 1
        }

        Label {
            id: label17
            width: 30
            text: qsTr("Cl:")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: _lbl_Class.left
            anchors.rightMargin: 0
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            color:THEME.botResName
            horizontalAlignment: Text.AlignRight

        }

        TextBox {
            id: _lbl_Class
            width: 55
            color: THEME.botResValue
            text: qsTr("None")
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            verticalAlignment: Text.AlignVCenter
            font.family: "Digital-7 Mono"
            lineHeight: 0.8
            font.pointSize: 16
            horizontalAlignment: Text.AlignHCenter
            property var value
            x: 4*parent.width/5+50
            onValueChanged: {
                switch(value){
                case Enums.AWSC_A:
                    text="A";break;
                case Enums.AWSC_B:
                    text="B";break;
                case Enums.AWSC_C:
                    text="C";break;
                case Enums.AWSC_D:
                    text="D";break;
                case Enums.AWSC_NONE:
                    text="None";break;
                default:
                    text="None";break;
                }
            }
        }






    }

}





















/*##^## Designer {
    D{i:16;anchors_height:39;anchors_x:"-13";anchors_y:5}D{i:19;anchors_height:25;anchors_y:"-20"}
D{i:20;anchors_height:25}D{i:21;anchors_height:39}D{i:22;anchors_x:5}D{i:23;anchors_height:41;anchors_x:5}
}
 ##^##*/
