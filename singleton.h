#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>
#include <QDebug>
class Singleton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ textProperty WRITE setTextProperty NOTIFY changedText)

public:
    explicit  Singleton(QObject *parent = nullptr);
    static QObject* createSingletonInstance(QQmlEngine *engine,  QJSEngine *scriptEngine);
    Q_INVOKABLE QString getInfo();
    static void setText(QString);

    QString textProperty();
    void setTextProperty(QString&);

signals:
    void callme();
    void changedText(QString txt);

private:
   static Singleton *m_instance;
   QString _text;
};

#endif // SINGLETON_H
