#include "Swarm.h"

namespace particles {

Swarm::Swarm() : lastTime(0) {
    m_pParticles = new Particle[nParticles];
}

Swarm::Swarm(int nParticles, double curl) : lastTime(0), nParticles(nParticles) {
    m_pParticles = new Particle[nParticles];
       for (size_t i = 0; i < nParticles; i++) {
        m_pParticles[i].curl = curl;
    }
}

Swarm::~Swarm() {
    delete[] m_pParticles;
}

const Particle* const Swarm::getParticles() {
    return m_pParticles;
}

void Swarm::update(int elapsed) {
    int interval = elapsed - lastTime;

    for (size_t i = 0; i < this->getNParticles(); i++) {
        m_pParticles[i].update(interval);
    }

    lastTime = elapsed;
}

void Swarm::updateReverse(int elapsed) {
    int interval = elapsed - lastTime;

    for (size_t i = 0; i < this->getNParticles(); i++) {
        m_pParticles[i].updateReverse(interval);
    }

    lastTime = elapsed;
}

int Swarm::getNParticles() {
    return nParticles;
}

}  // namespace particles