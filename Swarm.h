#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"
#include <iostream>

namespace particles {

class Swarm {
   private:
    int nParticles;
    Particle* m_pParticles;
    int lastTime;

   public:
    Swarm();
    Swarm(int nParticles, double curl);
    ~Swarm();
    const Particle* const getParticles();
    void update(int elapsed);
    void updateReverse(int elapsed);
    int getNParticles();
};
}  // namespace particles
#endif  // SWARM_H_