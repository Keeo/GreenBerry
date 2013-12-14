/* 
 * File:   Map.h
 * Author: Keo
 *
 * Created on 2. listopad 2013, 19:33
 */

#ifndef MAP_H
#define	MAP_H

#include "boost/multi_array.hpp"
#include "Chunk.h"
#include "../noise/MapNoise.h"
#include <iostream>
class Map
{
public:
    Map(sf::Vector3i position);
    
    void draw();
    
    
private:
    
    typedef boost::multi_array<Chunk*, 3> array_type;
    typedef array_type::index index;
    array_type grid;
    
    Chunk* core;
    
    Chunk* generateChunk(sf::Vector3i position);
    void connectChunk(sf::Vector3i pos);
    
    MapNoise _mn;
};

#endif	/* MAP_H */