#ifndef ALARMADAPTOR_H
#define ALARMADAPTOR_H

#include <QObject>
#include "../Helpers/qmlintegrator.h"

class AlarmAdaptor : public QObject
{
    Q_OBJECT
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

public:
    explicit AlarmAdaptor(QObject *parent = nullptr);
    static void declareQML();


signals:

public slots:
    void checkAlarms();
};

#endif // ALARMADAPTOR_H
