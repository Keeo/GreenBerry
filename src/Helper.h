/* 
 * File:   Helper.h
 * Author: Keo
 *
 * Created on 2. březen 2014, 17:43
 */

#ifndef HELPER_H
#define	HELPER_H

#include <iostream>
#include <sstream>
#include <SFML/System.hpp>


class Helper {
public:
    static void print(const sf::Vector3i, std::string message = "Vector");
    static std::string toString(sf::Vector3i);
    static int sgn(int);
};

#endif	/* HELPER_H */

