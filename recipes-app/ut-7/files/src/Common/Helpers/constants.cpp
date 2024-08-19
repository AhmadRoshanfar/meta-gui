#include "constants.h"
#include <QtMath>
#include <QtQml/QQmlContext>
const int Constants::RANGE_SIZE     = (Constants::RANGE_BASE + Constants::RANGE_OFFSET) * (Constants::SAMPLING_RATE/1000000);//SAMPLES
const int Constants::RANGE_PAGES    = qCeil(Constants::RANGE_SIZE * Constants::ASCAN_BYTES_PER_SAMPLE/(double)(Constants::ASCAN_FRAME_DATA_SIZE));
const int Constants::RANGE_MAX      = (Constants::RANGE_BASE) * (Constants::SAMPLING_RATE/1000000);
const int Constants::RANGE_MIN      = (-Constants::RANGE_OFFSET) * (Constants::SAMPLING_RATE/1000000);
const int Constants::RANGE_BASE     = 635;//360; //us
const int Constants::RANGE_OFFSET   = 15; //us
const int Constants::ASCAN_REF_RATE = 20; //Hz
const int Constants::SAMPLING_RATE  = 100*1000000; //Hz
const int Constants::MAX_CALIB_POINTS = 2;
const int Constants::MAX_NORMAL_POINTS = 0;
const int Constants::MAX_AWS_POINTS = 1;
const int Constants::MAX_DAC_POINTS = 10;
const int Constants::MAX_TCG_POINTS = 10;
const int Constants::DISP_POINTS_CNT= 200;
const QString Constants::UT_DEV_IP = "192.168.1.200";
const int Constants::ASCAN_FULL_MESSAGE_SIZE = (Constants::RANGE_PAGES*Constants::ASCAN_FRAME_DATA_SIZE)/ Constants::ASCAN_BYTES_PER_SAMPLE;
const int Constants::ASCAN_FRAME_FULL_SIZE = Constants::ASCAN_FRAME_DATA_SIZE + Constants::ASCAN_FRAME_HEADER_SIZE;
//const int Constants::ASCAN_PADDING_SAMPLES = (RANGE_PAGES * ASCAN_FRAME_DATA_SIZE/ ASCAN_BYTE_PER_SAMPLE - RANGE_SIZE) ;
const double Constants::INCH_TO_MM = 25.4;
const double Constants::IGNORE_IFSYNC_US = 3.0;


const QMap <Enums::DigitalFilter, double> Constants::FILTER_COEF = Constants::initFILTER_COEF();

QMap<Enums::DigitalFilter, double> Constants::initFILTER_COEF() {
    QMap < Enums::DigitalFilter,  double> map;

    map.insert(Enums::DigitalFilter::NOFILTER,2.0); // set filter coef
    map.insert(Enums::DigitalFilter::FILTER05TO11,1.88);
    map.insert(Enums::DigitalFilter::FILTER05TO2,2.016);
    map.insert(Enums::DigitalFilter::FILTER05TO4,2.04);
    map.insert(Enums::DigitalFilter::FILTER2TO8,2.08);
    map.insert(Enums::DigitalFilter::FILTER4TO11,1.78);

/*    map.insert(Enums::DigitalFilter::NOFILTER,1.0);
    map.insert(Enums::DigitalFilter::FILTER05TO4,1.8);s
    map.insert(Enums::DigitalFilter::FILTER2TO8,1.8);
    map.insert(Enums::DigitalFilter::FILTER05TO11,1.8);
    map.insert(Enums::DigitalFilter::FILTER8TO11,2.5);
*/

    return map;
}


