#include "stripdata.h"
QVector<double> StripData::vkStripA,StripData::vkStripB,StripData::vkStripDAC,
StripData::vvStripA,StripData::vvStripB,StripData::vvStripDAC;
double StripData::stripLevelA, StripData::stripLevelB;

StripData::StripData(QObject *parent) : QObject(parent)
{

}

void StripData::addToStrip(){
    double maxA = qAbs(_qmlIntegrator.currentPeakA().y());
    double maxB = qAbs(_qmlIntegrator.currentPeakB().y());


    if(!vkStripA.isEmpty()){
        vkStripA.append(vkStripA.last()+1.0/Constants::ASCAN_REF_RATE);
        vvStripA.append( maxA);
        vkStripB.append(vkStripB.last()+1.0/Constants::ASCAN_REF_RATE);
        vvStripB.append( maxB);
    }
    else{
        vkStripA.append(0);
        vvStripA.append(maxA);
        vkStripB.append(0);
        vvStripB.append(maxB);
    }
}

void StripData::generateData(){
//    vkStripLevelA.clear();
//    vvStripLevelA.clear();
//    vkStripLevelB.clear();
//    vvStripLevelB.clear();
    addToStrip();

//    vkStripLevelA.append(0);
//    vvStripLevelA.append( _qmlIntegrator.gateALevel());
//    vkStripLevelA.append(_qmlIntegrator.stripAxisXMax());
//    vvStripLevelA.append(_qmlIntegrator.gateALevel());
//    vkStripLevelB.append(0);
//    vvStripLevelB.append( _qmlIntegrator.gateBLevel());
//    vkStripLevelB.append(_qmlIntegrator.stripAxisXMax());
//    vvStripLevelB.append(_qmlIntegrator.gateBLevel());


}
