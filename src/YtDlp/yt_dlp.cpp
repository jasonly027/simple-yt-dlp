#include "yt_dlp.h"

#include <QtCore/qobject.h>
#include <QStringList>
#include "executable_controller.h"

YtDlp::YtDlp(QObject *parent)
    : QObject(parent),
      m_notifications(new Notifications(this)) {}

Notifications* YtDlp::notifications() const {
    return m_notifications;
}

void YtDlp::invoke() {
    qDebug() << "Invoked";
}

void YtDlp::checkExecutableExists() {
    ExecutableController worker = ExecutableController(QStringList());
}
