/* 
 * File:   Cube.h
 * Author: Keo
 *
 * Created on 9. březen 2014, 0:37
 */

#ifndef CUBE_H
#define	CUBE_H

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
#include "Direction.h"

class Cube : public ADrawable
{
public:
    Cube(sf::Vector3i position, sf::Vector3i vertexes[]);
    Cube(sf::Vector3i position);
    Cube();
    virtual ~Cube();
private:
    void buildCube(sf::Vector3i[]);
    void pushNormal(Direction d);
};

#endif	/* CUBE_H */

