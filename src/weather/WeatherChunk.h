/* 
 * File:   WeatherChunk.h
 * Author: Keo
 *
 * Created on 22. březen 2014, 19:37
 */

#ifndef WEATHERCHUNK_H
#define	WEATHERCHUNK_H

#include "SFML/System.hpp"

class WeatherChunk
{
public:
    
    WeatherChunk();
    WeatherChunk(const WeatherChunk& orig);
    virtual ~WeatherChunk();
    
    void update(const sf::Time&);
    void draw();
    
    void setPosition(sf::Vector3i pos);
    
    float floor;
    float ceil;
private:

    
    sf::Vector3i position_;
    
};

#endif	/* WEATHERCHUNK_H */

