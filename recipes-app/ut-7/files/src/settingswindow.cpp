#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QtQuickWidgets/QQuickWidget>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickView>
#include "../Common/Helpers/qmlintegrator.h"
#include "Helpers/themeshelper.h"
#include "../Common/Helpers/devicehelper.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    setGeometry(0,0,800,480);
    setWindowFlags(
                //Qt::Window | // Add if popup doesn't show up
                Qt::FramelessWindowHint|  // No window border
                Qt::WindowDoesNotAcceptFocus|  // No focus
                Qt::WindowStaysOnTopHint // Always on top
                );

    setAttribute(Qt::WA_ShowWithoutActivating);// hide from taskbar
//    _theme = ThemesHelper::instance().theme();
    QQuickView *view = new QQuickView();
    view->rootContext()->setContextProperty("qmlIntegrator",&(QmlIntegrator::instance()));
    view->rootContext()->setContextProperty("THEME",ThemesHelper::instance().theme());

    QWidget *pWidget;
    pWidget = QWidget::createWindowContainer(view,centralWidget());
    pWidget->setMinimumSize(QSize(800, 480));
    pWidget->setMaximumSize(QSize(800, 480));

    view->setSource(QUrl(QStringLiteral("qrc:/QML/Views/SettingsDialog.qml")));
//    connect(&_qmlIntegrator,&QmlIntegrator::onThemeChanged, this, &SettingsWindow::newTheme);
}

//void SettingsWindow::newTheme(){
//    centralWidget()->setStyleSheet(QString("background:rgb(%1,%2,%3);").arg(_theme->appBg().red()).arg(_theme->appBg().green()).arg(_theme->appBg().blue()));
//}

void SettingsWindow::keyPressEvent(QKeyEvent *event){
    auto& device = DeviceHelper::instance();
    switch(event->key()){
    case Qt::Key_F1:
        emit device.signalKeyPress(0x00001000);
        break;
    case Qt::Key_F2:
         emit device.signalKeyPress(0x00000080);
         break;
     case Qt::Key_F3:
         emit device.signalKeyPress(0x00000004);
         break;
     case Qt::Key_F4:
         emit device.signalKeyPress(0x00010000);
         break;
     case Qt::Key_F5:
         emit device.signalKeyPress(0x00000800);
         break;
     case Qt::Key_Left:
         emit device.signalKeyPress(0x00020000);
         break;
     case Qt::Key_Right:
         emit device.signalKeyPress(0x00020000);
         break;
         //        case Qt::Key_Up:
         //            nextPage();;
         //            break;
     case Qt::Key_Down:
         emit device.signalKeyPress(0x00000040);
         break;
     case Qt::Key_0:
         emit device.signalKeyPress(0x00000020);
         break;
     case Qt::Key_1:
         emit device.signalKeyPress(0x00000400);
         break;
     case Qt::Key_2:
         emit device.signalKeyPress(0x00008000);
         break;
     case Qt::Key_3:
         emit device.signalKeyPress(0x00000002);
         break;
     case Qt::Key_Plus:
         emit device.signalKeyPress(0x01000000);
         break;
     case Qt::Key_Minus:
         emit device.signalKeyPress(0x02000000);
         break;
     case Qt::Key_PageUp:
         emit device.signalKeyPress(0x10000000);
         break;
     case Qt::Key_PageDown:
         emit device.signalKeyPress(0x20000000);
         break;
     case Qt::Key_F:
         emit device.signalKeyPress(0x00000200);
         break;
     case Qt::Key_Z:
         emit device.signalKeyPress(0x00000100);
         break;
         //        case Qt::Key_E:
         //            qmlIntegrator.enveloped = qmlIntegrator.enveloped===Enums.ENV_ON ? Enums.ENV_OFF :Enums.ENV_ON;
         //            _ascanAdaptor.newEnveloped(qmlIntegrator.enveloped===Enums.ENV_ON);;
         //            break;
     case Qt::Key_S:
         emit device.signalKeyPress(0x00000008);
         break;
         //        case Qt::Key_P:
         //            saveSettings();;
         //            break;
     case Qt::Key_Tab:
         emit device.signalKeyPress(0x00000010);
         break;
     case Qt::Key_Home:
         emit device.signalKeyPress(0x00000001);
         break;
    case Qt::Key_Return:
        emit device.signalKeyPress(0x00002000);
        break;
    case Qt::Key_Delete:
        emit device.signalKeyPress(0x00040000);
        break;
     }
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}
