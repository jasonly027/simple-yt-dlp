#ifndef SIMPLE_YT_DLP_YT_DLP_H
#define SIMPLE_YT_DLP_YT_DLP_H
#pragma once

#include <qqmlintegration.h>
#include <QObject>
#include <QtCore/qobject.h>
#include <QtCore/qtmetamacros.h>
#include <QProcess>
#include "notifications.h"

class YtDlp: public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(Notifications *notifications READ notifications NOTIFY notificationsChanged)
public:
    YtDlp(QObject *parent = 0);

    [[nodiscard]] Notifications* notifications() const;
    Q_INVOKABLE void checkExecutableExists();
    Q_INVOKABLE void invoke();
signals:
    void notificationsChanged();
private:
    Notifications *m_notifications;
};

#endif