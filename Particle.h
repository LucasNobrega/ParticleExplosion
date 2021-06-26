#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SDL2/SDL.h>
#include <stdlib.h>

namespace particles{

class Particle {
   public:
    double curl;
    double m_speed;
    double m_direction;
    double m_x;
    double m_y;
    double m_xspeed;
    double m_yspeed;

   public:
    Particle();
    ~Particle();
    void update(int interval);
    void updateReverse(int interval);

    private:
        void init();
};

}
#endif  // PARTICLE_H_
