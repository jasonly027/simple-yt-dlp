#ifndef SIMPLE_YT_DLP_YT_DLP_H
#define SIMPLE_YT_DLP_YT_DLP_H
#pragma once

#include <qqmlintegration.h>
#include <QObject>
#include <QtCore/qobject.h>
#include <QtCore/qtmetamacros.h>
#include <QProcess>

class YtDlp: public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    YtDlp(QObject *parent = 0);

    Q_INVOKABLE void checkExecutableExists();
    Q_INVOKABLE void invoke();
private:
    QProcess *m_process;
};

#endif