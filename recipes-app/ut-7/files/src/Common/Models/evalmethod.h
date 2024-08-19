#ifndef EVALMETHOD_H
#define EVALMETHOD_H
#include <QObject>
#include "../Models/enums.h"
#include <QVector>
class EvalMethod{
public:
    QVector<QPointF> points;
    Enums::EvaluationMode mode;
    int maxPoints = 0;
    double gain = 0;
    double aux;
};



#endif // EVALMETHOD_H
