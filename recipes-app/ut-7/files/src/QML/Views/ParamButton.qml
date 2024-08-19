import QtQuick 2.0
import QtQuick.Controls 2.0
import Enums 1.0
ParamBase {
    id:_intParam_
    property int minValue
    property int maxValue
    property int value:0
    property var defaultValues
    property bool sure: false
    property bool twoStepMode: false
    type:Enums.PARTYP_BTN
    Binding{target: _lbl_param; property:"text";       value:twoStepMode?(sure?"Sure?":_intParam_.name):_intParam_.name}
    Binding{target: _lbl_param; property:"color";       value:selected?THEME.paramNameSelected:THEME.paramName}
    onSelectedChanged: {
        if(twoStepMode)
            sure = false
    }

    Label {
        id: _lbl_param
        x: 0
        y: 0
        anchors.fill:parent
        text: "-------------"
        font.pointSize: 14
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

    }


}





/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
