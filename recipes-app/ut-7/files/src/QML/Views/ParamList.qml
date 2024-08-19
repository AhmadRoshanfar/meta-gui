import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
ParamBase {
    id:_paramList_
    property var model:[]
    property int value :0
    type:Enums.PARTYP_LIST


    Binding{target: _lbl_param; property:"text";       value:_paramList_.name}
//    Binding{target: _lbl_value; property:"text";       value:model[value]}
    Binding{target: _lbl_param; property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    Binding{target: _lbl_value; property:"color";       value:selected?THEME.valueSelected:THEME.value}



    function up(){
        if(value==model.length-1)
            return;
        value++;
    }

    function down(){
        if(value==0)
            return;
        value--;
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
        text:isUndefined(model[value])?"":model[value]
//        text:isUndefined(model[value])?text:model[value]
        width: parent.width-50
        height: parent.height/2
        minimumPointSize: 8
        fontSizeMode: Text.Fit
        font.family: "Square721 BT"
        font.pointSize: 14
        font.bold: true
        anchors.top: _lbl_param.bottom
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
    }
}
