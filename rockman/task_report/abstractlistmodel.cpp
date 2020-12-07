#include "abstractlistmodel.h"

AbstractListModel::AbstractListModel(QObject *parent)
    :QAbstractListModel(parent){
}

void AbstractListModel::addlist(const AbstractList& list){
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_abstractlist.append(list);
    endInsertRows();
}

int AbstractListModel::rowCount(const QModelIndex& parent) const{
    Q_UNUSED(parent);
    return m_abstractlist.count();
}

QVariant AbstractListModel::data(const QModelIndex& index, int role) const{
  if(index.row() < 0 || index.row() >= m_abstractlist.count())
      return QVariant();
  const AbstractList& abstractlist = m_abstractlist[index.row()];
  if(role == AbstractListRoles::PlaceRole)
      return abstractlist.place();
  else if(role == AbstractListRoles::DateRole)
      return abstractlist.date();
  else if(role == AbstractListRoles::ModelRole)
      return abstractlist.model();
  else if(role == AbstractListRoles::AreaRole)
      return abstractlist.area();
  else if(role == AbstractListRoles::DurationRole)
      return abstractlist.duration();
  return QVariant();
}

QHash<int, QByteArray> AbstractListModel::roleNames() const{
    QHash<int, QByteArray> roles;
    roles.insert(AbstractListRoles::PlaceRole, "rrplace");
    roles.insert(AbstractListRoles::DateRole, "rdate");
    roles.insert(AbstractListRoles::ModelRole, "rmodel");
    roles.insert(AbstractListRoles::AreaRole, "rarea");
    roles.insert(AbstractListRoles::DurationRole, "rduration");
    return roles;
}
