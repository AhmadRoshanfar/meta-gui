import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Enums 1.0

import "../Views"


PageBase {
    id: _page_eval

    itemsList: [_param_evalMode,_param_points,_param_astart,_param_evalActive,_param_aws_table,_param_tcorr,_param_empty1,_param_empty2]

    Binding{target: _param_astart;  property:"value";               value:getLengthWithUnit(qmlIntegrator.gateAStart)}
    Binding{target: _param_astart; property: "unit";value: qmlIntegrator.unit === Enums.UNIT_INCH ? "inch":qmlIntegrator.unit === Enums.UNIT_US?"μs":"mm"}



    //    Timer {
    //        id: timer
    //        function setTimeout(cb, delayTime) {
    //            timer.interval = delayTime;
    //            timer.repeat = false;
    //            timer.triggered.connect(cb);
    //            timer.triggered.connect(function release () {
    //                timer.triggered.disconnect(cb); // This is important
    //                timer.triggered.disconnect(release); // This is important as well
    //            });
    //            timer.start();
    //        }
    //    }


    //    Component.onCompleted: {
    //        _param_evalMode.value = Enums.EVAL_TCG;
    //        timer.setTimeout(function(){
    //            qmlIntegrator.gateAStart = 50;
    //            timer.setTimeout(function(){
    //                _param_points.onEnterPressed();
    //                qmlIntegrator.gateAStart = 63;
    //                timer.setTimeout(function(){
    //                    _param_points.onEnterPressed();
    //                    qmlIntegrator.gateAStart = 76;
    //                    timer.setTimeout(function(){
    //                        _param_points.onEnterPressed();
    //                    }, 500);
    //                }, 500);
    //            }, 500);
    //        },500);
    //    }



    Binding{target: qmlIntegrator; property:"evaluationMode";   value:_param_evalMode.value}
    Binding{target: _param_evalMode; property:"value";  value:qmlIntegrator.evaluationMode}

    Binding{target: qmlIntegrator; property:"evaluationPointIndex";value:_param_points.value}
    Binding{target: _param_points; property:"value";value:qmlIntegrator.evaluationPointIndex}

    Binding{target: qmlIntegrator; property:"activated";        value:_param_evalActive.value}
    Binding{target: _param_evalActive; property:"value";        value:qmlIntegrator.activated}

    Binding{target: qmlIntegrator; property:"tcorr";        value:_param_tcorr.value}
    Binding{target: _param_tcorr; property:"value";        value:qmlIntegrator.tcorr}

    Binding{target: qmlIntegrator;  property:"evaluationPoints";          value:_param_points.model}
    Binding{target: _param_points;  property:"model";               value:qmlIntegrator.evaluationPoints}

    Binding{target: _param_aws_table; property: "value";value: qmlIntegrator.awsTable}
    Binding{target: qmlIntegrator;      property:"awsTable";      value:_param_aws_table.value}

    Binding{target: _param_astart; property:"stepIndex";      value:qmlIntegrator.classStep1}
    Binding{target: qmlIntegrator; property:"classStep1";       value:_param_astart.stepIndex}

    Binding{target: _param_tcorr; property:"stepIndex";      value:qmlIntegrator.classStep3}
    Binding{target: qmlIntegrator; property:"classStep3";       value:_param_tcorr.stepIndex}

    ParamEnum {
        id: _param_evalMode
        name: "Mode"
        Layout.topMargin: 5
        dictionary:{"Off":Enums.EVAL_NORMAL,"DAC":Enums.EVAL_DAC,"TCG":Enums.EVAL_TCG,"AWS":Enums.EVAL_AWS/*,"DGS":Enums.EVAL_DGS*/}


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamList {
        id: _param_points
        name: sure?"Delete?":"Points"
        property bool sure: false
        Layout.topMargin: 5


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop



        function onEnterPressed(){
            if(sure){
                evaluationAdaptor.removePoint();
                sure = false;
            }
            else
                evaluationAdaptor.getPosition();

        }
        function onDeletePressed(){
            if(_param_points.model.length > 0)
                sure = true
        }
        onSelectedChanged: sure = false
        onValueChanged:  sure =false
    }

    ParamDouble {
        id: _param_astart
        name: "A-Start"
        Layout.topMargin: 5
        minValue: getLengthWithUnit(0)
        maxValue: qmlIntegrator.UIRangeMax
        unit:"mm"
        stepsList: classSteps1
        onValueChanged: {
            qmlIntegrator.gateAStart = getLengthMM(_param_astart.value);
        }

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }
    ParamBool {
        id: _param_evalActive
        name: "Active"
        Layout.topMargin: 5

        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamEnum{
        id:_param_aws_table
        name: "AWS Table"

        dictionary:{"M1":Enums.AT_M1,"M2":Enums.AT_M2}
        Layout.topMargin: 5
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }

    ParamDouble {
        id: _param_tcorr
        name: "T.Corr"
        Layout.topMargin: 5
        minValue: 0
        maxValue: 60
        unit: "dB"
        stepsList: classSteps3


        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20

        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    }
    ParamBase{
        id:_param_empty1
        Layout.topMargin: 5
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
    }
    ParamBase{
        id:_param_empty2
        Layout.topMargin: 5
        Layout.fillHeight: true
        Layout.preferredHeight: 20
        Layout.maximumHeight: 1000
        Layout.fillWidth: true
        Layout.minimumHeight: 20
    }


}
