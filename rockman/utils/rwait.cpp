#include "rwait.h"

QLabel *Rwait::m_wait = nullptr;

QMovie *Rwait::m_mov = nullptr;

std::mutex Rwait::m_mutex;

std::shared_ptr<Rtimer> Rwait::m_timer = nullptr;

Rwait::Rwait(int) : QWidget(nullptr){
    //m_timer = std::make_shared<Rtimer>();
    m_wait = new QLabel();
    m_wait->setWindowOpacity(0.8);
    m_mov=new QMovie(":/map_resource/wait.gif");
    m_wait->setMovie(m_mov);
    m_wait->resize(700, 700);
    //m_mov->start();
}

Rwait::~Rwait(){
    m_mov->stop();
}

Rwait *Rwait::get_instance(int msec){
    static Rwait rwait(msec);
    return &rwait;
}
