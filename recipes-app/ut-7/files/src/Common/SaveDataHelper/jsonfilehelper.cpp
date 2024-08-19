#include "jsonfilehelper.h"
#include <QTextStream>
JSONFileHelper::JSONFileHelper(QObject *parent) : QObject(parent)
{

}

QJsonArray JSONFileHelper::toJson(const QVector<double> & list) {
   QJsonArray array;
   for (auto & val : list)
       array.append(QString::number(val));
   return array;
}

QJsonArray JSONFileHelper::toJson(const QVector<QPointF>& myVec) {
    QJsonArray result;
    for (const QPointF& point:myVec) {
        result.append(QString("%1,%2").arg(point.x()).arg(point.y()));
    }    return result;
}

QJsonArray JSONFileHelper::toJson(const QVector<QVector<QPointF>>& myVec) {
    QJsonArray result;
    for (const QVector<QPointF>& vec:myVec) {
        result.append(toJson(vec));
    }    return result;
}

QVector<QPointF> JSONFileHelper::fromJsonQVectorQPointF(const QJsonArray& myVec) {
    QVector<QPointF> result;
    for (auto point:myVec) {
        QStringList lst = point.toString().split(',');
        result.append(QPointF(lst[0].toDouble(),lst[1].toDouble()));
    }
    return result;
}

QVector<QVector<QPointF>> JSONFileHelper::fromJsonQVectorQVectorQPointF(const QJsonArray& myVec) {
    QVector<QVector<QPointF>> result;
    for (auto vec:myVec) {
        QVector<QPointF> lst = fromJsonQVectorQPointF(vec.toArray());
        result.append(lst);
    }
    return result;
}


QVector<double> JSONFileHelper::fromJsonQVectorDouble(const QJsonArray& myVec) {
    QVector<double> result;
    for (auto point:myVec) {
        result.append(point.toString().toDouble());
    }
    return result;
}

QString JSONFileHelper::toString(QJsonObject obj){
    qRegisterMetaTypeStreamOperators<QVector<QPointF>>("QVector<QPointF>");
    //    QSettings settings(filename, QSettings::IniFormat);

    QJsonDocument doc(obj);

    return (doc.toJson(QJsonDocument::Compact));
}

QJsonObject JSONFileHelper::fromString(QString strJson){
    QJsonDocument doc;
    doc = doc.fromJson(strJson.toUtf8());
//    qDebug()<<strJson.toUtf8();
    return doc.object();
}

void JSONFileHelper::save(QString filename,QJsonObject obj){
    qRegisterMetaTypeStreamOperators<QVector<QPointF>>("QVector<QPointF>");
    //    QSettings settings(filename, QSettings::IniFormat);

    QJsonDocument doc(obj);

    QString strJson(doc.toJson(QJsonDocument::Compact));
//    QString strJson(doc.toBinaryData());
    QFile file(filename);


    QTextStream outputStream(&file);
    file.open(QIODevice::WriteOnly| QIODevice::Text);
    outputStream << strJson;
    file.close();

}

QJsonObject JSONFileHelper::read(QString filename)
{
    QFile file(filename);
    QString strJson;
    QTextStream inputStream(&file);
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    strJson = inputStream.readAll();
    file.close();
    QJsonDocument doc;
    doc = doc.fromJson(strJson.toUtf8());
//    qDebug()<<strJson.toUtf8();
    return doc.object();
}
