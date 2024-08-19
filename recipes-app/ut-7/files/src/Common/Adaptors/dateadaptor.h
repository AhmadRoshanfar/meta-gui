#ifndef DATEADAPTOR_H
#define DATEADAPTOR_H

#include <QObject>
#include <QDateTime>

class DateAdaptor : public QObject
{
    Q_OBJECT
    QDateTime _date;
public:
    explicit DateAdaptor(QObject *parent = nullptr);

    static void declareQML();
signals:

public slots:
    int currentYear();
    int currentMonth();
    int currentDay();
    QDateTime now();
    QDateTime nextDay();
    QDateTime previousDay();
    QDateTime nextMonth();
    QDateTime previousMonth();
    QDateTime nextYear();
    QDateTime previousYear();
    int currentHour();
    int currentMin();
    int currentSec();
    void setDateTime(int y, int M, int d, int h, int m, int s);
    void init();
};

#endif // DATEADAPTOR_H
