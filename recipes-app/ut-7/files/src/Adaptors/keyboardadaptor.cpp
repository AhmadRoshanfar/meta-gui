#include "keyboardadaptor.h"
#include <QtQml>
#include "../Common/Helpers/devicehelper.h"
KeyboardAdaptor::KeyboardAdaptor(QObject *parent) : QObject(parent)
{
    connect(&DeviceHelper::instance(),&DeviceHelper::signalKeyPress,this,&KeyboardAdaptor::setKey);
}

void KeyboardAdaptor::declareQML() {
    qmlRegisterType<KeyboardAdaptor>("KeyboardAdaptor", 1, 0, "KeyboardAdaptor");
}

void KeyboardAdaptor::keyPress(quint32 key){
    setKey(key);
}

void KeyboardAdaptor::reset(){
    setKey(-1);
}
//void KeyboardAdaptor::newKeyPress(const char& key){
//    setKey(key);
//}

quint32 KeyboardAdaptor::key(){
    return _key;
}
void KeyboardAdaptor::setKey(const quint32 &val){
    if (val == _key)
        return;
    _key = val;
    emit onKeyChanged();
}

