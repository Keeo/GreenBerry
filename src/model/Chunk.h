/* 
 * File:   Chunk.h
 * Author: Keo
 *
 * Created on 26. říjen 2013, 21:12
 */

#ifndef CHUNK_H
#define	CHUNK_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../abstract/ADrawable.h"
#include "../observer/IEventMessagingSystem.h"
#include "Block.h"
#include "Direction.h"

#define SIZE 32

class Chunk : IEventMessagingSystem, public ADrawable
{
    
public:

    /**
     * 
     * @param Position in chunk scale
     */
    Chunk                       (sf::Vector3i);
    Chunk                       ();
    virtual ~Chunk              ();
    
    // place block on position, returns old one
    Block placeBlock            (sf::Vector3i, Block AIR);
    inline Block& getBlock      (sf::Vector3i);
    
    // Populate chunk with air and grass blocks
    void dummyGenerate          ();
    void randGenerate           ();
    
    const sf::Vector3i& getPosition();
    
    // surounding chunks
    Chunk* u = 0;
    Chunk* d = 0;
    Chunk* n = 0;
    Chunk* w = 0;
    Chunk* e = 0;
    Chunk* s = 0;
    
    void buildMesh();
    void buildCube(int, int, int);
    void buildSquare(float, float, float, Direction);
    
    static std::string getChunkName(sf::Vector3i&);
private:


    sf::Vector3i _pos;
    
    Block _data[SIZE][SIZE][SIZE];

    
    
    // BOOST SERIALIZE
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & _pos;
        ar & _data;
    }
};

namespace boost {
    namespace serialization {
        template<class Archive>
        void serialize(Archive & ar, sf::Vector3i & g, const unsigned int version)
        {
            ar & g.x;
            ar & g.y;
            ar & g.z;
        }
    } 
}

#endif	/* CHUNK_H */

