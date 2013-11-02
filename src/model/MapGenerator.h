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

class MapGenerator : IEventMessagingSystem
{
public:
    MapGenerator(std::string seed);
private:
    
    const std::string _seed;
};

#endif	/* MAPGENERATOR_H */

