#ifndef UTDEVICE_H
#define UTDEVICE_H

#include <QObject>
#include <QList>
#include "Helpers/qmlintegrator.h"
#include "Adaptors/ifsyncadaptor.h"
class UTDevice : public QObject
{
    Q_OBJECT
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    IFSyncAdaptor _ifSyncAdaptor;

public:
    explicit UTDevice(QObject *parent = nullptr);
    static QVector<QPointF> _signalData;
signals:

public slots:
    void newSignalData(const QVector<uint16_t> &data);

private slots:
};

#endif // UTDEVICE_H
