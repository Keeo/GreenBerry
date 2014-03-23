/* 
 * File:   WeatherChunk.cpp
 * Author: Keo
 * 
 * Created on 22. březen 2014, 19:37
 */

#include "WeatherChunk.h"
#include "Particle.h"

WeatherChunk::WeatherChunk()
{
}

WeatherChunk::WeatherChunk(const WeatherChunk& orig)
{
}

WeatherChunk::~WeatherChunk()
{
}

void WeatherChunk::setPosition(sf::Vector3i position)
{
    position_ = position;
}

void WeatherChunk::update(const sf::Time& time)
{
}
