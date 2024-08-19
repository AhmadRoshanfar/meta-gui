#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include <QObject>
#include <QUdpSocket>
#include "../Helpers/constants.h"
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QMutex>
#include <QQueue>
class UDPConnection : public  QObject
{
    Q_OBJECT
    Q_PROPERTY(QString address      READ address            WRITE setAddress            NOTIFY onAddressChanged)
    Q_PROPERTY(int port             READ port               WRITE setPort               NOTIFY onPortChanged)
    Q_PROPERTY(int packetSize       READ packetSize         WRITE setPacketSize         NOTIFY onPacketSizeChanged)
//    Q_PROPERTY(int packetHeaderSize READ packetHeaderSize   WRITE setPacketHeaderSize   NOTIFY onPacketHeaderSizeChanged)
//    Q_PROPERTY(int packetBodySize   READ packetBodySize     WRITE setPacketBodySize     NOTIFY onPacketBodySizeChanged)
    QMutex _mutex;
    QQueue<QByteArray> _queue;
public:
    explicit UDPConnection(QObject *parent = nullptr);

    void deviceConnect();
    void deviceDisconnect();
    void sendCommand(char reg, quint32 data);
    /***********************************/

    QString address();
    void setAddress(const 	QString&val);
    int port();
    void setPort(const 	int&val);
    int packetSize();
    void setPacketSize(const 	int&val);
//    int packetHeaderSize();
//    void setPacketHeaderSize(const 	int&val);
//    int packetBodySize();
//    void setPacketBodySize(const 	int&val);
    /***********************************/
signals:
    void processFrame(const QByteArray &frame);
    void onAddressChanged();
    void onPortChanged();
    void onPacketSizeChanged();
//    void onPacketHeaderSizeChanged();
//    void onPacketBodySizeChanged();
public slots:
private slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void newRead();
    void readData();

private:
    QString _address;
    int _port = 0, _packetSize = 0/*, _packetHeaderSize = 0, _packetBodySize = 0*/;
    //    virtual void processFrame(const QByteArray &frame) = 0;
    [[noreturn]]void packetizer();

protected:


    bool _connected = false;
    QUdpSocket *pUDPSocket = nullptr;
    QByteArray *pBuf = nullptr;

};

#endif // UDPCONNECTION_H
