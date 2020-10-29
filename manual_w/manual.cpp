#include "manual.h"
#include "manualcontroller.h"
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QLayout>
#include <QtQuickWidgets>

Manual::Manual(QWidget *parent) : QWidget(parent){
    m_mcon = new Manualcontroller(this);
    m_timer  = new QTimer(this);
    m_timer->start(1000);
    create_ui();
    create_connections();
}

void Manual::create_ui(){
    /*Unit test*/
    m_brush = new QLabel(tr("盘刷"));
    m_brushup_btn = new QPushButton(tr("升起"));
    m_brushdown_btn = new QPushButton(tr("放下"));
    QHBoxLayout *hlay1=new QHBoxLayout;
    hlay1->addWidget(m_brush);
    hlay1->addWidget(m_brushup_btn);
    hlay1->addWidget(m_brushdown_btn);
    QVBoxLayout *vlay=new QVBoxLayout;
    vlay->addLayout(hlay1);
    setLayout(vlay);
}

void Manual::create_connections(){
    //connect(this, SIGNAL(signal_faword()), m_mcon, SLOT(walkfaword()));
    //connect(this, SIGNAL(signal_back()), m_mcon, SLOT(walkback()));
    //connect(m_timer, &QTimer::timeout, m_mcon, &Manualcontroller::update_clean);
    //connect(m_timer, &QTimer::timeout, m_mcon, &Manualcontroller::update_drain);
    connect(m_brushup_btn, SIGNAL(clicked()), m_mcon, SLOT(brush_up()));
    connect(m_brushdown_btn, SIGNAL(clicked()), m_mcon, SLOT(brush_down()));
}
