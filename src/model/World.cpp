/* 
 * File:   World.cpp
 * Author: Keo
 * 
 * Created on 2. listopad 2013, 18:08
 */

#include "World.h"

World::World() : map_(sf::Vector3i(0, 0, 0))
{
    bool ret = shader_.loadFromFile("D:/_school/s5/BP/GreenBerry/src/shaders/world/vertex.shader", "D:/_school/s5/BP/GreenBerry/src/shaders/world/fragment.shader");
    assert(ret);

    img_.loadFromFile("D:\\_school\\s5\\BP\\GreenBerry\\cubes.png");
    tex_.loadFromImage(img_);
    shader_.setParameter("sampler", tex_);
    weatherManager_.initialize();
    entityManager_.initialize();
}

void World::update(const GameTime& time)
{
    weatherManager_.update(time);
    dayNightControl_.update(time);
    entityManager_.update(time);
}

void World::draw()
{
    shader_.bind();
    Post(Events::eveCameraDrawWorld, NULL, 0);
    
    map_.draw();
    
    entityManager_.draw();
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    weatherManager_.draw();
    glDisable(GL_BLEND);
}