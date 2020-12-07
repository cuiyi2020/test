#ifndef RWIDGET_H
#define RWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QtQuickWidgets/QtQuickWidgets>
#include <QStringList>

class Report;
class AbstractListModel;

class Rwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Rwidget(QWidget *parent = 0);
    ~Rwidget();
    Q_INVOKABLE void closeErrorMsg();
    Q_INVOKABLE void relieve(uint index);
    QStringList get_strlist(){
        return m_strlist;
    }

private slots:
    void slot_show_list();

private:
    void init();
    void create_ui();
    void create_connects();
    void set_list_context();

private:
    QStringList m_strlist;

private:
    QWidget *m_wd;
    QQuickWidget *m_list;
    QPushButton *m_btn;
    Report *m_report;
    QList<QObject*> m_datalist;    //QObject model
    AbstractListModel *m_listmodel;

};

#endif // RWIDGET_H
