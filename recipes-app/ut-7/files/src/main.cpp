/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011-2018 Emanuel Eichhammer                            **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.qcustomplot.com/                          **
**             Date: 25.06.18                                             **
**          Version: 2.0.1                                                **
****************************************************************************/

#include <QApplication>
#include "mainwindow.h"
#include "Adaptors/settingsadaptor.h"
#include "connectionhub.h"
#include "../Common/Helpers/qmlintegrator.h"
#include "../Common/Helpers/devicehelper.h"
#include "connectionhub.h"
#include "../Common/Models/enums.h"
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include "../Common/Adaptors/evaluationadaptor.h"
#include "../Common/Adaptors/faultcalcadaptor.h"
//#include "Adaptors/analysisascanadaptor.h"
//#include "Adaptors/analysisheatmapadaptor.h"
#include "../Common/Adaptors/ascanadaptor.h"
//#include "Adaptors/scanningheatmapadaptor.h"
//#include "CScan/heatmap.h"
//#include "CScan/bscanchart.h"
#include "../Common/Chart/ascanchart.h"
#include "Adaptors/calibrationadaptor.h"
#include "Adaptors/settingsadaptor.h"
#include "../Common/Adaptors/dateadaptor.h"
#include "../Common/Adaptors/snapshotadaptor.h"
#include "../Common/Adaptors/ifsyncadaptor.h"
#include "../Common/Adaptors/alarmadaptor.h"
#include "../Common/Adaptors/presparamsadaptor.h"
#include "Adaptors/keyboardadaptor.h"
#include "../Common/Adaptors/usbdeviceadaptor.h"
#include "../Common/Adaptors/batteryadaptor.h"
#include "Adaptors/settingswinadaptor.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)

    QApplication::setGraphicsSystem("raster");

#endif
    QApplication app(argc, argv);
//    app.setOrganizationName("Pejvak Rayan");
//    app.setOrganizationDomain("Pejvakrayan.com");
//    app.setApplicationName("UT Desktop");

    QCursor cursor(Qt::BlankCursor);
    QApplication::setOverrideCursor(cursor);
    QApplication::changeOverrideCursor(cursor);


    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

    _qmlIntegrator.setApplicationDirPath(QGuiApplication::applicationDirPath());


    DbHelper::instance().databaseConnect();
    DbHelper::instance().createTables();
    DbHelper::instance().vacuum();

    ConnectionHub ch;



    Enums::declareQML();
//    EvaluationAdaptor::declareQML();
    CalibrationAdaptor::declareQML();
    FaultCalcAdaptor::declareQML();
    AScanAdaptor::declareQML();
    SettingsAdaptor::declareQML();
    SnapshotAdaptor::declareQML();
    DateAdaptor::declareQML();
    IFSyncAdaptor::declareQML();
    AlarmAdaptor::declareQML();
    PresParamsAdaptor::declareQML();
    KeyboardAdaptor::declareQML();
    USBDeviceAdaptor::declareQML();
    BatteryAdaptor::declareQML();
    SettingsWinAdaptor::declareQML();
    MainWindow w;
    SettingsAdaptor _sa;
    _sa.loadDefaults();
    _sa.checkDir();
    _sa.loadLatest();
    _sa.recall();

    _qmlIntegrator.setStarted(true);


    w.show();
    _sa.recall();
    emit _qmlIntegrator.onThemeChanged();
    return app.exec();
}
