/* 
 * File:   Particle.cpp
 * Author: Keo
 * 
 * Created on 22. březen 2014, 19:38
 */

#include "Particle.h"

glm::vec3* Particle::cameraPosition_ = 0;
const int Particle::RANGE = 50;


Particle::Particle() : speed(0.1, -10.0, 0.1)
{
    countdown_ = rand() % REFRESH_RATE + 1;
    
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

void Particle::update(const sf::Time& gameTime, const glm::vec3& wind)
{
    position += (speed + wind) * gameTime.asSeconds();
    Block block;
    
    void *p[2];
    p[0] = &position;
    p[1] = &block;
    Post(Events::eveGetBlock, p, 0);
    if (block != Block::AIR) {
        position.y += RANGE * 2;
    }
    
    if (countdown_ < 0)
    {
        if (cameraPosition_ == 0) Post(Events::eveCameraGetPositionPointer, (void*)&cameraPosition_, 0);
        countdown_ = REFRESH_RATE;
        float distance = glm::distance(position, *cameraPosition_);
        if (distance > RANGE){
            if (abs(position.x - cameraPosition_->x) > RANGE) {
                position.x = rand() % RANGE * 2 - RANGE + cameraPosition_->x;
            }
            if (abs(position.y - cameraPosition_->y) > RANGE) {
                position.y = rand() % RANGE * 2 - RANGE + cameraPosition_->y;
            }
            if (abs(position.z - cameraPosition_->z) > RANGE) {
                position.z = rand() % RANGE * 2 - RANGE + cameraPosition_->z;
            }
        }
    }
    --countdown_;
}