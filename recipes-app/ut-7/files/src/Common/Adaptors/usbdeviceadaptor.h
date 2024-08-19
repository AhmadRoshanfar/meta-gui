#ifndef USBDEVICEADAPTOR_H
#define USBDEVICEADAPTOR_H

#include <QObject>
#include "../Helpers/qmlintegrator.h"

class USBDeviceAdaptor : public QObject
{
    Q_OBJECT
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    int _timer = 0;
public:
    explicit USBDeviceAdaptor(QObject *parent = nullptr);
    static void declareQML();

signals:

public slots:
    void checkUSBDevices();
};

#endif // USBDEVICEADAPTOR_H
