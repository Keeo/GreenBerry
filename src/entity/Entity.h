/* 
 * File:   Entity.h
 * Author: Keo
 *
 * Created on 7. duben 2014, 19:48
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "glm/ext.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "../abstract/ADrawable.h"
#include "../observer/IEventMessagingSystem.h"
#include "../observer/EventMessagingSystem.h"
#include "../util/Helper.h"
#include "../util/Log.h"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

class Entity {
public:
    Entity(std::string);
    Entity(const Entity& orig);
    virtual ~Entity();
private:
    

};

#endif	/* ENTITY_H */

