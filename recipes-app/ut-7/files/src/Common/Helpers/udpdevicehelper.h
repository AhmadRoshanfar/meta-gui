#ifndef TCP
#ifndef TCPDEVICEHELPER_H
#define TCPDEVICEHELPER_H

#include <QObject>
#include <QDataStream>
#include <QNetworkSession>
#include "../Helpers/constants.h"
#include "../Helpers/qmlintegrator.h"
#include "udpascan.h"
#ifdef STRIP_CHART
#include "udpstrip.h"
#endif
#include "tcpcommands.h"
class DeviceHelper : public QObject
{
    Q_OBJECT
public:
//    explicit TCPDeviceHelper(QObject *parent = nullptr);
    DeviceHelper(const DeviceHelper&) = delete;
    DeviceHelper& operator=(const DeviceHelper &) = delete;
    DeviceHelper(DeviceHelper &&) = delete;
    DeviceHelper & operator=(DeviceHelper &&) = delete;
    static auto& instance(){
        static DeviceHelper test;
        return test;
    }



signals:
    void signalDataReady(const QVector<uint16_t>&);
    void signalPeaksReady(const QPointF& peakA, const QPointF& peakB,
                          const QPointF& flankA, const QPointF& flankB,
                          const QPointF& jflankA, const QPointF& jflankB,
                          const QPointF& upwardA, const QPointF& upwardB,
                          const QPointF& downwardA, const QPointF& downwardB);
    void signalKeyPress(const quint32&);
    //void signalBattery(const quint8&, const quint8&,const bool);
    void signalBattery(const quint16&, const quint8&,const quint8&,const bool);
#ifdef STRIP_CHART
    void signalStripReady(const QVector<StripData::StripPoint>&);
#endif
public slots:
    void sendGain();
    void sendPulseAmp();
    void sendStart();
    void sendStop();
    void sendRange();
    void sendAScanRefreshRate();
    void sendPRF();
    void newStarted();
    void sendFilterDampDual();
    void sendGate(quint8 gate, bool ifsync, double start, double finish);
    void sendGateA();
    void sendGateB();
    void sendIP(quint8 ip);
    void sendBrightness();
    void sendTCGPoints(uint32_t startIndex, uint32_t finishIndex, QVector<quint16> codes);

    void sendTCGDisable();

    void sendGateLevel(quint8 gate, double level);
    void sendGateLevelA();
    void sendGateLevelB();
    void sendKeyPress(char key);

    void sendAlarmActive();

private:
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    DeviceHelper(QObject *parent = 0);
    UDPAScan* pAScan;
#ifdef STRIP_CHART
    UDPStrip* pStrip;
#endif
    TCPCommands* pTCPCommands;

    bool _connected = false;

    void deviceConnect();
    void sendCommand(char reg, quint32 data);
    void deviceDisconnect();
};

#endif // TCPDEVICEHELPER_H

#endif
