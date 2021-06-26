#include "Particle.h"

namespace particles {

Particle::Particle() : m_x(0), m_y(0) {
    init();
}

Particle::~Particle() {}

void Particle::init() {
    setCurl(m_curl);
    setX(0);
    setY(0);
    setSpeed(0.02 * rand() / RAND_MAX);  // Create Speed Coefficient
    setSpeed(getSpeed() * getSpeed());
    setDirection((2.0 * M_PI * rand()) / RAND_MAX);
}

void Particle::update(int interval) {
    double curl = getCurl();
    double direction = getDirection();
    double x = getX();
    double y = getY();
    double xSpeed = getXSpeed();
    double ySpeed = getYSpeed();
    double Speed = 0.0004 * rand() / RAND_MAX;

    setDirection(direction + (interval * 0.0001 * curl));
    setSpeed(Speed * Speed);
    setXSpeed(Speed * cos(direction));
    setYSpeed(Speed * sin(direction));
    setX(x + (xSpeed * interval));
    setY(y + (ySpeed * interval));

    if (x < -1 || x > 1 || y < -1 || y > 1) {
        init();
    }

    if (rand() < RAND_MAX / 100) {
        init();
    }

    /* Bounce on the wall:
    if (x < -1.0 || x >= 1.0) {
        if (x < -1.0) {
            setDirection(direction - (M_PI / 2));
        } else {
            setDirection(direction + (M_PI / 2));
        }
    }
    if (m_y < -1.0 || m_y >= 1.0) {
        if (y < -1.0) {
            setDirection(direction - (M_PI / 2));
        } else {
            setDirection(direction + (M_PI / 2));
        }
    }
    */
}

void Particle::updateReverse(int interval) {
    double curl = getCurl();
    double direction = getDirection();
    double x = getX();
    double y = getY();
    double xSpeed = getXSpeed();
    double ySpeed = getYSpeed();
    double Speed = 0.0004 * rand() / RAND_MAX;

    setDirection(direction + (interval * 0.0001 * curl));
    setSpeed(Speed * Speed);
    setXSpeed(Speed * cos(direction));
    setYSpeed(Speed * sin(direction));
    setX(x - (xSpeed * interval));
    setY(y - (ySpeed * interval));

    if (x < -1 || x > 1 || y < -1 || y > 1) {
        init();
    }

    if (rand() < RAND_MAX / 100) {
        init();
    }

}

double Particle::getCurl() {
    return m_curl;
}

double Particle::getSpeed() {
    return m_speed;
}

double Particle::getDirection() {
    return m_direction;
}

double Particle::getX() {
    return m_x;
}

double Particle::getY() {
    return m_y;
}

double Particle::getXSpeed() {
    return m_xspeed;
}

double Particle::getYSpeed() {
    return m_yspeed;
}

void Particle::setCurl(double new_m_curl) {
    m_curl = new_m_curl;
}

void Particle::setSpeed(double new_m_speed) {
    m_speed = new_m_speed;
}

void Particle::setDirection(double new_m_direction) {
    m_direction = new_m_direction;
}

void Particle::setX(double new_m_x) {
    m_x = new_m_x;
}

void Particle::setY(double new_m_y) {
    m_y = new_m_y;
}

void Particle::setXSpeed(double new_m_xspeed) {
    m_xspeed = new_m_xspeed;
}

void Particle::setYSpeed(double new_m_yspeed) {
    m_yspeed = new_m_yspeed;
}

}  // namespace particles