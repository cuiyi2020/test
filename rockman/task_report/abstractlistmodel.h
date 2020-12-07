#pragma once
#include <QObject>
#include <QAbstractListModel>

struct TaskReportCtx
{
    QString m_place;
    QString m_date;
    QString m_model;
    QString m_area;
    QString m_duration;
};

class AbstractList{
public:
    AbstractList(QString place, QString date, QString model,
                 QString area, QString duration){
        m_place = place;
        m_date = date;
        m_model = model;
        m_area = area;
        m_duration = duration;
    }
//    AbstractList::AbstractList(const QString &place, const QString &date, const QString &model,
//                               const QString &area, const QString &duration){
//        m_place = place;
//        m_date = date;
//        m_model = model;
//        m_area = area;
//        m_duration = duration;
//    }
    AbstractList(TaskReportCtx ctx){
        m_place = ctx.m_place;
        m_date = ctx.m_date;
        m_model = ctx.m_model;
        m_area = ctx.m_area;
        m_duration = ctx.m_duration;
    }
    QString place() const{
        return m_place;
    }
    QString date() const{
        return m_date;
    }
    QString model() const{
        return m_model;
    }
    QString area() const{
        return m_area;
    }
    QString duration() const{
        return m_duration;
    }

private:
    QString m_place;
    QString m_date;
    QString m_model;
    QString m_area;
    QString m_duration;
};

class AbstractListModel : public QAbstractListModel{

    Q_OBJECT

public:
    enum AbstractListRoles{
        PlaceRole=Qt::UserRole+1,
        DateRole,
        ModelRole,
        AreaRole,
        DurationRole
    };
    AbstractListModel(QObject *parent=nullptr);

    void addlist(const AbstractList& list);
    int rowCount(const QModelIndex& parent=QModelIndex()) const;
private:
    QVariant data(const QModelIndex& index, int role=Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
private:
    QList<AbstractList> m_abstractlist;
};
