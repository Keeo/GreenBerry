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
#include "MapNoise.h"
#include "Chunk.h"

class MapGenerator : IEventMessagingSystem
{
public:
    MapGenerator(std::string seed);

    Chunk generateChunk(sf::Vector3i postition);
private:
    
    MapNoise _mn;
    
    const double _noiseScale = 256;
    const std::string _seed;
};

#endif	/* MAPGENERATOR_H */

