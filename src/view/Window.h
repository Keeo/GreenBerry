/* 
 * File:   Window.h
 * Author: Keo
 *
 * Created on 24. listopad 2013, 15:34
 */

#ifndef WINDOW_H
#define	WINDOW_H

#include <gl/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "../abstract/ADrawable.h"
#include "../model/Direction.h"
#include "../model/Chunk.h"
#include "../observer/IEventMessagingSystem.h"

class Window : IEventMessagingSystem
{
public:
    Window();
    Window(const Window& orig);
    virtual ~Window();
    void draw();
    void update();
private:

    sf::RenderWindow _window;

};

#endif	/* WINDOW_H */

