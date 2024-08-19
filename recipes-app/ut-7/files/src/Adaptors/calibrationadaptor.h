#ifndef CALIBRATIONADAPTOR_H
#define CALIBRATIONADAPTOR_H

#include <QObject>
#include "../Common/Calculations/calccalibration.h"
#include "../Common/Models/evalmethod.h"
#include <QPointF>
#include "../Common/Helpers/qmlintegrator.h"

class CalibrationAdaptor : public QObject
{
    Q_OBJECT
    
    CalcCalibration _calibration;

    void add(/*QVector<QPointF> &points*/);
    void remove(QVector<double> &points, int idx);
    void deactivate();
    void refreshPoints();
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    QVector<double> vvPoints;
    QVector<double> vkPoints;
public:
    explicit CalibrationAdaptor(QObject *parent = nullptr);

    static void declareQML();
signals:

public slots:
    void getPosition();
    void deleteList();
    bool doCalibration();

    void activate();
};

#endif // CALIBRATIONADAPTOR_H
