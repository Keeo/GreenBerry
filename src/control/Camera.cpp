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

void Camera::update(const sf::Time& time)
{
    float delta = time.asSeconds();
    float move_speed = 10.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _position += _direction * move_speed * delta;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _position -= _direction * move_speed * delta;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _position += _right * move_speed * delta;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _position -= _right * move_speed * delta;
    
    rotate(delta);
}

void Camera::draw()
{
    //std::cout<<"Cam:"<<_position.x<<" "<<_position.y<<" "<<_position.z<<std::endl;
    glUniformMatrix4fv(3, 1, GL_FALSE, glm::value_ptr(_view));
    glUniformMatrix4fv(4, 1, GL_FALSE, glm::value_ptr(_projection));
}

void Camera::rotate(float& delta)
{
    
    static sf::Vector2i pos;
    
    float x = pos.x - sf::Mouse::getPosition().x;
    float y = pos.y - sf::Mouse::getPosition().y;
    pos = sf::Mouse::getPosition();
    
    float mouse_speed = 0.5f;
    _horizontalAngle += x * mouse_speed * delta;
    _verticalAngle += y * mouse_speed * delta;
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
    _projection = glm::perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    _view = glm::lookAt(_position, _direction, glm::vec3(0,1,0));
}

Camera::Camera(const Camera& orig)
{
}

Camera::~Camera()
{
}

