#ifndef RTIMER_H
#define RTIMER_H

#include <algorithm>
#include <vector>
#include <QTimer>
#include <QDebug>
#include <string>

class Rtimer : public QTimer
{
    Q_OBJECT

public:
    Rtimer(int msec = 5000, bool singleshot = true,  QObject *parent = Q_NULLPTR);
    ~Rtimer();

    template<class T>
    void begin(T f){
        rebind(f);
        //qDebug() << "Start keeping time..";
        this->start(m_msec);
    }

    template<class T>
    void begin(int msec, T f){
        rebind(f);
        this->start(msec);
    }

    template<class T>
    void bind_conn(T f){
        auto cnn = connect(this, &QTimer::timeout, f);
        m_cnns.push_back(cnn);
    }

    void begin(){
        this->start(m_msec);
    }

    void begin_timer(int msec){
        this->start(msec);
    }

private:
    template<class T>
    void rebind(T f){
        clear_conns();
        auto cnn = connect(this, &QTimer::timeout, f);
        m_cnns.push_back(cnn);
    }

    void clear_conns(){
        std::for_each(m_cnns.begin(), m_cnns.end(), [&](QMetaObject::Connection& cnn){
            disconnect(cnn);
        });
        m_cnns.clear();
    }

    void rtimeout();

private:
    std::vector<QMetaObject::Connection> m_cnns;
    int m_msec;
};


#endif // RTIMER_H
