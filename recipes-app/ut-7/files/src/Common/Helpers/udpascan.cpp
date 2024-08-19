#include "udpascan.h"
#include "../Calculations/chartscalculations.h"
UDPAScan::UDPAScan(QObject *parent):QObject (parent),
    pTempSignal(new QVector<uint16_t>(Constants::ASCAN_FULL_MESSAGE_SIZE,0)),
    pReceivedMask(new bool[Constants::RANGE_PAGES]),
    pConnection(new UDPConnection)
{
    pConnection->setAddress(Constants::UT_DEV_IP);
    pConnection->setPort(4096);
    pConnection->setPacketSize(730);
    connect(pConnection,&UDPConnection::processFrame,this,&UDPAScan::processFrame);

}

/*************************************************************/
void UDPAScan::processFrame(const QByteArray& frame){
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
        double coef = Constants::FILTER_COEF[QmlIntegrator::instance().digitalFilter()]/20.47*qPow(10.0,QmlIntegrator::instance().gateAGain()/20.0);

        quint16 peakY = uint8_t(frame.at(729))<<8 | uint8_t(frame.at(728));
        quint32 peakX =  /*uint8_t(frame.at(727))<<24 |*/ uint8_t(frame.at(726))<<16|uint8_t(frame.at(725))<<8 | uint8_t(frame.at(724));
        quint16 flankY = uint8_t(frame.at(723))<<8 | uint8_t(frame.at(722));
        quint32 flankX =  /*uint8_t(frame.at(721))<<24 |*/ uint8_t(frame.at(720))<<16|uint8_t(frame.at(719))<<8 | uint8_t(frame.at(718));
        quint16 jflankY = uint8_t(frame.at(717))<<8 | uint8_t(frame.at(716));
        quint32 jflankX =  /*uint8_t(frame.at(715))<<24 |*/ uint8_t(frame.at(714))<<16|uint8_t(frame.at(713))<<8 | uint8_t(frame.at(712));
        quint16 upwardY = uint8_t(frame.at(693))<<8 | uint8_t(frame.at(692));
        quint32 upwardX =  /*uint8_t(frame.at(691))<<24 |*/ uint8_t(frame.at(690))<<16|uint8_t(frame.at(689))<<8 | uint8_t(frame.at(688));
        quint16 downwardY = uint8_t(frame.at(687))<<8 | uint8_t(frame.at(686));
        quint32 downwardX =  /*uint8_t(frame.at(685))<<24 |*/ uint8_t(frame.at(684))<<16|uint8_t(frame.at(683))<<8 | uint8_t(frame.at(682));
        QPointF peakA(ChartsCalculations::lengthFromIndex(int(peakX-1)),qMin(100.0,((peakY>2047)?peakY-4096:peakY)*coef));
        QPointF flankA(ChartsCalculations::lengthFromIndex(flankX-1),qMin(100.0,((flankY>2047)?flankY-4096:flankY)*coef));
        QPointF jflankA(ChartsCalculations::lengthFromIndex(jflankX-1),qMin(100.0,((jflankY>2047)?jflankY-4096:jflankY)*coef));
        QPointF upwardA(ChartsCalculations::lengthFromIndex(upwardX-1),qMin(100.0,((upwardY>2047)?upwardY-4096:upwardY)*coef));
        QPointF downwardA(ChartsCalculations::lengthFromIndex(downwardX-1),qMin(100.0,((downwardY>2047)?downwardY-4096:downwardY)*coef));
        if(flankX == 0)
            flankA.setX(0);
        if(jflankX == 0)
            jflankA.setX(0);
        if(upwardX == 0)
            upwardA.setX(0);
        if(downwardX == 0)
            downwardA.setX(0);
//        qDebug()<<flankX<<jflankX<<flankA.x()<<jflankA.x()<<"++++++++++++++++++++";
        coef = Constants::FILTER_COEF[QmlIntegrator::instance().digitalFilter()]/20.47*qPow(10.0,QmlIntegrator::instance().gateBGain()/20.0);
        peakY = uint8_t(frame.at(711))<<8 | uint8_t(frame.at(710));
        peakX = /* uint8_t(frame.at(709))<<24 |*/ uint8_t(frame.at(708))<<16|uint8_t(frame.at(707))<<8 | uint8_t(frame.at(706));
        flankY = uint8_t(frame.at(705))<<8 | uint8_t(frame.at(704));
        flankX =  /*uint8_t(frame.at(703))<<24 |*/ uint8_t(frame.at(702))<<16|uint8_t(frame.at(701))<<8 | uint8_t(frame.at(700));
        jflankY = uint8_t(frame.at(699))<<8 | uint8_t(frame.at(698));
        jflankX =  /*uint8_t(frame.at(697))<<24 |*/ uint8_t(frame.at(696))<<16|uint8_t(frame.at(695))<<8 | uint8_t(frame.at(694));
        upwardY = uint8_t(frame.at(681))<<8 | uint8_t(frame.at(680));
        upwardX =  /*uint8_t(frame.at(679))<<24 |*/ uint8_t(frame.at(678))<<16|uint8_t(frame.at(677))<<8 | uint8_t(frame.at(676));
        downwardY = uint8_t(frame.at(675))<<8 | uint8_t(frame.at(674));
        downwardX =  /*uint8_t(frame.at(673))<<24 | */uint8_t(frame.at(672))<<16|uint8_t(frame.at(671))<<8 | uint8_t(frame.at(670));

        QPointF peakB(ChartsCalculations::lengthFromIndex(int(peakX-1)),qMin(100.0,((peakY>2047)?peakY-4096:peakY)*coef));
        QPointF flankB(ChartsCalculations::lengthFromIndex(flankX-1),qMin(100.0,((flankY>2047)?flankY-4096:flankY)*coef));
        QPointF jflankB(ChartsCalculations::lengthFromIndex(jflankX-1),qMin(100.0,((jflankY>2047)?jflankY-4096:jflankY)*coef));
        QPointF upwardB(ChartsCalculations::lengthFromIndex(upwardX-1),qMin(100.0,((upwardY>2047)?upwardY-4096:upwardY)*coef));
        QPointF downwardB(ChartsCalculations::lengthFromIndex(downwardX-1),qMin(100.0,((downwardY>2047)?downwardY-4096:downwardY)*coef));
        if(flankX == 0)
            flankB.setX(0);
        if(jflankX == 0)
            jflankB.setX(0);
        if(upwardX == 0)
            upwardB.setX(0);
        if(downwardX == 0)
            downwardB.setX(0);

        emit signalPeaksReady(peakA,peakB,flankA, flankB,jflankA, jflankB, upwardA, upwardB, downwardA, downwardB);

//        qDebug()<<peakA.x()<<peakA.y()<<flankA.x()<<flankA.y()<<jflankA.x()<<jflankA.y()<<upwardA.x()<<upwardA.y()<<downwardA.x()<<downwardA.y();
//        qDebug()<<"+"<<seqNo<<endl;
    }
}


/*************************************************************/
bool UDPAScan::signalDataCompleted(){
    for (int i = 0;i<Constants::RANGE_PAGES;i++) {
        if(!pReceivedMask[i])
            return false;
    }
    return true;
}
/*************************************************************/
void UDPAScan::clearMask(){

    for (int i = 0;i<Constants::RANGE_PAGES;i++) {
        //            qDebug()<<pReceivedMask[i]<<",";
        pReceivedMask[i] = false;
    }
}


void UDPAScan::deviceConnect(){
    pConnection->deviceConnect();
}

void UDPAScan::deviceDisconnect(){
    pConnection->deviceDisconnect();
}

void UDPAScan::sendCommand(char reg, quint32 data){
    pConnection->sendCommand(reg,data);
}
