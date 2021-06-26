#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"
#include <vector>

namespace particles {

class Swarm {
   private:
    int nParticles;
    int lastUpdate;
    std::vector<Particle> Particles;

   public:
    //Constructors and Destructors
    Swarm();
    Swarm(int nParticles, double curl);
    ~Swarm();

    //Getters and Setters
    int getNParticles();
    std::vector<Particle>& getParticleVector();

    //Update the Swarm
    void update(int elapsed);
    void updateReverse(int elapsed);
};
}  // namespace particles
#endif  // SWARM_H_