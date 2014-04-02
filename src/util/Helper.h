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
#include "glm/ext.hpp"

class Helper {
public:
    static void print(const sf::Vector3i&, std::string message = "Vector");
    static void print(const sf::Vector3f&, std::string message = "Vector");
    static std::string toString(const sf::Vector3i&);
    static std::string toString(const glm::vec3&);
    static int sgn(int);
    static int sgn(float);
    static sf::Vector3i sgn(const glm::vec3&);
    static sf::Vector3f normalize(const sf::Vector3f&);
    static sf::Vector3f glmToSf(const glm::vec3&);
    static glm::vec3 sfToGlm(const sf::Vector3f&);
    static glm::vec3 sfToGlm(const sf::Vector3i&);
};

#endif	/* HELPER_H */

