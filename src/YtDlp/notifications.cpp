#include "notifications.h"

Notifications::Notifications(QObject *parent)
        : QAbstractListModel(parent) {
    m_notifications << Notification("Title 1", "Desc 1");
    m_notifications << Notification("Title 2", "Desc 2");
}

int Notifications::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_notifications.size();
}

void Notifications::prependRow(Notification &&notification) {
    beginInsertRows(QModelIndex(), 0, 0);
    m_notifications.push_front(std::move(notification));
    endInsertRows();
}

QVariant Notifications::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    const Notification &notification = m_notifications[index.row()];
    switch ((NotificationsRoles) role) {
        case TitleRole:
            return notification.title;
        case DescriptionRole:
            return notification.description;
    }

    return QVariant();
}

QHash<int, QByteArray> Notifications::roleNames() const {
    static QHash<int, QByteArray> mapping {
            {TitleRole, "title"},
            {DescriptionRole, "description"}
    };
    return mapping;
}
