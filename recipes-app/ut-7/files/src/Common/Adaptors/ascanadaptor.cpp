#include "ascanadaptor.h"
#include "../ChartData/ascandata.h"
#include "../utdevice.h"
#include <QDebug>
#include "snapshotadaptor.h"


AScanAdaptor::AScanAdaptor(QObject *parent) : QObject(parent)
{
    connect(&_qmlIntegrator,&QmlIntegrator::onEnvelopeChanged, this, &AScanAdaptor::newEnvelope);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateAStartChanged, this, &AScanAdaptor::resetEnvelope);
    connect(&_qmlIntegrator,&QmlIntegrator::onGateAWidthChanged, this, &AScanAdaptor::resetEnvelope);
    connect(&_qmlIntegrator,&QmlIntegrator::onAScanAxisXMinChanged, this, &AScanAdaptor::newAScanX);
    connect(&_qmlIntegrator,&QmlIntegrator::onAScanAxisXMaxChanged, this, &AScanAdaptor::newAScanX);
    connect(&_qmlIntegrator,&QmlIntegrator::onAScanAxisYMinChanged, this, &AScanAdaptor::newAScanY);
    connect(&_qmlIntegrator,&QmlIntegrator::onAScanAxisYMaxChanged, this, &AScanAdaptor::newAScanY);
    connect(&_qmlIntegrator,&QmlIntegrator::onGridChanged, this, &AScanAdaptor::newGrid);
    connect(&_qmlIntegrator,&QmlIntegrator::onZoomedChanged, this, &AScanAdaptor::zoom);

    //    qRegisterMetaType<QAbstractSeries*>();
    //    qRegisterMetaType<QAbstractAxis*>();
    //    _AScanPoints.append(&ScanningAScanData::vAscanMain);
    //    _AScanPoints.append(&ScanningAScanData::vAscanOA);
    //    _AScanPoints.append(&ScanningAScanData::vAscanOB);
    //    _AScanPoints.append(&ScanningAScanData::vAscanGA);
    //    _AScanPoints.append(&ScanningAScanData::vAscanGB);
    //    _AScanPoints.append(&ScanningAScanData::vAscanCurrentMarker);
    //    _AScanPoints.append(&ScanningAScanData::vAscanEvaluationMarkers);
}

void AScanAdaptor::registerAScan(AScanChart  *chart){
    pChart = chart;

}

//void AScanAdaptor::reset(){
//    if(_qmlIntegrator.envelope() == Enums::EnvelopeType::ENV_ON)
//        resetEnvelope();

//}

void AScanAdaptor::updateAScan()
{
    double range = _qmlIntegrator.range();
    if(!_qmlIntegrator.started()){
        return;
    }
    if(_qmlIntegrator.freezed()){
        return;
    }
    if(UTDevice::_signalData.count() <range)
        return;
    generateData();
    setData();
    //    rescaleAxes();
    pChart->replotChart();
}


void AScanAdaptor::generateData(){
    _gateData.setAllGates();
    _AScanData.generateData(_qmlIntegrator.envelope());
    //    _AScanPoints.replace(0,&AScanData::vAscanMain);
    //    _AScanPoints.replace(1,&AScanData::vAscanOA);
    //    _AScanPoints.replace(2,&AScanData::vAscanOB);
    //    _AScanPoints.replace(3,&AScanData::vAscanGA);
    //    _AScanPoints.replace(4,&AScanData::vAscanGB);
    //    _AScanPoints.replace(5,&AScanData::vAscanEnvL);
    //    _AScanPoints.replace(6,&AScanData::vAscanEnvU);
    //    _AScanPoints.replace(7,&AScanData::vAscanDac100);
    //    _AScanPoints.replace(8,&AScanData::vAscanDac50);
    //    _AScanPoints.replace(9,&AScanData::vAscanDac20);
    //    _AScanPoints.replace(10,&AScanData::vAscanCurrentMarker);
    //    _AScanPoints.replace(11,&AScanData::vAscanEvaluationMarkers);
    //    _AScanPoints.replace(12,&AScanData::vAscanLeg);
    //    _AScanPoints.replace(13,AScanData::vAscanFillL);
    //    _peakMan.setPeakPoints();
}

/********************************************************************/
void AScanAdaptor::rescaleAxes(){
    //    pChart->xAxis->setRange(QCPRange(_qmlIntegrator.displayDelay(),_qmlIntegrator.displayDelay()+_qmlIntegrator.range()));
    //    pChart->yAxis->setRange(QCPRange(0, 100));
    //    m_CustomPlot->rescaleAxes();
}

void AScanAdaptor::setup(){

}

void AScanAdaptor::setData(){
    QString title = "";
    double textValue = 0;
    switch (_qmlIntegrator.textOnChart()) {
    case Enums::TextOnChart::TOC_D:
        title = "D";
        textValue = _qmlIntegrator.resD();
        break;
    case Enums::TextOnChart::TOC_Da:
        title = "Da";
        textValue = _qmlIntegrator.resDa();
        break;
    case Enums::TextOnChart::TOC_S:
        title = "S";
        textValue = _qmlIntegrator.resS();
        break;
    case Enums::TextOnChart::TOC_H:
        title = "H";
        textValue = _qmlIntegrator.currentPeakA().y();
        break;
    case Enums::TextOnChart::TOC_d:
        title = "d";
        textValue = _qmlIntegrator.awsd();
        break;
    case Enums::TextOnChart::TOC_NONE:
        title = "";
        break;

    }
    pChart->setData(AScanData::vkAscanMain,AScanData::vvAscanMain,
                    AScanData::vkAscanOA,AScanData::vvAscanOA,
                    AScanData::vkAscanOB,AScanData::vvAscanOB,
                    AScanData::vkAscanEnv,AScanData::vvAscanEnv,
                    AScanData::vkAscanDac100,AScanData::vvAscanDac100,
                    AScanData::vkAscanDac50,AScanData::vvAscanDac50,
                    AScanData::vkAscanDac20,AScanData::vvAscanDac20,
                    AScanData::vkAscanCurrentMarker,AScanData::vvAscanCurrentMarker,
                    _qmlIntegrator.activated()?QVector<double>(): AScanData::vkAscanEvaluationMarkers,_qmlIntegrator.activated()?QVector<double>():AScanData::vvAscanEvaluationMarkers,
                    AScanData::vkAscanLeg,AScanData::vvAscanLeg,
                    _qmlIntegrator.gateALevel(), _qmlIntegrator.gateAEnabled()?_qmlIntegrator.UIGateAStart():0, _qmlIntegrator.gateAEnabled()?_qmlIntegrator.UIGateAStart()+_qmlIntegrator.UIGateAWidth():0,
                    _qmlIntegrator.gateBLevel(), _qmlIntegrator.gateBEnabled()?_qmlIntegrator.UIGateBStart():0, _qmlIntegrator.gateBEnabled()?_qmlIntegrator.UIGateBStart()+_qmlIntegrator.UIGateBWidth():0,
                    title,textValue);
}



void AScanAdaptor::zoom(){
    if(_qmlIntegrator.zoomed()){
        _lastDisplayDelay = _qmlIntegrator.displayDelay();
        _lastRange = _qmlIntegrator.range();
        _qmlIntegrator.setDisplayDelay(_qmlIntegrator.gateAStart());
        _qmlIntegrator.setRange(_qmlIntegrator.gateAWidth());
    }
    else{
        _qmlIntegrator.setDisplayDelay(_lastDisplayDelay);
        _qmlIntegrator.setRange(_lastRange);
    }
}


/********************************************************************/
void AScanAdaptor::newEnvelope(){
    if(_qmlIntegrator.envelope()==Enums::EnvelopeType::ENV_ON){
        for(int i = 0;i<GateData::_gateA.count();i++){
            AScanData::vkAscanEnv.append(GateData::_gateA[i].x());
            AScanData::vvAscanEnv.append(0.0);
        }
        //        vAscanEnvL.append(QPointF(vAscanOA.first().x(),0.0));
        //        vAscanEnvL.append(QPointF(vAscanOA.last().x(),0.0));
        //        _qmlIntegrator.setEnvelope(Enums::EnvelopeType::ENV_ON);
    }
    else if(_qmlIntegrator.envelope()==Enums::EnvelopeType::ENV_OFF){
        //        _qmlIntegrator.setEnvelope(Enums::EnvelopeType::ENV_OFF);
        AScanData::vkAscanEnv.clear();
        AScanData::vvAscanEnv.clear();
    }
}

void AScanAdaptor::resetEnvelope(){
    if(_qmlIntegrator.envelope()!=Enums::EnvelopeType::ENV_ON)
        return;
    _qmlIntegrator.setEnvelope(Enums::EnvelopeType::ENV_OFF);
    newEnvelope();
    generateData();
    _qmlIntegrator.setEnvelope(Enums::EnvelopeType::ENV_ON);
    newEnvelope();
}
void AScanAdaptor::declareQML() {
    qmlRegisterType<AScanAdaptor>("AScanAdaptor", 1, 0, "AScanAdaptor");
}


/********************************************************************/

void AScanAdaptor::newAScanX(){
    pChart->xAxis->setRange(_qmlIntegrator.aScanAxisXMin(),_qmlIntegrator.aScanAxisXMax());
}

void AScanAdaptor::newAScanY(){
    pChart->yAxis->setRange(_qmlIntegrator.aScanAxisYMin(),_qmlIntegrator.aScanAxisYMax());
    pChart->yAxis2->setRange(_qmlIntegrator.aScanAxisYMin(),_qmlIntegrator.aScanAxisYMax());

}

void AScanAdaptor::newGrid(){
    pChart->xAxis->grid()->setVisible(_qmlIntegrator.grid());
    pChart->yAxis->grid()->setVisible(_qmlIntegrator.grid());
}


void AScanAdaptor::snapshot(){
    SnapshotAdaptor sa;
    auto filename = sa.newSnapshotName();
    pChart->savePng(filename);
    sa.sync();
}
