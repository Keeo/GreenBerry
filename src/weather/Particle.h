/* 
 * File:   Particle.h
 * Author: Keo
 *
 * Created on 22. březen 2014, 19:38
 */

#ifndef PARTICLE_H
#define	PARTICLE_H

#include <SFML/System.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/norm.hpp>
#include "../observer/IEventMessagingSystem.h"
#include "../model/Block.h"
#include "../control/GameTime.h"

class Particle : IEventMessagingSystem
{
public:
    Particle();
    Particle(const Particle& orig);
    virtual ~Particle();
    virtual void update(const GameTime& time, const glm::vec3& wind);
    
    bool operator<(const Particle& that);
    
    float cameraDistance;
    glm::vec3 position;
    glm::vec3 speed;

    void setPosition(glm::vec3 position);
private:
    static glm::vec3* cameraPosition_;
    static const int RANGE;
    
    int countdown_;
    const int REFRESH_RATE = 100;
    
};

#endif	/* PARTICLE_H */

