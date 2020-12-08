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
    void init();
    Q_INVOKABLE void set_uname(int index);

public slots:
    void slot_matching();

private:
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
    QQuickWidget *m_list;
    QString m_uname;
    QString m_pwd;
    QStringList m_unamelist;
};


