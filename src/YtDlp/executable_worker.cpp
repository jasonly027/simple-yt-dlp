#include "executable_worker.h"

#include <QDebug>

ExecutableWorker::ExecutableWorker(const QStringList &arguments, QObject *parent)
    : QObject(parent), m_process(new QProcess(this)) {
    m_process->setProgram("yt-dlp");
    m_process->setArguments(arguments);

    QObject::connect(m_process, &QProcess::readyReadStandardError, [&]() {
       qInfo() << m_process->readAllStandardError();
    });
    QObject::connect(m_process, &QProcess::readyReadStandardOutput, [&]() {
        qInfo() << m_process->readAllStandardOutput();
    });
}

ExecutableWorker::~ExecutableWorker() {
    qInfo() << "Destroying worker";
}

void ExecutableWorker::doWork() {
    m_process->start();
    m_process->waitForFinished(-1);
    qInfo() << "Finished work";
    emit workFinished();
}
