#include "rwidget.h"
#include "task_report/report.h"
#include "task_report/dataobject.h"
#include "task_report/abstractlistmodel.h"
#include <QDebug>

Rwidget::Rwidget(QWidget *parent) : QWidget(parent){
    init();
    create_ui();
    create_connects();
}

Rwidget::~Rwidget(){
}

void Rwidget::init(){
//    m_datalist << new DataObject("Bill Smith", "red", "555 3264")<<new DataObject("John Brown", "green", "555 8426")
//                       <<new DataObject("Sam Wise", "blue", "555 0473");
    m_listmodel = new AbstractListModel();
    for(int i=0; i<50; ++i){
        m_listmodel->addlist(AbstractList("一楼大厅A区清扫", "2019-12-30", "推尘模式", "45m²", "1时30分"));
        m_listmodel->addlist(AbstractList("一楼大厅B区清扫", "2020-12-01", "ECO洗地模式", "105m²", "10时45分"));
    }
}

void Rwidget::create_ui(){
    m_wd = new QWidget(this);
    m_wd->resize(1280, 800);
    m_wd->setStyleSheet("background:#FF101b2b");

    m_list = new QQuickWidget(this);
    m_list->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_list->setClearColor(QColor(Qt::transparent));
    m_list->rootContext()->setContextProperty("errorModel", {});
    m_list->rootContext()->setContextProperty("errorMsg", this);
    m_list->setSource(QUrl("qrc:/errorlist.qml"));
    m_list->move(154, 200);
    m_list->hide();
    m_list->raise();

    m_btn = new QPushButton(m_wd);
    m_btn->resize(30, 30);
    m_btn->move(100, 100);
    m_btn->setText("ShowList");
    //slot_show_list();
}

void Rwidget::create_connects(){
    connect(m_btn, SIGNAL(clicked()), this, SLOT(slot_show_list()));
}

void Rwidget::closeErrorMsg(){
    m_list->close();
}

void Rwidget::relieve(uint index){
    m_strlist.removeAt(index);
    set_list_context();
}

void Rwidget::slot_show_list(){
    if (m_list->isVisible()){
        m_list->hide();
    }
    else{
        set_list_context();
        m_list->show();
    }
}

void Rwidget::set_list_context(){
    m_list->rootContext()->setContextProperty("errorModel", {});
    //m_list->rootContext()->setContextProperty("errorModel" ,QVariant::fromValue(m_datalist));
    m_list->rootContext()->setContextProperty("errorModel", m_listmodel);
    qDebug() << m_listmodel->rowCount();
}
