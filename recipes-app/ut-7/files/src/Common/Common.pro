#-------------------------------------------------
#
# Project created by QtCreator 2022-07-19T11:21:01
#
#-------------------------------------------------

TEMPLATE = lib
CONFIG += staticlib
QT       += core gui  network quick quickcontrols2 quickwidgets sql


TARGET = common

DEFINES += ADAPTORS_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Adaptors/alarmadaptor.cpp \
    Adaptors/ascanadaptor.cpp \
    Adaptors/batteryadaptor.cpp \
    Adaptors/dateadaptor.cpp \
    Adaptors/evaluationadaptor.cpp \
    Adaptors/ifsyncadaptor.cpp \
    Adaptors/presparamsadaptor.cpp \
    Adaptors/snapshotadaptor.cpp \
    Adaptors/usbdeviceadaptor.cpp \
    Calculations/calcaws.cpp \
    Calculations/calccalibration.cpp \
    Calculations/calcdac.cpp \
    Calculations/calcfaultfeatures.cpp \
    Calculations/calctcg.cpp \
    Calculations/chartscalculations.cpp \
    Chart/ascanchart.cpp \
    Chart/qcustomplot.cpp \
    Chart/stripchart.cpp \
    ChartData/ascandata.cpp \
    ChartData/stripdata.cpp \
    Helpers/currentip.cpp \
    Helpers/datetimerhelper.cpp \
    Helpers/qmlintegrator.cpp \
    Helpers/tcpascan.cpp \
    Helpers/tcpcommands.cpp \
    Helpers/tcpconnection.cpp \
    Helpers/udpascan.cpp \
    Helpers/udpconnection.cpp \
    Helpers/udpdevicehelper.cpp \
    Helpers/udpstrip.cpp \
    Helpers/usbdevicehelper.cpp \
    Helpers/usbdiskhelper.cpp \
    SaveDataHelper/dbhelper.cpp \
    SaveDataHelper/jsonfilehelper.cpp \
    gaintable.cpp \
    gatedata.cpp \
    peakmethodmanager.cpp \
    utdevice.cpp

HEADERS += \
    Adaptors/alarmadaptor.h \
    Adaptors/ascanadaptor.h \
    Adaptors/batteryadaptor.h \
    Adaptors/dateadaptor.h \
    Adaptors/evaluationadaptor.h \
    Adaptors/ifsyncadaptor.h \
    Adaptors/presparamsadaptor.h \
    Adaptors/snapshotadaptor.h \
    Adaptors/usbdeviceadaptor.h \
    Calculations/calcaws.h \
    Calculations/calccalibration.h \
    Calculations/calcdac.h \
    Calculations/calcfaultfeatures.h \
    Calculations/calctcg.h \
    Calculations/chartscalculations.h \
    Chart/ascanchart.h \
    Chart/qcustomplot.h \
    Chart/stripchart.h \
    ChartData/ascandata.h \
    ChartData/stripdata.h \
    Helpers/currentip.h \
    Helpers/datetimerhelper.h \
    Helpers/devicehelper.h \
    Helpers/qmlintegrator.h \
    Helpers/tcpascan.h \
    Helpers/tcpcommands.h \
    Helpers/tcpconnection.h \
    Helpers/udpascan.h \
    Helpers/udpconnection.h \
    Helpers/udpdevicehelper.h \
    Helpers/udpstrip.h \
    Helpers/usbdevicehelper.h \
    Helpers/usbdiskhelper.h \
    Models/enums.h \
    Models/evalmethod.h \
    SaveDataHelper/dbhelper.h \
    SaveDataHelper/jsonfilehelper.h \
    gaintable.h \
    gatedata.h \
    peakmethodmanager.h \
    utdevice.h


