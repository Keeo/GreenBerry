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
#include <iostream>
struct Map
{
    Map();
    
    typedef boost::multi_array<Chunk*, 3> array_type;
    typedef array_type::index index;
    array_type grid;
    
    Chunk* core;
    
};

#endif	/* MAP_H */

