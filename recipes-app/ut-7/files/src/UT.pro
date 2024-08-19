QT       += core gui  network quick quickcontrols2 quickwidgets
CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport sql

TARGET = UT
TEMPLATE = app

#LIBS += $$top_builddir/../Common/$(OBJECTS_DIR)/libcommon.a
#INCLUDEPATH += $$top_srcdir/../Common/
#PRE_TARGETDEPS += $$top_builddir/../Common/$(OBJECTS_DIR)/libcommon.a


#LIBS += libcommon.a
#INCLUDEPATH += $$top_srcdir/../Common/
#PRE_TARGETDEPS += libcommon.a

SOURCES += main.cpp\
    "./Common/Adaptors/alarmadaptor.cpp" \
    "./Common/Adaptors/ascanadaptor.cpp" \
    "./Common/Adaptors/batteryadaptor.cpp" \
    "./Common/Adaptors/dateadaptor.cpp" \
    "./Common/Adaptors/evaluationadaptor.cpp" \
    "./Common/Adaptors/ifsyncadaptor.cpp" \
    "./Common/Adaptors/presparamsadaptor.cpp" \
    "./Common/Adaptors/snapshotadaptor.cpp" \
    "./Common/Adaptors/usbdeviceadaptor.cpp" \
    "./Common/Calculations/calcaws.cpp" \
    "./Common/Calculations/calccalibration.cpp" \
    "./Common/Calculations/calcdac.cpp" \
    "./Common/Calculations/calcfaultfeatures.cpp" \
    "./Common/Calculations/calctcg.cpp" \
    "./Common/Calculations/chartscalculations.cpp" \
    "./Common/Chart/ascanchart.cpp" \
    "./Common/Chart/qcustomplot.cpp" \
    "./Common/Chart/stripchart.cpp" \
    "./Common/ChartData/ascandata.cpp" \
    "./Common/ChartData/stripdata.cpp" \
    "./Common/Helpers/currentip.cpp" \
    "./Common/Helpers/datetimerhelper.cpp" \
    "./Common/Helpers/qmlintegrator.cpp" \
    "./Common/Helpers/tcpascan.cpp" \
    "./Common/Helpers/tcpcommands.cpp" \
    "./Common/Helpers/tcpconnection.cpp" \
    "./Common/Helpers/udpascan.cpp" \
    "./Common/Helpers/udpconnection.cpp" \
    "./Common/Helpers/udpdevicehelper.cpp" \
    "./Common/Helpers/udpstrip.cpp" \
    "./Common/Helpers/usbdiskhelper.cpp" \
    "./Common/SaveDataHelper/dbhelper.cpp" \
    "./Common/SaveDataHelper/jsonfilehelper.cpp" \
    "./Common/gaintable.cpp" \
    "./Common/gatedata.cpp" \
    "./Common/peakmethodmanager.cpp" \
    "./Common/utdevice.cpp"\
    ./Common/Adaptors/faultcalcadaptor.cpp \
        ../Common/Helpers/constants.cpp \
        Adaptors/calibrationadaptor.cpp \
        Adaptors/keyboardadaptor.cpp \
        Adaptors/settingsadaptor.cpp \
        Adaptors/settingswinadaptor.cpp \
    Helpers/subqmlintegrator.cpp \
        Helpers/themeshelper.cpp \
        Models/thememodel.cpp \
        SaveDataHelper/settingshelper.cpp \
        connectionhub.cpp \
        mainwindow.cpp \
        settingswindow.cpp

HEADERS  += mainwindow.h \
        "./Common/Adaptors/alarmadaptor.h" \
    "./Common/Adaptors/ascanadaptor.h" \
    "./Common/Adaptors/batteryadaptor.h" \
    "./Common/Adaptors/dateadaptor.h" \
    "./Common/Adaptors/evaluationadaptor.h" \
    "./Common/Adaptors/ifsyncadaptor.h" \
    "./Common/Adaptors/presparamsadaptor.h" \
    "./Common/Adaptors/snapshotadaptor.h" \
    "./Common/Adaptors/usbdeviceadaptor.h" \
    "./Common/Calculations/calcaws.h" \
    "./Common/Calculations/calccalibration.h" \
    "./Common/Calculations/calcdac.h" \
    "./Common/Calculations/calcfaultfeatures.h" \
    "./Common/Calculations/calctcg.h" \
    "./Common/Calculations/chartscalculations.h" \
    "./Common/Chart/ascanchart.h" \
    "./Common/Chart/qcustomplot.h" \
    "./Common/Chart/stripchart.h" \
    "./Common/ChartData/ascandata.h" \
    "./Common/ChartData/stripdata.h" \
    "./Common/Helpers/currentip.h" \
    "./Common/Helpers/datetimerhelper.h" \
    "./Common/Helpers/devicehelper.h" \
    "./Common/Helpers/qmlintegrator.h" \
    "./Common/Helpers/tcpascan.h" \
    "./Common/Helpers/tcpcommands.h" \
    "./Common/Helpers/tcpconnection.h" \
    "./Common/Helpers/udpascan.h" \
    "./Common/Helpers/udpconnection.h" \
    "./Common/Helpers/udpdevicehelper.h" \
    "./Common/Helpers/udpstrip.h" \
    "./Common/Helpers/usbdiskhelper.h" \
    "./Common/Models/enums.h" \
    "./Common/Models/evalmethod.h" \
    "./Common/SaveDataHelper/dbhelper.h" \
    "./Common/SaveDataHelper/jsonfilehelper.h" \
    "./Common/gaintable.h" \
    "./Common/gatedata.h" \
    "./Common/peakmethodmanager.h" \
    "./Common/utdevice.h"\
    ./Common/Adaptors/faultcalcadaptor.h \
        ./Common/Helpers/constants.h \
         Adaptors/keyboardadaptor.h \
         Adaptors/settingswinadaptor.h \
         Adaptors/calibrationadaptor.h \
         Adaptors/settingsadaptor.h \
    Helpers/subqmlintegrator.h \
         Helpers/themeshelper.h \
         Models/thememodel.h \
         SaveDataHelper/settingshelper.h \
    connectionhub.h \
         settingswindow.h

FORMS    += mainwindow.ui \
    settingswindow.ui

DISTFILES += \
    QML/Common.qml \
    QML/MainBottomBar.qml \
    QML/MainBottomMenu.qml \
    QML/MainRight.qml \
    QML/MainTop.qml \
    QML/Pages/PageAlarms.qml \
    QML/Pages/PageAutoCal.qml \
    QML/Pages/PageBase.qml \
    QML/Pages/PageBasic.qml \
    QML/Pages/PageDisplay.qml \
    QML/Pages/PageEval.qml \
    QML/Pages/PageGateA.qml \
    QML/Pages/PageGateB.qml \
    QML/Pages/PageMaterial.qml \
    QML/Pages/PageMemory.qml \
    QML/Pages/PageMisc.qml \
    QML/Pages/PageProbe.qml \
    QML/Pages/PagePulser.qml \
    QML/Pages/PageReceiver.qml \
    QML/Pages/PageSettings.qml \
    QML/Pages/PageSnapshot.qml \
    QML/Views/AScanChart.qml \
    QML/Views/ElevatedGroupBox.qml \
    QML/Views/ElevatedPane.qml \
    QML/Views/ParamBase.qml \
    QML/Views/ParamBool.qml \
    QML/Views/ParamButton.qml \
    QML/Views/ParamDate.qml \
    QML/Views/ParamDouble.qml \
    QML/Views/ParamEnum.qml \
    QML/Views/ParamInt.qml \
    QML/Views/ParamList.qml \
    QML/Views/ParamTextInput.qml \
    QML/Views/ParamTime.qml \
    QML/Views/SettingsDialog.qml \
    QML/Views/SideMenu.qml \
    QML/Views/TextBox.qml \
    QML/main.qml

RESOURCES += \
    res.qrc

SUBDIRS += \
    ../Common/Common.pro

