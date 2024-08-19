#ifndef GATEDATA_H
#define GATEDATA_H
#include <QObject>
#include <QVector>
#include <QPointF>
#include "Models/enums.h"
#include "Calculations/chartscalculations.h"
#include "Helpers/qmlintegrator.h"

class GateData
{
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

public:
    GateData();
    static QVector<QPointF> _gateA;
    static QVector<QPointF> _gateB;
    static QVector<QPointF> _gateDAC;
    void setAllGates();

private:
    QVector<QPointF> setGate( double start, double width);
};

#endif // GATEDATA_H
