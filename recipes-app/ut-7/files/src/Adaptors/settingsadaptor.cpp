#include "settingsadaptor.h"
#include <QDir>
#include "../Common/SaveDataHelper/jsonfilehelper.h"
#include "unistd.h"
#define FOLDER_NAME "settings"
SettingsAdaptor::SettingsAdaptor(QObject *parent) : QObject(parent)
{

}

void SettingsAdaptor::declareQML() {
    qmlRegisterType<SettingsAdaptor>("SettingsAdaptor", 1, 0, "SettingsAdaptor");
}

void SettingsAdaptor::loadDescription(){
    _subqmlIntegrator.setMemoryDescription(_dbHelper.getSettingsDescription(_qmlIntegrator.memoryFilename()));
}

void SettingsAdaptor::save(){
    //    QString filename = QString("%1/settings/%2.ini").arg(_qmlIntegrator.applicationDirPath()).arg(_qmlIntegrator.settingsFilename());
    auto zoomed = _qmlIntegrator.zoomed();
    _qmlIntegrator.setZoomed(false);

    _settingsHelper.save(_qmlIntegrator.memoryFilename(),_subqmlIntegrator.memoryDescription());
	_qmlIntegrator.setZoomed(zoomed);
    sync();
}

void SettingsAdaptor::recall(){

    //    QString filename = QString("%1/settings/%2.ini").arg(_qmlIntegrator.applicationDirPath()).arg(_qmlIntegrator.settingsFilename());
    //    if(QFile::exists(filename))
	auto zoomed = _qmlIntegrator.zoomed();
	_qmlIntegrator.setZoomed(false);
    //        _settingsHelper.read(filename);
    _settingsHelper.read(_qmlIntegrator.memoryFilename());
	_qmlIntegrator.setZoomed(zoomed);
}

void SettingsAdaptor::loadDefaults(){
    _settingsHelper.loadDefaults();
}

bool SettingsAdaptor::fileExists(QString name){
    //    auto path = QString("%1/%2/%3.ini").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME).arg(name);
    //    return (QFile(path).size()>0) && QFile::exists(path);
    return _dbHelper.existSettings(name);
}

void SettingsAdaptor::checkDir(){
    //    QDir dir = QDir(QString("%1/%2").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME));
    //    if(!dir.exists()){
    //        dir.mkdir(dir.path());
    //    }

}

void SettingsAdaptor::loadLatest(){
    auto latest = _dbHelper.latestSettings();
    _qmlIntegrator.setMemoryFilename(latest);
//    if(latest != "" && _settingsHelper.read(latest)){

//    }
//    else {
//        loadDefaults();
//    }
}

QStringList SettingsAdaptor::list(){

    //    QDir directory(QString("%1/%2").arg(_qmlIntegrator.applicationDirPath()).arg(FOLDER_NAME));
    //    QStringList list = directory.entryList(QStringList() << "*.ini" << "*.INI",QDir::Files);
    //    for(auto& str:list){
    //        str = str.replace(".ini","").replace(".INI","")/*.replace("_"," ")*/;
    //    }
    //    return list;
    return _dbHelper.listSettings();

}


void SettingsAdaptor::setLatest(){
    _dbHelper.setLatestSettings(_qmlIntegrator.memoryFilename());
    sync();
}

void SettingsAdaptor::sync(){
#ifdef Q_OS_UNIX
    //    fsync(file.handle());
    std::system("sync");
#endif
}

void SettingsAdaptor::remove(){
    _dbHelper.deleteSettings(_qmlIntegrator.memoryFilename());
    sync();
}
