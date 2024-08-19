#ifndef SETTINGSADAPTOR_H
#define SETTINGSADAPTOR_H

#include <QObject>
#include "SaveDataHelper/settingshelper.h"
#include "../Common/Helpers/qmlintegrator.h"
#include "../Common/SaveDataHelper/dbhelper.h"
#include "Helpers/subqmlintegrator.h"

class SettingsAdaptor : public QObject
{
    Q_OBJECT
    SettingsHelper _settingsHelper;
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    SubQMLIntegrator& _subqmlIntegrator = SubQMLIntegrator::instance();

    DbHelper& _dbHelper = DbHelper::instance();

public:
    explicit SettingsAdaptor(QObject *parent = nullptr);

    static void declareQML();
    void mkDir();
    void loadLatest();

signals:

public slots:
    void save();
    void remove();
    void recall();
    bool fileExists(QString index);
    void checkDir();
    void setLatest();
    void loadDefaults();
    void sync();
    QStringList list();
    void loadDescription();
};

#endif // SETTINGSADAPTOR_H
