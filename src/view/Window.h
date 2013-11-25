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
#include <iostream>

class Window {
public:
    Window();
    Window(const Window& orig);
    virtual ~Window();
    void draw();
    void update();
private:

    void initShader();
    sf::RenderWindow _window;
    sf::Shader _shader;
    ADrawable _adrawable;
};

#endif	/* WINDOW_H */

