#include "udpconnection.h"
#include <QAbstractSocket>
#include "../Helpers/currentip.h"

UDPConnection::UDPConnection(QObject *parent) : QObject(parent),
    pBuf(new QByteArray),
    pUDPSocket(new QUdpSocket(this))
{
    connect(pUDPSocket, &QIODevice::readyRead, this, &UDPConnection::readData);
    connect(pUDPSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &UDPConnection::displayError);
    //     qDebug()<<pTcpSocket->readBufferSize();
    //    pTcpSocket->setReadBufferSize(1456*1000);
    QFuture<void> future = QtConcurrent::run(this, &UDPConnection::packetizer );

    //    pTcpSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,1456*1000);
    //    qDebug()<<pTcpSocket->readBufferSize();
}
/*************************************************************/
void UDPConnection::readData()
{
    //    qDebug()<<"avail:"<<(port()==4096?"A":"S")<<pTcpSocket->bytesAvailable();
//    while(true){
        _mutex.lock();
//        if(pTcpSocket->state() != QAbstractSocket::ConnectedState){
//            QThread::msleep(30);
//            _mutex.unlock();
//            continue;
//        }
//        if(pTcpSocket->bytesAvailable()==0){
//            QThread::msleep(30);
//            _mutex.unlock();
//            continue;
//        }
        while (pUDPSocket->hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(pUDPSocket->pendingDatagramSize());
            pUDPSocket->readDatagram(datagram.data(), datagram.size());
            _queue.enqueue(datagram);

//            qDebug() << "Message receive: " << datagram.data();
        }
//        QByteArray data = (pUDPSocket->readAll());

        _mutex.unlock();
//    }
}

void UDPConnection::newRead(){
//        readData();
//    QFuture<void> future = QtConcurrent::run(this, &TCPConnection::readData );
}

void UDPConnection::packetizer(){
    QByteArray startbytes;
    startbytes.append(char(0xFF)).append(0x0F).append(char(0xFF));
    while (true) {
        int lastIdx = -_packetSize,startIdx = 0;

        if(_queue.count()==0){
            QThread::msleep(2);
            continue;
        }
        _mutex.lock();
        QByteArray buffer = _queue.dequeue();
        _mutex.unlock();

        while(startIdx >= 0){
            startIdx    = buffer.indexOf(startbytes,lastIdx+_packetSize);
            //        if(port() == 4097)qDebug()<<"s:"<<startIdx;
            if(startIdx == -1){
                //            qDebug()<<"/*/*/*/*/*/*/";
                break;
            }
            lastIdx = startIdx;
            QByteArray arr = buffer.mid(startIdx,_packetSize);
            emit processFrame(arr);
        }
        //        delete buffer;
        //        int len = pBuf->length() - pBuf->lastIndexOf(startbytes);
        //        lastIdx = pBuf->lastIndexOf(startbytes,lastIdx+_packetSize);
        //        //    if(port() == 4097)qDebug()<<"l:"<<lastIdx;
        //        if(lastIdx>0)
        //            pBuf->remove(0,lastIdx);
        //        else
        //        pBuf->clear();

    }
}

/*************************************************************/
void UDPConnection::deviceConnect()
{
//    pUDPSocket->connectToHost(_address,_port);
    CurrentIP ip;
    pUDPSocket->bind( QHostAddress("192.168.1."+QString::number(ip.getIP())), _port);
    _connected = true;
}
/*************************************************************/
void UDPConnection::deviceDisconnect()
{
//    pUDPSocket->disconnectFromHost();
    pUDPSocket->close();
    _connected = false;
}

/*************************************************************/
void UDPConnection::sendCommand(char reg, quint32 data){
    if(!_connected)
        return;
    char command[8];
    command[0] = char(0xFF);
    command[1] = 0x0F;
    command[2] = char(0xFF);
    command[3] = reg;
    command[4] = char((0x000000FF)&data);
    command[5] = char((0x0000FF00&data)>>8);
    command[6] = char((0x00FF0000&data)>>16);
    command[7] = char((0xFF000000&data)>>24);
    pUDPSocket->write(command,8);
}

/*************************************************************/

QString UDPConnection::address(){
    return _address;
}
void UDPConnection::setAddress(const 	QString &val){
    if (val == _address)
        return;
    _address = val;
    emit onAddressChanged();
}

int UDPConnection::port(){
    return _port;
}
void UDPConnection::setPort(const 	int &val){
    if (val == _port)
        return;
    _port = val;
    emit onPortChanged();
}

int UDPConnection::packetSize(){
    return _packetSize;
}
void UDPConnection::setPacketSize(const 	int &val){
    if (val == _packetSize)
        return;
    _packetSize = val;
    emit onPacketSizeChanged();
}

//int UDPConnection::packetHeaderSize(){
//    return _packetHeaderSize;
//}
//void UDPConnection::setPacketHeaderSize(const 	int &val){
//    if (val == _packetHeaderSize)
//        return;
//    _packetHeaderSize = val;
//    emit onPacketHeaderSizeChanged();
//}

//int UDPConnection::packetBodySize(){
//    return _packetBodySize;
//}
//void UDPConnection::setPacketBodySize(const 	int &val){
//    if (val == _packetBodySize)
//        return;
//    _packetBodySize = val;
//    emit onPacketBodySizeChanged();
//}



void UDPConnection::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        qDebug()<<tr("The host was closed.");

        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug()<<tr("The host was not found.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug()<<tr("The connection was refused");
        break;
    default:
        qDebug()<<tr("The following error occurred: %1.").arg(pUDPSocket->errorString());
    }

}
