#ifndef GAINTABLE_H
#define GAINTABLE_H
#include <QObject>

class GainTable
{
public:
    GainTable();
    static const double* _gainTable;

    static uint16_t getCode(double gaindb);
private:
    static double *initTable();
};

#endif // GAINTABLE_H
