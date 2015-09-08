#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "plot.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Plot>("Plot",1,0,"Plot");

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
