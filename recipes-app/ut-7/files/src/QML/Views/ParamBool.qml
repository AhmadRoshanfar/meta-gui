import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
ParamBase {
    id:_paramBool_
    property bool value :false
        type:Enums.PARTYP_BOOL


    Binding{target: _lbl_param; property:"text";       value:_paramBool_.name}
//    Binding{target: _lbl_value; property:"text";       value:value?"on":"off"}
    Binding{target: _lbl_param; property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    Binding{target: _lbl_value; property:"color";       value:selected?THEME.valueSelected:THEME.value}


    function up(){
        value = !value;
    }

    function down(){
        value = !value;
    }


    Label {
        id: _lbl_param
        x: titleStartingX
        y: 0
        width: parent.width-titleStartingX
        height: parent.height/2
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft

    }
    Label {
        id: _lbl_value
        x: 0
        font.family: "Square721 BT"
        width: parent.width-50
        height: parent.height/2
        font.pointSize: 14
        font.bold: true
        anchors.top: _lbl_param.bottom
        anchors.topMargin: 0
        text :value?"on":"off"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
    }
}
