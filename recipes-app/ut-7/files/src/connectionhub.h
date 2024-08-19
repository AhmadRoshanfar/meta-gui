#ifndef CONNECTIONHUB_H
#define CONNECTIONHUB_H

#include <QObject>
#include "../Common/utdevice.h"
#include "../Common/Helpers/qmlintegrator.h"

class ConnectionHub : public QObject
{
    Q_OBJECT
    UTDevice utd;
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

private slots:
    void refreshUsToMm();
    void refreshSoundPathMultiplier();
    void refreshSingleDual();
public:
    explicit ConnectionHub(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONNECTIONHUB_H
