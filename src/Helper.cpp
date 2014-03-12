/* 
 * File:   Helper.cpp
 * Author: Keo
 * 
 * Created on 2. březen 2014, 17:43
 */

#include "Helper.h"

void Helper::print(const sf::Vector3i vector, std::string message) {
    std::cout<<message;
    printf(" {x: %i, y:%i, z:%i}\n", vector.x, vector.y, vector.z);
}

std::string Helper::toString(sf::Vector3i v)
{
    std::stringstream ss;
    ss << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    return ss.str();
}

int Helper::sgn(int val) {
    return (0 < val) - (val < 0);
}