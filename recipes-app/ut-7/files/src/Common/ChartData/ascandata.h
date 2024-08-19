#ifndef ASCANDATA_H
#define ASCANDATA_H

#include <QObject>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QXYSeries>
#include "../Common/peakmethodmanager.h"
#include "../Common/Models/enums.h"
#include "../Helpers/qmlintegrator.h"

class AScanData : public QObject
{
    Q_OBJECT
    int nonNANIndex = 0;
    int nonNANCnt = 0;
    QPointF _lastPoint;
    bool _lastInMain = false;
    PeakMethodManager _peakMan;
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    void addByIndex(int index);
public:
    explicit AScanData(QObject *parent = nullptr);
    void generateData(Enums::EnvelopeType enveloped);
    static QVector<double> vkAscanMain,vvAscanMain;
    static QVector<double> vkAscanOA, vvAscanOA;
    static QVector<double> vkAscanOB, vvAscanOB;
//    static QVector<double> vkAscanGA, vvAscanGA;
//    static QVector<double> vkAscanGB, vvAscanGB;
//    static QVector<double> vAscanFillL;
    static QVector<double> vkAscanEnv, vvAscanEnv;
    static QVector<double> vkAscanCurrentMarker, vvAscanCurrentMarker;
    static QVector<double> vkAscanEvaluationMarkers, vvAscanEvaluationMarkers;
    static QVector<double> vkAscanLeg, vvAscanLeg;
    static QVector<double> vkAscanDac100, vkAscanDac50, vkAscanDac20, vvAscanDac100, vvAscanDac50, vvAscanDac20;
signals:

public slots:

};

#endif // ASCANDATA_H
