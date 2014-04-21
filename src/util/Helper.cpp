/* 
 * File:   Helper.cpp
 * Author: Keo
 * 
 * Created on 2. březen 2014, 17:43
 */

#include "Helper.h"

void Helper::print(const sf::Vector3i& vector, std::string message) {
    std::cout<<message;
    printf(" {x: %i, y:%i, z:%i}\n", vector.x, vector.y, vector.z);
}

void Helper::print(const sf::Vector3f& vector, std::string message) {
    std::cout<<message;
    printf(" {x: %f, y:%f, z:%f}\n", vector.x, vector.y, vector.z);
}

template <typename T>
std::string Helper::toString(const T& a)
{
    std::ostringstream ss;
    ss << a;
    return ss.str();
}

std::string Helper::toString(const sf::Vector3i& v)
{
    std::stringstream ss;
    ss << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    return ss.str();
}

std::string Helper::toString(const glm::vec3& v)
{
    return glm::to_string(v);
}

int Helper::sgn(int val) {
    return (0 < val) - (val < 0);
}

int Helper::sgn(float val) {
    return (0 < val) - (val < 0);
}

sf::Vector3i Helper::sgn(const glm::vec3& v)
{
    return sf::Vector3i(sgn(v.x), sgn(v.y), sgn(v.z));
}

sf::Vector3f Helper::glmToSf(const glm::vec3& v)
{
    return sf::Vector3f(v.x, v.y, v.z);
}

glm::vec3 Helper::sfToGlm(const sf::Vector3f& v)
{
    return glm::vec3(v.x, v.y, v.z);
}

glm::vec3 Helper::sfToGlm(const sf::Vector3i& v)
{
    return glm::vec3(v.x, v.y, v.z);
}

void Helper::gl(const std::string& place, bool verbose)
{
    int err = glGetError();
    if (err) {
        std::cout<<"GLError on "<<place<<": "<<err<<std::endl;
    } else {
        if (verbose) { 
                std::cout<<"GL OK on"<<place<<std::endl;
        }
    }
}