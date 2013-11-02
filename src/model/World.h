/* 
 * File:   World.h
 * Author: Keo
 *
 * Created on 2. listopad 2013, 18:08
 */

#ifndef WORLD_H
#define	WORLD_H

#include "MapGenerator.h"
#include "Map.h"

class World
{
public:
    World();
private:
    
    
    
    MapGenerator _mg;
    
    Map* _map;
};

#endif	/* WORLD_H */

