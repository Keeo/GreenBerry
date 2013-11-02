/* 
 * File:   Chunk.cpp
 * Author: Keo
 * 
 * Created on 26. říjen 2013, 21:12
 */
#include <stdlib.h>

#include "Chunk.h"

Chunk::Chunk(sf::Vector3i position) : _pos(position)
{
}

Chunk::Chunk(){}

Chunk::~Chunk()
{
}

Block& Chunk::getBlock(sf::Vector3i position)
{
    return _data[position.x][position.y][position.z];
}

void Chunk::dummyGenerate()
{
    for (int i=0; i<32; ++i )
        for (int j=0; j<32; ++j )
                for (int k=0; k<32; ++k )
                    _data[i][j][k] = j < 16 ? GRASS : AIR;
}

Block Chunk::placeBlock(sf::Vector3i position, Block replacement)
{
    Block& b = getBlock(position);
    Block ret = b;
    b = replacement;
    return ret;
}

const sf::Vector3i& Chunk::getPosition()
{
    return _pos;
}

std::string Chunk::getChunkName(sf::Vector3i& pos)
{
    std::stringstream ss;
    ss << pos.x;
    ss << '-';
    ss << pos.y;
    ss << '-';
    ss << pos.z;
    ss << ".chunk";
    return ss.str();
}