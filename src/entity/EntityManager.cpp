/* 
 * File:   EntityManager.cpp
 * Author: Keo
 * 
 * Created on 7. duben 2014, 19:48
 */

#include "EntityManager.h"

EntityManager::EntityManager()
{
    
}

EntityManager::EntityManager(const EntityManager& orig)
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::initialize()
{
    bool ret = shader_.loadFromFile("D:/_school/s5/BP/GreenBerry/src/shaders/model/vertex.shader", "D:/_school/s5/BP/GreenBerry/src/shaders/model/fragment.shader");
    assert(ret);
    
    shader_.bind();
}
