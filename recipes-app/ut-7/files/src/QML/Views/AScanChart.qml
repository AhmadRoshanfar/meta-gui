/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtCharts 2.0
import FaultCalcAdaptor 1.0
import AScanAdaptor 1.0

//![1]

ChartView {
    id: chartView
    animationOptions: ChartView.NoAnimation
    backgroundColor:  window.theme.chartBg
//    theme: ChartView.ChartThemeBrownSand
    legend.visible: false
    antialiasing:true
    property bool openGL: true
    property real axisXMin:0
    property real axisXMax:100
    property int axisYMin:0
    property int axisYMax:1000
    property bool grid: true
    Binding{target: axisX; property:"min";value:axisXMin}
    Binding{target: axisX; property:"max";value:axisXMax}
    Binding{target: axisY; property:"min";value:axisYMin}
    Binding{target: axisY; property:"max";value:axisYMax}

    //    Binding{target: axisY; property:"min";value:qmlIntegrator.stripAxisYMin}
    //    Binding{target: axisY; property:"max";value:qmlIntegrator.stripAxisYMax}
    ValueAxis {
        id: axisX
        tickCount: 6
        gridVisible: grid

        gridLineColor: window.theme.chartGrid
//        minorTickCount: 5
        lineVisible: true
        minorGridVisible: false
        //        tickAnchor: 99
        //        tickType: ValueAxis.TicksDynamic
        color: window.theme.chartAxis
        labelsColor: window.theme.chartAxis
    }

//    ValueAxis{
//        id: axisX50
//        tickCount: 11
//        gridVisible: grid
//        minorTickCount: 10
//        minorGridVisible: false

//        //        tickAnchor: 99
//        //        tickType: ValueAxis.TicksDynamic
//        color: "white"
//    }

    ValueAxis {
        id: axisY
        tickCount: 6
        gridLineColor: window.theme.chartGrid
        minorTickCount: 5
        minorGridVisible: false
        gridVisible: grid
        color: window.theme.chartAxis
        labelsColor: window.theme.chartAxis
        labelFormat:"%d"
    }



    LineSeries {
        id: _series_main
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        color: window.theme.chartMain
    }

    LineSeries {
        id: _series_AOverlay
        //        axisX: axisX
        //        axisY: axisY
        useOpenGL: chartView.openGL
        color: "red"

    }
    LineSeries {
        id: _series_BOverlay
        //        axisX: axisX
        //        axisY: axisY
        useOpenGL: chartView.openGL
        color: "green"
    }
    LineSeries {
        id: _series_gateA
        //        axisX: axisX
        //        axisY: axisY
        useOpenGL: chartView.openGL
        color: "red"
        opacity: 0.5
        width: 3
    }
    LineSeries {
        id: _series_gateB
        //        axisX: axisX
        //        axisY: axisY
        useOpenGL: chartView.openGL
        color: "green"
        opacity: 0.5
        width: 3
    }
    LineSeries {
        id: _series_envelope_l
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        color: window.theme.chartEnvelope

    }
    LineSeries {
        id: _series_envelope_u
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL

        color:  window.theme.chartEnvelope
    }
    AreaSeries{
        id: _series_area
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        lowerSeries: _series_envelope_l
        upperSeries: _series_envelope_u
        color:  window.theme.chartEnvelope
        borderWidth: 0
        borderColor:  window.theme.chartEnvelope
    }
//    LineSeries {
//        id: _series_fill_l
//        axisX: axisX
//        axisY: axisY
//        useOpenGL: chartView.openGL
//        color: "yellow"

//    }
//    AreaSeries{
//        id: _series_fill
//        axisX: axisX
//        axisY: axisY
//        useOpenGL: chartView.openGL
//        lowerSeries: _series_fill_l
//        upperSeries: _series_main
//        color: "white"
//        borderWidth: 0
//        borderColor: "yellow"
//    }

    LineSeries{
        id: _series_dac100
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        color: "orange"
        width: 4
    }

    LineSeries{
        id: _series_dac50
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        color: "orange"
        width: 2
    }

    LineSeries{
        id: _series_dac20
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        color: "orange"
        width: 2
    }

    ScatterSeries{
        id:_series_currentmarker
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        color: window.theme.chartMarker
        markerShape: "MarkerShapeCircle"
        markerSize: 7
    }
    ScatterSeries{
        id:_series_evaluationMarker
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        color:"red"
        markerShape: "MarkerShapeCircle"
        markerSize: 7
    }

    LineSeries{
        id: _series_leg
        axisX: axisX
        axisY: axisY
        useOpenGL: chartView.openGL
        width:3
        color: "blue"
    }

    FaultCalcAdaptor{
        id: _adaptor
    }

    Component.onCompleted: {
//        _ascanAdaptor.registerAScanSeries(0,_series_main);
//        _ascanAdaptor.registerAScanSeries(1,_series_AOverlay);
//        _ascanAdaptor.registerAScanSeries(2,_series_BOverlay);
//        _ascanAdaptor.registerAScanSeries(3,_series_gateA);
//        _ascanAdaptor.registerAScanSeries(4,_series_gateB);
//        _ascanAdaptor.registerAScanSeries(5,_series_envelope_l);
//        _ascanAdaptor.registerAScanSeries(6,_series_envelope_u);
//        _ascanAdaptor.registerAScanSeries(7,_series_dac100);
//        _ascanAdaptor.registerAScanSeries(8,_series_dac50);
//        _ascanAdaptor.registerAScanSeries(9,_series_dac20);
//        _ascanAdaptor.registerAScanSeries(10,_series_currentmarker);
//        _ascanAdaptor.registerAScanSeries(11,_series_evaluationMarker);
//        _ascanAdaptor.registerAScanSeries(12,_series_leg);
        chartView.enabled =false;

//        _ascanAdaptor.registerAScanSeries(13,_series_fill_l);
    }
//    AScanAdaptor{
//        id:_ascanAdaptor
//    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
