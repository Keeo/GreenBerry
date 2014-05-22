/* 
 * File:   Camera.cpp
 * Author: Keo
 * 
 * Created on 25. listopad 2013, 16:52
 */

#include "Camera.h"

Camera::Camera()
{
        EventMessagingSystem::getInstance().Register(Events::eveCameraDrawWorld, this, (Callback) & Camera::draw);
        EventMessagingSystem::getInstance().Register(Events::eveCameraDrawWeather, this, (Callback) & Camera::drawWeather);
        EventMessagingSystem::getInstance().Register(Events::eveCameraGetPositionPointer, this, (Callback) & Camera::getPositionPointer);
}

void Camera::update(const GameTime& time)
{
    float delta = time.asSeconds();

    move(delta);
    rotate(delta);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        glm::vec3 *p[2];
        p[0] = &position_;
        p[1] = &direction_;
        Post(Events::eveDeleteCube, p, 2);
    }
    
    sf::Vector3i sf_position(position_.x,position_.y,position_.z);
    sf::Vector3i sf_position_last(positionLast_.x,positionLast_.y,positionLast_.z);
    if (Chunk::getChunkCoords(sf_position) != Chunk::getChunkCoords(sf_position_last)) {
        sf::Vector3i t = sf_position - sf_position_last;
        t.x = chunkilize(t.x);
        t.y = chunkilize(t.y);
        t.z = chunkilize(t.z);
        Post(Events::evePlayerChangedChunk, (void*)&t, 0);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) Post(Events::eveShutdown, 0, 0);
    positionLast_ = position_;
}

void Camera::move(float& delta)
{
    float move_speed = 50.0f;
    float border_const = 0.2f;
            
    glm::vec3 axis(0, 0, 0);
    glm::vec3 border;
    glm::vec3 nextPosition = position_;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) axis += direction_ * move_speed * delta;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) axis -= direction_ * move_speed * delta;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) axis += right_ * move_speed * delta;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) axis -= right_ * move_speed * delta;
    
    border.x = border_const * Helper::sgn(axis.x);
    border.y = border_const * Helper::sgn(axis.y);
    border.z = border_const * Helper::sgn(axis.z);
    
    nextPosition += axis + border;
    
    void* p[2];
    Block block = Block::AIR;
    p[0] = &nextPosition;
    p[1] = &block;
    Post(Events::eveGetBlock, p, 0);
    if (block == Block::AIR) {
        position_ += axis;
    } else {
        nextPosition = position_;

        nextPosition.x += axis.x + border.x;
        Post(Events::eveGetBlock, p, 0);
        if (block == Block::AIR) {
            position_.x += axis.x;
        } else {
            nextPosition.x = position_.x;
        }
        
        nextPosition.y += axis.y + border.y;
        Post(Events::eveGetBlock, p, 0);
        if (block == Block::AIR) {
            position_.y += axis.y;
        } else {
            nextPosition.y = position_.y;
        }
        
        nextPosition.z += axis.z + border.z;
        Post(Events::eveGetBlock, p, 0);
        if (block == Block::AIR) {
            position_.z += axis.z;
        } else {
            nextPosition.z = position_.z;
        }
    }
}


void Camera::getPositionPointer(void* data)
{
    *(glm::vec3**)data = (glm::vec3*)&position_;
}

void Camera::draw(void* data)
{
    assert(data == NULL);
    //std::cout<<"Cam:"<<_position.x<<" "<<_position.y<<" "<<_position.z<<std::endl;
    glUniformMatrix4fv(3, 1, GL_FALSE, glm::value_ptr(view_));
    glUniformMatrix4fv(4, 1, GL_FALSE, glm::value_ptr(projection_));
    glUniform3fv(6,  1, glm::value_ptr(position_));
    
    
    glm::vec3 color;
    Post(Events::getDirectionalLight, (void*)&color, 0);
    glUniform3fv(7,  1, glm::value_ptr(color));
}

void Camera::drawWeather(void* data)
{
    assert(data == NULL);
    //std::cout<<"Cam:"<<_position.x<<" "<<_position.y<<" "<<_position.z<<std::endl;
    glUniform3fv(3,  1, glm::value_ptr(right_));
    glUniform3fv(4,  1, glm::value_ptr(up_));
    glUniformMatrix4fv(5, 1, GL_FALSE, glm::value_ptr(projection_ * view_));
    
    glm::vec3 color;
    Post(Events::getDirectionalLight, (void*)&color, 0);
    glUniform3fv(7,  1, glm::value_ptr(color));
    glUniform3fv(8,  1, glm::value_ptr(position_));
}

void Camera::rotate(float& delta)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

        float x = sf::Mouse::getPosition().x-500;
        float y = sf::Mouse::getPosition().y-500;
        sf::Mouse::setPosition(sf::Vector2i(500,500));

        static float mouse_speed = .007f;
        horizontalAngle_ -= x * mouse_speed;// * delta;
        verticalAngle_ -= y * mouse_speed;// * delta;
        updateDirection();

        view_ = glm::lookAt(position_, position_ + direction_, up_);
    }
}

void Camera::updateDirection()
{
	direction_ = glm::vec3(
		cos(verticalAngle_) * sin(horizontalAngle_),
		sin(verticalAngle_),
		cos(verticalAngle_) * cos(horizontalAngle_)
	);

	right_ = glm::vec3(
		sin(horizontalAngle_ - 3.14f/2.0f),
		0,
		cos(horizontalAngle_ - 3.14f/2.0f)
	);

	up_ = glm::cross(right_, direction_);
}

void Camera::init()
{
    positionLast_ = position_ = glm::vec3(0,40,0);
    direction_ = glm::vec3(1,40,0);
    projection_ = glm::perspective(100.0f, 4.0f / 3.0f, 0.1f, 400.0f);
    view_ = glm::lookAt(position_, direction_, glm::vec3(0,1,0));
}

Camera::Camera(const Camera& orig)
{
}

Camera::~Camera()
{
}

