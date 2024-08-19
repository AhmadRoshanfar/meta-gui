#include "settingswinadaptor.h"
#include <QtQml>

SettingsWinAdaptor::SettingsWinAdaptor(QObject *parent) : QObject(parent)
{

}

void SettingsWinAdaptor::show(){
    _window.show();
}

void SettingsWinAdaptor::hide(){
    _window.hide();
}

void SettingsWinAdaptor::declareQML() {
    qmlRegisterType<SettingsWinAdaptor>("SettingsWinAdaptor", 1, 0, "SettingsWinAdaptor");
}
