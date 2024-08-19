#ifndef STRIPDATA_H
#define STRIPDATA_H

#include <QObject>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QXYSeries>
#include "../Models/enums.h"
#include "../Helpers/qmlintegrator.h"
#include "../Helpers/constants.h"
class StripData : public QObject
{
    Q_OBJECT

    void addToStrip();
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

public:
    struct StripPoint{
        quint16 max1 = 0;
        quint16 max2 = 0;
        quint16 max3 = 0;
        quint16 max4 = 0;
        quint32 time = 0;
        quint32 encoder = 0;
        quint32 depthA = 0;
        quint32 depthB = 0;
        quint32 thickness = 0;
        quint8 sensors = 0;
    };
    explicit StripData(QObject *parent = nullptr);
    static QVector<double> vkStripA,vkStripB,vkStripDAC,
    vvStripA,vvStripB,vvStripDAC;
    static double stripLevelA, stripLevelB/*, stripLevelDAC*/;

    void generateData();
signals:

public slots:
};

#endif // STRIPDATA_H
