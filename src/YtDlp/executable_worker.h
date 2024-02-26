#ifndef SIMPLE_YT_DLP_EXECUTABLE_WORKER_H
#define SIMPLE_YT_DLP_EXECUTABLE_WORKER_H
#pragma once

#include <QObject>
#include <QProcess>

class ExecutableWorker : public QObject {
    Q_OBJECT
public:
    ExecutableWorker(const QStringList &arguments, QObject *parent = 0);
    ~ExecutableWorker();
public slots:
    void doWork();
signals:
    void workFinished();
private:
    QProcess *m_process;
};

#endif //SIMPLE_YT_DLP_EXECUTABLE_WORKER_H
