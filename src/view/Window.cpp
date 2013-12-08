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
    
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS); 
    
    //glFrontFace(GL_CCW);
    
    glClearColor(0.f, 0.1f, 0.2f, .1f);
    //glMatrixMode(GL_PROJECTION);

    //glEnable(GL_DEPTH_TEST);
    
    initShader();
    _shader.bind();
    
    _chunk.init();
    _chunk.prebuildSquare();
    _chunk.dummyGenerate();
    _chunk.buildMesh();
    
    /*_chunk.buildSquare(0, 0, 0, UP);
    _chunk.buildSquare(0, 0, 0, DOWN);
    
    _chunk.buildSquare(0, 0, 0, LEFT);
    _chunk.buildSquare(0, 0, 0, RIGHT);
        
    _chunk.buildSquare(0, 0, 0, FORWARD);
    _chunk.buildSquare(0, 0, 0, BACKWARD);*/
    
    _chunk.VBDToGpu();
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

    
    _chunk.draw();

    std::cout<<"GLError"<<glGetError()<<std::endl;
    _window.display();
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
    assert(ret);
}