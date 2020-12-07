#pragma once

#include <QWidget>

class QPushButton;
class QLabel;
class QLineEdit;

class Rlogin : public QWidget{
public:
    Rlogin();
    ~Rlogin(){

    }
    void init();

private:
    void create_ui();
    void create_connections();

private:
    QWidget *m_wd;
    QLineEdit *m_uname;
    QLineEdit *m_pwd;
    QLabel *m_pwderror;
    QPushButton *m_unamelist;
    QPushButton *m_login;
};


