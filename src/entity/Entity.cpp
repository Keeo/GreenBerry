/* 
 * File:   Entity.cpp
 * Author: Keo
 * 
 * Created on 7. duben 2014, 19:48
 */

#include "Entity.h"

glm::vec3* Entity::cameraPosition_ = 0;

Entity::Entity()
{
    model_ = new Model("D:/_school/s5/BP/model/sheep_anim_%06i.obj", 5, 1.0, 10);
    position_ = glm::vec3(rand() % 20, rand() % 20, rand() % 20);
    direction_ = glm::vec3(0, 0, 1.0f);
    
    transform_ = glm::translate(transform_, position_);
}

Entity::Entity(const Entity& orig)
{
}

Entity::~Entity()
{
    delete model_;
}

void Entity::update(const GameTime& time)
{
    model_->update(time);
    if (cameraPosition_ == 0) Post(Events::eveCameraGetPositionPointer, (void*)&cameraPosition_, 0);

    glm::vec3 dirLeft(glm::rotate(direction_, 1.0f, glm::vec3(0, 1, 0)));
    glm::vec3 dirRight(glm::rotate(direction_, -1.0f, glm::vec3(0, 1, 0)));
    double left = glm::distance(dirLeft + position_, *cameraPosition_);
    double right = glm::distance(dirRight + position_, *cameraPosition_);
    if (abs(left - right) > 0.003f) {
        if (left > right) {
            transform_ = glm::rotate(transform_, -1.0f, glm::vec3(0, 1, 0));
            direction_ = dirRight;
        } else {
            transform_ = glm::rotate(transform_, 1.0f, glm::vec3(0, 1, 0));
            direction_ = dirLeft;
        }
    }
}

void Entity::draw()
{
    //model_->draw(transform_);
    model_->drawAnim(transform_);
}
