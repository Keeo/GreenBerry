/* 
 * File:   MapModel.cpp
 * Author: Keo
 * 
 * Created on 26. říjen 2013, 21:11
 */

#include "ChunkModel.h"

ChunkModel::ChunkModel(sf::Vector3i position) : _offset(position), _location("save/")
{
    
}

Chunk* ChunkModel::loadChunk(sf::Vector3i position)
{
    std::ifstream ifs(getFullChunkPath(position), std::ios::binary);
    boost::archive::binary_iarchive ia(ifs);
    Chunk* c = new Chunk;
    ia >> *c;
    return c;
}

void ChunkModel::saveChunk(Chunk* c)
{
    std::ofstream ofs(getFullChunkPath(c->getPosition()), std::ios::binary);
    boost::archive::binary_oarchive oa(ofs);
    oa << *c;
    delete c;
}

std::string ChunkModel::getFullChunkPath(sf::Vector3i pos)
{
    sf::Vector3i v = pos + _offset;
    return _location + Chunk::getChunkName(v);
}