#include "rlogin.h"
#include "rxml.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>

Rlogin::Rlogin(QWidget *parent) : QWidget(parent){
    init();
    create_ui();
    create_connections();
}

Rlogin::~Rlogin(){
    if (m_xml){
        delete m_xml;
    }
}

void Rlogin::init(){
    m_xml = new Rxml();
    m_unamelist = m_xml->get_unamelist();
    //m_cmb->addItem(QString::asprintf("Item %d",i));
}

void Rlogin::create_ui(){
    m_wd = new QWidget(this);
    m_wd->resize(1280, 800);
    m_wd->setStyleSheet("background:#FF101b2b");

    QFont title_ft("黑体", 15);
    QFont input_ft("黑体", 13);
    QFont close_ft("黑体", 16);

    QLabel *account_lb = new QLabel(m_wd);
    account_lb->setText("账号");
    account_lb->setFont(title_ft);
    account_lb->move(201, 284);
    account_lb->setStyleSheet("color:white");
    //account_lb->setStyleSheet("background-color:transparent");//背景色

    m_uname_le = new QLineEdit(m_wd);
    m_uname_le->setFont(input_ft);
    m_uname_le->move(273, 292-3);
    m_uname_le->setStyleSheet("color:white; border:no");
    m_uname_le->setText("xuzuzu");

    m_unamebtn = new QPushButton(m_wd);
    m_unamebtn->resize(22, 12);
    m_unamebtn->move(530, 291);
    m_unamebtn->setStyleSheet("QPushButton{border-image: url(:/login-btn-down.png)}");

    QLabel *up_lb = new QLabel(m_wd);
    up_lb->resize(390, 1);
    up_lb->move(170, 342);
    up_lb->setStyleSheet("background-color:white");

    QLabel *pwd_lb = new QLabel(m_wd);
    pwd_lb->setText("密码");
    pwd_lb->setFont(title_ft);
    pwd_lb->move(201, 392);
    pwd_lb->setStyleSheet("color:white");

    m_pwd_le = new QLineEdit(m_wd);
    m_pwd_le->setFont(input_ft);
    m_pwd_le->move(273, 400-3);
    m_pwd_le->setStyleSheet("color:white; border:no");

    m_pwderror = new QLabel(m_wd);
    m_pwderror->setText("密码错误");
    m_pwderror->setFont(input_ft);
    m_pwderror->move(459+10, 396);
    m_pwderror->setStyleSheet("color:red");
    m_pwderror->hide();

    QLabel *down_lb = new QLabel(m_wd);
    down_lb->resize(390, 1);
    down_lb->move(170, 455);
    down_lb->setStyleSheet("background-color:white");

    m_login = new QPushButton(m_wd);
    m_login->resize(390, 78);
    m_login->move(170, 508);
    m_login->setStyleSheet("QPushButton{border-image: url(:/login-btn-login.png)}");


    m_closed = new QPushButton(m_wd);
    m_closed->resize(29, 29);
    m_closed->move(321, 640);
    m_closed->setStyleSheet("QPushButton{border-image: url(:/关机.png)}");

    m_close = new QPushButton(m_wd);
    m_close->resize(47, 22);
    m_close->setText("关机");
    m_close->move(360, 644);
    m_close->setStyleSheet("color:white; border:no");
    m_close->setFont(close_ft);

    m_list = new QQuickWidget(this);
    m_list->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_list->setClearColor(QColor(Qt::transparent));
    m_list->rootContext()->setContextProperty("accountMsg", this);
    m_list->rootContext()->setContextProperty("accountModel", QVariant::fromValue(m_unamelist));
    m_list->setSource(QUrl("qrc:/account.qml"));
    m_list->move(256, 317);
    m_list->hide();
    m_list->raise();
}

void Rlogin::create_connections(){
    connect(m_login, SIGNAL(clicked()), this, SLOT(slot_matching()));
    connect(m_closed, SIGNAL(clicked()), this, SLOT(slot_close()));
    connect(m_close, SIGNAL(clicked()), this, SLOT(slot_close()));
    connect(m_unamebtn, &QPushButton::clicked, [&](){
        if (m_list->isVisible()){
            m_unamebtn->setStyleSheet("QPushButton{border-image: url(:/login-btn-down.png)}");
            m_list->hide();
        }
        else{
            m_unamebtn->setStyleSheet("QPushButton{border-image: url(:/login-btn-up.png)}");
            m_list->show();
        }
    });
}

void Rlogin::slot_matching(){
    m_uname = m_uname_le->text();
    m_pwd = m_pwd_le->text();
    //qDebug() << m_uname << m_pwd;
    bool ret = m_xml->is_ok(m_uname, m_pwd);
    if (!ret){
        if (!m_pwderror->isVisible())
            m_pwderror->show();
    }
    else{
        if (m_pwderror->isVisible())
            m_pwderror->hide();
    }
//    QString res = ret ? "成功" : "失败";
//    QMessageBox::warning(NULL, "账号密码校验:", res, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void Rlogin::set_uname(int index){
    if(index >= m_unamelist.size())
        return;
    m_uname_le->setText(m_unamelist.at(index)); 
    m_unamebtn->setStyleSheet("QPushButton{border-image: url(:/login-btn-down.png)}");
    m_list->hide();
}

void Rlogin::slot_close(){
    //qDebug() << "Shut down.";
}

