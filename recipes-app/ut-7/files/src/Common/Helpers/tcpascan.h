#ifndef TCPASCAN_H
#define TCPASCAN_H

#include <QObject>
#include "tcpconnection.h"
class TCPAScan : public QObject
{
    Q_OBJECT
public:
    explicit TCPAScan(QObject *parent = nullptr);
    void deviceConnect();
    void deviceDisconnect();
    void sendCommand(char reg, quint32 data);
signals:
    void signalDataReady(const QVector<uint16_t>&);

protected:
    void processFrame(const QByteArray &frame);
private:
    TCPConnection *pTCPConnection;
    int lastSeq = 0, lastSect = 0;
    QVector<uint16_t>* pTempSignal;
    bool *pReceivedMask;
    bool signalDataCompleted();
    void clearMask();
};

#endif // TCPASCAN_H
