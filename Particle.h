#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <stdlib.h>     // rand()
#include <math.h>       // Pi constant
#include "Screen.h"     // Updating the particle

namespace particles {

class Particle {
   private:
    double m_curl;
    double m_speed;
    double m_direction;
    double m_x;
    double m_y;
    double m_xspeed;
    double m_yspeed;

   public:
    //Constructor and destructor
    Particle();
    ~Particle();

    //Getters
    double getCurl();
    double getSpeed();
    double getDirection();
    double getX();
    double getY();
    double getXSpeed();
    double getYSpeed();

    //Setters
    void setCurl(double new_m_curl);
    void setSpeed(double new_m_speed);
    void setDirection(double new_m_direction);
    void setX(double new_m_x);
    void setY(double new_m_y);
    void setXSpeed(double new_m_xspeed);
    void setYSpeed(double new_m_yspeed);

    //Updating particle position
    void update(int interval);
    void updateReverse(int interval);

   private:
    //Constructor helper
    void init();
};

}  // namespace particles
#endif  // PARTICLE_H_
