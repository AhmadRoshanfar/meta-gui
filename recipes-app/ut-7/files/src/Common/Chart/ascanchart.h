#ifndef ASCANCHART_H
#define ASCANCHART_H
//#include <QtQuick>
#include "qcustomplot.h"
#include "../Helpers/qmlintegrator.h"

//class QCustomPlot;

class AScanChart: public QCustomPlot /*: public QQuickPaintedItem*/
{
    Q_OBJECT
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    QCPItemText *textLabel;
    bool _isSetup = false;
public:
    AScanChart( QWidget* parent = 0 );
    virtual ~AScanChart();

    void setData(QVector<double> mainK, QVector<double> mainV, QVector<double> OAK, QVector<double> OAV, QVector<double> OBK, QVector<double> OBV, QVector<double> envK, QVector<double> envV, QVector<double> dac100K, QVector<double> dac100V, QVector<double> dac50K, QVector<double> dac50V, QVector<double> dac20K, QVector<double> dac20V, QVector<double> currentMarkerK, QVector<double> currentMarkerV, QVector<double> evalMarkersK, QVector<double> evalMarkersV, QVector<double> legK, QVector<double> legV, double GALevel, double GAStart, double GAEnd, double GBLevel, double GBStart, double GBEnd,QString title, double textValue);
signals:
    void onClicked(double x, double y/*, int pixelX, int pixelY*/, double step);

public slots:
        void replotChart();
        void newTheme(QColor bg, QColor main, QColor envelope, QColor grid, QColor axis);

private:
    void setup();
private slots:

};
#endif // ASCANCHART_H
