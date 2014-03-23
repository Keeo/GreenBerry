/* 
 * File:   Particle.h
 * Author: Keo
 *
 * Created on 22. březen 2014, 19:38
 */

#ifndef PARTICLE_H
#define	PARTICLE_H

#include "WeatherChunk.h"
#include <SFML/System.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/norm.hpp>

class Particle
{
public:
    Particle();
    Particle(const Particle& orig);
    virtual ~Particle();
    
    bool operator<(const Particle& that);
    
    float cameraDistance;
    glm::vec3 position;
    glm::vec3 speed;
};

#endif	/* PARTICLE_H */

