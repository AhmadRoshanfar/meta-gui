#ifndef STRIPCHART_H
#define STRIPCHART_H
//#include <QtQuick>
#include "qcustomplot.h"
#include "../Helpers/qmlintegrator.h"

//class QCustomPlot;

class StripChart: public QCustomPlot /*: public QQuickPaintedItem*/
{
    Q_OBJECT
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

public:
    StripChart( QWidget* parent = 0 );
    virtual ~StripChart();

    void setData(QVector<double> vkStripA, QVector<double> vvStripA, QVector<double> vkStripB, QVector<double> vvStripB, QVector<double> vkStripDAC, QVector<double> vvStripDAC, double stripLevelA, double stripLevelB, bool gateAVisible, bool gateBVisible);
signals:
    void onClicked(double x, double y/*, int pixelX, int pixelY*/, double step);

public slots:
        void replotChart();
        void newTheme(QColor bg, QColor grid, QColor axis);

private:
    void setup();
private slots:

};
#endif // STRIPCHART_H
