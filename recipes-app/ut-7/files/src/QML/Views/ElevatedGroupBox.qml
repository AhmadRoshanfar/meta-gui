import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0


ElevatedPane{
    id: elevatedPane
    property color titlebarBackground: "black"
    property color titlebarForeground: "white"
    property string title: ""
    topPadding: 0

    Rectangle{
        id:_titlebar
        height: 40
//        Material.accent:  titlebarBackground
        color: titlebarBackground
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        border.width: 0
    }
    Label{
        id:_title
        text: title
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.verticalCenter: _titlebar.verticalCenter
        color: titlebarForeground
    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
