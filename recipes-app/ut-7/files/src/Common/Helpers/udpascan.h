#ifndef UDPASCAN_H
#define UDPASCAN_H

#include <QObject>
#include "tcpconnection.h"
#include "udpconnection.h"
class UDPAScan : public QObject
{
    Q_OBJECT
public:
    explicit UDPAScan(QObject *parent = nullptr);
    void deviceConnect();
    void deviceDisconnect();
    void sendCommand(char reg, quint32 data);
signals:
    void signalDataReady(const QVector<uint16_t>&);
    void signalPeaksReady(const QPointF& peakA, const QPointF& peakB,
                          const QPointF& flankA, const QPointF& flankB,
                          const QPointF& jflankA, const QPointF& jflankB,
                          const QPointF& upwardA, const QPointF& upwardB,
                          const QPointF& downwardA, const QPointF& downwardB);



protected:
    void processFrame(const QByteArray &frame);
private:
    UDPConnection *pConnection;
    int lastSeq = 0, lastSect = 0;
    QVector<uint16_t>* pTempSignal;
    bool *pReceivedMask;
    bool signalDataCompleted();
    void clearMask();
};

#endif // TCPASCAN_H
