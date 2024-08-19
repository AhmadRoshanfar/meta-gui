#ifndef THEMEMODEL_H
#define THEMEMODEL_H

#include <QObject>
#include <QColor>
class ThemeModel : public QObject
{
    Q_OBJECT
Q_PROPERTY(	QColor appBg READ appBg WRITE setAppBg NOTIFY onAppBgChanged)
Q_PROPERTY(QColor paramBg READ paramBg WRITE setParamBg NOTIFY onParamBgChanged)
Q_PROPERTY(QColor paramName READ paramName WRITE setParamName NOTIFY onParamNameChanged)
Q_PROPERTY(QColor paramSelectedBg READ paramSelectedBg WRITE setParamSelectedBg NOTIFY onParamSelectedBgChanged)
Q_PROPERTY(QColor paramNameSelected READ paramNameSelected WRITE setParamNameSelected NOTIFY onParamNameSelectedChanged)
Q_PROPERTY(QColor unit READ unit WRITE setUnit NOTIFY onUnitChanged)
Q_PROPERTY(QColor unitSelected READ unitSelected WRITE setUnitSelected NOTIFY onUnitSelectedChanged)
Q_PROPERTY(QColor value READ value WRITE setValue NOTIFY onValueChanged)
Q_PROPERTY(QColor valueSelected READ valueSelected WRITE setValueSelected NOTIFY onValueSelectedChanged)
Q_PROPERTY(QColor tabBg READ tabBg WRITE setTabBg NOTIFY onTabBgChanged)
Q_PROPERTY(QColor tabFg READ tabFg WRITE setTabFg NOTIFY onTabFgChanged)
Q_PROPERTY(QColor topResName READ topResName WRITE setTopResName NOTIFY onTopResNameChanged)
Q_PROPERTY(QColor topResValue READ topResValue WRITE setTopResValue NOTIFY onTopResValueChanged)
Q_PROPERTY(QColor botResName READ botResName WRITE setBotResName NOTIFY onBotResNameChanged)
Q_PROPERTY(QColor botResValue READ botResValue WRITE setBotResValue NOTIFY onBotResValueChanged)
Q_PROPERTY(QColor chartBg READ chartBg WRITE setChartBg NOTIFY onChartBgChanged)
Q_PROPERTY(QColor chartMain READ chartMain WRITE setChartMain NOTIFY onChartMainChanged)
Q_PROPERTY(QColor chartMarker READ chartMarker WRITE setChartMarker NOTIFY onChartMarkerChanged)
Q_PROPERTY(QColor chartEnvelope READ chartEnvelope WRITE setChartEnvelope NOTIFY onChartEnvelopeChanged)
Q_PROPERTY(QColor chartAxis READ chartAxis WRITE setChartAxis NOTIFY onChartAxisChanged)
Q_PROPERTY(QColor chartGrid READ chartGrid WRITE setChartGrid NOTIFY onChartGridChanged)
Q_PROPERTY(QColor chartDAC READ chartDAC WRITE setChartDAC NOTIFY onChartDACChanged)
Q_PROPERTY(QColor topBarBg READ topBarBg WRITE setTopBarBg NOTIFY onTopBarBgChanged)
Q_PROPERTY(QColor chartTopBarBg READ chartTopBarBg WRITE setChartTopBarBg NOTIFY onChartTopBarBgChanged)
Q_PROPERTY(QColor bottomBarBg READ bottomBarBg WRITE setBottomBarBg NOTIFY onBottomBarBgChanged)
Q_PROPERTY(QColor downArrowBg READ downArrowBg WRITE setDownArrowBg NOTIFY onDownArrowBgChanged)
Q_PROPERTY(QColor downArrowFg READ downArrowFg WRITE setDownArrowFg NOTIFY onDownArrowFgChanged)
Q_PROPERTY(QColor leftRightArrowBg READ leftRightArrowBg WRITE setLeftRightArrowBg NOTIFY onLeftRightArrowBgChanged)
Q_PROPERTY(QColor leftRightArrowFg READ leftRightArrowFg WRITE setLeftRightArrowFg NOTIFY onLeftRightArrowFgChanged)


        QColor _appBg;
     QColor _paramBg;
     QColor _paramName;
     QColor _paramSelectedBg;
     QColor _paramNameSelected;
     QColor _unit;
     QColor _unitSelected;
     QColor _value;
     QColor _valueSelected;
     QColor _tabBg;
     QColor _tabFg;
     QColor _topResName;
     QColor _topResValue;
     QColor _botResName;
     QColor _botResValue;
     QColor _chartBg;
     QColor _chartMain;
     QColor _chartMarker;
     QColor _chartEnvelope;
     QColor _chartAxis;
     QColor _chartGrid;
     QColor _chartDAC;
     QColor _topBarBg;
     QColor _chartTopBarBg;
     QColor _bottomBarBg;
     QColor _downArrowBg;
     QColor _downArrowFg;
     QColor _leftRightArrowBg;
     QColor _leftRightArrowFg;


public:
    explicit ThemeModel(QObject* parent = nullptr);
        QColor appBg();
void setAppBg(const 	QColor&val);
QColor paramBg();
void setParamBg(const QColor&val);
QColor paramName();
void setParamName(const QColor&val);
QColor paramSelectedBg();
void setParamSelectedBg(const QColor&val);
QColor paramNameSelected();
void setParamNameSelected(const QColor&val);
QColor unit();
void setUnit(const QColor&val);
QColor unitSelected();
void setUnitSelected(const QColor&val);
QColor value();
void setValue(const QColor&val);
QColor valueSelected();
void setValueSelected(const QColor&val);
QColor tabBg();
void setTabBg(const QColor&val);
QColor tabFg();
void setTabFg(const QColor&val);
QColor topResName();
void setTopResName(const QColor&val);
QColor topResValue();
void setTopResValue(const QColor&val);
QColor botResName();
void setBotResName(const QColor&val);
QColor botResValue();
void setBotResValue(const QColor&val);
QColor chartBg();
void setChartBg(const QColor&val);
QColor chartMain();
void setChartMain(const QColor&val);
QColor chartMarker();
void setChartMarker(const QColor&val);
QColor chartEnvelope();
void setChartEnvelope(const QColor&val);
QColor chartAxis();
void setChartAxis(const QColor&val);
QColor chartGrid();
void setChartGrid(const QColor&val);
QColor chartDAC();
void setChartDAC(const QColor&val);
QColor topBarBg();
void setTopBarBg(const QColor&val);
QColor chartTopBarBg();
void setChartTopBarBg(const QColor&val);
QColor bottomBarBg();
void setBottomBarBg(const QColor&val);
QColor downArrowBg();
void setDownArrowBg(const QColor&val);
QColor downArrowFg();
void setDownArrowFg(const QColor&val);
QColor leftRightArrowBg();
void setLeftRightArrowBg(const QColor&val);
QColor leftRightArrowFg();
void setLeftRightArrowFg(const QColor&val);

signals:

void onAppBgChanged();
void onParamBgChanged();
void onParamNameChanged();
void onParamSelectedBgChanged();
void onParamNameSelectedChanged();
void onUnitChanged();
void onUnitSelectedChanged();
void onValueChanged();
void onValueSelectedChanged();
void onTabBgChanged();
void onTabFgChanged();
void onTopResNameChanged();
void onTopResValueChanged();
void onBotResNameChanged();
void onBotResValueChanged();
void onChartBgChanged();
void onChartMainChanged();
void onChartMarkerChanged();
void onChartEnvelopeChanged();
void onChartAxisChanged();
void onChartGridChanged();
void onChartDACChanged();
void onTopBarBgChanged();
void onChartTopBarBgChanged();
void onBottomBarBgChanged();
void onDownArrowBgChanged();
void onDownArrowFgChanged();
void onLeftRightArrowBgChanged();
void onLeftRightArrowFgChanged();
};
#endif // THEMEMODEL_H
