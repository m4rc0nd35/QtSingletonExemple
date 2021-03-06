#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <singleton.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<Singleton>("QtSingleton", 1, 12, "Sinstance",
                                        Singleton::createSingletonInstance);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    Singleton *sing = new Singleton();
    sing->setText("Instance sing->setTexto");
    Singleton::setText("Static Singleton::setTexto");

    return app.exec();
}
