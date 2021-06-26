#include "Particle.h"
#include "Screen.h"
#include <math.h>


namespace particles {

Particle::Particle() : m_x(0), m_y(0) {
    init();
}

Particle::~Particle() {}

void Particle::init(){
    curl = 2;
    m_x = 0;
    m_y = 0;
    m_speed = 0.02 * rand() / RAND_MAX;
    m_speed *= m_speed;
    m_direction = ((2 * M_PI * rand()) / RAND_MAX);
}

void Particle::update(int interval) {

    m_direction += interval*0.0001*curl;
    m_xspeed = m_speed * cos(m_direction);
    m_yspeed = m_speed * sin(m_direction);
    
    m_x += m_xspeed*interval;
    m_y += m_yspeed*interval;

    if(m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
        init();

    }

    if(rand() < RAND_MAX/100){
        init();
    }

    /*
    if (m_x < -1.0 || m_x >= 1.0) {
        m_xspeed = -m_xspeed;
    }
    if (m_y < -1.0 || m_y >= 1.0) {
        m_yspeed = -m_yspeed;
    }
    */
}


void Particle::updateReverse(int interval) {
    
    m_x -= m_xspeed*interval;
    m_y -= m_yspeed*interval;

    /*
    if (m_x < -1.0 || m_x >= 1.0) {
        m_xspeed = -m_xspeed;
    }
    if (m_y < -1.0 || m_y >= 1.0) {
        m_yspeed = -m_yspeed;
    }
    */
}


}  // namespace particles