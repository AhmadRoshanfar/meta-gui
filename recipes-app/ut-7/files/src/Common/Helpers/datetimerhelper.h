#ifndef DATETIMERHELPER_H
#define DATETIMERHELPER_H

#include <QObject>
#include <QDateTime>
#define HWCLOCK_I2C_ADDR 0x68
#define ROOT_PASS "pejvakrayan"
#define I2C_PATH "/dev/i2c-2"//i2c-2 for NanoPi and i2c-7 for Rock Pi


class DateTimerHelper : public QObject
{
    Q_OBJECT

    uint8_t bcd2bin(uint8_t val);
    uint8_t bin2bcd(uint8_t val);
    void setHwDateTime(QDateTime datetime);
    QDateTime getHwDateTime();


public:
    explicit DateTimerHelper(QObject *parent = nullptr);
    void init();
signals:

public slots:

    void setDateTime(int y, int M, int d, int h, int m, int s,bool hw = false);
};

#endif // DATETIMERHELPER_H
