#ifndef TCPCOMMANDS_H
#define TCPCOMMANDS_H


#include <QObject>
#include "tcpconnection.h"
class TCPCommands: public QObject
{
    Q_OBJECT
public:
    explicit TCPCommands(QObject *parent = nullptr);
    void deviceConnect();
    void deviceDisconnect();
    void sendCommand(char reg, quint32 data);
signals:
    void signalKeyPress(const quint32&);
    void signalBattery(const quint16&, const quint8&,const quint8&,const bool);

private:
    TCPConnection *pTCPConnection;
    void processFrame(const QByteArray &frame);
};

#endif // TCPCOMMANDS_H


