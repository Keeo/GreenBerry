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
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        glm::vec3 **p = new glm::vec3*[2];
        p[0] = &_position;
        p[1] = &_direction;
        Post(Events::eveDeleteCube, p, 2);
        delete[] p;
    }
}

void Camera::draw()
{
    //std::cout<<"Cam:"<<_position.x<<" "<<_position.y<<" "<<_position.z<<std::endl;
    glUniformMatrix4fv(3, 1, GL_FALSE, glm::value_ptr(_view));
    glUniformMatrix4fv(4, 1, GL_FALSE, glm::value_ptr(_projection));
    glUniform3fv(6,  1, glm::value_ptr(_position));
    
}

void Camera::rotate(float& delta)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

        float x = sf::Mouse::getPosition().x-500;
        float y = sf::Mouse::getPosition().y-500;
        sf::Mouse::setPosition(sf::Vector2i(500,500));

        float mouse_speed = 1.0f;
        _horizontalAngle += x * mouse_speed * delta;
        _verticalAngle += y * mouse_speed * delta;
        updateDirection();

        _view = glm::lookAt(_position, _position + _direction, glm::vec3(0,1,0));
    }
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

