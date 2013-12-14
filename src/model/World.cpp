/* 
 * File:   World.cpp
 * Author: Keo
 * 
 * Created on 2. listopad 2013, 18:08
 */

#include "World.h"

World::World() : _map(sf::Vector3i(0,0,0))
{
}

void World::draw()
{
    _map.draw();
}