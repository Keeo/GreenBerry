/* 
 * File:   RainParticle.h
 * Author: Keo
 *
 * Created on 22. březen 2014, 19:38
 */

#ifndef RAINPARTICLE_H
#define	RAINPARTICLE_H

#include "Particle.h"


class RainParticle : Particle
{
public:
    RainParticle();
    RainParticle(const RainParticle& orig);
    virtual ~RainParticle();
private:

};

#endif	/* RAINPARTICLE_H */

