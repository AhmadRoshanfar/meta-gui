#ifndef AWSCALC_H
#define AWSCALC_H

#include <QObject>
#include "../Common/Models/enums.h"
class CalcAWS : public QObject
{
    Q_OBJECT
    int aws_table[2][11][4];
    int aws_lim[11][3];

public:
    explicit CalcAWS(QObject *parent = nullptr);
    Enums::AWSClass findClass(double d, double angle, int table_no, double thickness);
    std::tuple<double,double,double> calc(double y,double gain, double s);
    static double yRef, gainRef;
signals:

public slots:
};

#endif // AWSCALC_H
