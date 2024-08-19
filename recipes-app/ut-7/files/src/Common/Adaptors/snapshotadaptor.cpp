#include "snapshotadaptor.h"
#include <QDir>
#include <QStorageInfo>
#include <QPixmap>
#include <QDateTime>
#include <QDebug>
#define FOLDER_NAME "snapshots"


SnapshotAdaptor::SnapshotAdaptor(QObject *parent) : QObject(parent)
{

}

void SnapshotAdaptor::declareQML() {
    qmlRegisterType<SnapshotAdaptor>("SnapshotAdaptor", 1, 0, "SnapshotAdaptor");
}

QStringList SnapshotAdaptor::list(){
    QDir directory(QString("%1/%2").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME));
    QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
    for(auto& str:images){
        str = str.replace(".png","").replace(".PNG","")/*.replace("_"," ")*/;
    }
    return images;
}




bool SnapshotAdaptor::fileExists(QString name){
    auto file = QString("%1/%2/%3.png").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME).arg(name);
    return QFile::exists(file);
}

void SnapshotAdaptor::remove(){
    auto file = QString("%1/%2/%3.png").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME).arg(_qmlIntegrator.currentSnapshot());

    if(fileExists(_qmlIntegrator.currentSnapshot())){
        QFile::remove(file);
        _usbdiskhelper.sync();
    }
}


QString SnapshotAdaptor::newSnapshotName(){
    checkDir();
    return QString("%1/%2/%3.png").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME).arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
}

void SnapshotAdaptor::checkDir(){
    QDir dir = QDir(QString("%1/%2").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME));
    if(!dir.exists()){
        dir.mkdir(dir.path());
    }
}

QPixmap SnapshotAdaptor::currentSnapshotPix(){
    QPixmap pic(QString("%1/%2/%3.png").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME).arg(_qmlIntegrator.currentSnapshot()));
    return pic;
}

bool SnapshotAdaptor::copyFiles(){
    qDebug() << "copyFiles"<<QStorageInfo::mountedVolumes().count();

    QString path1= FOLDER_NAME;
    return _usbdiskhelper.copyDirToUSB(path1);
}

void SnapshotAdaptor::sync(){
    _usbdiskhelper.sync();
}
