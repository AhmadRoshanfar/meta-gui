#include "calccalibration.h"

CalcCalibration::CalcCalibration(QObject *parent) : QObject(parent)
{

}

double CalcCalibration::CalcNewVelocity(int oldVelocity,double spath1,double spath2,double x1,double x2){
    return qAbs((spath2-spath1)/(x2-x1)*oldVelocity);
}

double CalcCalibration::CalcNewProbeDelay(int newVelocity,int oldVelocity, double oldProbedelay, double spath1, double spath2, double x1, double x2){
    return  ((qMax(x1,x2)/oldVelocity)-qMax(spath1,spath2)/newVelocity)*1000.0/_qmlIntegrator.soundPathMultiplier()+oldProbedelay;
}
