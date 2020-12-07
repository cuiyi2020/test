#include "rlogin.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

Rlogin::Rlogin(){
    create_ui();
    create_connections();
    init();
}

void Rlogin::init(){
    if (!m_cmb)
        return;
    //m_cmb->addItem(QString::asprintf("Item %d",i));
    m_cmb->addItem("aa");
    m_cmb->addItem("bb");
    m_cmb->addItem("cc");

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

    m_cmb = new QComboBox(m_wd);
    m_cmb->move(256, 317);
    m_cmb->resize(280, 290);
    m_cmb->setStyleSheet("color:white");//文本颜色
    m_cmb->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    m_cmb->hide();

    QLabel *pwd_lb = new QLabel(m_wd);
    pwd_lb->setText("密码");
    pwd_lb->setFont(title_ft);
    pwd_lb->move(201, 392);
    pwd_lb->setStyleSheet("color:white");

    m_pwd = new QLineEdit(m_wd);
    m_pwd->setFont(input_ft);
    m_pwd->move(273, 400-5);
    m_pwd->setStyleSheet("color:white");
    m_pwd->setStyleSheet("background-color:green");

    m_pwderror = new QLabel(m_wd);
    m_pwderror->setText("密码错误");
    m_pwderror->setFont(input_ft);
    m_pwderror->move(459+10, 396);
    m_pwderror->setStyleSheet("color:red");

    m_login = new QPushButton(m_wd);
    m_login->resize(390, 78);
    m_login->setText("登录");
    m_login->move(170, 508);
    m_login->setStyleSheet("color:white");
    m_login->setFont(title_ft);
}

void Rlogin::create_connections(){
    connect(m_unamelist, &QPushButton::clicked, [&](){
        if (m_cmb->isVisible()){
            m_cmb->close();
        }
        else{
            m_cmb->show();
        }
    });
}
