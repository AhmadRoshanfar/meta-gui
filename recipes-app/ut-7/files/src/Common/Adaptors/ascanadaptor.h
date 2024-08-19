#ifndef ASCANADAPTOR_H
#define ASCANADAPTOR_H
//#define STRIP_CHART
#include <QObject>
#include "../Helpers/constants.h"
#include "../Common/ChartData/ascandata.h"
#include "../gatedata.h"
#include "../Helpers/qmlintegrator.h"
#include <QVector>
#include "../Common/Chart/qcustomplot.h"
#include "../Common/Chart/ascanchart.h"

class AScanAdaptor : public QObject
{
    Q_OBJECT
    GateData _gateData;
    AScanChart *pChart;

    Enums::EnvelopeType _enveloped = Enums::EnvelopeType::ENV_OFF;

    double _lastRange,_lastDisplayDelay;
    AScanData _AScanData;
    PeakMethodManager _peakMan;
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

    void generateData();
    void setData();
    void rescaleAxes();
    void setup();
public:
    explicit AScanAdaptor(QObject *parent = nullptr);

    static void declareQML();
signals:

public slots:

    void updateAScan();
    void newEnvelope();
    void resetEnvelope();
    void zoom();
    void registerAScan(AScanChart *pChart);
    void snapshot();
private slots:
    void newAScanX();
    void newAScanY();
    void newGrid();

};

#endif // ASCANADAPTOR_H
