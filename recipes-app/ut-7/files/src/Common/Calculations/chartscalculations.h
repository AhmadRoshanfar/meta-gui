#ifndef CHARTSCALCULATIONS_H
#define CHARTSCALCULATIONS_H

#include <QObject>
#include "../Helpers/qmlintegrator.h"

class ChartsCalculations
{
    static QmlIntegrator& _qmlIntegrator;

public:
    ChartsCalculations();
    static double indexFromLength(double length);
    static double lengthEplison();
    static double lengthFromTime(double microsec);
    static QPointF pointBasedOnPolarity(QPointF p);
    static double lengthFromIndex(int idx);
    static double lengthWithUnit(double lenght);
    static double mmLengthEplison();
    static double timeuSFromLength(double mm);
    static double indexFromLengthWithoutProbeDelay(double length_mm);
    static double lengthFromIndexWithoutProbeDelay(int idx);

};

#endif // CHARTSCALCULATIONS_H
