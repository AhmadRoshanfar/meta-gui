#ifndef SETTINGSWINADAPTOR_H
#define SETTINGSWINADAPTOR_H

#include <QObject>
#include "settingswindow.h"
class SettingsWinAdaptor : public QObject
{
    Q_OBJECT
    SettingsWindow _window;
public:
    explicit SettingsWinAdaptor(QObject *parent = nullptr);
    static void declareQML();


signals:

public slots:
    void show();
    void hide();
};

#endif // SETTINGSWINADAPTOR_H
