/* 
 * File:   Window.cpp
 * Author: Keo
 * 
 * Created on 24. listopad 2013, 15:34
 */

#include "Window.h"

Window::Window() : _chunk(sf::Vector3i(0,-1,0))
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
    

    _img.loadFromFile("D:\\_school\\s5\\BP\\GreenBerry\\cubes.png");
    _tex.loadFromImage(_img);
    _shader.setParameter("sampler", _tex);
    _shader.bind();
    
    _chunk.prebuildSquare();
    //_chunk.dummyGenerate();
    //_chunk.randGenerate();
    _chunk.placeBlock(sf::Vector3i(1,0,1),AIR);
    _chunk.placeBlock(sf::Vector3i(1,2,1),AIR);
    
    _chunk.placeBlock(sf::Vector3i(0,1,1),AIR);
    _chunk.placeBlock(sf::Vector3i(2,1,1),AIR);
    
    _chunk.placeBlock(sf::Vector3i(1,1,0),AIR);
    _chunk.placeBlock(sf::Vector3i(1,1,2),AIR);
    
    _chunk.placeBlock(sf::Vector3i(1,1,1),GRASS);
    //_chunk.buildCube(1, 1, 1);
    _chunk.buildSquare(0, 0, 0, UP);
    //_chunk.buildMesh();
    
    _chunk.init();
    _chunk.moveToGpu();
    

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
    
    std::cout<<"GLError: "<<glGetError()<<std::endl;
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