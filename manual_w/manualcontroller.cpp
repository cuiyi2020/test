#include "manualcontroller.h"
#include "manual.h"
#include "manualros.h"
#include "map/waitwidget.h"
#include <QPushButton>

Manualcontroller::Manualcontroller(Manual *m) : m_manual(m)
{
    m_wait = new WaitWidget();
    m_ros = new Manualros(this);
    m_ros->observer_status(this);
}

Manualcontroller::~Manualcontroller(){
    if (m_ros){
        //m_ros->m_obs_state->erase(this);// If neccesarry.
        delete m_ros;
    }
    if (m_wait){
        delete m_wait;
    }
}

void Manualcontroller::walkfaword(){
    m_wait->start([&](){
        m_ros->ros_walkfaword();
    });
}

void Manualcontroller::walkback(){
    m_wait->start([&](){
        m_ros->ros_walkback();
    });
}

// ******************* 盘刷升降按钮 ***************

void Manualcontroller::brush_up() {
     m_wait->start([&](){
        m_ros->set_brush_up();
        QPushButton *up = m_manual->get_brushup_btn();
        up->setText(tr("已升起"));
        QPushButton *down = m_manual->get_brushdown_btn();
        down->setText(tr("放下"));
     });
}

void Manualcontroller::brush_down() {
     m_wait->start([&](){
        m_ros->set_brush_down();
        QPushButton *up = m_manual->get_brushup_btn();
        up->setText(tr("升起"));
        QPushButton *down = m_manual->get_brushdown_btn();
        down->setText(tr("已放下"));
     });
}

// ******************* 盘刷速度按钮 ****************

void Manualcontroller::brush_slow(){
    m_wait->start([&](){
        m_ros->set_brush_slow();
    });
}

void Manualcontroller::brush_middle(){
    m_wait->start([&](){
        m_ros->set_brush_middle();
    });
}

void Manualcontroller::brush_fast(){
    m_wait->start([&](){
        m_ros->set_brush_fast();
    });
}

//**************************  风机速度按钮 **************************

void Manualcontroller::water_pump_slow() {
    m_wait->start([&](){
        m_ros->set_waterpump_slow();
    });
}

void Manualcontroller::water_pump_middle() {
    m_wait->start([&](){
        m_ros->set_waterpump_middle();
    });
}

void Manualcontroller::water_pump_fast() {
    m_wait->start([&](){
        m_ros->set_waterpump_fast();
    });
}

void Manualcontroller::water_pump_stop(){
    m_wait->start([&](){
        m_ros->set_waterpump_stop();
    });
}

//******************* 吸水扒升降按钮 *************************

void Manualcontroller::scrub_up(){
    m_wait->start([&](){
       m_ros->set_watersuck_up();
    });
}

void Manualcontroller::scrub_down(){
    m_wait->start([&](){
       m_ros->set_watersuck_down();
    });
}

//*******************  吸水扒速度按钮 ****************************

void Manualcontroller::scrub_slow() {
    m_wait->start([&](){
        m_ros->set_scrub_slow();
    });
}

void Manualcontroller::scrub_middle() {
    m_wait->start([&](){
        m_ros->set_scrub_middle();
    });
}

void Manualcontroller::scrub_fast() {
    m_wait->start([&](){
        m_ros->set_scrub_fast();
    });
}

void Manualcontroller::scrub_stop(){
    m_wait->start([&](){
        m_ros->set_scrub_stop();
    });
}

//******************** 速度按钮 *****************************

void Manualcontroller::walk_slow(){
    m_ros->ros_set_walkspeed(0.5);
}

void Manualcontroller::walk_middle(){
    m_ros->ros_set_walkspeed(0.8);
}

void Manualcontroller::walk_fast(){
    m_ros->ros_set_walkspeed(1.2);

}

//********************* 声音按钮 ****************************

void Manualcontroller::sound_play(){
    m_ros->ros_soundplay();
}


