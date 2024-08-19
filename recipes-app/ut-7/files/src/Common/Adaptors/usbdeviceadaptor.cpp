#include "usbdeviceadaptor.h"
#include "../Helpers/usbdiskhelper.h"
USBDeviceAdaptor::USBDeviceAdaptor(QObject *parent) : QObject(parent)
{

}

void USBDeviceAdaptor::checkUSBDevices(){
    if((_timer % 600) == 0){
        _qmlIntegrator.setUsbConnected( USBDiskHelper::checkList() != "");
    }
    _timer = (_timer+1)%(600);

}

void USBDeviceAdaptor::declareQML() {
    qmlRegisterType<USBDeviceAdaptor>("USBDeviceAdaptor", 1, 0, "USBDeviceAdaptor");
}
