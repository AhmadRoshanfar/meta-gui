import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import SideMenuAdaptor 1.0
ColumnLayout {
    id: _frm_options
    width: 200
    height: 380
    spacing: 2
SideMenuAdaptor{
    id:_sideMenuAdaptor
}




    Label{
        text: "\u2303"
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignHCenter
        anchors.top: _frm_topbar.bottom
        anchors.topMargin: 0
        anchors.bottom: _frm_bottom.top
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        Layout.maximumHeight: 20
        Layout.minimumHeight: 20
        Layout.preferredHeight: 20
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        background: Rectangle {
            color: "lightGray"
        }
    }



    Rectangle {
        id: rectangle3
        x: 84
        width: 141

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        border.width: 1
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }
    Rectangle {
        id: rectangle4
        x: 84
        width: 141

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
        border.width: 1
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    Rectangle {
        id: rectangle5
        x: 84
        width: 141

        Layout.preferredHeight: 20
        Layout.fillHeight: true
        Layout.maximumHeight: 1000
        border.width: 1
        Layout.minimumHeight: 20
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    Label{
        id:_lbl_down
        text: "\u2304"
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignHCenter
        Layout.preferredHeight: 20
        Layout.maximumHeight: 20
        Layout.minimumHeight: 20
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
        background: Rectangle {
            color: "lightGray"
        }
    }

}


/*##^## Designer {
    D{i:4;anchors_y:0}
}
 ##^##*/
