#include <pybind11/embed.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "testpy.h"

namespace py = pybind11;

int main(int argc, char *argv[]) {
    py::scoped_interpreter guard{};

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_TestPy", new TestPy());
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.loadFromModule("web-media-downloader-gui", "Main");

    return app.exec();
}
