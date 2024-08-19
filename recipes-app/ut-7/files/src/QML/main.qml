/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.2
import QtQuick.Layouts 1.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Universal 2.2
import QtQuick.Controls.Material 2.0
import QtQuick.Window 2.0
import Enums 1.0

import AScanAdaptor 1.0
import SettingsAdaptor 1.0
import SnapshotAdaptor 1.0
import AlarmAdaptor 1.0
import FaultCalcAdaptor 1.0
import PresParamsAdaptor 1.0
import USBDeviceAdaptor 1.0
import BatteryAdaptor 1.0

import "Views"
import "Pages"


Rectangle {
    id: window
    width: 800
    height: 480
    visible: true

//    flags: Qt.FramelessWindowHint
//    background:  Rectangle {
        color: THEME.appBg
//    }
//    onClosing:  {
//        qmlIntegrator.started = false
//        console.log("closing")
//    }

    //    title: "UT Desktop"


    /*********************************************************************************/
//    property var theme :_themeDefault
//    ThemeModel{
//        id:_themeDefault
//        appBg:"#dddddd"//"#7f8c8d"
//        paramBg:"white"
//        paramName:"black"
//        paramSelectedBg:"black"
//        paramNameSelected:"white"
//        unit:"black"
//        unitSelected:"white"
//        value:"red"
//        valueSelected:"red"
//        tabBg:"white"
//        tabFg:"black"
//        topResName:"red"
//        topResValue:"black"
//        botResName:"red"
//        botResValue:"black"
//        chartBg:"white"
//        chartMain:"black"
//        chartMarker:"darkorange"
//        chartEnvelope:"yellow"
//        chartAxis:"black"
//        chartGrid: "#cccccc"
//        topBarBg:"white"
//        chartTopBarBg:"white"
//        bottomBarBg:"white"
//        downArrowBg:"white"
//        downArrowFg:"black"
//        leftRightArrowBg:"#dddddd"
//        leftRightArrowFg:"black"
//    }
    /*********************************************************************************/
    SnapshotAdaptor{
        id:_snapshotAdaptor
    }


    SettingsAdaptor{
        id:_settingsAdaptor
    }


    FaultCalcAdaptor{
        id: _faultCalcAdaptor
    }


    AlarmAdaptor{
        id:_alarmAdaptor
    }


//    AScanAdaptor{
//        id:_ascanAdaptor
//    }


    PresParamsAdaptor{
        id:_presParamsAdaptor
    }



    USBDeviceAdaptor{
        id: _USBDeviceAdaptor
    }

    BatteryAdaptor{
        id: _batteryAdaptor
    }
    /*********************************************************************************/


    /*********************************************************************************/




    /*********************************************************************************/


    /*********************************************************************************/




    function saveChart(){
        _chart_AScan.grabToImage(function(result) {
            _snapshotAdaptor.checkDir();
            result.saveToFile("snapshots/"+Qt.formatDateTime(new Date(), "yyyyMMdd_hhmmss")+".png");
        });
    }


    function showSnapshot(filename){
        _chart_AScan.visible =false;
        _img_snapshot.visible = true;
        _img_snapshot.source = filename;
    }

    function hideSnapshot(){
        _img_snapshot.visible = false;
        _chart_AScan.visible =true;
    }

    function longPressed(idx){
        console.log("long pressed "+idx);
        pagesList[subqmlIntegrator.bottomIndex].longPressed(idx);
    }









    /*********************************************************************************/

    Binding{target: _pane_bottom;   property:"visible";         value:subqmlIntegrator.bottombarVisible}
    Binding{target: _pane_bottom;   property:"height";         value:subqmlIntegrator.bottombarVisible?40:0}
//    Binding{target: _chart_AScan;   property:"grid";            value:qmlIntegrator.grid}





    /*********************************************************************************/
    Component.onCompleted: {
        //        qmlIntegrator.started = true;
//        console.log(aaaa)

    }

    MainRight {
        id: _pane_right
        width: 200
        anchors.bottom: _pane_bottom.top
        anchors.bottomMargin: 10
        anchors.top: _pane_top.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 7
//        background: Rectangle{
//            color:  theme.appBg
//        }
    }

    MainBottom{
        id:_pane_bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0

    }





    MainTop {
        id: _pane_top
        height: 40
//        topPadding: 0
//        bottomPadding: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
//        padding: 0
        Layout.maximumHeight: 40
        Layout.minimumHeight: 40
        Layout.preferredHeight: 40
        Layout.fillWidth: true
        Material.background: THEME.chartTopBarBg






    }

    Image{
        id:_img_snapshot
        anchors.left: _chart_AScan.left
        anchors.right: _chart_AScan.right
        anchors.top: _chart_AScan.top
        anchors.bottom: _chart_AScan.bottom
        visible: false
    }

    Item{
        id:_chart_AScan
        anchors.right: _pane_right.left
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: _pane_bottom.top
        anchors.bottomMargin: 0
        anchors.top: _pane_top.bottom
        anchors.topMargin: 0
//        margins.bottom: 0
//        margins.right: 0
//        margins.top: 0
//        margins.left: 0
        Component.onCompleted: {axisYMin = (qmlIntegrator.polarity === Enums.POL_RF)?-100:0}
    }


}

















