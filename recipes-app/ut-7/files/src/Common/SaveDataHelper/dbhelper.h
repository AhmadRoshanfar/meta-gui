#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QJsonObject>
#include "jsonfilehelper.h"
class DbHelper : public QObject
{
    Q_OBJECT
    JSONFileHelper _jsonFileHelper;

public:
    explicit DbHelper(QObject *parent = nullptr);
    DbHelper(const DbHelper&) = delete;
    DbHelper & operator= (const DbHelper &) = delete;
    DbHelper(DbHelper &&) = delete;
    DbHelper & operator= (DbHelper &&) = delete;
    static DbHelper& instance(){
        static DbHelper test;
        return test;
    }
    void createTables();
    void databaseConnect();
    bool insertSettings(QString name, QString desc, QJsonObject obj);
    bool deleteSettings(QString name);
    bool updateSettings(QString name, QJsonObject obj);
    QJsonObject getSettings(QString name);
    void vacuum();
    QString latestSettings();
    void setLatestSettings(QString name);
    bool existSettings(QString name);
    QString getSettingsDescription(QString name);
signals:

public slots:
    QStringList listSettings();
};

#endif // DBHELPER_H
