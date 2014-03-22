/* 
 * File:   Ddm.h
 * Author: Keo
 *
 * Created on 22. březen 2014, 14:00
 */

#ifndef DDM_H
#define	DDM_H

#include <stdlib.h>
#include <iostream>
#include <SFML/System.hpp>
#include "Log.h"
#include "Helper.h"
#include "../model/Cube.h"
#include "glm/ext.hpp"

class Ddm {
public:
    
    static sf::Vector3i* traverse(const glm::vec3& pos, const glm::vec3& dir, int length);
    
private:

};

#endif	/* DDM_H */

