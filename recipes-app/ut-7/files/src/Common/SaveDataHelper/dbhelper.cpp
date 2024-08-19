#include "dbhelper.h"
#include <QDebug>
#include "../Helpers/qmlintegrator.h"
DbHelper::DbHelper(QObject *parent) : QObject(parent)
{

}

void DbHelper::createTables(){
    QSqlQuery query("CREATE TABLE settings ([id] INTEGER PRIMARY KEY, [NAME] TEXT, [description] TEXT,[value] TEXT,CONSTRAINT [NAME] UNIQUE ([NAME]) ON CONFLICT REPLACE)");
    if(!query.isActive())
        qWarning() << "DatabaseCreate - ERROR: " << query.lastError().text();
    query = QSqlQuery("CREATE TABLE scan ([id] INTEGER PRIMARY KEY, [NAME] TEXT,[value] TEXT,CONSTRAINT [NAME] UNIQUE ([NAME]) ON CONFLICT REPLACE)");
    if(!query.isActive())
        qWarning() << "DatabaseCreate - ERROR: " << query.lastError().text();
    query = QSqlQuery("CREATE TABLE description ([id] INTEGER PRIMARY KEY, [NAME] TEXT,[value] TEXT,CONSTRAINT [NAME] UNIQUE ([NAME]) ON CONFLICT REPLACE)");
    if(!query.isActive())
        qWarning() << "DatabaseCreate - ERROR: " << query.lastError().text();
    query = QSqlQuery("CREATE TABLE params ([id] INTEGER PRIMARY KEY, [NAME] TEXT,[value] TEXT,CONSTRAINT [NAME] UNIQUE ([NAME]) ON CONFLICT REPLACE)");
    if(!query.isActive())
        qWarning() << "DatabaseCreate - ERROR: " << query.lastError().text();
}

bool DbHelper::insertSettings(QString name,QString desc, QJsonObject obj){

    QSqlQuery query;
    query.prepare("INSERT INTO settings([NAME],[description],[value]) VALUES(?,?,?)");
    query.addBindValue(QVariant(name));
    query.addBindValue(QVariant(desc));
    query.addBindValue(QVariant(_jsonFileHelper.toString(obj)));
    if(!query.exec()){
        qWarning() << "DbHelper::insertSettings - ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

bool DbHelper::deleteSettings(QString name){
    QSqlQuery query;
    query.prepare("DELETE FROM settings WHERE [NAME]=?");
    query.addBindValue(QVariant(name));
    if(!query.exec()){
        qWarning() << "DbHelper::deleteSettings - ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

bool DbHelper::updateSettings(QString name, QJsonObject obj){
    QSqlQuery query;
    query.prepare("UPDATE  settings SET [value] = ? where [NAME]=?");
    query.addBindValue(QVariant(_jsonFileHelper.toString(obj)));
    query.addBindValue(QVariant(name));

    if(!query.exec()){
        qWarning() << "DbHelper::updateSettings - ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

QJsonObject DbHelper::getSettings(QString name){
    QSqlQuery query;
    query.prepare("select  [value] FROM settings where [NAME]=?");
    query.addBindValue(QVariant(name));

    if(!query.exec())
        qWarning() << "DbHelper::getSettings - ERROR: " << query.lastError().text();
    if(query.first()){
        return _jsonFileHelper.fromString(QString(query.value(0).toString()));
    }
    else
        return QJsonObject();
}


QStringList DbHelper::listSettings(){
    QSqlQuery query;
    query.prepare("select  [Name] FROM settings");
    QStringList res;
    if(!query.exec())
        qWarning() << "DbHelper::getSettings - ERROR: " << query.lastError().text();
    while (query.next()){
        res.append(query.value(0).toString());
        query.nextResult();
    }
    return res;
}

bool DbHelper::existSettings(QString name){
    QSqlQuery query;
    query.prepare("select count([Value]) FROM settings where [NAME] = ?");
    query.addBindValue(QVariant(name));

    QStringList res;
    if(!query.exec())
        qWarning() << "DbHelper::latestSettings - ERROR: " << query.lastError().text();
    if(query.first()){
        return query.value(0).toInt()>0;
    }
}

QString DbHelper::getSettingsDescription(QString name){
    QSqlQuery query;
    query.prepare("select [description] FROM settings where [NAME] = ?");
    query.addBindValue(QVariant(name));

    QStringList res;
    if(!query.exec())
        qWarning() << "DbHelper::latestSettings - ERROR: " << query.lastError().text();
    if(query.first()){
        return query.value(0).toString();
    }
    return "";
}

QString DbHelper::latestSettings(){
    QSqlQuery query;
    query.prepare("select  [Value] FROM params where [NAME] = 'latest'");
    QStringList res;
    if(!query.exec())
        qWarning() << "DbHelper::latestSettings - ERROR: " << query.lastError().text();
    if(query.first()){
        return query.value(0).toString();
    }
    return "";
}

void DbHelper::setLatestSettings(QString name){
    QSqlQuery query;
    query.prepare("INSERT INTO params([NAME],[value]) VALUES('latest',?)");
    query.addBindValue(QVariant(name));
    if(!query.exec()){
        qWarning() << "DbHelper::setLatestSettings - ERROR: " << query.lastError().text();
    }
}

void DbHelper::vacuum(){
    QSqlQuery query("VACUUM;");
    query.exec();
}

void DbHelper::databaseConnect() {
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        QString filename = QString("%1/data.db").arg(QmlIntegrator::instance().applicationDirPath());

        //db.setDatabaseName(":memory:");
        db.setDatabaseName(filename);

        if(!db.open())
            qWarning() << "DatabaseConnect - ERROR: " << db.lastError().text();
    }
    else
        qWarning() << "DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}
