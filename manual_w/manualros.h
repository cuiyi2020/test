#ifndef MANUALROS_H
#define MANUALROS_H

#include "../qtros/qtnode.h"

class Manualcontroller;

class Manualros : virtual public QtNode
{

public:
    explicit Manualros(Manualcontroller *mcon);
    virtual ~Manualros();
    bool ros_walkfaword();
    bool ros_walkback();
    bool ros_set_brush_state(uint8_t brush_state);
    bool set_brush_up();
    bool set_brush_down();
    inline bool ros_set_brush_speed(uint8_t brush_speed);
    bool set_brush_slow();
    bool set_brush_middle();
    bool set_brush_fast();
    inline bool ros_set_waterpump_speed(uint8_t waterpump_speed);
    bool set_waterpump_slow();
    bool set_waterpump_middle();
    bool set_waterpump_fast();
    bool set_waterpump_stop();
    inline bool ros_set_watersuck_state(uint8_t scrub_state);
    bool set_watersuck_up();
    bool set_watersuck_down();
    inline bool ros_set_scrub_speed(uint8_t scrub_speed);
    bool set_scrub_slow();
    bool set_scrub_middle();
    bool set_scrub_fast();
    bool set_scrub_stop();
    inline void ros_set_walkspeed(float speed);
    inline void ros_soundplay();

private:
    ros::ServiceClient m_client;
    roborock_app::ManualConfig m_srv_data;
    Manualcontroller *m_mcon;

};

#endif // MANUALROS_H
