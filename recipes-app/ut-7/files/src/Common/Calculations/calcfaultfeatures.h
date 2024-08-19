#ifndef CALCFAULTFEATURE_H
#define CALCFAULTFEATURE_H

#include <QObject>
#include "../Common/Models/enums.h"
#include "../Helpers/qmlintegrator.h"
class CalcFaultFeatures : public QObject
{
    Q_OBJECT
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
public:
    explicit CalcFaultFeatures(QObject *parent = nullptr);
    struct FaultFeatRes{
        double S, D,Da,leg;
    };
    FaultFeatRes calc(double soundPathMultiplier, double S_mm, double pipeDiameter, Enums::Shape shape, Enums::ProbeType probeType, Enums::Unit unit);


signals:

public slots:
};

#endif // CALCFAULTFEATURE_H
