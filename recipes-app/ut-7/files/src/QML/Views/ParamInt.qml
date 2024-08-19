import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
ParamBase {
    id:_intParam_
    property int minValue:-10000000
    property int maxValue:10000000
    property int value:0
    property var defaultValues
    property var stepsList:[1]
    property int stepIndex:0
    type:Enums.PARTYP_INT
    step:stepsList[stepIndex]
    Binding{target: _lbl_value; property:"text";       value:_intParam_.value}
    Binding{target: _lbl_param; property:"text";       value:_intParam_.name}
    Binding{target: _lbl_param; property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    Binding{target: _lbl_value; property:"color";       value:selected?THEME.valueSelected:THEME.value}

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
        if(value+step<=maxValue)
            value+=step;
    }

    function down(){
        if(value-step>=minValue)
            value-=step;
    }

    function nextDefault(){
        if(isUndefined(defaultValues))
            return;
        if(value>=defaultValues[defaultValues.length-1]){
            value = defaultValues[0];
            return;
        }
        for(var i = 0; i< defaultValues.length;i++){
            if(defaultValues[i]>value){
                value = defaultValues[i];
                break;
            }
        }
    }

    function prevDefault(){
        for(var i = 0; i< defaultValues.length;i++){
            if(defaultValues[i]>value){
                value = defaultValues[i];
                break;
            }
        }
    }

    function nextStep(){
        stepIndex = (stepIndex+1)%stepsList.length;
        qmlIntegrator.paramStep = stepsList[stepIndex];

    }

    Label {
        id: _lbl_param
        x: titleStartingX
        y: 0
        width: parent.width-titleStartingX
        height: parent.height/2
        fontSizeMode: Text.HorizontalFit
        minimumPointSize: 6
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
        text: "-------------"
        font.family: "Square721 BT"
        font.pointSize: 14
        font.bold: true
        anchors.top: _lbl_param.bottom
        anchors.topMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        validator:IntValidator{
            top: maxValue
            bottom: minValue
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
