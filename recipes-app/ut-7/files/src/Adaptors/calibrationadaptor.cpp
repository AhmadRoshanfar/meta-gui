#include "calibrationadaptor.h"
#include "../Common/ChartData/ascandata.h"
#include "../Common/Helpers/constants.h"
#include <QDebug>

CalibrationAdaptor::CalibrationAdaptor(QObject *parent) : QObject(parent)
{

}

bool CalibrationAdaptor::doCalibration(){
    auto spath1  = _qmlIntegrator.spath1();
    auto spath2  = _qmlIntegrator.spath2();
    if(spath1 == spath2)
        return false;
    if(vkPoints.count()!= Constants::MAX_CALIB_POINTS)
        return false;
    double newVel = _calibration.CalcNewVelocity(_qmlIntegrator.velocity(),
                                                 spath1,
                                                 spath2,
                                                 vkPoints.at(0),
                                                 vkPoints.at(1));

    double newPD =  _calibration.CalcNewProbeDelay(newVel,
                                                   _qmlIntegrator.velocity(),
                                                   _qmlIntegrator.probeDelay(),
                                                   spath1,
                                                   spath2,
                                                   vkPoints.at(0),
                                                   vkPoints.at(1));
    _qmlIntegrator.setVelocity(newVel);
    _qmlIntegrator.setProbeDelay(newPD);
    vkPoints.clear();
    vvPoints.clear();
    refreshPoints();
    _qmlIntegrator.setCalibrationPointIndex(0);
    return true;
}

void CalibrationAdaptor::getPosition(){
    if(_qmlIntegrator.calibrationPointIndex() == Constants::MAX_CALIB_POINTS)
        doCalibration();
    else
        add(/*_points*/);
}

void CalibrationAdaptor::deleteList(){
    vkPoints.clear();
    vvPoints.clear();
    refreshPoints();
}

void CalibrationAdaptor::declareQML() {
    qmlRegisterType<CalibrationAdaptor>("CalibrationAdaptor", 1, 0, "CalibrationAdaptor");
}

void CalibrationAdaptor::remove(QVector<double> &points,int idx){
    points.remove(idx,points.count()-idx);
}

void CalibrationAdaptor::add(/*QVector<QPointF> &points*/){
    if(_qmlIntegrator.currentMarkerA().x()< _qmlIntegrator.gateAStart()
            || _qmlIntegrator.currentMarkerA().x()>_qmlIntegrator.gateAStart()+_qmlIntegrator.gateAWidth())
        return;
    int idx = qMin(vkPoints.count(), _qmlIntegrator.calibrationPointIndex());
    remove(vkPoints, idx);
    remove(vvPoints, idx);
    vkPoints.append(_qmlIntegrator.currentMarkerA().x());
    vvPoints.append(qAbs(_qmlIntegrator.currentMarkerA().y()));
    refreshPoints();
    _qmlIntegrator.setCalibrationPointIndex(qMin(Constants::MAX_CALIB_POINTS,idx+1));
}

void CalibrationAdaptor::activate(){
    bool res = false;
    if(_qmlIntegrator.activated())
        res = doCalibration();
    _qmlIntegrator.setActivated(res);
}

void CalibrationAdaptor::deactivate(){
    _qmlIntegrator.setActivated(false);
    AScanData::vvAscanEvaluationMarkers = QVector<double>();
    AScanData::vkAscanEvaluationMarkers = QVector<double>();

}


void CalibrationAdaptor::refreshPoints(){
    QStringList temp;
    for(int i = 0; i<Constants::MAX_CALIB_POINTS; i++){
        if(i<vvPoints.count()){
            double y = vvPoints.at(i);
            double x = vkPoints.at(i);
            temp.append(QString("%1 : %2,%3").arg(i+1).arg(int(x*100)/100.0).arg(int(y*100)/100.0));
        }
        else{
            temp.append(QString::number(i+1));
        }
    }
    if(vvPoints.count()== Constants::MAX_CALIB_POINTS)
        temp.append("active");
    _qmlIntegrator.setCalibrationPoints(temp);
    AScanData::vvAscanEvaluationMarkers = vvPoints;
    AScanData::vkAscanEvaluationMarkers = vkPoints;
}

