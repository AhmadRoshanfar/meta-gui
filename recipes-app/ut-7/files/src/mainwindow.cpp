 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QtQuickWidgets/QQuickWidget>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickView>
#include "Helpers/themeshelper.h"
#include "../Common/Helpers/devicehelper.h"
#include "../Common/Adaptors/snapshotadaptor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(
                //Qt::Window | // Add if popup doesn't show up
                Qt::FramelessWindowHint  // No window border
                //Qt::WindowDoesNotAcceptFocus  // No focus
                // Qt::WindowStaysOnTopHint // Always on top
                );

    setAttribute(Qt::WA_ShowWithoutActivating);// hide from taskbar

    ui->setupUi(this);
    setGeometry(0, 0, 800, 480);
    _theme = ThemesHelper::instance().theme();
    newTheme();
    /***************************************/
    //    ui->quickWidget->rootContext()->setContextProperty("w",this);

    QQuickView *viewT = new QQuickView();
    QQuickView *viewM = new QQuickView();
    QQuickView *viewR = new QQuickView();
    QQuickView *viewB = new QQuickView();
    viewT->rootContext()->setContextProperty("qmlIntegrator",&(QmlIntegrator::instance()));
    viewB->rootContext()->setContextProperty("qmlIntegrator",&(QmlIntegrator::instance()));
    viewM->rootContext()->setContextProperty("qmlIntegrator",&(QmlIntegrator::instance()));
    viewR->rootContext()->setContextProperty("qmlIntegrator",&(QmlIntegrator::instance()));

    viewT->rootContext()->setContextProperty("subqmlIntegrator",&(SubQMLIntegrator::instance()));
    viewB->rootContext()->setContextProperty("subqmlIntegrator",&(SubQMLIntegrator::instance()));
    viewM->rootContext()->setContextProperty("subqmlIntegrator",&(SubQMLIntegrator::instance()));
    viewR->rootContext()->setContextProperty("subqmlIntegrator",&(SubQMLIntegrator::instance()));

    viewT->rootContext()->setContextProperty("THEME",ThemesHelper::instance().theme());
    viewB->rootContext()->setContextProperty("THEME",ThemesHelper::instance().theme());
    viewM->rootContext()->setContextProperty("THEME",ThemesHelper::instance().theme());
    viewR->rootContext()->setContextProperty("THEME",ThemesHelper::instance().theme());

//    viewM->rootContext()->setContextProperty("evaluationAdaptor",&(EvaluationAdaptor::instance()));
    viewR->rootContext()->setContextProperty("evaluationAdaptor",&(EvaluationAdaptor::instance()));

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(3);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));


    containerT = QWidget::createWindowContainer(viewT,centralWidget());
    containerT->setMinimumSize(QSize(0, 50));
    containerT->setMaximumSize(QSize(16777215, 50));


    centralWidget()->setStyleSheet("background:rgb(238,238,238);");



    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
//    horizontalLayout_2->setContentsMargins(5, 0, 5, 0);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setSpacing(3);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    snapshot = new QLabel(centralWidget());
    snapshot->setObjectName(QString::fromUtf8("snapshot"));
    snapshot->setMaximumSize(QSize(16777215, 0));
    snapshot->setVisible(false);



    plot = new AScanChart(centralWidget());


    containerB = QWidget::createWindowContainer(viewB,centralWidget());
    containerB->setObjectName(QString::fromUtf8("containerB"));
    containerB->setMinimumSize(QSize(0, 50));
    containerB->setMaximumSize(QSize(16777215, 50));



    setup(plot);

    containerR = QWidget::createWindowContainer(viewR,centralWidget());
    containerR->setMinimumSize(QSize(200, 0));
    containerR->setMaximumSize(QSize(200, 16777215));

    containerM = QWidget::createWindowContainer(viewM,centralWidget());
    containerM->setMinimumSize(QSize(0, 60));
    containerM->setMaximumSize(QSize(16777215, 60));


    viewT->setSource(QUrl(QStringLiteral("qrc:/QML/MainTop.qml")));
    viewB->setSource(QUrl(QStringLiteral("qrc:/QML/MainBottomBar.qml")));
    viewR->setSource(QUrl(QStringLiteral("qrc:/QML/MainRight.qml")));
    viewM->setSource(QUrl(QStringLiteral("qrc:/QML/MainBottomMenu.qml")));


    verticalLayout_2->addWidget(containerT);
    verticalLayout_3->addWidget(snapshot);
    verticalLayout_3->addWidget(plot);
    verticalLayout_3->addWidget(containerB);
    horizontalLayout_2->addLayout(verticalLayout_3);
    horizontalLayout_2->addWidget(containerR);

    verticalLayout_2->addLayout(horizontalLayout_2);
    verticalLayout_2->addWidget(containerM);
    ui->verticalLayout->addLayout(verticalLayout_2);




    statusBar()->clearMessage();
    statusBar()->setSizeGripEnabled( false );
    statusBar()->hide();

    plot->replot();
    plot->yAxis->setRange((_qmlIntegrator.polarity() == Enums::Polarity::POL_RF)?-100:0,100);

//    centralWidget()->setCursor(Qt::BlankCursor);

    connect(&_qmlIntegrator,&QmlIntegrator::onFullscreenChanged, this, &MainWindow::fullscreen);

    connect(&_subqmlIntegrator,&SubQMLIntegrator::onTopbarVisibleChanged, this, &MainWindow::newTopbar);
    connect(&_subqmlIntegrator,&SubQMLIntegrator::onBottombarVisibleChanged, this, &MainWindow::newBottombar);
    connect(&_qmlIntegrator,&QmlIntegrator::onThemeChanged, this, &MainWindow::newTheme);
    connect(&_keyboardAdaptor,&KeyboardAdaptor::onKeyChanged, this, &MainWindow::newKey);
    connect(&_qmlIntegrator,&QmlIntegrator::onCallShowSnapshotChanged, this, &MainWindow::showSnapshot);
    connect(&_qmlIntegrator,&QmlIntegrator::onCallHideSnapshotChanged, this, &MainWindow::hideSnapshot);


    //    centralWidget()->setStyleSheet("background:rgb(238,238,238);");

}


void MainWindow::keyPressEvent(QKeyEvent *event){
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
//    qDebug()<<"key "<<event->key();
}

void MainWindow::newKey(){
    if(_keyboardAdaptor.key() == -1)
        return;
    switch(_keyboardAdaptor.key()&0xFF8FFFFF){
    case 0x00000200:
        if(_qmlIntegrator.fullscreen())
            break;
        if(!_qmlIntegrator.freezed())
            _ascanAdaptor.snapshot();
        _qmlIntegrator.setFreezed(!_qmlIntegrator.freezed());
        break;
    case 0x00000100:
        _qmlIntegrator.setZoomed(!_qmlIntegrator.zoomed());
        break;
    }
    _keyboardAdaptor.reset();

}



void MainWindow::setup(AScanChart *customPlot)
{
    _ascanAdaptor.registerAScan(customPlot);
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}




void MainWindow::fullscreen(){
    if(_qmlIntegrator.fullscreen()){
        //        pContainerB->setVisible(false);
        //        pContainerR->setVisible(false);
        //        pContainerR->setMaximumWidth(0);
        //        pContainerR->setMinimumWidth(0);
//        containerB->setMaximumHeight((_qmlIntegrator.bottombarVisible()?50:0));
//        containerB->setMinimumHeight((_qmlIntegrator.bottombarVisible()?50:0));
        containerR->setMaximumWidth(0);
        containerR->setMinimumWidth(0);
        containerR->setVisible(false);
        containerM->setMaximumHeight(0);
        containerM->setMinimumHeight(0);
        containerM->setVisible(false);
    }
    else{
        //        pContainerB->setVisible(true);
        containerR->setVisible(true);
        containerR->setMaximumWidth(200);
        containerR->setMinimumWidth(200);
        containerR->setMaximumHeight(1000);
        containerR->setMinimumHeight(0);
        containerM->setMaximumHeight(60);
        containerM->setMinimumHeight(60);
        containerM->setVisible(true);
    }
}

void MainWindow::newBottombar(){
    containerB->setVisible(_subqmlIntegrator.bottombarVisible());
    containerB->setMaximumHeight(_subqmlIntegrator.bottombarVisible()?50:0);
    containerB->setMinimumHeight(_subqmlIntegrator.bottombarVisible()?50:0);
}

void MainWindow::newTopbar(){
    containerT->setVisible(_subqmlIntegrator.topbarVisible());
    containerT->setMaximumHeight(_subqmlIntegrator.topbarVisible()?50:0);
    containerT->setMinimumHeight(_subqmlIntegrator.topbarVisible()?50:0);
}

//void MainWindow::newBottombar(){
//    if(_qmlIntegrator.fullscreen()){
////        pContainerB->setVisible(false);
//        //        pContainerR->setVisible(false);
//        //        pContainerR->setMaximumWidth(0);
//        //        pContainerR->setMinimumWidth(0);
//        pContainerB->setMaximumHeight((_qmlIntegrator.bottombarVisible()?45:0));
//        pContainerB->setMinimumHeight((_qmlIntegrator.bottombarVisible()?45:0));
//        pContainerR->setMaximumWidth(0);
//        pContainerR->setMinimumWidth(0);

//    }
//    else{
////        pContainerB->setVisible(true);
//        pContainerR->setVisible(true);
//        pContainerR->setMaximumWidth(200);
//        pContainerR->setMinimumWidth(200);
//        pContainerB->setMaximumHeight(100 - (_qmlIntegrator.bottombarVisible()?0:40));
//        pContainerB->setMinimumHeight(100 - (_qmlIntegrator.bottombarVisible()?0:40));
//    }
//}

void MainWindow::newTheme(){
//    qDebug()<<_theme->appBg();
    centralWidget()->setStyleSheet(QString("background:rgb(%1,%2,%3);").arg(_theme->appBg().red()).arg(_theme->appBg().green()).arg(_theme->appBg().blue()));
    if(plot != nullptr)
        plot->newTheme(_theme->chartBg(),_theme->chartMain(),_theme->chartEnvelope(),_theme->chartGrid(),_theme->chartAxis());
}

void MainWindow::showSnapshot(){

    QPixmap pic = SnapshotAdaptor().currentSnapshotPix();
    //    QPixmap scaled=pic.scaled ( 800, 480, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    snapshot->setVisible(true);
    auto h = plot->height();
//    auto h = pPlot->width();
    snapshot->setMinimumHeight(h);
    snapshot->setMaximumHeight(1000);
//    pSnapshot->setMaximumHeight(h);

    snapshot->setPixmap(pic);

    plot->setVisible(false);
}

void MainWindow::hideSnapshot(){
    snapshot->setVisible(false);
    snapshot->setMinimumHeight(0);
    snapshot->setMaximumHeight(0);
    plot->setVisible(true);

}

void MainWindow::realtimeDataSlot()
{
    static QTime time(QTime::currentTime());
    static int cnt;
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.05) // at most add point every 2 ms
    {
        _ascanAdaptor.updateAScan();
        _faultCalcAdaptor.calc();
        _alarmAdaptor.checkAlarms();
        _presParamsAdaptor.refresh();
        _USBDeviceAdaptor.checkUSBDevices();
    }
    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
        //        qDebug()<<QString("%1 FPS, Total Data points: %2")
        //                  .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
        //                  .arg(pPlot->graph(0)->data()->size()+pPlot->graph(1)->data()->size());
        lastFpsKey = key;
        frameCount = 0;
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::screenShot()
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QPixmap pm = QPixmap::grabWindow(qApp->desktop()->winId(), this->x()+2, this->y()+2, this->frameGeometry().width()-4, this->frameGeometry().height()-4);
#elif QT_VERSION < QT_VERSION_CHECK(5, 5, 0)
    QPixmap pm = qApp->primaryScreen()->grabWindow(qApp->desktop()->winId(), this->x()+2, this->y()+2, this->frameGeometry().width()-4, this->frameGeometry().height()-4);
#else

    QPixmap pm = qApp->primaryScreen()->grabWindow(qApp->desktop()->winId(), this->x()-7, this->y()-7, this->frameGeometry().width()+14, this->frameGeometry().height()+14);
#endif
    QString fileName = demoName.toLower()+".png";
    fileName.replace(" ", "");
    pm.save("./screenshots/"+fileName);
    qApp->quit();
}

//void MainWindow::allScreenShots()
//{
//#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
//    QPixmap pm = QPixmap::grabWindow(qApp->desktop()->winId(), this->x()+2, this->y()+2, this->frameGeometry().width()-4, this->frameGeometry().height()-4);
//#elif QT_VERSION < QT_VERSION_CHECK(5, 5, 0)
//    QPixmap pm = qApp->primaryScreen()->grabWindow(qApp->desktop()->winId(), this->x()+2, this->y()+2, this->frameGeometry().width()-4, this->frameGeometry().height()-4);
//#else
//    QPixmap pm = qApp->primaryScreen()->grabWindow(qApp->desktop()->winId(), this->x()-7, this->y()-7, this->frameGeometry().width()+14, this->frameGeometry().height()+14);
//#endif
//    QString fileName = demoName.toLower()+".png";
//    fileName.replace(" ", "");
//    pm.save("./screenshots/"+fileName);

//    if (currentDemoIndex < 19)
//    {
//        if (dataTimer.isActive())
//            dataTimer.stop();
//        dataTimer.disconnect();
//        delete ui->customPlot;
//        ui->customPlot = new QCustomPlot(ui->centralWidget);
//        ui->verticalLayout->addWidget(ui->customPlot);
//        setupDemo(currentDemoIndex+1);
//        // setup delay for demos that need time to develop proper look:
//        int delay = 250;
//        if (currentDemoIndex == 10) // Next is Realtime data demo
//            delay = 12000;
//        else if (currentDemoIndex == 15) // Next is Item demo
//            delay = 5000;
//        QTimer::singleShot(delay, this, SLOT(allScreenShots()));
//    } else
//    {
//        qApp->quit();
//    }
//}
