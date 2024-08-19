#include "tcpcommands.h"
#include "constants.h"

TCPCommands::TCPCommands(QObject *parent):QObject (parent),
    pTCPConnection(new TCPConnection)
{
    pTCPConnection->setAddress(Constants::UT_DEV_IP);
    pTCPConnection->setPort(4098);
    pTCPConnection->setPacketSize(8);
    connect(pTCPConnection,&TCPConnection::processFrame,this,&TCPCommands::processFrame);
}

void TCPCommands::deviceConnect(){
    pTCPConnection->deviceConnect();
}

void TCPCommands::deviceDisconnect(){
    pTCPConnection->deviceDisconnect();
}

void TCPCommands::sendCommand(char reg, quint32 data){
    pTCPConnection->sendCommand(reg,data);
}

void TCPCommands::processFrame(const QByteArray& frame){
    if(frame.at(0)!=char(0xFF)||frame.at(1)!=char(0x0F)||frame.at(2)!=char(0xFF)){
        qDebug()<<"**********ERR**********"<<endl;
        return;
    }
    if(frame.count()<8)
        return;
    if(frame.at(3) == char(0x0F)){
        quint32 key = quint32(quint8(frame.at(4)))|(quint32(quint8(frame.at(5)))<<8)|(quint32(quint8(frame.at(6)))<<16)|(quint32(quint8(frame.at(7)))<<24);
        emit signalKeyPress(key);
    }
    else if(frame.at(3) == char(0x1F)){
        quint16 vacs = quint16(quint8(frame.at(4)))|(quint16(quint8(frame.at(5)))<<8);//uint16(frame.at(4));
        quint8 ich = quint8(frame.at(6))&0x7F;
        quint8 vbat = quint8(frame.at(7))&0x7F;
        //bool connected = (quint8(frame.at(6))&0x01)==0x01;
        bool connected = (quint8(frame.at(6))&0x7f)>0;
        emit signalBattery(vacs, ich, vbat, connected);
    }
}
