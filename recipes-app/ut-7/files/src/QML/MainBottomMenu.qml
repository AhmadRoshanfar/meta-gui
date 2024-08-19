
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
    width: 800
    height: 60

    color:THEME.appBg
    KeyboardAdaptor{
        id: _keyboardAdaptor
    }
    //    Loader{
    //        source: "main.qml"
    //    }
    property int selectedPageIndex: subqmlIntegrator.bottomIndex%_common.cBTM_ITEMS_PER_PAGE

    //    property int qmlIntegrator.bottomPage: subqmlIntegrator.bottomIndex/_common.cBTM_ITEMS_PER_PAGE
    Common{
        id: _common
    }



    Connections{
        target:subqmlIntegrator
        onBottomPageChanged: {
            setBottomMenu();
        }
    }



    function setBottomMenu(){
        switch(subqmlIntegrator.bottomPage){
        case 0:
            _lbl_bottomItem0.text = " Basic";
            _lbl_bottomItem1.text = " Pulser";
            _lbl_bottomItem2.text = " Receiver";
            _lbl_bottomItem3.text = "Gate A";
            _lbl_bottomItem4.text = "Gate B";
            break;
        case 1:
            _lbl_bottomItem0.text = " Material";
            _lbl_bottomItem1.text = " Probe";
            _lbl_bottomItem2.text = " AutoCal";
            _lbl_bottomItem3.text = " EVAL";
            _lbl_bottomItem4.text = " Display";
            break;
        case 2:
            _lbl_bottomItem0.text = " Alarms";
            _lbl_bottomItem1.text = " Memory";
            _lbl_bottomItem2.text = " Misc";
            _lbl_bottomItem3.text = " Settings";
            _lbl_bottomItem4.text = " Snapshots";
            break;
        }
    }




    RowLayout {
        id: _frm_bottom
        anchors.top: parent.top
        anchors.topMargin: -5
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        spacing: 10

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        Rectangle {
            id: _rectangle11
            x: 84
            width: 20
            color: THEME.leftRightArrowBg
            Layout.maximumWidth: 20
            Layout.minimumWidth: 20
            Layout.preferredWidth: 20
            Layout.fillHeight: true
            //            border.width: 0
            Layout.maximumHeight: 200
            Layout.minimumHeight: 0
            Layout.preferredHeight: 20
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Label{
                id:_lbl_prevPageInd
                text: "\u25c4"
                color: THEME.leftRightArrowFg
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent

            }
        }

        Button {
            id: _rectangle12
            x: 84
            width: 141
            Material.background: (subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE === subqmlIntegrator.bottomPage &&  selectedPageIndex === 0)? THEME.tabFg:THEME.tabBg
            Layout.fillHeight: true
            Layout.preferredHeight: 20
            Layout.maximumHeight: 1000
            Layout.fillWidth: true
            Layout.minimumHeight: 20
            //            border.width: 0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            hoverEnabled: false
            Label {
                id: _lbl_bottomItem0
                text: " Basic"

                font.family: "Themify"
                color:  (subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE === subqmlIntegrator.bottomPage &&  selectedPageIndex === 0)? THEME.tabBg:THEME.tabFg
                font.pointSize: 16

                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
//                MouseArea{
//                    anchors.fill:parent
//                    onClicked: selectedPageIndex
//                }
            }

        }
        Button {
            id: _rectangle13
            x: 84
            width: 141
            Material.background: (Math.floor(subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE) === subqmlIntegrator.bottomPage &&  selectedPageIndex === 1)? THEME.tabFg:THEME.tabBg
            Layout.fillHeight: true
            Layout.preferredHeight: 20
            Layout.maximumHeight: 1000
            Layout.fillWidth: true
            Layout.minimumHeight: 20
            //            border.width: 0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            hoverEnabled: false
            Label {
                id: _lbl_bottomItem1
                text: " Pulser"
                font.family: "Themify"
                font.pointSize: 16
                color: (Math.floor(subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE) === subqmlIntegrator.bottomPage &&  selectedPageIndex === 1)? THEME.tabBg:THEME.tabFg
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
        Button {
            id: _rectangle14
            x: 84
            width: 141
            Material.background: (Math.floor(subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE) === subqmlIntegrator.bottomPage &&  selectedPageIndex === 2)? THEME.tabFg:THEME.tabBg
            Layout.fillHeight: true
            Layout.preferredHeight: 20
            Layout.maximumHeight: 1000
            Layout.fillWidth: true
            Layout.minimumHeight: 20
            //            border.width: 0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            hoverEnabled: false
            Label {
                id: _lbl_bottomItem2
                text: " Receiver"
                font.family: "Themify"
                color: (Math.floor(subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE) === subqmlIntegrator.bottomPage &&  selectedPageIndex === 2)? THEME.tabBg:THEME.tabFg
                font.pointSize: 16
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Button {
            id: _rectangle15
            x: 84
            width: 141
            Material.background: (Math.floor(subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE) === subqmlIntegrator.bottomPage &&  selectedPageIndex === 3)? THEME.tabFg:THEME.tabBg
            Layout.preferredHeight: 20
            Layout.fillHeight: true
            Layout.maximumHeight: 1000
            //            border.width: 0
            Layout.minimumHeight: 20
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            hoverEnabled: false
            Label {
                id: _lbl_bottomItem3
                text: "Gate A"
                font.family: "Themify"
                color:(Math.floor(subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE) === subqmlIntegrator.bottomPage &&  selectedPageIndex === 3)? THEME.tabBg:THEME.tabFg
                font.pointSize: 16
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
        Button {
            id: _rectangle16
            x: 84
            width: 141
            Material.background: (Math.floor(subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE) === subqmlIntegrator.bottomPage &&  selectedPageIndex === 4)? THEME.tabFg:THEME.tabBg
            Layout.preferredHeight: 20
            Layout.fillHeight: true
            Layout.maximumHeight: 1000
            //            border.width: 0
            Layout.minimumHeight: 20
            Layout.fillWidth: true
            Material.elevation: 5
            hoverEnabled: false
            Label {
                id: _lbl_bottomItem4
                text: "Gate B"
                font.family: "Themify"
                color: (Math.floor(subqmlIntegrator.bottomIndex/ _common.cBTM_ITEMS_PER_PAGE) === subqmlIntegrator.bottomPage &&  selectedPageIndex === 4)? THEME.tabBg:THEME.tabFg
                font.pointSize: 16
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            id: _rectangle17
            x: 84
            width: 141
            color: THEME.leftRightArrowBg
            Layout.maximumWidth: 20
            Layout.minimumWidth: 20
            Layout.preferredWidth: 20
            Layout.fillHeight: true
            Layout.preferredHeight: 20
            Layout.maximumHeight: 2000
            border.width: 0
            Layout.minimumHeight: 0
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Label{
                id : _lbl_nextPageInd
                text: "\u25ba"
                color: THEME.leftRightArrowFg
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }
    }


}





/*##^## Designer {
    D{i:4;anchors_height:60;anchors_width:800;anchors_x:0;anchors_y:0}
}
 ##^##*/
