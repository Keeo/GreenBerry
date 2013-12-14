/* 
 * File:   World.h
 * Author: Keo
 *
 * Created on 2. listopad 2013, 18:08
 */

#ifndef WORLD_H
#define	WORLD_H

#include "Map.h"

class World
{

public:
    World();
    
    void draw();
    
private:
    
    Map _map;
};

#endif	/* WORLD_H */

