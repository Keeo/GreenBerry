/* 
 * File:   MapGenerator.cpp
 * Author: Keo
 * 
 * Created on 1. listopad 2013, 13:42
 */

#include "MapGenerator.h"
#include "Chunk.h"

MapGenerator::MapGenerator(std::string seed) : _seed(seed)
{
}

Chunk MapGenerator::generateChunk(sf::Vector3i position)
{
    Chunk chunk(position);
    int* field = _mn.getHeightField(position.x, position.y);
    
    for (int i=0; i<position.x; ++i)
        for (int j=0; i<position.y; ++j)
            for(int k=0; k<32; ++k)
            {
                Block b = k<field[i + j*32] ? Block::GRASS : Block::AIR;
                sf::Vector3i p = sf::Vector3i(i,k,j) + (position * 32);
                chunk.placeBlock(p, b);
            }
    
    return chunk;
}