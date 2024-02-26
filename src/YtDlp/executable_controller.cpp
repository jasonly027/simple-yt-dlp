#include "executable_controller.h"

#include <QProcess>
#include <QDebug>
#include "executable_worker.h"

ExecutableController::ExecutableController(QStringList arguments, QObject *parent)
    : QObject(parent), m_thread(new QThread) {
    auto *worker = new ExecutableWorker(arguments);
    worker->moveToThread(m_thread);

    QObject::connect(m_thread, &QThread::started, worker, &ExecutableWorker::doWork);
    QObject::connect(worker, &ExecutableWorker::workFinished, m_thread, &QThread::quit);
    QObject::connect(m_thread, &QThread::finished, worker, &QObject::deleteLater);
    QObject::connect(m_thread, &QThread::finished, m_thread, &QObject::deleteLater);

    m_thread->start();
}
