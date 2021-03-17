#include "singleton.h"
Singleton *Singleton::m_instance=nullptr;

Singleton::Singleton(QObject *parent) : QObject(parent)
{
    _text = "Q_PROPRERTY C++ >> QML";
    Q_EMIT changedText("changedText Construct C++");
}
QObject* Singleton::createSingletonInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    if(m_instance==nullptr)
        m_instance = new Singleton;

    return m_instance;
}
QString Singleton::getInfo()
{
    emit callme();
    return "Hi, i am from SingletonClass";
}
void Singleton::setText(QString txt)
{
    Q_EMIT m_instance->changedText(txt);
}
QString Singleton::textProperty()
{
    return _text;
}
void Singleton::setTextProperty(QString &txt)
{
    qDebug() << txt << endl;
}
