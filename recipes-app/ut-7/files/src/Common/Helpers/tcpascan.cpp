#include "tcpascan.h"

TCPAScan::TCPAScan(QObject *parent):QObject (parent),
    pTempSignal(new QVector<uint16_t>(Constants::ASCAN_FULL_MESSAGE_SIZE,0)),
    pReceivedMask(new bool[Constants::RANGE_PAGES]),
    pTCPConnection(new TCPConnection)
{
    pTCPConnection->setAddress(Constants::UT_DEV_IP);
    pTCPConnection->setPort(4096);
    pTCPConnection->setPacketSize(730);
    connect(pTCPConnection,&TCPConnection::processFrame,this,&TCPAScan::processFrame);

}

/*************************************************************/
void TCPAScan::processFrame(const QByteArray& frame){
    if(frame.at(0)!=char(0xFF)||frame.at(1)!=char(0x0F)||frame.at(2)!=char(0xFF)){
        qDebug()<<"**********ERR**********"<<endl;
        return;
    }
    if(frame.count()<6)
        return;
    quint8 seqNo = quint8(frame.at(3)&0x0F);
    if(uint8_t(frame.at(5)) == 0xFF)
        return;
    quint16 sectorNo = quint16(uint8_t(frame.at(5))<<8 | uint8_t(frame.at(4)));
//    qDebug()<<seqNo<<":"<<sectorNo<<endl;
    if(sectorNo > Constants::RANGE_PAGES)
        return;

    if(frame.count() != Constants::ASCAN_FRAME_FULL_SIZE&&!(sectorNo == Constants::RANGE_PAGES-1 && frame.count()==Constants::ASCAN_FRAME_FULL_SIZE-1)){
        //                       qDebug()<<"cnt="<<frame.count()<<endl;
        return;
    }
    if(lastSeq!=seqNo){
        clearMask();
//                qDebug()<<"-------------"<<seqNo<<endl;
    }
    lastSeq = seqNo;
    //    quint8 sectorNo = quint8(frame.at(4));
    for(int i = Constants::ASCAN_FRAME_HEADER_SIZE; i < Constants::ASCAN_FRAME_FULL_SIZE; i+=2){
        pTempSignal->replace((sectorNo*Constants::ASCAN_FRAME_DATA_SIZE+i-Constants::ASCAN_FRAME_HEADER_SIZE)/2, uint8_t(frame.at(i+1))<<8 | uint8_t(frame.at(i)));
    }
    pReceivedMask[sectorNo] = true;
    //        qDebug()<<seqNo<<":"<<sectorNo<<endl;
    if(signalDataCompleted()){
        QVector<uint16_t> _signalData = pTempSignal->mid(0,Constants::RANGE_SIZE);
        emit signalDataReady(_signalData);
        clearMask();
        _signalData.clear();
//                qDebug()<<"+"<<seqNo<<endl;
    }
}


/*************************************************************/
bool TCPAScan::signalDataCompleted(){
    for (int i = 0;i<Constants::RANGE_PAGES;i++) {
        if(!pReceivedMask[i])
            return false;
    }
    return true;
}
/*************************************************************/
void TCPAScan::clearMask(){

    for (int i = 0;i<Constants::RANGE_PAGES;i++) {
        //            qDebug()<<pReceivedMask[i]<<",";
        pReceivedMask[i] = false;
    }
}


void TCPAScan::deviceConnect(){
    pTCPConnection->deviceConnect();
}

void TCPAScan::deviceDisconnect(){
    pTCPConnection->deviceDisconnect();
}

void TCPAScan::sendCommand(char reg, quint32 data){
    pTCPConnection->sendCommand(reg,data);
}
