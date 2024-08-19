#include "stripchart.h"
#include "qcustomplot.h"
#include <QDebug>
//#include "ascandata.h"

StripChart::StripChart( QWidget* parent )  :QCustomPlot ( parent )
  /*,*/
{
    setup();
//    connect(&_qmlIntegrator,&QmlIntegrator::onThemeChanged, this, &StripChart::newTheme);
//    newTheme();
}

StripChart::~StripChart()
{
    delete this;
}

void StripChart::newTheme(QColor bg, QColor grid,QColor axis){
    this->xAxis->grid()->setPen(QPen(grid));
    this->yAxis->grid()->setPen(QPen(grid));
//    this->xAxis2->grid()->setPen(QPen(grid));
//    this->yAxis2->grid()->setPen(QPen(grid));
    this->xAxis->setTickLabelColor(axis);
    this->yAxis->setTickLabelColor(axis);
    this->xAxis->setTickPen(axis);
    this->yAxis->setTickPen(axis);
//    this->xAxis2->setTickPen(axis);
//    this->yAxis2->setTickPen(axis);
    this->xAxis->setSubTickPen(axis);
    this->yAxis->setSubTickPen(axis);
//    this->xAxis2->setSubTickPen(axis);
//    this->yAxis2->setSubTickPen(axis);
    this->xAxis->setBasePen(QPen(axis));
    this->yAxis->setBasePen(QPen(axis));
//    this->xAxis2->setBasePen(QPen(axis));
//    this->yAxis2->setBasePen(QPen(axis));
    this->setBackground(QBrush(bg));
    this->replot();
}

void StripChart::setup()
{
    this->addGraph(); // ASignal line
    this->graph(0)->setPen(QPen("Red"));
    this->addGraph(); // BSignal line
    this->graph(1)->setPen(QPen("Green"));
    this->addGraph(); // DACSignal line
    this->graph(2)->setPen(QPen("Yellow"));
    this->addGraph(); // ALevel line
    auto pen = QPen("Red");
    pen.setStyle(Qt::DashLine);
    this->graph(3)->setPen(pen);

    this->addGraph(); // BLevel line
    pen = QPen("Green");
    pen.setStyle(Qt::DashLine);
    this->graph(4)->setPen(pen);
    //    this->addGraph(); // DACLevel line
    //    this->graph(5)->setPen(QPen("Yellow"));
    this->axisRect()->setupFullAxesBox();
    this->xAxis->setRange(0, 10);
    this->yAxis->setRange(0, 101);

}


void StripChart::setData( QVector<double> vkStripA,QVector<double> vvStripA,
                          QVector<double> vkStripB,QVector<double> vvStripB,
                          QVector<double> vkStripDAC,QVector<double> vvStripDAC,
                          double stripLevelA,
                          double stripLevelB,
                          bool gateAVisible,
                          bool gateBVisible){
    this->graph(0)->setData(vkStripA,vvStripA,true);
    this->graph(1)->setData(vkStripB,vvStripB,true);
    this->graph(2)->setData(vkStripDAC,vvStripDAC,true);
    QVector<double> tK,tV;
    tK.append(0);
    tK.append(100000);
    tV.append(stripLevelA);
    tV.append(stripLevelA);
    this->graph(3)->setData(tK,tV,true);
    tV.clear();
    tK.clear();
    tK.append(0);
    tK.append(100000);
    tV.append(stripLevelB);
    tV.append(stripLevelB);
    this->graph(4)->setData(tK,tV,true);
    this->graph(0)->setVisible(gateAVisible);
    this->graph(1)->setVisible(gateBVisible);
    this->graph(3)->setVisible(gateAVisible);
    this->graph(4)->setVisible(gateBVisible);
}



void StripChart::replotChart(){
    this->replot();
}


