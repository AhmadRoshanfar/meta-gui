#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QObject>
#include "../Models/enums.h"
class Constants: public QObject
{
    Q_GADGET
public:
//    Constants() = delete;
    static const int RANGE_BASE     ; //us
    static const int RANGE_OFFSET   ; //us
    static const int ASCAN_REF_RATE ; //Hz
    static const int SAMPLING_RATE  ; //Hz
    static const int RANGE_SIZE;
    static const int RANGE_PAGES;
    static const int RANGE_MAX;
    static const int RANGE_MIN;
    static const int MAX_CALIB_POINTS;
    static const int MAX_AWS_POINTS;
    static const int MAX_DAC_POINTS;
    static const int MAX_TCG_POINTS;
    static const int MAX_NORMAL_POINTS;
    static const int ASCAN_SERIES_CNT = 13;
    static const int DISP_POINTS_CNT ;
    static const int ASCAN_FRAME_DATA_SIZE = 724 ;
    static const int ASCAN_FRAME_HEADER_SIZE = 6 ;
    static const int ASCAN_FRAME_FULL_SIZE;
    static const int ASCAN_FULL_MESSAGE_SIZE;
    static const int ASCAN_BYTES_PER_SAMPLE = 2 ;
    static const QString UT_DEV_IP;
    //static const int ASCAN_PADDING_SAMPLES ;
    static const double INCH_TO_MM;
    static const double IGNORE_IFSYNC_US;

    static const QMap <Enums::DigitalFilter,double> FILTER_COEF;
public:
    static QMap<Enums::DigitalFilter, double> initFILTER_COEF();
//    static void declareQML();
};

#endif // CONSTANTS_H
