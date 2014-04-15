/* 
 * File:   World.h
 * Author: Keo
 *
 * Created on 2. listopad 2013, 18:08
 */

#ifndef WORLD_H
#define	WORLD_H

#include "Map.h"
#include "../control/DayNightControl.h"
#include "../weather/WeatherManager.h"
#include "../observer/IEventMessagingSystem.h"
#include "../entity/Entity.h"

class World : IEventMessagingSystem
{

public:
    World();
    
    void update(const sf::Time&);
    void draw();
    
private:
    
    sf::Shader shader_;
    sf::Image img_;
    sf::Texture tex_;
    
    DayNightControl dayNightControl_;
    Map map_;
    WeatherManager weatherManager_;
    Entity entity_;
    void setDirectionalLight(void* data);
};

#endif	/* WORLD_H */

