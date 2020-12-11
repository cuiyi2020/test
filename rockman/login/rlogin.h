#pragma once

#include <QWidget>
#include <QtQuickWidgets/QtQuickWidgets>

class QPushButton;
class QLabel;
class QLineEdit;
class Rxml;

class Rlogin : public QWidget{

    Q_OBJECT

public:
    explicit Rlogin(QWidget *parent = 0);
    ~Rlogin();

    Q_INVOKABLE void set_uname(int index);

private slots:
    void slot_matching();
    void slot_close();

private:
    void init();
    void create_ui();
    void create_connections();

private:
    Rxml *m_xml;
    QWidget *m_wd;
    QLineEdit *m_uname_le;
    QLineEdit *m_pwd_le;
    QLabel *m_pwderror;
    QPushButton *m_unamebtn;
    QPushButton *m_login;
    QPushButton *m_closed;
    QPushButton *m_close;
    QQuickWidget *m_list;
    QString m_uname;
    QString m_pwd;
    QStringList m_unamelist;
};


