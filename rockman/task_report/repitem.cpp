#include "repitem.h"
#include <string>
#include <QLabel>
#include <QPushButton>

#define DEBUG 1

struct Repitemtext{
    std::string place;
    std::string date;
    std::string model;
    std::string area;
    std::string duration;
};

Repitem::Repitem(QWidget *parent) : Repitembase(parent) {
    init();
    create_ui();
    create_connections();
}
//Repitem::Repitem(){
//    init();
//    create_ui();
//    create_connections();
//}

Repitem::~Repitem(){
    if (m_text)
        delete m_text;
}

void Repitem::init(){
    m_text = new Repitemtext;
    set_text(nullptr);
}

void Repitem::set_text(Repitemtext *){
//    if (!rhs)
//        return;
//    m_text->place = rhs->place;
//    m_text->date = rhs->date;
//    m_text->model = rhs->model;
//    m_text->area = rhs->area;
//    m_text->duration = rhs->duration;

    m_text->place = "aaa";
    m_text->date = "aaa";
    m_text->model = "aaa";
    m_text->area = "aaa";
    m_text->duration = "aaa";
}

void Repitem::create_ui(){
    m_wd = new QWidget(this);
    m_wd->resize(486.3*2, 61.2*2);

    QFont place_ft("黑体", 25);
    m_place = new QLabel(m_wd);
    m_place->setText(m_text->place.c_str());
    m_place->setFont(place_ft);
    //m_place->adjustSize();
    m_place->move(26*2, 20*2);

    QFont most_ft("黑体", 20);
    m_date = new QLabel(m_wd);
    m_date->setText(m_text->date.c_str());
    m_date->setFont(most_ft);
    m_date->move(26*2, 40*2);

    m_model = new QLabel(m_wd);
    m_model->setText(m_text->model.c_str());
    m_model->setFont(most_ft);
    m_model->move(170*2, 26*2);

    m_area = new QLabel(m_wd);
    m_area->setText(m_text->area.c_str());
    m_area->setFont(most_ft);
    m_area->move(242*2, 26*2);

    m_duration = new QLabel(m_wd);
    m_duration->setText(m_text->duration.c_str());
    m_duration->setFont(most_ft);
    m_duration->move(296*2, 26*2);

    m_detail_btn = new QPushButton(m_wd);
    m_detail_btn->resize(47.5*2, 20.5*2);
    m_detail_btn->setText("详情");
    m_detail_btn->move(418*2, 20*2);
}

void Repitem::create_connections(){

}
