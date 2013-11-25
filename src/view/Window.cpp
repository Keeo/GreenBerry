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
    
    _adrawable.setVAO();
    _adrawable.setVB();
    _adrawable.setColor();
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

    glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    glm::mat4 View       = glm::lookAt(
                                                            glm::vec3(4,3,-3), // Camera is at (4,3,-3), in World Space
                                                            glm::vec3(0,0,0), // and looks at the origin
                                                            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                               );
    glm::mat4 Model      = glm::mat4(1.0f);
    glm::mat4 MVP        = Projection * View * Model;
    
    glUniformMatrix4fv(2,  1, GL_FALSE, glm::value_ptr(MVP));
    
    _adrawable.draw();
    
    std::cout<<glGetError();
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
    if (!ret) std::cout<<"Cannot load shaders."<<std::endl;
}