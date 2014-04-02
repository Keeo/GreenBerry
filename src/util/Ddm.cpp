/* 
 * File:   Ddm.cpp
 * Author: Keo
 * 
 * Created on 22. březen 2014, 14:00
 */

#include "Ddm.h"

sf::Vector3i* Ddm::traverse(const glm::vec3& pos, const glm::vec3& dir, int length)
{
    sf::Vector3i* ret = new sf::Vector3i[length];
    
    glm::vec3 ndir(glm::normalize(dir));
    
    const sf::Vector3i step(Helper::sgn(ndir));
    
    glm::vec3 temp;
    temp.x = dir.x > 0 ? ceil(pos.x) : floor(pos.x);
    temp.y = dir.y > 0 ? ceil(pos.y) : floor(pos.y);
    temp.z = dir.z > 0 ? ceil(pos.z) : floor(pos.z);
    
    glm::vec3 tMax;
    tMax.x = (temp.x - pos.x) / ndir.x;
    tMax.y = (temp.y - pos.y) / ndir.y;
    tMax.z = (temp.z - pos.z) / ndir.z;
    //std::cout<<glm::to_string(tMax)<<std::endl;
    
    glm::vec3 tDelta;
    tDelta.x = abs(1 / ndir.x);
    tDelta.y = abs(1 / ndir.y);
    tDelta.z = abs(1 / ndir.z);
    //std::cout<<glm::to_string(tDelta)<<std::endl;
    
    int x = (int)(pos.x);
    int y = (int)(pos.y);
    int z = (int)(pos.z);
    
    for (int i=0; i<length; ++i) {
        if(tMax.x < tMax.y) {
            if(tMax.x < tMax.z) {
                x = x + step.x;
                tMax.x = tMax.x + tDelta.x;
            } else {
                z = z + step.z;
                tMax.z = tMax.z + tDelta.z;
            }
        } else {
            if(tMax.y < tMax.z) {
                y = y + step.y;
                tMax.y = tMax.y + tDelta.y;
            } else {
                z = z + step.z;
                tMax.z = tMax.z + tDelta.z;
            }
        }
        ret[i] = sf::Vector3i(x,y,z);
    };
    
    return ret;
}

