import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
import QtQuick.Controls.Material 2.0


    ElevatedPane {
        id: rectangle
        width: 141
        height: 80
        property real step:0
        property int titleStartingX: 20
//         "#ffffff"
        //border.width: 2
        property string name: ""
        property string unit: ""
        property bool selected: false
        property var type
        Material.background: selected?THEME.paramSelectedBg:THEME.paramBg
        Binding{target: _lbl_unit; property:"text";       value:rectangle.unit}
        Binding{target: _lbl_unit; property:"color";       value:selected?THEME.unitSelected:THEME.unit}
//        Binding{target: rectangle; property:"Material.background";       value:selected?THEME.paramSelectedBg:THEME.paramBg}
//        Binding{target: rectangle; property:"border.color";       value:selected?THEME.paramNameSelected:THEME.paramName}
        Label {
            id: _lbl_unit
            x: 0
            width: 45
            height: parent.height/2
            text: ""
            font.pointSize: 14
            font.family: "OpenSans"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

        }

        function up(){}
        function down(){}
        function onEnterPressed(){}
        function onDeletePressed(){}
        function onReselect(){}

    }

