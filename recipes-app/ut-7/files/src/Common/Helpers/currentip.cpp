#include "currentip.h"
#include <QNetworkInterface>
CurrentIP::CurrentIP(QObject *parent) : QObject(parent)
{

}

quint8 CurrentIP::getIP(){
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
             if((address.toIPv4Address()&0x0000FF00) == 0x00000100)
               return(address.toIPv4Address()&0xFF);
    }
}
