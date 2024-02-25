#include "executable_worker.h"

ExecutableWorker::ExecutableWorker(QStringList &arguments, QObject *parent)
    : QObject(parent), m_process(new QProcess(this)) {
    m_process->setProgram("yt-dlp");
    m_process->setArguments(arguments);
}

QProcess * ExecutableWorker::process() const {
    return m_process;
}

void ExecutableWorker::doWork() {
    m_process->start();
    m_process->waitForFinished(-1);
}