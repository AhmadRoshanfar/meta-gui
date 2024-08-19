#include "ascanchart.h"
#include "qcustomplot.h"
#include <QDebug>
//#include "ascandata.h"

AScanChart::AScanChart( QWidget* parent )  :QCustomPlot ( parent )
  /*,*/
{
    setup();
    _isSetup = true;

//    connect(&_qmlIntegrator,&QmlIntegrator::onThemeChanged, this, &AScanChart::newTheme);
//    newTheme();
}

AScanChart::~AScanChart()
{
    delete this;
}

void AScanChart::newTheme(QColor bg, QColor main, QColor envelope, QColor grid, QColor axis){

    if(!_isSetup)
        return;
    this->graph(1)->setPen(QPen(main));
    this->graph(0)->setPen(QPen(envelope));
    this->graph(0)->setBrush(QBrush(envelope));
    this->xAxis->grid()->setPen(QPen(grid));
    this->yAxis->grid()->setPen(QPen(grid));
    this->xAxis2->grid()->setPen(QPen(grid));
    this->yAxis2->grid()->setPen(QPen(grid));
    this->xAxis->setTickLabelColor(axis);
    this->yAxis->setTickLabelColor(axis);
    this->xAxis->setTickPen(axis);
    this->yAxis->setTickPen(axis);
    this->xAxis2->setTickPen(axis);
    this->yAxis2->setTickPen(axis);
    this->xAxis->setSubTickPen(axis);
    this->yAxis->setSubTickPen(axis);
    this->xAxis2->setSubTickPen(axis);
    this->yAxis2->setSubTickPen(axis);
    this->xAxis->setBasePen(QPen(axis));
    this->yAxis->setBasePen(QPen(axis));
    this->xAxis2->setBasePen(QPen(axis));
    this->yAxis2->setBasePen(QPen(axis));
    this->setBackground(QBrush(bg));
    this->replot();
}

void AScanChart::setup()
{
    this->addGraph(); // 0: Envelope line
    this->addGraph(); // 1: main line
    this->addGraph(); // 2: OA line
    this->addGraph(); // 3: OB line
    this->addGraph(); // 4: GA line
    this->addGraph(); // 5: GB line
    this->addGraph(); // 6: DAC100 line
    this->addGraph(); // 7: DAC50 line
    this->addGraph(); // 8: DAC20 line
    this->addGraph(); // 9: currentMarker
    this->addGraph(); // 10: evalMarkers
    this->addGraph(); // 11: leg line

     // 0: Envelope line
    this->graph(0)->setPen(QPen(QColor(255, 255, 0)));
    this->graph(0)->setBrush(QBrush(QColor(255, 255, 0,255)));
    // 1: main line
    this->graph(1)->setPen(QPen(QColor(0, 0, 0)));
    // 2: OA line
    this->graph(2)->setPen(QPen(QColor(255, 0, 0)));
    // 3: OB line
    this->graph(3)->setPen(QPen(QColor(0, 255, 0)));
    // 4: GA line
    auto pen = this->graph(4)->pen();
    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(3);
    this->graph(4)->setPen(pen);
    // 5: GB line
    pen = this->graph(5)->pen();
    pen.setColor(QColor(0, 255, 0));
    pen.setWidth(3);
    this->graph(5)->setPen(pen);
    // 6: DAC100 line
    pen = this->graph(6)->pen();
    pen.setColor("orange");
    pen.setWidth(3);
    this->graph(6)->setPen(pen);
    pen.setWidth(2);
    // 7: DAC50 line
    this->graph(7)->setPen(pen);
    pen.setWidth(2);
    // 8: DAC20 line
    this->graph(8)->setPen(pen);
    // 9:currentMarker
    this->graph(9)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 6));
    this->graph(9)->setLineStyle(QCPGraph::lsNone);
    this->graph(9)->setPen(QPen(QColor(200, 120, 0)));
    pen = this->graph(9)->pen();
    pen.setWidth(2);
    this->graph(9)->setPen(pen);
    // 10: evalMarkers
    this->graph(10)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 6));
    this->graph(10)->setLineStyle(QCPGraph::lsNone);
    this->graph(10)->setPen(QPen(QColor(255, 0, 0)));
    // 11: leg line
    this->graph(11)->setPen(QPen(QColor(255, 0, 0)));

    this->axisRect()->setupFullAxesBox();
    //    this->yAxis->setRange(_yMin, _yMax);
    textLabel = new QCPItemText(this);
    textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
    textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel->position->setCoords(0.85, 0.05); // place position at center/top of axis rect
    textLabel->setText("S: 0");
    textLabel->setFont(QFont(font().family(), 20)); // make font a bit larger
    textLabel->setColor(Qt::red); // show black border around text
//    textLabel->setBrush(QBrush(Qt::lightGray)); // show black border around text

}





void AScanChart::setData( QVector<double> mainK,QVector<double> mainV,
                          QVector<double> OAK,QVector<double> OAV,
                          QVector<double> OBK,QVector<double> OBV,
                          QVector<double> envK,QVector<double> envV,
                          QVector<double> dac100K,QVector<double> dac100V,
                          QVector<double> dac50K,QVector<double> dac50V,
                          QVector<double> dac20K,QVector<double> dac20V,
                          QVector<double> currentMarkerK,QVector<double> currentMarkerV,
                          QVector<double> evalMarkersK,QVector<double> evalMarkersV,
                          QVector<double> legK,QVector<double> legV,
                          double GALevel, double GAStart,double GAEnd,
                          double GBLevel, double GBStart, double GBEnd,
                          QString title, double textValue){
    this->graph(1)->setData(mainK,mainV,true);
    this->graph(2)->setData(OAK,OAV,true);
    this->graph(3)->setData(OBK,OBV,true);
    QVector<double> tK,tV;
    tK.append(GAStart);
    tK.append(GAEnd);
    tV.append(GALevel);
    tV.append(GALevel);
    this->graph(4)->setData(tK,tV,true);
    tV.clear();
    tK.clear();
    tK.append(GBStart);
    tK.append(GBEnd);
    tV.append(GBLevel);
    tV.append(GBLevel);
    this->graph(5)->setData(tK,tV,true);
    this->graph(0)->setData(envK,envV,true);
    this->graph(6)->setData(dac100K,dac100V,true);
    this->graph(7)->setData(dac50K,dac50V,true);
    this->graph(8)->setData(dac20K,dac20V,true);
    this->graph(9)->setData(currentMarkerK,currentMarkerV,true);
    this->graph(10)->setData(evalMarkersK,evalMarkersV,true);
    this->graph(11)->setData(legK,legV,true);
    if(title == ""){
        textLabel->setText("");
        textLabel->setVisible(false);
    }
    else{
        textLabel->setVisible(true);
        textLabel->setText(QString("%1: %2").arg(title).arg(QString::number(textValue,'f',2)));
    }
}



void AScanChart::replotChart(){
    this->replot();
}


