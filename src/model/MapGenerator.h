/* 
 * File:   MapGenerator.h
 * Author: Keo
 *
 * Created on 1. listopad 2013, 13:42
 */

#ifndef MAPGENERATOR_H
#define	MAPGENERATOR_H

#include <string>

#include "../observer/IEventMessagingSystem.h"
#include "../noise/MapNoise.h"
#include "Chunk.h"
#include "Map.h"

class MapGenerator : IEventMessagingSystem
{
public:
    MapGenerator(std::string seed);
    
    Map* generateMap          (sf::Vector3i position);
    Chunk* generateChunk        (sf::Vector3i postition);
    
    /**
     * Connect chunk to his neightbours
     * Will not check for edges, please use it only for guts
     * @param Map
     * @param Position of chunk in Map.grid
     */
    void connectChunk(Map*, sf::Vector3i);
private:
    
    MapNoise _mn;
    
    const double _noiseScale = 256;
    const std::string _seed;
};

#endif	/* MAPGENERATOR_H */

