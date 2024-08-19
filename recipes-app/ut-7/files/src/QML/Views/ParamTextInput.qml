import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
import DateAdaptor 1.0

ParamBase {
    id:_textInputParam_


//    property int idx: 0
    property int cursor: 0
    property var value
    property var text: "          "
    property var array: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    property int maxLength: 20
    type:Enums.PARTYP_TIME
        property var charSet: [' ', 'a' , 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '#', '_', '.' , '*']
    property var name: ""
    Binding{target: _lbl_value;     property:"text";        value:_textInputParam_.text}
    Binding{target: _lbl_param;     property:"text";        value:_textInputParam_.name}
    Binding{target: _lbl_param;     property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    Binding{target: _lbl_value;     property:"color";       value:selected?THEME.valueSelected:THEME.value}
    Binding{target: _lbl_indicator; property:"color";       value:selected?THEME.paramBg:THEME.paramFg}



//    function onEnterPressed(){
//        if(sure){
//            setDateTime()
//            sure = false
//        }
//        else{
//            sure = true;
//        }
//    }

    function cursorRedraw(){
        _lbl_value.text = text.substring(0,cursor)
        _lbl_indicator.anchors.leftMargin = _lbl_value.width
        _lbl_indicator.text = "▬"
        _lbl_value.text = text
    }

    function onReselect(){
        cursor = (cursor+1)%maxLength;
        cursorRedraw()
    }



    function setTextChars(){
        for(var i = 0; i < Math.min(text.length,maxLength); i++){
            var ch = text.charAt(i)
            array[i] = 0;
            for(var j = 0; j < charSet.length; j++){
                if(ch === charSet[j]){
                    array[i] = j
                    break
                }
            }
        }
    }


    property bool isChanging: false
//    onValueChanged: {
//        if(isChanging === false)
//            return;
//        isChanging = true;
//        if(value<minValue)
//            value = minValue;
//        if(value>maxValue)
//            value = maxValue;
//        isChanging = false;
//    }

    function reset(){
        for(var i = 0; i < maxLength; i++){
            array[i] = 0
        }
        textRefresh()
        cursor = 0
        cursorRedraw()
    }

    function up(){
        array[cursor] = (array[cursor]+1) % charSet.length
        textRefresh()
    }

    function down(){
        array[cursor] = (array[cursor]+charSet.length-1) % charSet.length
        textRefresh()
    }

    function textRefresh(){
        text = ""
        for(var i = 0; i < maxLength; i++){
            text = text.concat(charSet[array[i]])
        }
    }




    Label {
        id: _lbl_param
        x: titleStartingX
        y: 0
        width: parent.width-titleStartingX
        height: parent.height/2
        text: "-------------"
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft

    }
    TextInput {
        id: _lbl_value
        enabled: false
        height: parent.height/2
        text: "00:00:00"
        anchors.left: parent.left
        anchors.leftMargin: 5
        autoScroll: false
        font.family: "Roboto Mono"
        font.pointSize: 11
        font.bold: true
        anchors.top: _lbl_param.bottom
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft

    }

    TextInput {
        id: _lbl_indicator
        y: 240
        height: parent.height/2
        text: "\u25ac"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: _lbl_value.left
        anchors.leftMargin: 0
        anchors.topMargin: 10
        horizontalAlignment: Text.AlignLeft
        font.pointSize: 6
        font.family: "Square721 BT"
        enabled: false
        anchors.top: _lbl_param.bottom
        autoScroll: false
        verticalAlignment: Text.AlignVCenter
    }
}

































/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:7;anchors_x:0}D{i:8;anchors_width:590;anchors_x:0}
}
 ##^##*/
