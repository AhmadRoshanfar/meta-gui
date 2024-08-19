#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QObject>
#include "../Helpers/qmlintegrator.h"

class CalcCalibration : public QObject
{
    Q_OBJECT
public:
    explicit CalcCalibration(QObject *parent = nullptr);
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

    double CalcNewVelocity(int oldVelocity, double spath1, double spath2, double x1, double x2);
    double CalcNewProbeDelay(int newVelocity, int oldVelocity, double oldProbedelay,  double spath1, double spath2, double x1, double x2);
signals:

public slots:
};

#endif // CALIBRATION_H
