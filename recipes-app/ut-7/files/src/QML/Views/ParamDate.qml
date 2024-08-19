import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
import DateAdaptor 1.0
ParamBase {
    id:_dateParam_
    property int year:0
    property int mon: 0
    property int day: 0
    property int idx: 0
    property bool sure: false

    property var _date:_dateAdaptor.now()
    on_DateChanged: {
        year = _date.getFullYear()
        mon = _date.getMonth()+1
        day = _date.getDate()
    }
    function reset(){
        _date=_dateAdaptor.now()
    }

    type:Enums.PARTYP_DATE
    Binding{target: _lbl_value; property:"text";       value:zeroPad(_date.getFullYear())+"/"+zeroPad(_date.getMonth()+1)+"/"+zeroPad(_date.getDate())}
    Binding{target: _lbl_param; property:"text";        value:sure? "Sure?":_dateParam_.name}
    Binding{target: _lbl_param; property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    Binding{target: _lbl_value; property:"color";       value:selected?THEME.valueSelected:THEME.value}
    Binding{target: _lbl_indicator; property:"color";       value:selected?THEME.paramBg:THEME.paramFg}

    onSelectedChanged: sure = false

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

    Component.onCompleted: _date= _dateAdaptor.now()

    //    property bool isChanging: false
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
            _date = _dateAdaptor.nextDay();
            break;
        case 1:
            _date = _dateAdaptor.nextMonth();
            break;
        case 2:
            _date = _dateAdaptor.nextYear();
            break;
        }
        //        _lbl_value.text =  _date.getFullYear()+"/"+(_date.getMonth()+1)+"/"+(_date.getDate());
        //        console.log(Qt.formatDateTime(_date, "yyyyMMdd_hhmmss"));
    }

    function down(){
        switch(idx){
        case 0:
            _date = _dateAdaptor.previousDay();
            break;
        case 1:
            _date = _dateAdaptor.previousMonth();
            break;
        case 2:
            _date = _dateAdaptor.previousYear();
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
