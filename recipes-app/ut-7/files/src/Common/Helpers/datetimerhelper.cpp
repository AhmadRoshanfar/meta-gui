#include "datetimerhelper.h"
#include <QProcess>
#include <QStringList>


#ifdef Q_OS_UNIX
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>
#include <errno.h>

#include <linux/types.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#include <sys/ioctl.h>



static inline __s32 i2c_smbus_access(int file, char read_write, __u8 command,
                                     int size, union i2c_smbus_data *data)
{
    struct i2c_smbus_ioctl_data args;

    args.read_write = read_write;
    args.command = command;
    args.size = size;
    args.data = data;
    return ioctl(file,I2C_SMBUS,&args);
}

static inline __s32 i2c_smbus_read_byte_data(int file, __u8 command)
{
    union i2c_smbus_data data;
    if (i2c_smbus_access(file,I2C_SMBUS_READ,command,
                         I2C_SMBUS_BYTE_DATA,&data))
        return -1;
    else
        return 0x0FF & data.byte;
}


static inline __s32 i2c_smbus_write_byte_data(int file, __u8 command,
                                              __u8 value)
{
    union i2c_smbus_data data;
    data.byte = value;
    return i2c_smbus_access(file,I2C_SMBUS_WRITE,command,
                            I2C_SMBUS_BYTE_DATA, &data);
}

#endif
void DateTimerHelper::setHwDateTime(QDateTime datetime){
#ifdef Q_OS_UNIX
    int file, rc;
    file = open(I2C_PATH, O_RDWR);
    rc = ioctl(file, I2C_SLAVE, HWCLOCK_I2C_ADDR);
    if (rc < 0)
        err(errno, "Tried to set device address '0x%02x'", HWCLOCK_I2C_ADDR);
    i2c_smbus_write_byte_data(file, 0, bin2bcd(datetime.time().second()));
    i2c_smbus_write_byte_data(file, 1, bin2bcd(datetime.time().minute()));
    i2c_smbus_write_byte_data(file, 2, bin2bcd(datetime.time().hour()));
    i2c_smbus_write_byte_data(file, 4, bin2bcd(datetime.date().day()));
    i2c_smbus_write_byte_data(file, 5, bin2bcd(datetime.date().month()));
    i2c_smbus_write_byte_data(file, 6, bin2bcd(datetime.date().year()%100));
#endif
}

QDateTime DateTimerHelper::getHwDateTime(){
#ifdef Q_OS_UNIX
    int file, rc;
    uint8_t hour = 0, min = 0, sec = 0, year, mon , day;
    file = open(I2C_PATH, O_RDWR);
    rc = ioctl(file, I2C_SLAVE, HWCLOCK_I2C_ADDR);
    if (rc < 0)
        err(errno, "Tried to set device address '0x%02x'", HWCLOCK_I2C_ADDR);
    year =  bcd2bin(i2c_smbus_read_byte_data(file, 6));
    mon =   bcd2bin(i2c_smbus_read_byte_data(file, 5));
    day =   bcd2bin(i2c_smbus_read_byte_data(file, 4));
    hour =  bcd2bin(i2c_smbus_read_byte_data(file, 2));
    min =   bcd2bin(i2c_smbus_read_byte_data(file, 1));
    sec =   bcd2bin(i2c_smbus_read_byte_data(file, 0));
    return QDateTime(QDate(year,mon,day),QTime(hour, min, sec));
#endif
#ifndef Q_OS_UNIX
    return QDateTime::currentDateTime();
#endif
}



uint8_t DateTimerHelper::bcd2bin (uint8_t val) { return val - 6 * (val >> 4); }
uint8_t DateTimerHelper::bin2bcd (uint8_t val) { return val + 6 * (val / 10); }


DateTimerHelper::DateTimerHelper(QObject *parent) : QObject(parent)
{

}

void DateTimerHelper::setDateTime(int y, int M, int d, int h, int m, int s, bool hw ){

    std::system((QString("echo %7|sudo -S date -s \"%1-%2-%3 %4:%5:%6\";echo %7|sudo -S /sbin/hwclock --systohc").arg(y).arg(M).arg(d).arg(h).arg(m).arg(s).arg(ROOT_PASS)).toLocal8Bit().data());
    if(hw)
        setHwDateTime(QDateTime(QDate(y,M,d),QTime(h, m, s)));
//    qDebug()<<(QString("echo salam|sudo -S date -s \"%1-%2-%3 %4:%5:%6\"").arg(y).arg(M).arg(d).arg(h).arg(m).arg(s)).toLocal8Bit().data();
}


void DateTimerHelper::init(){
    auto datetime = getHwDateTime();
    setDateTime(datetime.date().year(),datetime.date().month(), datetime.date().day(), datetime.time().hour(), datetime.time().minute(), datetime.time().second());
}


