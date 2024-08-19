#ifndef THEMESHELPER_H
#define THEMESHELPER_H

#include <QObject>
#include "Models/thememodel.h"
#include "../Common/Helpers/qmlintegrator.h"
class ThemesHelper : public QObject
{
    Q_OBJECT
    ThemesHelper(QObject *parent = nullptr);
    ThemeModel _themes[7];
    ThemeModel _theme;
//    Q_PROPERTY(	ThemeModel theme READ theme)

    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

public:
    ThemesHelper(const ThemesHelper&) = delete;
    ThemesHelper & operator= (const ThemesHelper &) = delete;
    ThemesHelper(ThemesHelper &&) = delete;
    ThemesHelper & operator= (ThemesHelper &&) = delete;
    static ThemesHelper&instance(){
        static ThemesHelper test;
        return test;
    }
    ThemeModel* theme();

private slots:
    void newTheme();
};
#endif // THEMESHELPER_H
