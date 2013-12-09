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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _position += _direction * 0.1f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _position -= _direction * 0.1f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _position += _right * 0.1f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _position -= _right * 0.1f;
    
    rotate();
}

void Camera::draw()
{
    //std::cout<<"Cam:"<<_position.x<<" "<<_position.y<<" "<<_position.z<<std::endl;
    glUniformMatrix4fv(3, 1, GL_FALSE, glm::value_ptr(_view));
    glUniformMatrix4fv(4, 1, GL_FALSE, glm::value_ptr(_projection));
}

void Camera::rotate()
{
    
    static sf::Vector2i pos;
    
    float x = pos.x - sf::Mouse::getPosition().x;
    float y = pos.y - sf::Mouse::getPosition().y;
    pos = sf::Mouse::getPosition();
    
    _horizontalAngle += x * 0.01f;
    _verticalAngle += y * 0.01f;
    updateDirection();
    
    _view = glm::lookAt(_position, _position + _direction, glm::vec3(0,1,0));
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
    _position = glm::vec3(4,3,-3);
    _direction = glm::vec3(0,0,0);
    _projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    _view = glm::lookAt(_position, _direction, glm::vec3(0,1,0));
}

Camera::Camera(const Camera& orig)
{
}

Camera::~Camera()
{
}

