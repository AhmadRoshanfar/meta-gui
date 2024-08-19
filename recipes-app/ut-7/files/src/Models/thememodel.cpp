#include "thememodel.h"

ThemeModel::ThemeModel( QObject *parent) :
    QObject(parent)
{
}

QColor ThemeModel::appBg(){
    return _appBg;
}
void ThemeModel::setAppBg(const 	QColor &val){
    if (val == _appBg)
        return;
    _appBg = val;
    emit onAppBgChanged();
}

QColor ThemeModel::paramBg(){
    return _paramBg;
}
void ThemeModel::setParamBg(const QColor &val){
    if (val == _paramBg)
        return;
    _paramBg = val;
    emit onParamBgChanged();
}

QColor ThemeModel::paramName(){
    return _paramName;
}
void ThemeModel::setParamName(const QColor &val){
    if (val == _paramName)
        return;
    _paramName = val;
    emit onParamNameChanged();
}

QColor ThemeModel::paramSelectedBg(){
    return _paramSelectedBg;
}
void ThemeModel::setParamSelectedBg(const QColor &val){
    if (val == _paramSelectedBg)
        return;
    _paramSelectedBg = val;
    emit onParamSelectedBgChanged();
}

QColor ThemeModel::paramNameSelected(){
    return _paramNameSelected;
}
void ThemeModel::setParamNameSelected(const QColor &val){
    if (val == _paramNameSelected)
        return;
    _paramNameSelected = val;
    emit onParamNameSelectedChanged();
}

QColor ThemeModel::unit(){
    return _unit;
}
void ThemeModel::setUnit(const QColor &val){
    if (val == _unit)
        return;
    _unit = val;
    emit onUnitChanged();
}

QColor ThemeModel::unitSelected(){
    return _unitSelected;
}
void ThemeModel::setUnitSelected(const QColor &val){
    if (val == _unitSelected)
        return;
    _unitSelected = val;
    emit onUnitSelectedChanged();
}

QColor ThemeModel::value(){
    return _value;
}
void ThemeModel::setValue(const QColor &val){
    if (val == _value)
        return;
    _value = val;
    emit onValueChanged();
}

QColor ThemeModel::valueSelected(){
    return _valueSelected;
}
void ThemeModel::setValueSelected(const QColor &val){
    if (val == _valueSelected)
        return;
    _valueSelected = val;
    emit onValueSelectedChanged();
}

QColor ThemeModel::tabBg(){
    return _tabBg;
}
void ThemeModel::setTabBg(const QColor &val){
    if (val == _tabBg)
        return;
    _tabBg = val;
    emit onTabBgChanged();
}

QColor ThemeModel::tabFg(){
    return _tabFg;
}
void ThemeModel::setTabFg(const QColor &val){
    if (val == _tabFg)
        return;
    _tabFg = val;
    emit onTabFgChanged();
}

QColor ThemeModel::topResName(){
    return _topResName;
}
void ThemeModel::setTopResName(const QColor &val){
    if (val == _topResName)
        return;
    _topResName = val;
    emit onTopResNameChanged();
}

QColor ThemeModel::topResValue(){
    return _topResValue;
}
void ThemeModel::setTopResValue(const QColor &val){
    if (val == _topResValue)
        return;
    _topResValue = val;
    emit onTopResValueChanged();
}

QColor ThemeModel::botResName(){
    return _botResName;
}
void ThemeModel::setBotResName(const QColor &val){
    if (val == _botResName)
        return;
    _botResName = val;
    emit onBotResNameChanged();
}

QColor ThemeModel::botResValue(){
    return _botResValue;
}
void ThemeModel::setBotResValue(const QColor &val){
    if (val == _botResValue)
        return;
    _botResValue = val;
    emit onBotResValueChanged();
}

QColor ThemeModel::chartBg(){
    return _chartBg;
}
void ThemeModel::setChartBg(const QColor &val){
    if (val == _chartBg)
        return;
    _chartBg = val;
    emit onChartBgChanged();
}

QColor ThemeModel::chartMain(){
    return _chartMain;
}
void ThemeModel::setChartMain(const QColor &val){
    if (val == _chartMain)
        return;
    _chartMain = val;
    emit onChartMainChanged();
}

QColor ThemeModel::chartMarker(){
    return _chartMarker;
}
void ThemeModel::setChartMarker(const QColor &val){
    if (val == _chartMarker)
        return;
    _chartMarker = val;
    emit onChartMarkerChanged();
}

QColor ThemeModel::chartEnvelope(){
    return _chartEnvelope;
}
void ThemeModel::setChartEnvelope(const QColor &val){
    if (val == _chartEnvelope)
        return;
    _chartEnvelope = val;
    emit onChartEnvelopeChanged();
}

QColor ThemeModel::chartAxis(){
    return _chartAxis;
}
void ThemeModel::setChartAxis(const QColor &val){
    if (val == _chartAxis)
        return;
    _chartAxis = val;
    emit onChartAxisChanged();
}

QColor ThemeModel::chartGrid(){
    return _chartGrid;
}
void ThemeModel::setChartGrid(const QColor &val){
    if (val == _chartGrid)
        return;
    _chartGrid = val;
    emit onChartGridChanged();
}

QColor ThemeModel::chartDAC(){
    return _chartDAC;
}
void ThemeModel::setChartDAC(const QColor &val){
    if (val == _chartDAC)
        return;
    _chartDAC = val;
    emit onChartDACChanged();
}

QColor ThemeModel::topBarBg(){
    return _topBarBg;
}
void ThemeModel::setTopBarBg(const QColor &val){
    if (val == _topBarBg)
        return;
    _topBarBg = val;
    emit onTopBarBgChanged();
}

QColor ThemeModel::chartTopBarBg(){
    return _chartTopBarBg;
}
void ThemeModel::setChartTopBarBg(const QColor &val){
    if (val == _chartTopBarBg)
        return;
    _chartTopBarBg = val;
    emit onChartTopBarBgChanged();
}

QColor ThemeModel::bottomBarBg(){
    return _bottomBarBg;
}
void ThemeModel::setBottomBarBg(const QColor &val){
    if (val == _bottomBarBg)
        return;
    _bottomBarBg = val;
    emit onBottomBarBgChanged();
}

QColor ThemeModel::downArrowBg(){
    return _downArrowBg;
}
void ThemeModel::setDownArrowBg(const QColor &val){
    if (val == _downArrowBg)
        return;
    _downArrowBg = val;
    emit onDownArrowBgChanged();
}

QColor ThemeModel::downArrowFg(){
    return _downArrowFg;
}
void ThemeModel::setDownArrowFg(const QColor &val){
    if (val == _downArrowFg)
        return;
    _downArrowFg = val;
    emit onDownArrowFgChanged();
}

QColor ThemeModel::leftRightArrowBg(){
    return _leftRightArrowBg;
}
void ThemeModel::setLeftRightArrowBg(const QColor &val){
    if (val == _leftRightArrowBg)
        return;
    _leftRightArrowBg = val;
    emit onLeftRightArrowBgChanged();
}

QColor ThemeModel::leftRightArrowFg(){
    return _leftRightArrowFg;
}
void ThemeModel::setLeftRightArrowFg(const QColor &val){
    if (val == _leftRightArrowFg)
        return;
    _leftRightArrowFg = val;
    emit onLeftRightArrowFgChanged();
}

