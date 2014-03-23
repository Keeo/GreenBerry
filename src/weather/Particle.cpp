/* 
 * File:   Particle.cpp
 * Author: Keo
 * 
 * Created on 22. březen 2014, 19:38
 */

#include "Particle.h"

Particle::Particle() : speed(0.1, 1.0, 0.1)
{
}

Particle::Particle(const Particle& orig)
{
}

Particle::~Particle()
{
}

bool Particle::operator<(const Particle& that)
{
    return this->cameraDistance > that.cameraDistance;
}