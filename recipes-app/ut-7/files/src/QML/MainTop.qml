import QtQuick 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Universal 2.2
import QtQuick.Controls.Material 2.0
import QtQuick.Window 2.0
import Qt.labs.settings 1.0
import Enums 1.0
import BatteryAdaptor 1.0

import "Views"
import "Pages"
Rectangle{
    id:_top
    property int battery: 2
    property string colorBat: "green"
    width:800
    height:subqmlIntegrator.topbarVisible?50:0
    color: THEME.appBg
    BatteryAdaptor{
        id: _batteryAdaptor
    }
    ElevatedPane {
        id: _pane_top
        topPadding: 0
        bottomPadding: 0

        padding: 0
        Material.background: THEME.chartTopBarBg

        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        anchors.fill: parent

//        Themes{
//            id:_themes
//        }


        Connections{
            target:qmlIntegrator
            onCurrentPeakAChanged:{
                if(qmlIntegrator.freezed===false)
                    _lbl_h.text = Math.abs(qmlIntegrator.currentPeakA.y.toFixed(1))
            }
        }

        Connections{
            target:qmlIntegrator
            onResDChanged:{
                if(qmlIntegrator.freezed===false)
                    _lbl_D.text = qmlIntegrator.resD
            }
        }

        Connections{
            target:qmlIntegrator
            onResDaChanged:{
                if(qmlIntegrator.freezed===false)
                    _lbl_Da.text = qmlIntegrator.resDa
            }
        }

        Connections{
            target:qmlIntegrator
             onResSChanged:{
                if(qmlIntegrator.freezed===false)
                    _lbl_S.text = qmlIntegrator.resS
            }
        }

//        Binding{target: _lbl_h;         property:"text";            value:Math.abs(qmlIntegrator.currentPeakA.y.toFixed(1))}
//        Binding{target: _lbl_D;         property:"text";            value:qmlIntegrator.resD }
//        Binding{target: _lbl_Da;        property:"text";            value:qmlIntegrator.resDa}
//        Binding{target: _lbl_S;         property:"text";            value:qmlIntegrator.resS }
        Binding{target: _lbl_step;      property:  "text";          value: qmlIntegrator.paramStep}


        Timer {
            id: refreshTimer
            interval:  1000 // 60 Hz
            running: true
            repeat: true
            onTriggered: {
                if(qmlIntegrator.batteryCharging){
                    battery = (battery+1)%4
                }
                else{
                    //battery = 4*qmlIntegrator.batteryLevel/101 + 1
                    if (qmlIntegrator.batteryLevel < 10){
                        colorBat = "red"
                        battery = 0
                    }
                    else if (qmlIntegrator.batteryLevel < 35){
                        colorBat = "yellow"
                        battery = 1
                    }
                    else if (qmlIntegrator.batteryLevel < 70){
                        colorBat = "blue"
                        battery = 2
                    }
                    else{
                        colorBat = "green"
                        battery = 3
                    }
                }
            }
        }

        Label {
            id: label19
            y: 200
            height: 25
            text: qsTr("H:")
            anchors.right: _lbl_h.left
            anchors.rightMargin: 0
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            color:THEME.topResName
            horizontalAlignment: Text.AlignRight
            anchors.verticalCenter: parent.verticalCenter

        }

        TextBox {
            id: _lbl_h
            x: 3*parent.width/7+50
            width: 70
            height: 25
            color: THEME.topResValue
            text: qsTr("0")
            verticalAlignment: Text.AlignVCenter
            font.family: "Digital-7 Mono"
            font.pointSize: 16
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter

        }

        TextBox {
            id: _lbl_S
            x: 2*parent.width/7+50
            y: -13
            width: 70
            height: 25
            color: THEME.topResValue
            text: qsTr("0")
            font.family: "Digital-7 Mono"
            font.pointSize: 16
            minimumPixelSize: 1
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            fontSizeMode: Text.Fit
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label18
            x: 12
            y: -13
            height: 25
            color: THEME.topResName
            text: qsTr("S:")
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            anchors.right: _lbl_S.left
            anchors.rightMargin: 0
            anchors.verticalCenter: parent.verticalCenter
        }

        TextBox {
            id: _lbl_Da
            x: 1*parent.width/7+50
            y: -13
            width: 70
            height: 25
            color: THEME.topResValue
            text: qsTr("0")
            font.family: "Digital-7 Mono"
            font.pointSize: 16
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label9
            x: 0
            y: -13
            height: 25
            color: THEME.topResName
            text: qsTr("Da:")
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            anchors.right: _lbl_Da.left
            anchors.rightMargin: 0
            anchors.verticalCenter: parent.verticalCenter
        }

        TextBox {
            id: _lbl_D
            x: 0*parent.width/7+40
            y: -13
            width: 70
            height: 25
            color: THEME.topResValue
            text: qsTr("0")
            font.family: "Digital-7 Mono"
            font.pointSize: 16
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label8
            x: 0
            y: -13
            width: 30
            height: 25
            color: THEME.topResName
            text: qsTr("D:")
            font.pointSize: 14
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
            anchors.right: _lbl_D.left
            anchors.rightMargin: 0
            anchors.verticalCenter: parent.verticalCenter
        }

        TextBox {
            property var icons: ["","","",""]
            id: _lbl_batteryIndicator
            x: 736
            width: 30
            height: 21
            text: icons[Math.min(3,battery)]
            anchors.right: label15.left
            anchors.rightMargin: 20
            color: qmlIntegrator.batteryCharging ? "green":colorBat
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            //
            font.family: "IcoFont"
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 24
            opacity: 1
            horizontalAlignment: Text.AlignLeft
        }

        TextBox {
            id: _lbl_battery
            x: 736
            width: 20
            height: 21
            text: (qmlIntegrator.batteryLevel < 0) ? "DIS":(qmlIntegrator.batteryLevel === 0) ? "%?":(qmlIntegrator.batteryLevel > 100)?"%100":"%"+qmlIntegrator.batteryLevel
            color: qmlIntegrator.batteryCharging ? "green":THEME.topResValue
            anchors.right: _lbl_batteryIndicator.left
            anchors.rightMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            //
            verticalAlignment: Text.AlignVCenter
            opacity: 1
            horizontalAlignment: Text.AlignRight
        }


        TextBox {
            id: _lbl_usbIndicator
            x: 680
            width: 50
            height: 21
            color: THEME.topResValue
            text: qsTr("")
            anchors.right: _lbl_battery.left
            anchors.rightMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0

            verticalAlignment: Text.AlignVCenter
            font.family: "IcoFont"
            font.pointSize: 24
            opacity: 1
            horizontalAlignment: Text.AlignHCenter
            visible: qmlIntegrator.usbConnected
        }
        TextBox {
            id: _lbl_step
            x: 526
            y: -9
            width: 50
            height: 25
            color: THEME.topResValue
            text: qsTr("0")
            verticalAlignment: Text.AlignVCenter
            font.family: "Digital-7 Mono"
            anchors.rightMargin: 0
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 16
            opacity: 1
            anchors.verticalCenterOffset: 0
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: label15
            x: 120
            y: -23
            width: 30
            height: 25
            color: THEME.topResName
            text: qsTr("Rate:")
            anchors.right: _lbl_step.left
            anchors.rightMargin: 0
            horizontalAlignment: Text.AlignRight
            font.pointSize: 14
            anchors.verticalCenterOffset: 0
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}






/*##^## Designer {
    D{i:1;anchors_height:40;anchors_width:800}
}
 ##^##*/
