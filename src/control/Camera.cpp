/* 
 * File:   Camera.cpp
 * Author: Keo
 * 
 * Created on 25. listopad 2013, 16:52
 */

#include "Camera.h"

Camera::Camera()
{
    _projection = glm::perspective(90.f, float(800) / float(600), 1.f, 100.f);
    _view = glm::lookAt(_position, _position + _direction, glm::vec3(0, 1, 0));
}

void Camera::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _position.x+=0.005f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _position.x-=0.005f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _position.z+=0.005f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _position.z-=0.005f;
    
    rotate();
}

glm::mat4 Camera::getVP()
{
    return _view * _projection;
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


Camera::Camera(const Camera& orig)
{
}

Camera::~Camera()
{
}

