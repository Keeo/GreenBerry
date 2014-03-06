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
#include "../observer/IEventMessagingSystem.h"
#include "../observer/EventMessagingSystem.h"
#include "glm/ext.hpp"
#include <SFML/System.hpp>
#include "../Helper.h"
#include "../model/ChunkModel.h"

class Map : IEventMessagingSystem
{
public:
    Map(sf::Vector3i position);
    
    void draw();
    
    /**
     * Finds pointer to chunk
     * @param pos Global coordinates
     * @return 
     */
    Chunk* getChunk(glm::vec3 pos);
    
    void moveMap(void* data);
    
    void moveCenter(sf::Vector3i dir);
    
    void deleteCube(void* data);
private:
    
    typedef boost::multi_array<Chunk*, 3> array_type;
    typedef array_type::index index;
    array_type grid;
    
    Chunk* core;
    sf::Vector3i _centerGrid;
    sf::Vector3i _centerGlob;
    
    Chunk* generateChunk(sf::Vector3i position);
    void connectChunk(sf::Vector3i pos);
    void _connectAll();
    
    MapNoise _mn;
};

#endif	/* MAP_H */