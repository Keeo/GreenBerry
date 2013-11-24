/* 
 * File:   Window.cpp
 * Author: Keo
 * 
 * Created on 24. listopad 2013, 15:34
 */

#include "Window.h"

Window::Window() : _window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32))
{
    glewInit();
    
    // create the window
    _window.setVerticalSyncEnabled(true);

    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glMatrixMode(GL_PROJECTION);

    glEnable(GL_DEPTH_TEST);
}

Window::Window(const Window& orig)
{
}

Window::~Window()
{
}

void Window::draw()
{
    ADrawable a;
    a.setVAO();
    a.setVB();
    a.draw();
    //std::cout<<"Hey";
}