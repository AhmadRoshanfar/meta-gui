#include "udpstrip.h"

UDPStrip::UDPStrip(QObject *parent) :QObject (parent),
    pTCPConnection(new UDPConnection),
    socket(new QUdpSocket(this))
{
    pTCPConnection->setAddress(Constants::UT_DEV_IP);
    pTCPConnection->setPort(4097);
    pTCPConnection->setPacketSize(1456);

    connect(pTCPConnection,&UDPConnection::processFrame,this,&UDPStrip::processFrame);
}

void UDPStrip::readyRead()
{
   while (socket->hasPendingDatagrams()) {
       QByteArray datagram;
       datagram.resize(socket->pendingDatagramSize());
       socket->readDatagram(datagram.data(), datagram.size());
       qDebug() << "Message receive: " << datagram.data();
   }
}

/*************************************************************/
void UDPStrip::processFrame(const QByteArray& frame){
    if(frame.at(0)!=char(0xFF)||frame.at(1)!=char(0x0F)||frame.at(2)!=char(0xFF)){
        qDebug()<<"**********ERR**********"<<endl;
        return;
    }
    if((frame.at(3)&char(0xF0))!=char(0xC0))
        return;
    if(frame.count() != pTCPConnection->packetSize())
        return;
    QVector<StripData::StripPoint> arr;

    for (int i=0;i<52;i++) {
        int startIdx= i*28;
        struct StripData::StripPoint point;
        point.max1 = quint16(quint8(frame.at(startIdx+5))<<8  | quint8(frame.at(startIdx+4 )));
        point.max2 = quint16(quint8(frame.at(startIdx+7))<<8  | quint8(frame.at(startIdx+6 )));
        point.max3 = quint16(quint8(frame.at(startIdx+9))<<8  | quint8(frame.at(startIdx+8 )));
        point.max4 = quint16(quint8(frame.at(startIdx+11))<<8 | quint8(frame.at(startIdx+10)));
        point.time = quint32(quint8(frame.at(startIdx+14))<<16 | quint8(frame.at(startIdx+13))<<8 | quint8(frame.at(startIdx+12)));
        point.encoder = quint32(quint8(frame.at(startIdx+17))<<16 | quint8(frame.at(startIdx+16))<<8 | quint8(frame.at(startIdx+15)));
        point.depthA = quint32(quint8(frame.at(startIdx+20))<<16 | quint8(frame.at(startIdx+19))<<8 | quint8(frame.at(startIdx+18)));
        point.depthB = quint32(quint8(frame.at(startIdx+23))<<16 | quint8(frame.at(startIdx+22))<<8 | quint8(frame.at(startIdx+21)));
        point.thickness = quint32(quint8(frame.at(startIdx+26))<<16 | quint8(frame.at(startIdx+25))<<8 | quint8(frame.at(startIdx+24)));
        point.sensors = quint8(quint8(frame.at(startIdx+27)));
        arr.append(point);
//        qDebug()<<point.time;
    }
     emit signalStripReady(arr);
    //            qDebug()<<seqNo<<":"<<sectorNo<<endl;

}

void UDPStrip::deviceConnect(){
    pTCPConnection->deviceConnect();
}

void UDPStrip::deviceDisconnect(){
    pTCPConnection->deviceDisconnect();
}


