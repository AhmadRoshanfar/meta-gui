#ifndef UDPSTRIP_H
#define UDPSTRIP_H


#include <QObject>
#include "udpconnection.h"
#include "../ChartData/stripdata.h"
#include <QUdpSocket>

class UDPStrip : public  QObject
{
    Q_OBJECT
    QUdpSocket* socket = nullptr;
public:
    UDPStrip(QObject *parent=nullptr);

    void deviceConnect();
    void deviceDisconnect();
signals:
    void signalStripReady(const QVector<StripData::StripPoint>& points);

protected:
    void processFrame(const QByteArray &frame);
private slots:
    void readyRead();
private:
    UDPConnection *pTCPConnection;
};

#endif // TCPSTRIP_H
