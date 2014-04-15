/* 
 * File:   Entity.cpp
 * Author: Keo
 * 
 * Created on 7. duben 2014, 19:48
 */

#include "Entity.h"

Entity::Entity()
{
    model_ = new Model("D:/_school/s5/BP/model/sheep.obj");
    transform_ = glm::translate(transform_, glm::vec3(rand() % 20, rand() % 20, rand() % 20));
}

Entity::Entity(const Entity& orig)
{
}

Entity::~Entity()
{
}

void Entity::update(const sf::Time& time)
{
    transform_ = glm::rotate(transform_, 1.0f, glm::vec3(0, 1, 0));
    transform_ = glm::translate(transform_, glm::vec3(1, 0, 1) * time.asSeconds());
}

void Entity::draw()
{
    model_->draw(transform_);
}
