#include "report.h"
#include "repitem.h"
#include <QHBoxLayout>

Report::Report(QWidget *parent) : QWidget(parent) {
    create_ui();
}

void Report::create_ui(){
//    m_wd = new QWidget(this);
//    m_wd->resize(972, 800);
//    m_wd->setStyleSheet("background:#FF101b2b");
    m_list = new QListWidget(this);
    m_list->resize(972, 800);
    add_list_items();
}

void Report::create_connections(){

}

void Report::add_list_items(){
    if(!m_list)
        return;
    Repitembase *item1 = new Repitem(this);
    Repitembase *item2 = new Repitem(this);
    Repitembase *item3 = new Repitem(this);
    Repitembase *item4 = new Repitem(this);
    m_list->addItem(item1);
    m_list->addItem(item2);
    m_list->addItem(item3);
    m_list->addItem(item4);
    //QHBoxLayout *layout = new QHBoxLayout(this);
    QStringList items = {"aaa", "bbb", "ccc"};
    m_list->addItems(items);
    //Repitembase *item = nullptr;
//    for(int i=0; i<3; i++){
//        Repitembase *item = new Repitem(m_wd);
//        m_list->addItem(item);
////        QListWidgetItem *it = new QListWidgetItem(m_list);
////        if (!item)
////            continue;
////        m_list->addItem(it);
////        it->setSizeHint(QSize(0,50));
////        m_list->setItemWidget(it, item);
//    }
}
