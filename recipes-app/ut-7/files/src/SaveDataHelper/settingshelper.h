#ifndef SETTINGSHELPER_H
#define SETTINGSHELPER_H

#include <QObject>
#include <QFile>
#include <QMap>
#include <QDataStream>
#include <QDebug>
#include "../Common/Helpers/qmlintegrator.h"
#include "Helpers/subqmlintegrator.h"
#include "../Common/SaveDataHelper/jsonfilehelper.h"
#include "../Common/Adaptors/evaluationadaptor.h"
#include "../Common/SaveDataHelper/dbhelper.h"
class SettingsHelper : public QObject
{
    Q_OBJECT
    JSONFileHelper _jsonFileHelper;
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    SubQMLIntegrator& _subqmlIntegrator = SubQMLIntegrator::instance();
    EvaluationAdaptor &evalAdap = EvaluationAdaptor::instance();
    DbHelper& _dbHelper = DbHelper::instance();

public:
    explicit SettingsHelper(QObject *parent = nullptr);

    bool save(QString, QString desc);
    bool read(QString);
    void loadDefaults();
signals:

public slots:
};

#endif // SETTINGSHELPER_H
