#ifndef BATTERYADAPTOR_H
#define BATTERYADAPTOR_H

#include <QObject>
#include "../Helpers/qmlintegrator.h"

class BatteryAdaptor : public QObject
{
    Q_OBJECT
    int minAdcCh = 9100;//9900;
    int maxAdcCh = 12820;//13000;
    int minAdc = 9100;
    int maxAdc = 12700;
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

public:
    explicit BatteryAdaptor(QObject *parent = nullptr);
    static void declareQML();

signals:

public slots:
private slots:

    void newBattery(const quint16&, const quint8&,const quint8&,const bool);

};

#endif // BATTERYADAPTOR_H
