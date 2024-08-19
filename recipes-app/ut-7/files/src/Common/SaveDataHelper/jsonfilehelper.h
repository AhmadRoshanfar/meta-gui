#ifndef JSONFILEHELPER_H
#define JSONFILEHELPER_H

#include <QObject>
#include <QPointF>
#include <QVector>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDataStream>

class JSONFileHelper : public QObject
{
    Q_OBJECT
public:
    explicit JSONFileHelper(QObject *parent = nullptr);

    QJsonArray toJson(const QVector<QPointF> &myVec);
    QVector<QPointF> fromJsonQVectorQPointF(const QJsonArray &myVec);
    void save(QString filename, QJsonObject obj);
    QJsonObject read(QString filename);
    QJsonArray toJson(const QVector<double> &list);
    QVector<double> fromJsonQVectorDouble(const QJsonArray &myVec);
    QJsonArray toJson(const QVector<QVector<QPointF> > &myVec);
    QVector<QVector<QPointF> > fromJsonQVectorQVectorQPointF(const QJsonArray &myVec);
    QString toString(QJsonObject obj);
    QJsonObject fromString(QString str);
signals:

public slots:
};

#endif // JSONFILEHELPER_H
