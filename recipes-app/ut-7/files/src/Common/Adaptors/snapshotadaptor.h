#ifndef SNAPSHOTADAPTOR_H
#define SNAPSHOTADAPTOR_H

#include <QObject>
//#include "SaveDataHelper/settingshelper.h"
#include "../Helpers/qmlintegrator.h"
#include "../Helpers/usbdiskhelper.h"

class SnapshotAdaptor : public QObject
{
    Q_OBJECT
//    SettingsHelper _settingsHelper;
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
    USBDiskHelper _usbdiskhelper;
public:
    explicit SnapshotAdaptor(QObject *parent = nullptr);

    static void declareQML();
    QPixmap currentSnapshotPix();
    QString newSnapshotName();

signals:

public slots:
    void remove();
//    void recall();
    QStringList list();
    bool fileExists(QString name);
    bool copyFiles();
    void checkDir();
    void sync();
};

#endif // SNAPSHOTADAPTOR_H
