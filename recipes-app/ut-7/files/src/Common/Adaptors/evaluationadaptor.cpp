#include "evaluationadaptor.h"
#include <QtMath>
#include "../Models/enums.h"
#include "../Helpers/constants.h"
#include "../ChartData/ascandata.h"
#include "../Helpers/qmlintegrator.h"
#include "../Calculations/chartscalculations.h"
#include "../Helpers/devicehelper.h"
//QMap<Enums::EvaluationMode,EvalMethod> EvaluationAdaptor::_map;

EvaluationAdaptor::EvaluationAdaptor(QObject *parent) : QObject(parent)
{
    EvalMethod m;
    m.mode = Enums::EvaluationMode::EVAL_AWS;
    m.maxPoints = Constants::MAX_AWS_POINTS;
    _map.insert(m.mode, m);
    m.mode = Enums::EvaluationMode::EVAL_DAC;
    m.maxPoints = Constants::MAX_DAC_POINTS;
    _map.insert(m.mode, m);
    m.mode = Enums::EvaluationMode::EVAL_TCG;
    m.maxPoints = Constants::MAX_TCG_POINTS;
    _map.insert(m.mode, m);
    m.mode = Enums::EvaluationMode::EVAL_NORMAL;
    m.maxPoints = Constants::MAX_NORMAL_POINTS;
    _map.insert(m.mode, m);

    connect(&_qmlIntegrator,&QmlIntegrator::onEvaluationModeChanged,this,&EvaluationAdaptor::deactivate);
    connect(&_qmlIntegrator,&QmlIntegrator::onEvaluationModeChanged,this,&EvaluationAdaptor::refreshPoints);
    connect(&_qmlIntegrator,&QmlIntegrator::onActivatedChanged,this,&EvaluationAdaptor::activate);
    connect(&_qmlIntegrator,&QmlIntegrator::onUnitChanged,this,&EvaluationAdaptor::refreshPoints);
    connect(&_qmlIntegrator,&QmlIntegrator::onGainChanged,this,&EvaluationAdaptor::renewDac);
    connect(&_qmlIntegrator,&QmlIntegrator::onGainChanged,this,&EvaluationAdaptor::DACRefreshPoints);

}

void EvaluationAdaptor::getPosition(){
    auto mode = _qmlIntegrator.evaluationMode();
    add(_map[mode].points);
    if(mode == Enums::EvaluationMode::EVAL_AWS)
        _map[mode].aux = _qmlIntegrator.gain();
    else if(mode == Enums::EvaluationMode::EVAL_DAC && _map[mode].points.count() == 1)
        _DACGains.append(_qmlIntegrator.gain());
}

void EvaluationAdaptor::deleteList(){
    _map[_qmlIntegrator.evaluationMode()].points.clear();
    refreshPoints();
}

void EvaluationAdaptor::activate(){
    bool res = false;
    _map[_qmlIntegrator.evaluationMode()].gain = _qmlIntegrator.gain();
    _qmlIntegrator.setRefGain(_qmlIntegrator.gain());

    if(_qmlIntegrator.activated()){
        switch (_qmlIntegrator.evaluationMode()) {
        case Enums::EvaluationMode::EVAL_DAC:{
            auto points = _map[_qmlIntegrator.evaluationMode()].points;
            for(int i = 0; i<points.count(); i++){
                double coef = qPow(10.0,(_qmlIntegrator.gain() -  _DACGains.at(i))/20.0);
                auto& point = points.at(i);
                points.replace(i,QPointF(point.x(),coef * point.y()));
            }
            res = doDAC(points);
            break;
        }
        case Enums::EvaluationMode::EVAL_TCG:
            res = doTCG();
            break;
        case Enums::EvaluationMode::EVAL_AWS:
            res = doAWS();
            break;
        case Enums::EvaluationMode::EVAL_NORMAL:
            break;
        }
    }
    else{
        AScanData::vvAscanDac100.clear();
        AScanData::vvAscanDac50.clear();
        AScanData::vvAscanDac20.clear();
        AScanData::vkAscanDac100.clear();
        AScanData::vkAscanDac50.clear();
        AScanData::vkAscanDac20.clear();
        deactivate();
    }
    _qmlIntegrator.setActivated(res);
}

//void EvaluationAdaptor::declareQML() {
//    qmlRegisterType<EvaluationAdaptor>("EvaluationAdaptor", 1, 0, "EvaluationAdaptor");
//}

void EvaluationAdaptor::remove(QVector<QPointF> &points,int idx){
    points.remove(idx,points.count()-idx);
}

void EvaluationAdaptor::remove(QVector<double> &points,int idx){
    points.remove(idx,points.count()-idx);
}

void EvaluationAdaptor::removePoint(){
    auto& points  = _map[_qmlIntegrator.evaluationMode()].points;
    if(_qmlIntegrator.evaluationPointIndex()>=points.count())
        return;
    points.remove(_qmlIntegrator.evaluationPointIndex());
    refreshPoints();
}

void EvaluationAdaptor::add(QVector<QPointF> &points){
    int idx = qMin(points.count(), _qmlIntegrator.evaluationPointIndex());
    remove(points,idx);
    points.append(QPointF(_qmlIntegrator.currentMarkerA().x(),qAbs(_qmlIntegrator.currentMarkerA().y())));
    if(_qmlIntegrator.evaluationMode() == Enums::EvaluationMode::EVAL_DAC){
        remove(_DACGains,idx);
        _DACGains.append(_qmlIntegrator.gain());
    }
    refreshPoints();
    _qmlIntegrator.setEvaluationPointIndex(qMin(_map[_qmlIntegrator.evaluationMode()].maxPoints-1,idx+1));
}

void EvaluationAdaptor::deactivate(){
    DeviceHelper::instance().sendTCGDisable();
    _qmlIntegrator.setActivated(false);
    _qmlIntegrator.setEvaluationPointIndex(qMax(_map[_qmlIntegrator.evaluationMode()].points.count()-1,0));
    AScanData::vkAscanEvaluationMarkers = QVector<double>();
    AScanData::vvAscanEvaluationMarkers = QVector<double>();
}

void EvaluationAdaptor::refreshPoints(){
    QStringList temp;
    auto &points = _map[_qmlIntegrator.evaluationMode()].points;
    for(int i = 0; i<_map[_qmlIntegrator.evaluationMode()].maxPoints; i++){

        if(i<points.count()){
            double coef = 1;
            if(_qmlIntegrator.evaluationMode() == Enums::EvaluationMode::EVAL_DAC)
                coef = qPow(10.0,(_qmlIntegrator.gain() -  _DACGains.at(i))/20.0);
            auto tmp = points.at(i);
            temp.append(QString("%1 - %2,%3").arg(i+1).arg(int(ChartsCalculations::lengthWithUnit(tmp.x())*100)/100.0).arg(int(tmp.y()*coef*100)/100.0));
        }
        else{
            temp.append(QString::number(i+1));
        }
    }
    _qmlIntegrator.setEvaluationPoints(temp);
    QVector<double> kEvaluationMarkers;
    QVector<double> vEvaluationMarkers;
    for(int i = 0; i<points.count(); i++){
        double coef = 1;
        auto point = points.at(i);
        if(_qmlIntegrator.evaluationMode() == Enums::EvaluationMode::EVAL_DAC)
            coef = qPow(10.0,(_qmlIntegrator.gain() -  _DACGains.at(i))/20.0);

        kEvaluationMarkers.append(ChartsCalculations::lengthWithUnit(point.x()));
        vEvaluationMarkers.append(coef * point.y());
    }
    AScanData::vkAscanEvaluationMarkers = kEvaluationMarkers;
    AScanData::vvAscanEvaluationMarkers = vEvaluationMarkers;
    _qmlIntegrator.setRefGain(_map[_qmlIntegrator.evaluationMode()].gain);
}

void EvaluationAdaptor::renewDac(){
    if(!_qmlIntegrator.activated())
        return;
    if(_qmlIntegrator.evaluationMode() != Enums::EvaluationMode::EVAL_DAC)
        return;
    auto &dac = _map[Enums::EvaluationMode::EVAL_DAC];
    auto dacpoints = dac.points;
    QVector<QPointF> newPoints;
    for(int i = 0; i <dacpoints.count(); i++){
        newPoints.append(QPointF(dacpoints[i].x(),dacpoints[i].y()*qPow(10,(_qmlIntegrator.gain() - dac.gain)/20.0))) ;
    }
    doDAC(newPoints);
}

bool EvaluationAdaptor::doAWS(){
    auto &aws = _map[Enums::EvaluationMode::EVAL_AWS];
    if(aws.points.count()!=1)
        return false;
    if(_qmlIntegrator.probeType() != Enums::ProbeType::PT_ANGULAR || _qmlIntegrator.probeAngle() != 70)
        return false;
    _calcAws.yRef = aws.points.at(0).y();
    _calcAws.gainRef = aws.aux;
    return true;
}

void EvaluationAdaptor::DACRefreshPoints(){
    if(_qmlIntegrator.evaluationMode() == Enums::EvaluationMode::EVAL_DAC){
        refreshPoints();
    }
}

bool EvaluationAdaptor::doTCG(){
    auto &tcg = _map[Enums::EvaluationMode::EVAL_TCG];
    if(tcg.points.count()<2)
        return false;
    auto [start,finish,list] = _calcTcg.calc(_qmlIntegrator.gain(),tcg.points);
            DeviceHelper::instance().sendTCGPoints(start,finish,list);
            return true;
}



bool EvaluationAdaptor::doDAC(QVector<QPointF> points){
        //        auto &dac = _map[Enums::EvaluationMode::EVAL_DAC];
        if(points.count()<2)
            return false;
        auto [kpoints100,kpoints50,kpoints20,vpoints100,vpoints50,vpoints20] = _calcDac.computeCurvePoints(points);
                AScanData::vkAscanDac100 = kpoints100;
                AScanData::vkAscanDac50 = kpoints50;
                AScanData::vkAscanDac20 = kpoints20;
                AScanData::vvAscanDac100 = vpoints100;
                AScanData::vvAscanDac50 = vpoints50;
                AScanData::vvAscanDac20 = vpoints20;
                return true;
}





