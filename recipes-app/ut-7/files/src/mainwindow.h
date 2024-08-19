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

/************************************************************************************************************
**                                                                                                         **
**  This is the example code for QCustomPlot.                                                              **
**                                                                                                         **
**  It demonstrates basic and some advanced capabilities of the widget. The interesting code is inside     **
**  the "setup(...)Demo" functions of MainWindow.                                                          **
**                                                                                                         **
**  In order to see a demo in action, call the respective "setup(...)Demo" function inside the             **
**  MainWindow constructor. Alternatively you may call setupDemo(i) where i is the index of the demo       **
**  you want (for those, see MainWindow constructor comments). All other functions here are merely a       **
**  way to easily create screenshots of all demos for the website. I.e. a timer is set to successively     **
**  setup all the demos and make a screenshot of the window area and save it in the ./screenshots          **
**  directory.                                                                                             **
**                                                                                                         **
*************************************************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "../Common/Chart/qcustomplot.h" // the header file of QCustomPlot. Don't forget to add it to your project, if you use an IDE, so it gets compiled.
#include "../Common/Adaptors/ascanadaptor.h"
#include "../Common/Adaptors/presparamsadaptor.h"
#include "../Common/Adaptors/alarmadaptor.h"
#include "../Common/Adaptors/usbdeviceadaptor.h"
#include "../Common/Adaptors/faultcalcadaptor.h"
#include "Adaptors/keyboardadaptor.h"
#include "Helpers/themeshelper.h"
#include "../Common/Adaptors/evaluationadaptor.h"
#include "Helpers/subqmlintegrator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT


  AScanAdaptor _ascanAdaptor;
  AlarmAdaptor _alarmAdaptor;
  PresParamsAdaptor _presParamsAdaptor;
  USBDeviceAdaptor _USBDeviceAdaptor;
  FaultCalcAdaptor _faultCalcAdaptor;
  KeyboardAdaptor _keyboardAdaptor;
  QVBoxLayout *verticalLayout_2;
  QWidget *containerT;
  QHBoxLayout *horizontalLayout_2;
  QVBoxLayout *verticalLayout_3;
  QLabel *snapshot;
  AScanChart *plot = nullptr;
  QWidget *containerB;
  QWidget *containerR;
  QWidget *containerM;

  QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
  SubQMLIntegrator& _subqmlIntegrator = SubQMLIntegrator::instance();

  ThemeModel* _theme;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  


  void setup(AScanChart *customPlot);

  
  void setupPlayground(QCustomPlot *customPlot);
protected:
void keyPressEvent(QKeyEvent *event);

private slots:
  void realtimeDataSlot();
//  void bracketDataSlot();
  void screenShot();
//  void allScreenShots();
  
  void fullscreen();

  void newTopbar();
  void newBottombar();
  void newTheme();
  void newKey();
  void showSnapshot();
  void hideSnapshot();

private:
  Ui::MainWindow *ui;
  QString demoName;
  QTimer dataTimer;
  QCPItemTracer *itemDemoPhaseTracer;
  int currentDemoIndex;
};

#endif // MAINWINDOW_H
