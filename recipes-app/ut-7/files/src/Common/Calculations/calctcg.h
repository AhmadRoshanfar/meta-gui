#ifndef TCGCALC_H
#define TCGCALC_H

#include <QObject>
#include <QPointF>
#include <QVector>
class CalcTCG : public QObject
{
    Q_OBJECT
    void sort(QVector<QPointF> &dacPoints);
public:
    explicit CalcTCG(QObject *parent = nullptr);

    std::tuple<uint16_t, uint16_t, QVector<quint16>> calc(double gain, QVector<QPointF> points);

signals:

public slots:
};

#endif // TCGCALC_H
