import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
import DateAdaptor 1.0

ParamBase {
    id:_timeParam_
    property bool sure: false

    property int min:0
    property int hour: 0
    property int sec: 0
    property int idx: 0
    property var value
    type:Enums.PARTYP_TIME
    Binding{target: _lbl_value; property:"text";        value:_timeParam_.value}
    Binding{target: _lbl_param; property:"text";        value:sure? "Sure?":_timeParam_.name}
    Binding{target: _lbl_param; property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    Binding{target: _lbl_value; property:"color";       value:selected?THEME.valueSelected:THEME.value}
    Binding{target: _timeParam_;property: "value";       value:zeroPad(hour)+":"+zeroPad(min)+":"+zeroPad(sec)}
    Binding{target: _lbl_indicator; property:"color";       value:selected?THEME.paramBg:THEME.paramFg}

    onSelectedChanged: sure = false

    function reset(){
        hour = _dateAdaptor.currentHour();
        min = _dateAdaptor.currentMin();
        sec = _dateAdaptor.currentSec();
    }

    function onEnterPressed(){
        if(sure){
            setDateTime()
            sure = false
        }
        else{
            sure = true;
        }
    }

    function onReselect(){
        idx = (idx+1)%3;
        switch(idx){
        case 0: _lbl_indicator.text = "▬▬ "
            break;
        case 1: _lbl_indicator.text = "▬▬          "
            break;
        case 2: _lbl_indicator.text = "▬▬                    "
            break;
        }
        sure = false
    }

    function zeroPad(num) {
      return num>9?""+num:"0"+num;
    }

    DateAdaptor{
        id:_dateAdaptor
    }

    Component.onCompleted:{
        reset()
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

    function up(){
        switch(idx){
        case 0:
            sec = (sec+1)%60;
            break;
        case 1:
            min = (min+1)%60;
            break;
        case 2:
            hour = (hour+1)%24;
            break;
        }
    }

    function down(){
        switch(idx){
        case 0:
            sec = (60+sec-1)%60;
            break;
        case 1:
            min = (60+min-1)%60;
            break;
        case 2:
            hour = (24+hour-1)%24;
            break;
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
        x: 0
        enabled: false
        width: parent.width-50
        height: parent.height/2
        text: "00:00:00"
        autoScroll: false
        font.family: "Square721 BT"
        font.pointSize: 14
        font.bold: true
        anchors.top: _lbl_param.bottom
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight

    }

    TextInput {
        id: _lbl_indicator
        x: 0
        y: 240
        width: parent.width-50
        height: parent.height/2
        text: "▬▬"
        anchors.topMargin: 10
        horizontalAlignment: Text.AlignRight
        font.pointSize: 8
        font.family: "Square721 BT"
        enabled: false
        anchors.top: _lbl_param.bottom
        autoScroll: false
        verticalAlignment: Text.AlignVCenter
    }
}

















/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
