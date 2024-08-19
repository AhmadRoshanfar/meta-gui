#ifndef DACHELPER_H
#define DACHELPER_H

#include <QObject>
#include <QVector>
class CalcDAC : public QObject
{
    Q_OBJECT
    std::tuple<double, double> calcAlphaBeta(const QVector<QPointF> &dacpoints);
    double calcSingleAlpha(QPointF p1, QPointF p2);
    void sort(QVector<QPointF>&);
public:
    explicit CalcDAC(QObject *parent = nullptr);
//    QVector<QPointF>* dacPoints = nullptr;
    std::tuple<QVector<double>, QVector<double>, QVector<double>,QVector<double>, QVector<double>, QVector<double>> computeCurvePoints(QVector<QPointF> &dacpoints);
signals:

public slots:
};

#endif // DACHELPER_H
