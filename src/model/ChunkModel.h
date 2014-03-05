/* 
 * File:   MapModel.h
 * Author: Keo
 *
 * Created on 26. říjen 2013, 21:11
 */

#ifndef CHUNKMODEL_H
#define	CHUNKMODEL_H

#include "Chunk.h"
#include "../noise/MapNoise.h"
#include "../observer/EventMessagingSystem.h"
#include "../Helper.h"

class ChunkModel : IEventMessagingSystem
{
public:
    ChunkModel(sf::Vector3i worldOffset);
    
    // loads chunk from disk and returns its pointer
    Chunk* loadChunk(sf::Vector3i pos);
    
    // saves chunk on disk and delete it
    void saveChunk(Chunk* chunk);
    
    // create and return new chunk in second argument and with return value
    // Input values [sf::Vector3i, Chunk*]
    Chunk* loadNewChunk(void * pData);
private:
    
    std::string getFullChunkPath(sf::Vector3i);
    
    const sf::Vector3i _offset;
    std::string _location;
    MapNoise _mn;
};

#endif	/* CHUNKMODEL_H */

