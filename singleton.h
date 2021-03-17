#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>
#include <QDebug>
class Singleton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString texto MEMBER _texto NOTIFY changedTexto)

public:
    explicit  Singleton(QObject *parent = nullptr);
    static QObject* createSingletonInstance(QQmlEngine *engine,  QJSEngine *scriptEngine);
    Q_INVOKABLE QString getInfo();
    void setTexto(QString);

signals:
    void callme();
    void changedTexto();

private:
   static Singleton *m_instance;
//   void setTexto(QString&);
   QString _texto;
};

#endif // SINGLETON_H
