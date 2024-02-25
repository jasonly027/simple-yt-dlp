#include "executable_controller.h"

#include "executable_worker.h"
#include <QProcess>
#include <QDebug>

ExecutableController::ExecutableController(QStringList arguments, QObject *parent)
    : QObject(parent), m_thread() {
    ExecutableWorker *worker(new ExecutableWorker(arguments));
    worker->moveToThread(&m_thread);
    QObject::connect(&m_thread, &QThread::started, worker, &ExecutableWorker::doWork);
    QObject::connect(&m_thread, &QThread::finished, worker, &QObject::deleteLater);

    QObject::connect(worker->process(), &QProcess::readAllStandardError, [&]() {
       qInfo() << worker->process()->readAllStandardError();
    });

    m_thread.start();
}
