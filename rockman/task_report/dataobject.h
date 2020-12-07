#pragma once

#include <QObject>
#include <QString>

class DataObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString number READ number WRITE setNumber NOTIFY numberChanged)
public:
    DataObject(QObject *parent = nullptr);
    DataObject(const QString &name,const QString &color,const QString &number,QObject *parent=nullptr);
    QString name()const;
    void setName(const QString &name);
    QString color()const;
    void  setColor(const QString &color);
    QString number()const;
    void setNumber(const QString &number);

signals:
    void nameChanged();
    void colorChanged();
    void numberChanged();

private:
    QString m_name;
    QString m_color;
    QString m_number;
};
