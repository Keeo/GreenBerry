/* 
 * File:   MapGenerator.cpp
 * Author: Keo
 * 
 * Created on 1. listopad 2013, 13:42
 */

#include "MapGenerator.h"


MapGenerator::MapGenerator(std::string seed) : _seed(seed)
{
}

Chunk* MapGenerator::generateChunk(sf::Vector3i position)
{
    Chunk* chunk = new Chunk(position);
    int* field = _mn.getHeightField(position.x, position.y);
    
    for (int i=0; i<32; ++i) //x
        for (int j=0; j<32; ++j) //z
            for(int k=0; k<32; ++k) //y
            {
                Block b = k<field[i + j*32] ? Block::GRASS : Block::AIR;
                sf::Vector3i p = sf::Vector3i(i,k,j);
                chunk->placeBlock(p, b);
            }
    
    return chunk;
}

Map* MapGenerator::generateMap(sf::Vector3i position)
{
    Map* map = new Map;
    
    for (int i=0; i!=9; ++i)
        for (int j=0; j!=9; ++j)
            for (int k=0; k!=9; ++k)
            {
                sf::Vector3i p = position + sf::Vector3i(i, j, k) - sf::Vector3i(-4, -4, -4);
                map->grid[i][j][k] = generateChunk(p);
            }

    for (int i=1; i!=8; ++i)
        for (int j=1; j!=8; ++j)
            for (int k=1; k!=8; ++k)
                connectChunk(map, sf::Vector3i(i, j, k));
    
    return map;
}

void MapGenerator::connectChunk(Map* map, sf::Vector3i pos)
{
    const int x = pos.x;
    const int y = pos.y;
    const int z = pos.z;

    Chunk* chunk = map->grid[x][y][z];
    
    chunk->u = map->grid[x][y+1][z];
    chunk->d = map->grid[x][y-1][z];
    
    chunk->n = map->grid[x+1][y][z];
    chunk->w = map->grid[x-1][y][z];
    
    chunk->e = map->grid[x][y][z+1];
    chunk->s = map->grid[x][y][z-1];
}