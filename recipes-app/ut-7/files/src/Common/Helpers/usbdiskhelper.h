#ifndef USBDISKHELPER_H
#define USBDISKHELPER_H

#include <QObject>
#include "../Common/Helpers/qmlintegrator.h"
#include <QDir>
class USBDiskHelper : public QObject
{
    Q_OBJECT

    static QStringList listDev();
    static QStringList listMedia();
    static int runCommand(QString cmd);
public:
    explicit USBDiskHelper(QObject *parent = nullptr);
    //static void mount();
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

    static QString checkList();
    static QString exec(QString cmd);
    static QString lastDev;
    static void sync();

signals:

public slots:
    bool copyFileToUSB(QString content, QString filename);
    bool copyFileToUSB(QString filename);
    bool copyDirToUSB(QString dir);
};

#endif // USBDISKHELPER_H
