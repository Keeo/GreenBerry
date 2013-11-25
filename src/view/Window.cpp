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
    _window.create(sf::VideoMode(800, 600), "GreenBerryEngine", sf::Style::Default, settings);
    
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    // create the window
    _window.setVerticalSyncEnabled(true);
    
    glClearDepth(1.f);
    glClearColor(1.f, 1.f, 1.f, .1f);
    //glMatrixMode(GL_PROJECTION);

    //glEnable(GL_DEPTH_TEST);
    
    initShader();
    _shader.bind();
    
    _adrawable.setVAO();
    _adrawable.setVB();
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _adrawable.draw();
    _window.display();
    
    
    //std::cout<<"Hey";
}

void Window::update()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}

void Window::initShader()
{
    bool ret = _shader.loadFromFile("D:/_school/s5/BP/GreenBerry/src/shaders/vertex.shader", "D:/_school/s5/BP/GreenBerry/src/shaders/fragment.shader");
    if (!ret) std::cout<<"Cannot load shaders."<<std::endl;
}