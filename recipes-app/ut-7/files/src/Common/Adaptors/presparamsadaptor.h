#ifndef PRESPARAMSADAPTOR_H
#define PRESPARAMSADAPTOR_H

#include <QObject>
#include "../Helpers/qmlintegrator.h"

class PresParamsAdaptor : public QObject
{
    Q_OBJECT
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

public:
    explicit PresParamsAdaptor(QObject *parent = nullptr);
    static void declareQML();

signals:

public slots:
    void refresh();
};

#endif // PRESPARAMSADAPTOR_H
