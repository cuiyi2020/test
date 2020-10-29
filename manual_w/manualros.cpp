#include "manualros.h"
#include "manualcontroller.h"
#include <QDebug>

Manualros::Manualros(Manualcontroller *mcon) : m_mcon(mcon),
                                    m_client(n->serviceClient<roborock_app::ManualConfig>(SRV_MANUAL_CONFIG)){
}

Manualros::~Manualros(){

}

bool Manualros::ros_walkfaword(){
    m_srv_data.request.configType = roborock_app::ConfigType::WALK_DIRECTION;
    m_srv_data.request.intValue = roborock_app::Direction::FORWARD;
    bool ret = m_client.call(m_srv_data);
    while (true) {
        uint8_t state = m_mcon->get_robo_state().walk_direction;
        if(state == roborock_app::Direction::FORWARD)
            break;
    }
    return ret;
}

bool Manualros::ros_walkback(){
    m_srv_data.request.configType = roborock_app::ConfigType::WALK_DIRECTION;
    m_srv_data.request.intValue = roborock_app::Direction::BACKWARD;
    bool ret = m_client.call(m_srv_data);
    while (true) {
        uint8_t state = m_mcon->get_robo_state().walk_direction;
        if(state == roborock_app::Direction::BACKWARD)
            break;
    }
    return ret;
}
////
bool Manualros::ros_set_brush_state(uint8_t brush_state){
    m_srv_data.request.configType = roborock_app::ConfigType::BRUSH_DISC_STAT;
    m_srv_data.request.intValue = brush_state;
    bool ret = m_client.call(m_srv_data);
    return ret;
}

bool Manualros::set_brush_up(){
    bool ret = ros_set_brush_state(roborock_app::UpDown::UP);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().brush_disc_stat;
          if(state == roborock_app::UpDown::UP)
                break;
     }
    return ret;
}

bool Manualros::set_brush_down(){
    bool ret = ros_set_brush_state(roborock_app::UpDown::DOWN);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().brush_disc_stat;
          if(state == roborock_app::UpDown::DOWN)
                break;
     }
    return ret;
}
///
bool Manualros::ros_set_brush_speed(uint8_t brush_speed){
    m_srv_data.request.configType = roborock_app::ConfigType::BRUSH_DISC_SPEED;
    m_srv_data.request.intValue = brush_speed;
    bool ret = m_client.call(m_srv_data);
    return ret;
}

bool Manualros::set_brush_slow(){
    bool ret = ros_set_brush_speed(roborock_app::Speed::SLOW);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().brush_disc_stat;
          if(state == roborock_app::Speed::SLOW)
                break;
     }
    return ret;
}

bool Manualros::set_brush_middle(){
    bool ret = ros_set_brush_speed(roborock_app::Speed::MIDDLE);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().brush_disc_stat;
          if(state == roborock_app::Speed::MIDDLE)
                break;
     }
    return ret;
}

bool Manualros::set_brush_fast(){
    bool ret = ros_set_brush_speed(roborock_app::Speed::FAST);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().brush_disc_stat;
          if(state == roborock_app::Speed::FAST)
                break;
     }
    return ret;
}
////
bool Manualros::ros_set_waterpump_speed(uint8_t waterpump_speed){
    m_srv_data.request.configType = roborock_app::ConfigType::WATER_PUMP_SPEED;
    m_srv_data.request.intValue = waterpump_speed;
    bool ret = m_client.call(m_srv_data);
    return ret;
}

bool Manualros::set_waterpump_slow(){
    bool ret = ros_set_waterpump_speed(roborock_app::Speed::SLOW);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_pump_speed;
          if(state == roborock_app::Speed::SLOW)
                break;
     }
    return ret;
}

bool Manualros::set_waterpump_middle(){
    bool ret = ros_set_waterpump_speed(roborock_app::Speed::MIDDLE);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_pump_speed;
          if(state == roborock_app::Speed::MIDDLE)
                break;
     }
    return ret;
}

bool Manualros::set_waterpump_fast(){
    bool ret = ros_set_waterpump_speed(roborock_app::Speed::FAST);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_pump_speed;
          if(state == roborock_app::Speed::FAST)
                break;
     }
    return ret;
}

bool Manualros::set_waterpump_stop(){
    bool ret = ros_set_waterpump_speed(roborock_app::Speed::STOP);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_pump_speed;
          if(state == roborock_app::Speed::STOP)
                break;
     }
    return ret;
}
////
bool Manualros::ros_set_watersuck_state(uint8_t scrub_state){
    m_srv_data.request.configType = roborock_app::ConfigType::WATER_SUCK_STAT;
    m_srv_data.request.intValue = scrub_state;
    bool ret = m_client.call(m_srv_data);
    return ret;
}

bool Manualros::set_watersuck_up(){
    bool ret = ros_set_watersuck_state(roborock_app::UpDown::UP);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_suck_stat;
          if(state == roborock_app::UpDown::UP)
                break;
     }
    return ret;
}

bool Manualros::set_watersuck_down(){
    bool ret = ros_set_watersuck_state(roborock_app::UpDown::DOWN);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_suck_stat;
          if(state == roborock_app::UpDown::DOWN)
                break;
     }
    return ret;
}
///
bool Manualros::ros_set_scrub_speed(uint8_t scrub_speed){
    m_srv_data.request.configType = roborock_app::ConfigType::WATER_SUCK_SPEED;
    m_srv_data.request.intValue = scrub_speed;
    bool ret = m_client.call(m_srv_data);
    return ret;
}

bool Manualros::set_scrub_slow(){
    bool ret = ros_set_scrub_speed(roborock_app::Speed::SLOW);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_suck_speed;
          if(state == roborock_app::Speed::SLOW)
                break;
     }
    return ret;
}

bool Manualros::set_scrub_middle(){
    bool ret = ros_set_scrub_speed(roborock_app::Speed::MIDDLE);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_suck_speed;
          if(state == roborock_app::Speed::MIDDLE)
                break;
     }
    return ret;
}

bool Manualros::set_scrub_fast(){
    bool ret = ros_set_scrub_speed(roborock_app::Speed::FAST);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_suck_speed;
          if(state == roborock_app::Speed::FAST)
                break;
     }
    return ret;
}

bool Manualros::set_scrub_stop(){
    bool ret = ros_set_scrub_speed(roborock_app::Speed::STOP);
    while (true) {
          uint8_t state = m_mcon->get_robo_state().water_suck_speed;
          if(state == roborock_app::Speed::STOP)
                break;
     }
    return ret;
}

////
void Manualros::ros_set_walkspeed(float speed){
    m_srv_data.request.configType = roborock_app::ConfigType::WALK_SPEED;
    m_srv_data.request.floatValue = speed;
    m_client.call(m_srv_data);
}

void Manualros::ros_soundplay(){
    m_srv_data.request.configType = roborock_app::ConfigType::SOUND_PLAY;
    m_client.call(m_srv_data);
}


























