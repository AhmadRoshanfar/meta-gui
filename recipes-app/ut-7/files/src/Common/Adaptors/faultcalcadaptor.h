#ifndef FAULTCALCADAPTOR_H
#define FAULTCALCADAPTOR_H

#include <QObject>
#include "../Common/Calculations/calcfaultfeatures.h"
#include "../Common/Calculations/calcaws.h"
#include "../Common/Helpers/qmlintegrator.h"

class FaultCalcAdaptor : public QObject
{
    Q_OBJECT
    CalcAWS _awsCalc;
    CalcFaultFeatures _faultCalc;
    void calcFaultFeature();
    void calcAWS();
    double TwoDecimals(double d);
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

public:
    explicit FaultCalcAdaptor(QObject *parent = nullptr);
    static void declareQML();

signals:

public slots:
    void calc();
};

#endif // FAULTCALCADAPTOR_H
