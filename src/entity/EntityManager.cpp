/* 
 * File:   EntityManager.cpp
 * Author: Keo
 * 
 * Created on 7. duben 2014, 19:48
 */

#include "EntityManager.h"

EntityManager::EntityManager()
{
    bool ret = shader_.loadFromFile("D:/_school/s5/BP/GreenBerry/src/shaders/model/vertex.shader", "D:/_school/s5/BP/GreenBerry/src/shaders/model/fragment.shader");
    assert(ret);
}

EntityManager::EntityManager(const EntityManager& orig)
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::draw()
{
    shader_.bind();
    Post(Events::eveCameraDrawWorld, NULL, 0);
    std::for_each(entities_.begin(), entities_.end(), std::mem_fun(&Entity::draw));
}

void EntityManager::update(const GameTime& time)
{
    std::for_each(entities_.begin(), entities_.end(), std::bind2nd(std::mem_fun(&Entity::update), time));
}

void EntityManager::initialize()
{
    entities_.assign(1, new Entity());
}
