#ifndef KEYBOARDADAPTOR_H
#define KEYBOARDADAPTOR_H

#include <QObject>

class KeyboardAdaptor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint32 key READ key WRITE setKey NOTIFY onKeyChanged)

public:
    explicit KeyboardAdaptor(QObject *parent = nullptr);
    static void declareQML();
    quint32 key();
    void setKey(const quint32&val);
signals:
    void onKeyChanged();

public slots:
    void reset();
    void keyPress(quint32 key);
private slots:
//    void newKeyPress(const char &key);
private:
    quint32 _key = -1;

};

#endif // KEYBOARDADAPTOR_H
