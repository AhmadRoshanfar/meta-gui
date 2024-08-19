#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include "Helpers/themeshelper.h"
namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();
//    ThemeModel* _theme;
public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;
private slots:
//    void newTheme();

protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // SETTINGSWINDOW_H
