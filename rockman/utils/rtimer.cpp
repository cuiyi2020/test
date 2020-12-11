#include "rtimer.h"

Rtimer::Rtimer(int msec, bool singleshot, QObject *parent)
    : QTimer(parent), m_msec(msec){
    this->setSingleShot(singleshot);
    this->setTimerType(Qt::VeryCoarseTimer);
}

Rtimer::~Rtimer(){

}

void Rtimer::rtimeout(){
    if (this->isActive())
    {
        this->stop();
    }
}

