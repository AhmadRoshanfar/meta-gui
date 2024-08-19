#ifndef PEAKMETHODMANAGER_H
#define PEAKMETHODMANAGER_H
#include <QPointF>
#include <QVector>
#include "Helpers/qmlintegrator.h"
#include <QObject>
class PeakMethodManager: public QObject
{
    Q_OBJECT
public:
    explicit PeakMethodManager(QObject *parent = nullptr);

    QPointF getFlank(const QVector<QPointF> &vector, double peak_x);
    QPointF getJFlank(const QVector<QPointF> &vector);
    QPointF maxElement(const QVector<QPointF> &vector);
    QPointF getPeakMethodPointA();
    void setPeakPoints();
    QPointF getPeakMethodPointB();
    QPointF upward(const QVector<QPointF> &vector);
    QPointF downward(const QVector<QPointF> &vector);
public slots:

private:
    QVector<QPointF> getGate(double start, double width);
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
private slots:
    void newPeaks(const QPointF& peakA, const QPointF& peakB,
                          const QPointF& flankA, const QPointF& flankB,
                          const QPointF& jflankA, const QPointF& jflankB,
                          const QPointF& upwardA, const QPointF& upwardB,
                          const QPointF& downwardA, const QPointF& downwardB);

};

#endif // PEAKMETHODMANAGER_H
