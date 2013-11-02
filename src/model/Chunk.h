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
#include "../observer/IEventMessagingSystem.h"
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <fstream>
#include <string>
#include <sstream>

enum Block : unsigned short
{
    AIR = 0,
    GRASS,
};

class Chunk : IEventMessagingSystem
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
    
    const sf::Vector3i& getPosition    ();
    
    static std::string getChunkName(sf::Vector3i&);
private:


    
    
    
    sf::Vector3i _pos;
    
    Block _data[32][32][32];

    
    
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
