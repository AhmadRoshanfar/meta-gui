#include "batteryadaptor.h"
#include "../Helpers/devicehelper.h"
BatteryAdaptor::BatteryAdaptor(QObject *parent) : QObject(parent)
{
    connect(&DeviceHelper::instance(),&DeviceHelper::signalBattery,this,&BatteryAdaptor::newBattery);
}

void BatteryAdaptor::newBattery(const quint16& vacs, const quint8& ich,const quint8& vbat,const bool connected){

    const int Rin_DISCHARGE=57;
    const int Rin_CHARGE=50;
    const int Ich_VALID_VAL=96;
    const int Vacs_VALID_VAL=46580;
    const int Vacs_BAT_DISCHARGE_VAL=40000;
    const int Vbat_ACTUAL_VALID_VAL=3000;
    const int Vbat_ACTUAL_MAX_VAL=4200;
    const int Vbat_ACTUAL_MIN_VAL=3250;//3120;
    const int Vbat_MORE_THAN_ONE_PERCENT_VAL=3265;
    const int Vbat_ONE_PERCENT_VAL=3260;

    static double Iacs=0;
    double Rin = 50;
    double Vbat_actual=0;
    static double Vbat_actual_old=0;
    double Vbat_read_percent=0;
    static bool start_flag=false;
    static quint16 Icharge = 0;
    static quint16 Vbat_read = 0 ;

    if (!connected)
    {
        Rin =Rin_DISCHARGE;
        _qmlIntegrator.setBatteryCharging(false);
    }
    else
    {
        Rin = Rin_CHARGE;
        _qmlIntegrator.setBatteryCharging(true);
    }

    if(ich < Ich_VALID_VAL)//valid data
    {
        Icharge = 50*ich;
        Vbat_read = (20*vbat) + 2300 ;
    }

    if(vacs >= Vacs_VALID_VAL)//valid data
    {
        Iacs = (((vacs * 0.053636)  - 2500) / 0.186);
        Vbat_actual = Vbat_read - ((Rin/1000) * (Icharge - Iacs ));
        if(start_flag == false)
        {
            Vbat_actual_old = Vbat_actual;
            start_flag = true;
        }
        if(Vbat_actual_old < Vbat_ACTUAL_VALID_VAL)
        {
            Vbat_actual_old = Vbat_actual;
        }
        if (vbat>0)
        {
            Vbat_actual_old=(Vbat_actual+(59* Vbat_actual_old))/60;
            Vbat_read_percent = (Vbat_actual_old - Vbat_ACTUAL_MIN_VAL) / (Vbat_ACTUAL_MAX_VAL - Vbat_ACTUAL_MIN_VAL);
        }
        if((!connected) && ((Vbat_actual_old <Vbat_ONE_PERCENT_VAL)|| (vbat==0)))
        {
            Vbat_read_percent=0.01;
        }
        if((connected) && ((Vbat_actual_old < Vbat_MORE_THAN_ONE_PERCENT_VAL)))
        {
            Vbat_read_percent=0.01;
        }
        _qmlIntegrator.setBatteryLevel((uint32_t)(Vbat_read_percent * 100));
    }

    if(vacs < Vacs_BAT_DISCHARGE_VAL)// Battery is disconnected
    {
        start_flag = false;
        _qmlIntegrator.setBatteryLevel((int)(-1));
        //       qDebug()<<"Battery is disconnected: "<< vacs;
    }
    //       qDebug()<< "Vbattery_Read_Value: "<< Vbat_read<< "Vbattery_Actual: "<< Vbat_actual<< "Vbattery_Actual_avg: "<< Vbat_actual_old <<"percent: "<< Vbat_read_percent * 100;

}

void BatteryAdaptor::declareQML() {
    qmlRegisterType<BatteryAdaptor>("BatteryAdaptor", 1, 0, "BatteryAdaptor");
}
