#include "Swarm.h"

namespace particles {

Swarm::Swarm() : lastUpdate(0), Particles(nParticles) {
}

Swarm::Swarm(int nParticles, double curl) : lastUpdate(0), Particles(nParticles) {
    for (std::vector<Particle>::iterator it = Particles.begin(); it != Particles.end(); it++) {
        it->setCurl(curl);
    }
}

Swarm::~Swarm() {
    std::vector<Particle>().swap(Particles);
}

void Swarm::update(int elapsed) {
    int interval = elapsed - lastUpdate;

    for (std::vector<Particle>::iterator it = this->getParticleVector().begin(); it != this->getParticleVector().end(); it++) {
        it->update(interval);
    }

    lastUpdate = elapsed;
}

void Swarm::updateReverse(int elapsed) {
    int interval = elapsed - lastUpdate;

    for (auto it : Particles) {
        it.updateReverse(interval);
    }

    lastUpdate = elapsed;
}

int Swarm::getNParticles() {
    return nParticles;
}

std::vector<Particle> &Swarm::getParticleVector() {
    return Particles;
}

}  // namespace particles