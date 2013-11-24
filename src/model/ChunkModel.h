/* 
 * File:   MapModel.h
 * Author: Keo
 *
 * Created on 26. říjen 2013, 21:11
 */

#ifndef CHUNKMODEL_H
#define	CHUNKMODEL_H

#include "Chunk.h"

class ChunkModel : IEventMessagingSystem
{
public:
    ChunkModel(sf::Vector3i worldOffset);
    
    // loads chunk from disk and returns its pointer
    Chunk* loadChunk(sf::Vector3i pos);
    
    // saves chunk on disk and delete it
    void saveChunk(Chunk* chunk);
private:
    
    std::string getFullChunkPath(sf::Vector3i);
    
    const sf::Vector3i _offset;
    std::string _location;
    
};

#endif	/* CHUNKMODEL_H */

