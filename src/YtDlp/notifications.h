#ifndef SIMPLE_YT_DLP_NOTIFICATIONS_H
#define SIMPLE_YT_DLP_NOTIFICATIONS_H
#pragma once

#include <QObject>
#include <QAbstractListModel>

struct Notification {
    Notification(const QString &title, const QString &description)
        : title(title),
          description(description) {}
    QString title;
    QString description;
};

class Notifications: public QAbstractListModel {
    Q_OBJECT
public:
    enum NotificationsRoles {
        TitleRole = Qt::UserRole + 1,
        DescriptionRole
    };

    explicit Notifications(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const override;
    void prependRow(Notification &&notification);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<Notification> m_notifications;
};


#endif //SIMPLE_YT_DLP_NOTIFICATIONS_H
