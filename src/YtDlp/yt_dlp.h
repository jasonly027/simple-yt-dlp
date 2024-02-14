#ifndef SIMPLE_YT_DLP_YT_DLP_H
#define SIMPLE_YT_DLP_YT_DLP_H
#include <qqmlintegration.h>
#pragma once

#include <QObject>
#include <QtCore/qobject.h>
#include <QtCore/qtmetamacros.h>

class YtDlp: public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    YtDlp(QObject *parent = 0);

};

#endif