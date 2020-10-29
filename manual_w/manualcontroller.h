#ifndef MANUALCONTROLLER_H
#define MANUALCONTROLLER_H

#include "manualros.h"
#include <QObject>
#include <QDebug>

class Manual;
class Manualros;
class WaitWidget;

class Manualcontroller : public QObject, public QtRosCb
{
    Q_OBJECT

public:
    explicit Manualcontroller(Manual *m);
    virtual ~Manualcontroller();
    void update_all_status(const roborock_app::RobotStatus::ConstPtr &robo_state) override{
        qDebug()<< "robo_state" << robo_state->brush_disc_stat;
        //m_robo_state = &robo_state;
        m_robo_status = *robo_state;
    }
    const roborock_app::RobotStatus& get_robo_state(){
        return m_robo_status;
    }
    void brush_slow();
    void brush_middle();
    void brush_fast();
    void water_pump_slow();
    void water_pump_middle();
    void water_pump_fast();
    void water_pump_stop();
    void scrub_slow();
    void scrub_middle();
    void scrub_fast();
    void scrub_stop();
    inline void walk_slow();
    inline void walk_middle();
    inline void walk_fast();
    inline void sound_play();

public slots:
    void walkfaword();
    void walkback();
    void brush_up();
    void brush_down();
    void scrub_up();
    void scrub_down();

private:
    Manual *m_manual;
    WaitWidget *m_wait;
    Manualros *m_ros;
    const roborock_app::RobotStatus::ConstPtr *m_robo_state;
    roborock_app::RobotStatus m_robo_status;

};

#endif // MANUALCONTROLLER_H
