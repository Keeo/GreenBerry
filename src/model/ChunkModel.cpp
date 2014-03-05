/* 
 * File:   MapModel.cpp
 * Author: Keo
 * 
 * Created on 26. říjen 2013, 21:11
 */

#include "ChunkModel.h"

ChunkModel::ChunkModel(sf::Vector3i position) : _offset(position), _location("save/")
{
    EventMessagingSystem::getInstance().Register(Events::eveLoadNewChunk, this, (Callback) & ChunkModel::loadNewChunk);
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

Chunk* ChunkModel::loadNewChunk(void* pData)
{
    void** data = (void**)pData;
    sf::Vector3i& position = *(sf::Vector3i*)((data)[0]);
    
    Chunk* chunk = new Chunk(position);
    data[1] = (void*)chunk;
    Helper::print(position);    
    
    int* field = _mn.getHeightField(position.x, position.z);

    for (int i = 0; i < 32; ++i) {//x
        for (int j = 0; j < 32; ++j) {//z
            for (int k = 0; k < 32; ++k) { //y
                Block b = k + position.y * SIZE < field[i + j * 32] ? Block::GRASS : Block::AIR;
                sf::Vector3i p = sf::Vector3i(i, k, j);
                chunk->placeBlock(p, b);
            }
        }
    }
    
    return chunk;
}