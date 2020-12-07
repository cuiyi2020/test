#include "rlogin.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

Rlogin::Rlogin(){
    create_ui();
}

void Rlogin::init(){

}

void Rlogin::create_ui(){
    m_wd = new QWidget(this);
    m_wd->resize(1280, 800);
    m_wd->setStyleSheet("background:#FF101b2b");

    QFont title_ft("黑体", 15);
    QFont input_ft("黑体", 13);

    QLabel *account_lb = new QLabel(m_wd);
    account_lb->setText("账号");
    account_lb->setFont(title_ft);
    account_lb->move(201, 284);
    account_lb->setStyleSheet("color:white");//文本颜色
    //account_lb->setStyleSheet("background-color:green");//背景色

    m_uname = new QLineEdit(m_wd);
    m_uname->setFont(input_ft);
    m_uname->move(273, 292-5);
    m_uname->setStyleSheet("color:white");//文本颜色
    m_uname->setStyleSheet("background-color:green");//背景色

    m_unamelist = new QPushButton(m_wd);
    m_unamelist->resize(20, 12);
    m_unamelist->move(516, 291);
    m_unamelist->setStyleSheet("QPushButton{border-image: url(:/返回箭头.png)}");

    QLabel *pwd_lb = new QLabel(m_wd);
    pwd_lb->setText("密码");
    pwd_lb->setFont(title_ft);
    pwd_lb->move(201, 392);
    pwd_lb->setStyleSheet("color:white");//文本颜色

    m_pwd = new QLineEdit(m_wd);
    m_pwd->setFont(input_ft);
    m_pwd->move(273, 400-5);
    m_pwd->setStyleSheet("color:white");//文本颜色
    m_pwd->setStyleSheet("background-color:green");//背景色

    m_pwderror = new QLabel(m_wd);
    m_pwderror->setText("密码错误");
    m_pwderror->setFont(input_ft);
    m_pwderror->move(459+10, 396);
    m_pwderror->setStyleSheet("color:red");//文本颜色

    m_login = new QPushButton(m_wd);
    m_login->resize(390, 78);
    m_login->setText("登陆");
    m_login->move(170, 508);
    m_login->setStyleSheet("color:white");//背景色
    m_login->setFont(title_ft);
}

void Rlogin::create_connections(){

}
