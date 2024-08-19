import QtQuick 2.0
import QtQuick.Controls 2.0
ParamBase {
    id:_paramEnum_
    property var defaultValues:Object.keys(dictionary)
    property var dictionary:{"":""}
    property string currentText
    property var value :0
    Component.onCompleted: {
        find();
    }

    onValueChanged: {
        find();
    }

    onCurrentTextChanged: {
        value = dictionary[currentText];
    }
    Binding{target: _lbl_param; property:"text";       value:_paramEnum_.name}
    Binding{target: _lbl_value; property:"text";       value:currentText}
    Binding{target: _lbl_param; property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    Binding{target: _lbl_value; property:"color";       value:selected?THEME.valueSelected:THEME.value}

    function find(){
        const keys = Object.keys(dictionary);
        for(var i = 0; i<keys.length;i++){
            if(dictionary[keys[i]] === value){
                currentText = keys[i];
            }
        }
    }

    function up(){
        const keys = Object.keys(dictionary);
        var i = keys.indexOf(currentText);
        currentText = keys[(i+1)%keys.length];
    }

    function down(){
        const keys = Object.keys(dictionary);
        var i = keys.indexOf(currentText);
        currentText = keys[(keys.length+i-1)%keys.length];
    }


    Label {
        id: _lbl_param
        x: titleStartingX
        y: 0
        width: parent.width-titleStartingX
        height: parent.height/2
        fontSizeMode: Text.HorizontalFit
        minimumPointSize: 6
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft

    }
    Label {
        id: _lbl_value
        x: 0
        width: parent.width-50
        height: parent.height/2
        font.pointSize: 14
        font.family: "Square721 BT"
        font.bold: true
        fontSizeMode: Text.HorizontalFit
        minimumPointSize: 6
        anchors.top: _lbl_param.bottom
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
    }
}
