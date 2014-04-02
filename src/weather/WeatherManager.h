/* 
 * File:   WeatherManager.h
 * Author: Keo
 *
 * Created on 22. březen 2014, 19:37
 */

#ifndef WEATHERMANAGER_H
#define	WEATHERMANAGER_H

#include <gl/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>

#include "boost/multi_array.hpp"

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "../observer/IEventMessagingSystem.h"
#include "Particle.h"

#define frand() static_cast <float> (rand()) / static_cast <float> (RAND_MAX)

class WeatherManager : IEventMessagingSystem
{
public:
    WeatherManager();
    WeatherManager(const WeatherManager& orig);
    virtual ~WeatherManager();
    
    void initialize();
    void draw();
    void update(const sf::Time&);
    
private:
    
    static const int MAX_PARTICLES = 100 * 5 * 5;    
    Particle particles_[MAX_PARTICLES];
    int particlesCount_ = 0;
    
    static const GLfloat g_vertex_buffer_data[];
    
    GLuint billboard_vertex_buffer;
    GLuint particles_position_buffer;
    GLuint particles_color_buffer;
    
    GLfloat* g_particule_position_size_data = new GLfloat[MAX_PARTICLES * 4];
    GLubyte* g_particule_color_data         = new GLubyte[MAX_PARTICLES * 4];
    
    sf::Shader shader_;
};

#endif	/* WEATHERMANAGER_H */

