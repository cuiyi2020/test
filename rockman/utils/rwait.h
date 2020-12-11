#ifndef RWAIT_H
#define RWAIT_H

#include "rtimer.h"
#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QApplication>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <memory>
#include <QDebug>

#define CLOSELF 10*1000

class Rwait : public QWidget{
    Q_OBJECT
private:
    Rwait(int msec = CLOSELF);
    ~Rwait();

public:
    static Rwait* get_instance(int msec = CLOSELF);

    template<class F>
    void start(F f){
        m_wait->showFullScreen();
        m_mov->start();
        volatile bool ok = false;
        std::thread t(f);
        std::thread t2([&](){
                t.join();
                ok = true;
        });
        while(true){
            if(ok)
                break;
            QApplication::processEvents();
            usleep(50*1000);
        }
        t2.join();
        m_wait->hide();
    }

    template<class F>
    void start_block(F f, int sec=5){

    }

    template<class F>
    void start_with_timer(F f){
        m_timer->begin([&](){
            qDebug() << "rwait timeout.";
            m_mov->stop();
            m_wait->hide();
        });
        m_mov->start();
        m_wait->showFullScreen();
        m_wait->show();
        volatile bool ok = false;
        std::thread t(f);
        std::thread t2([&](){
                t.join();

                ok = true;
        });
        while(true){
            if(ok)
                break;
            QApplication::processEvents();
            usleep(50*1000);
        }
        t2.join();
        m_mov->stop();
        m_wait->hide();
    }

private:
    static QLabel *m_wait;
    static QMovie *m_mov;
    static std::shared_ptr<Rtimer> m_timer;
    static std::mutex m_mutex;
};


#endif // RWAIT_H
