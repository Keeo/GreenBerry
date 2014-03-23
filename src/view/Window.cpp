/* 
 * File:   Window.cpp
 * Author: Keo
 * 
 * Created on 24. listopad 2013, 15:34
 */

#include "Window.h"

Window::Window()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    _window.create(sf::VideoMode(1024, 768), "GreenBerryEngine", sf::Style::Default, settings);
    
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    // create the window
    _window.setVerticalSyncEnabled(false);
    
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS); 
    
    glEnable(GL_CULL_FACE);
    
    //glFrontFace(GL_CCW);
    
    glClearColor(0.f, 0.1f, 0.2f, .1f);
    //glMatrixMode(GL_PROJECTION);

    //glEnable(GL_DEPTH_TEST);
}

Window::Window(const Window& orig)
{
}

Window::~Window()
{
}

void Window::draw()
{
    //_window.clear();
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int err = glGetError();
    if (err) {
        std::cout<<"GLError: "<<err<<std::endl;
    }
    _window.display();
}

void Window::update()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            _window.close();
            Post(Events::eveShutdown, 0, 0);
        }
    }
}