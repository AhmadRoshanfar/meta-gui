import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
ParamBase {
    id:_doubleParam_
    property real minValue
    property real maxValue
    property real value:0
    property var defaultValues:[]
    property var stepsList:[1]
    property int stepIndex:0
    type:Enums.PARTYP_DOUBLE
    step:stepsList[stepIndex]
    Binding{target: _lbl_value; property:"text";       value:_doubleParam_.value.toFixed(2)}
    Binding{target: _lbl_param; property:"text";       value:_doubleParam_.name}
    Binding{target: _lbl_param; property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    Binding{target: _lbl_value; property:"color";       value:selected?THEME.valueSelected:THEME.value}

    function toFixed2(val){
        return Math.round((val*100))/100.0;
    }

    function onEnterPressed(){
        nextDefault();
    }

    onMinValueChanged: {
        if(value<minValue)
            value = minValue;
    }

    onMaxValueChanged: {
        if(value>maxValue)
            value = maxValue;
    }

    property bool isChanging: false
    onValueChanged: {
        if(isChanging === false)
            return;
        isChanging = true;
        if(value<minValue)
            value = minValue;
        if(value>maxValue)
            value = maxValue;
        isChanging = false;
    }

    function up(){
        if(!_doubleParam_.visible)
            return
        if(value+stepsList[stepIndex]<=maxValue)
            value= toFixed2(value +stepsList[stepIndex]);
    }

    function down(){
        if(!_doubleParam_.visible)
            return
        if(value-stepsList[stepIndex]>=minValue)
            value= toFixed2(value - stepsList[stepIndex]);
    }
    function nextDefault(){
        if(!_doubleParam_.visible)
            return
        if(isUndefined(defaultValues))
            return;
        if(value>=defaultValues[defaultValues.length-1]){
            if(defaultValues[0]<=maxValue && defaultValues[0]>=minValue)
            value = defaultValues[0];
            return;
        }
        for(var i = 0; i< defaultValues.length;i++){
            if(defaultValues[i]>value && defaultValues[i]<=maxValue && defaultValues[i]>=minValue){
                value = defaultValues[i];
                break;
            }
        }
    }

    function prevDefault(){
        if(!_doubleParam_.visible)
            return
        for(var i = 0; i< defaultValues.length;i++){
            if(defaultValues[i]>value){
                value = defaultValues[i];
                break;
            }
        }
    }

    function nextStep(){
        if(!_doubleParam_.visible)
            return
        stepIndex = (stepIndex+1)%stepsList.length;
        qmlIntegrator.paramStep = stepsList[stepIndex];
    }


    Label {
        id: _lbl_param
        x: titleStartingX
        y: 0
        width: parent.width-titleStartingX
        height: parent.height/2
        text: "-------------"
        fontSizeMode: Text.HorizontalFit
        font.family: "Themify"
        minimumPointSize: 6
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        visible:_doubleParam_.visible

    }
    TextInput {
        id: _lbl_value
        x: 0
        enabled: false
        width: _doubleParam_.visible? parent.width-50:0
        height: parent.height/2
        text: "-------------"
        font.family: "Square721 BT"
        font.pointSize: 14
        font.bold: true
        anchors.top: _lbl_param.bottom
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        validator:DoubleValidator{
            top: maxValue
            bottom: minValue
            decimals: 2
        }
    }
}
