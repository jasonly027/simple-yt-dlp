#include "yt_dlp.h"
#include <QtCore/qobject.h>
#include <QDebug>

YtDlp::YtDlp(QObject *parent)
    : QObject(parent), m_process(new QProcess(this)) {
    m_process->setProgram("yt-dlp");
}

void YtDlp::invoke() {
    qDebug() << "Invoked";
    m_process->start();
}

void YtDlp::checkExecutableExists() {
    QProcess temp_process;

    QObject::connect(&temp_process, &QProcess::errorOccurred, [&temp_process]() {
        switch (temp_process.error()) {
            case QProcess::FailedToStart:
            case QProcess::Crashed:
            case QProcess::Timedout:
            case QProcess::ReadError:
            case QProcess::WriteError:
            case QProcess::UnknownError:
                qDebug() << "Error checking exec: " <<temp_process.errorString();
                break;
        }
    });

    temp_process.start("yt-dlpa");
}
