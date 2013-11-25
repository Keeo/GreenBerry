/* 
 * File:   Camera.cpp
 * Author: Keo
 * 
 * Created on 25. listopad 2013, 16:52
 */

#include "Camera.h"

Camera::Camera()
{
}

void Camera::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _position.x+=0.005f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _position.x-=0.005f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _position.z+=0.005f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _position.z-=0.005f;
    
    rotate();
    std::cout<<"Position:"<<" ";
    std::cout<<_position.x<<" ";
    std::cout<<_position.y<<" ";
    std::cout<<_position.z<<std::endl;
    
    std::cout<<"Directioin:"<<" ";
    std::cout<<_direction.x<<" ";
    std::cout<<_direction.y<<" ";
    std::cout<<_direction.z<<std::endl;
    
    std::cout<<std::endl;
}

glm::mat4 Camera::getVP()
{
    return _projection * _view * glm::mat4();
}

void Camera::rotate()
{
    
    static sf::Vector2i pos;
    
    float x = pos.x - sf::Mouse::getPosition().x;
    float y = pos.y - sf::Mouse::getPosition().y;
    pos = sf::Mouse::getPosition();
    
    _horizontalAngle -=x;
    _verticalAngle -=y;
    updateDirection();
}

void Camera::updateDirection()
{
	_direction = glm::vec3(
		cos(_verticalAngle) * sin(_horizontalAngle),
		sin(_verticalAngle),
		cos(_verticalAngle) * cos(_horizontalAngle)
	);

	_right = glm::vec3(
		sin(_horizontalAngle - 3.14f/2.0f),
		0,
		cos(_horizontalAngle - 3.14f/2.0f)
	);

	_up = glm::cross(_right, _direction);
}

void Camera::init()
{
    _position = glm::vec3(0);
    _projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    _view = glm::lookAt(glm::vec3(4,3,-3), glm::vec3(0,0,0), glm::vec3(0,1,0));
}

Camera::Camera(const Camera& orig)
{
}

Camera::~Camera()
{
}

