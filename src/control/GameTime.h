/* 
 * File:   GameTime.h
 * Author: Keo
 *
 * Created on 21. duben 2014, 16:54
 */

#ifndef GAMETIME_H
#define	GAMETIME_H

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

struct GameTime {

    float asSeconds() const {
        return time.asSeconds();
    }

    float getTotalElapsedTime() const {
        return totalTime.getElapsedTime().asSeconds();
    }

    sf::Time time;
    sf::Clock totalTime;
};

#endif	/* GAMETIME_H */
