#ifndef IFSYNCADAPTOR_H
#define IFSYNCADAPTOR_H

#include <QObject>
#include "../Helpers/qmlintegrator.h"

class IFSyncAdaptor : public QObject
{
    Q_OBJECT
    static QmlIntegrator& _qmlIntegrator ;
    static double last;

public:
    explicit IFSyncAdaptor(QObject *parent = nullptr);
//    static QPointF ref;
    static double trackingOffset();
    static void declareQML();
    static double calc();


signals:

public slots:
    void setRefPoint();
};

#endif // IFSYNCADAPTOR_H
