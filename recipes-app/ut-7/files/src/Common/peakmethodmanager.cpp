#include "peakmethodmanager.h"
#include <QtMath>
#include "Calculations/chartscalculations.h"
#include "utdevice.h"
#include "gatedata.h"
#include "Helpers/devicehelper.h"
PeakMethodManager::PeakMethodManager(QObject *parent) : QObject(parent)
{
    connect(&DeviceHelper::instance(),&DeviceHelper::signalPeaksReady,this,&PeakMethodManager::newPeaks);

}

//QPointF PeakMethodManager::getJFlank(const QVector<QPointF> &vector){
//    for(auto point:vector){
//        if(qAbs(point.y())>_qmlIntegrator.gateALevel())
//            return point;
//    }
//    return QPointF(qQNaN(),qQNaN());
//}

//QPointF PeakMethodManager::getFlank(const QVector<QPointF> &vector, double peak_x){
//    auto lastPoint = QPointF(0,0);
//    bool underGate = false;
//    if(vector.count()>0){
//        if(qAbs(vector.first().y())<_qmlIntegrator.gateALevel())
//            underGate = true;
//    }

//    for(auto point:vector){
//        if(underGate&& qAbs(point.y())>=_qmlIntegrator.gateALevel())
//            lastPoint = point;
//        if(point.x() == peak_x)
//            return lastPoint;
//        if(qAbs(point.y())<_qmlIntegrator.gateALevel())
//            underGate = true;
//        else
//            underGate = false;
//    }
//    return QPointF(qQNaN(),qQNaN());
//}

//QPointF PeakMethodManager::maxElement(const QVector<QPointF> &vector){
//    return *std::max_element(vector.begin(),vector.end(),[&](auto a,auto b){return qAbs(a.y())<qAbs(b.y());});
//}


//QPointF PeakMethodManager::upward(const QVector<QPointF> &vector){
//    bool intersectionPassed = false;
//    for (auto& point :vector) {
//        //        if(point.x()>=_qmlIntegrator.gateBStart()&&point.x()<=_qmlIntegrator.gateBStart()+_qmlIntegrator.gateBWidth()){
//        if(point.y()>=0&&point.y()>_qmlIntegrator.gateBLevel())
//            intersectionPassed = true;
//        if(intersectionPassed){
//            if(point.y()<=0)
//                return point;
//        }
//        //        }
//    }
//    return QPointF();
//}

//QPointF PeakMethodManager::downward(const QVector<QPointF> &vector){
//    bool intersectionPassed = false;
//    for (auto& point :vector) {
//        if(point.x()>=_qmlIntegrator.gateBStart()&&point.x()<=_qmlIntegrator.gateBStart()+_qmlIntegrator.gateBWidth()){
//            if(point.y()<0&&point.y()<-_qmlIntegrator.gateBLevel())
//                intersectionPassed = true;
//            if(intersectionPassed){
//                if(point.y()>=0)
//                    return point;
//            }
//        }
//    }
//    return QPointF();
//}

QPointF PeakMethodManager::getPeakMethodPointA(){
    auto mode = _qmlIntegrator.evaluationMode();
    if(!_qmlIntegrator.activated()&&(mode == Enums::EvaluationMode::EVAL_TCG||mode == Enums::EvaluationMode::EVAL_DAC||mode == Enums::EvaluationMode::EVAL_AWS))
        return _qmlIntegrator.currentPeakA();
    switch (_qmlIntegrator.peakMethodA()) {
    case Enums::PeakMethod::PM_PEAK:
        return _qmlIntegrator.currentPeakA();
    case Enums::PeakMethod::PM_FLANK:
        return _qmlIntegrator.currentFlankA();
    case Enums::PeakMethod::PM_JFLANK:
        return _qmlIntegrator.currentJFlankA();
    }
    return QPointF (qQNaN(),qQNaN());
}

QPointF PeakMethodManager::getPeakMethodPointB(){
//    auto mode = _qmlIntegrator.evaluationMode();
    //    if(!_qmlIntegrator.activated()&&(mode == Enums::EvaluationMode::EVAL_TCG||mode == Enums::EvaluationMode::EVAL_DAC||mode == Enums::EvaluationMode::EVAL_AWS))
    //        return _qmlIntegrator.currentPeakB();
    switch (_qmlIntegrator.peakMethodB()) {
    case Enums::PeakMethod::PM_PEAK:
        return _qmlIntegrator.currentPeakB();
    case Enums::PeakMethod::PM_FLANK:
        return _qmlIntegrator.currentFlankB();
    case Enums::PeakMethod::PM_JFLANK:
        return _qmlIntegrator.currentJFlankB();
    }
    return QPointF (qQNaN(),qQNaN());
}





//void PeakMethodManager::setPeakPoints(){
//    QVector<QPointF> gateA = GateData::_gateA;
//    QVector<QPointF> gateB = GateData::_gateB;
//    if(gateA.count()== 0){
//        QPointF nanP(qQNaN(),qQNaN());
//        _qmlIntegrator.setCurrentPeakA(nanP);
//        _qmlIntegrator.setCurrentFlankA(nanP);
//        _qmlIntegrator.setCurrentJFlankA(nanP);
//        _qmlIntegrator.setCurrentMarkerA(nanP);
//        _qmlIntegrator.setCurrentUpwardA(nanP);
//        _qmlIntegrator.setCurrentDownwardA(nanP);
//    }
//    else{
//        _qmlIntegrator.setCurrentPeakA(maxElement(gateA));
//        _qmlIntegrator.setCurrentFlankA(getFlank(gateA,_qmlIntegrator.currentPeakA().x()));
//        _qmlIntegrator.setCurrentJFlankA(getJFlank(gateA));
//        _qmlIntegrator.setCurrentMarkerA(getPeakMethodPointA());
//        _qmlIntegrator.setCurrentUpwardA(upward(gateA));
//        _qmlIntegrator.setCurrentDownwardA(downward(gateA));
//    }
//    if(gateB.count()== 0){
//        QPointF nanP(qQNaN(),qQNaN());
//        _qmlIntegrator.setCurrentPeakB(nanP);
//        _qmlIntegrator.setCurrentFlankB(nanP);
//        _qmlIntegrator.setCurrentJFlankB(nanP);
//        _qmlIntegrator.setCurrentMarkerB(nanP);
//        _qmlIntegrator.setCurrentUpwardB(nanP);
//        _qmlIntegrator.setCurrentDownwardB(nanP);
//    }
//    else{
//        _qmlIntegrator.setCurrentPeakB(maxElement(gateB));
//        _qmlIntegrator.setCurrentFlankB(getFlank(gateB,_qmlIntegrator.currentPeakB().x()));
//        _qmlIntegrator.setCurrentJFlankB(getJFlank(gateB));
//        _qmlIntegrator.setCurrentMarkerB(getPeakMethodPointB());
//        _qmlIntegrator.setCurrentUpwardB(upward(gateB));
//        _qmlIntegrator.setCurrentDownwardB(downward(gateB));
//    }
//}


void PeakMethodManager::newPeaks(const QPointF& peakA, const QPointF& peakB,
              const QPointF& flankA, const QPointF& flankB,
              const QPointF& jflankA, const QPointF& jflankB,
              const QPointF& upwardA, const QPointF& upwardB,
              const QPointF& downwardA, const QPointF& downwardB){

    _qmlIntegrator.setCurrentPeakA(peakA);
    _qmlIntegrator.setCurrentFlankA(flankA);
    _qmlIntegrator.setCurrentJFlankA(jflankA);
    _qmlIntegrator.setCurrentMarkerA(getPeakMethodPointA());
    _qmlIntegrator.setCurrentUpwardA(upwardA);
    _qmlIntegrator.setCurrentDownwardA(downwardA);
    _qmlIntegrator.setCurrentPeakB(peakB);
    _qmlIntegrator.setCurrentFlankB(flankB);
    _qmlIntegrator.setCurrentJFlankB(jflankB);
    _qmlIntegrator.setCurrentMarkerB(getPeakMethodPointB());
    _qmlIntegrator.setCurrentUpwardB(upwardB);
    _qmlIntegrator.setCurrentDownwardB(downwardB);
//    qDebug()<<peakA.x()<<peakA.y()<<flankA.x()<<flankA.y()<<jflankA.x()<<jflankA.y()<<upwardA.x()<<upwardA.y()<<downwardA.x()<<downwardA.y();

}

