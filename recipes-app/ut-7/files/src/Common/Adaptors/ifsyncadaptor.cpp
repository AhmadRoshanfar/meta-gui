#include "ifsyncadaptor.h"
#include <QDebug>
QmlIntegrator& IFSyncAdaptor::_qmlIntegrator = QmlIntegrator::instance();
//QPointF IFSyncAdaptor::ref;
double IFSyncAdaptor::last = 0;
IFSyncAdaptor::IFSyncAdaptor(QObject *parent) : QObject(parent)
{

}

void IFSyncAdaptor::setRefPoint(){
    _qmlIntegrator.setIFSyncRef(_qmlIntegrator.currentUpwardB().x());
}

double IFSyncAdaptor::calc(){
    if(_qmlIntegrator.gateBSync() != Enums::SyncType::SYNC_IF){
        last = 0;
        _qmlIntegrator.setIFSyncRef(0);
        return 0;
    }
//    qDebug()<<"last+last :"<<_qmlIntegrator.currentUpwardB().x() - ref.x() /*+ last*/;
    if(_qmlIntegrator.currentUpwardB().x()>0)
        last = _qmlIntegrator.currentUpwardB().x() - _qmlIntegrator.iFSyncRef() + last;
    else last = 0;
//    qDebug()<<"last:"<<last;
}
    
double IFSyncAdaptor::trackingOffset(){

//    qDebug()<<"ref.x() :"<<ref.x();

//    qDebug()<<"*************************";
    return last;

}

void IFSyncAdaptor::declareQML() {
    qmlRegisterType<IFSyncAdaptor>("IFSyncAdaptor", 1, 0, "IFSyncAdaptor");
}
