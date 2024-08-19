#ifndef CURRENTIP_H
#define CURRENTIP_H

#include <QObject>

class CurrentIP : public QObject
{
    Q_OBJECT
public:
    explicit CurrentIP(QObject *parent = nullptr);

    quint8 getIP();
signals:

public slots:
};

#endif // CURRENTIP_H
