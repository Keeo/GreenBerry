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
#include "Cube.h"
#include "../util/Helper.h"
#include "../util/Log.h"

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
    
    /**
     * 
     * @param Local position
     * @param AIR
     * @return 
     */
    Block placeBlock            (sf::Vector3i, Block AIR);
    
    /**
     * 
     * @param Global position
     * @param AIR
     * @return 
     */
    Block placeBlock            (glm::vec3, Block AIR);
    Block& getBlock             (const sf::Vector3i&);
    Block& getBlock             (const glm::vec3&);
    
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
    inline void buildCube(int, int, int);
    inline void buildCubeOnEdge(int, int, int);
    inline void buildSquare(float, float, float, Direction);
    
    static std::string getChunkName(sf::Vector3i&);
    
    /**
     * Get chunk's coords from global pos
     * @param 
     * @return 
     */
    static sf::Vector3i getChunkCoords(const sf::Vector3i pos) { return pos / SIZE; };
    virtual void draw();
private:
    inline void pushNormal(Direction);
    inline sf::Vector3i globToLoc(const glm::vec3&);
    
    sf::Vector3i pos_;
    
    Block data_[SIZE][SIZE][SIZE];

    bool fullAir_;
    Cube cube_;
    
    // BOOST SERIALIZE
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & pos_;
        ar & data_;
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

