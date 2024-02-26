#ifndef SIMPLE_YT_DLP_EXECUTABLE_CONTROLLER_H
#define SIMPLE_YT_DLP_EXECUTABLE_CONTROLLER_H
#pragma once

#include <QObject>
#include <QThread>

class ExecutableController : public QObject {
    Q_OBJECT
public:
    ExecutableController(QStringList arguments, QObject *parent = 0);
private:
    QThread *m_thread;
};

#endif //SIMPLE_YT_DLP_EXECUTABLE_CONTROLLER_H
