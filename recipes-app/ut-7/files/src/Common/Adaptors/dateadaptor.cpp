#include "dateadaptor.h"
#include <QtQml>
#include "../Helpers/datetimerhelper.h"

DateAdaptor::DateAdaptor(QObject *parent) : QObject(parent)
{
    _date = QDateTime::currentDateTime();
}

void DateAdaptor::setDateTime(int y, int M, int d, int h, int m, int s){
    DateTimerHelper().setDateTime(y,M,d,h,m,s,true);
}

void DateAdaptor::init(){
    DateTimerHelper().init();
}

QDateTime DateAdaptor::nextDay(){
    int dim = _date.date().daysInMonth();
    _date.setDate(QDate(_date.date().year(),_date.date().month(), (_date.date().day())%dim+1));
    return _date;
}

QDateTime DateAdaptor::previousDay(){
    int dim = _date.date().daysInMonth();
    _date.setDate(QDate(_date.date().year(),_date.date().month(), (dim+_date.date().day()-2)%dim+1));
    return _date;
}


QDateTime DateAdaptor::nextMonth(){
    QDate temp(_date.date().year(),(_date.date().month())%12+1,1);
    int newDay = qMin(temp.daysInMonth(), _date.date().day());
    _date.setDate(QDate(_date.date().year(),(_date.date().month())%12+1, newDay));
    return _date;
}

QDateTime DateAdaptor::previousMonth(){
    QDate temp(_date.date().year(),(_date.date().month()+10)%12+1,1);
    int newDay = qMin(temp.daysInMonth(), _date.date().day());
    _date.setDate(QDate(_date.date().year(),(_date.date().month()+10)%12+1, newDay));
    return _date;
}

QDateTime DateAdaptor::nextYear(){
    int newYear = 2000+(_date.date().year()-1999)%100;
    QDate temp(newYear,_date.date().month(),1);
    int newDay = qMin(temp.daysInMonth(), _date.date().day());
    _date.setDate(QDate(newYear,_date.date().month(), newDay));
    return _date;
}

QDateTime DateAdaptor::previousYear(){
    int newYear = 2000+(_date.date().year()-1901)%100;
    QDate temp(newYear,_date.date().month(),1);
    int newDay = qMin(temp.daysInMonth(), _date.date().day());
    _date.setDate(QDate(newYear,_date.date().month(), newDay));
    return _date;
}

QDateTime DateAdaptor::now(){
    return QDateTime::currentDateTime();
}

int DateAdaptor::currentDay(){
    return QDateTime::currentDateTime().date().day();
}


int DateAdaptor::currentMonth(){
    return QDateTime::currentDateTime().date().month();
}


int DateAdaptor::currentYear(){
    return QDateTime::currentDateTime().date().year();
}

int DateAdaptor::currentHour(){
    return QDateTime::currentDateTime().time().hour();
}

int DateAdaptor::currentMin(){
    return QDateTime::currentDateTime().time().minute();
}

int DateAdaptor::currentSec(){
    return QDateTime::currentDateTime().time().second();
}

void DateAdaptor::declareQML() {
    qmlRegisterType<DateAdaptor>("DateAdaptor", 1, 0, "DateAdaptor");
}
