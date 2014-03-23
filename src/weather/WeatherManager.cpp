/* 
 * File:   WeatherManager.cpp
 * Author: Keo
 * 
 * Created on 22. březen 2014, 19:37
 */

#include "WeatherManager.h"
#include "Particle.h"

const GLfloat WeatherManager::g_vertex_buffer_data[] = { 
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,
};

WeatherManager::WeatherManager() : weatherChunks_(boost::extents[5][5])
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; j++) {
            weatherChunks_[i][j] = new WeatherChunk();
        }
    }
    
    for (int i = 0; i< MAX_PARTICLES ; ++i) {
        new (&particles_[i]) Particle();
        particles_[i].position = glm::vec3(rand() % 100 - 50,rand() % 100 - 50,rand() % 100 - 50);
        particles_[i].speed = glm::vec3(rand() % 2 - 1,rand() % 2 - 1,rand() % 2 - 1);
        ++particlesCount_;
    }
}

WeatherManager::WeatherManager(const WeatherManager& orig)
{
}

WeatherManager::~WeatherManager()
{
}

void WeatherManager::update(const sf::Time& time)
{
    for (int i = 0; i < MAX_PARTICLES; ++i) {
        Particle& p = particles_[i];
        p.position += time.asSeconds() * p.speed;
        
        g_particule_position_size_data[4*i+0] = p.position.x;
        g_particule_position_size_data[4*i+1] = p.position.y;
        g_particule_position_size_data[4*i+2] = p.position.z;

        g_particule_position_size_data[4*i+3] = 1;

        g_particule_color_data[4*i+0] = 128;
        g_particule_color_data[4*i+1] = 0;
        g_particule_color_data[4*i+2] = 128;
        g_particule_color_data[4*i+3] = 50;
    }
}

void WeatherManager::draw()
{
    shader_.bind();
    Post(Events::eveCameraDrawWeather, NULL, 0);

    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, particlesCount_ * sizeof(GLfloat) * 4, g_particule_position_size_data);

    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, particlesCount_ * sizeof(GLubyte) * 4, g_particule_color_data);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
    glVertexAttribPointer(
        0, // attribute. No particular reason for 0, but must match the layout in the shader.
        3, // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0, // stride
        (void*)0 // array buffer offset
    );

    // 2nd attribute buffer : positions of particles' centers
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
    glVertexAttribPointer(
        1, // attribute. No particular reason for 1, but must match the layout in the shader.
        4, // size : x + y + z + size => 4
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0, // stride
        (void*)0 // array buffer offset
    );

    // 3rd attribute buffer : particles' colors
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    glVertexAttribPointer(
        2, // attribute. No particular reason for 1, but must match the layout in the shader.
        4, // size : r + g + b + a => 4
        GL_UNSIGNED_BYTE, // type
        GL_TRUE, // normalized? *** YES, this means that the unsigned char[4] will be accessible with a vec4 (floats) in the shader ***
        0, // stride
        (void*)0 // array buffer offset
    );
    
    
    // These functions are specific to glDrawArrays*Instanced*.
    // The first parameter is the attribute buffer we're talking about.
    // The second parameter is the "rate at which generic vertex attributes advance when rendering multiple instances"
    // http://www.opengl.org/sdk/docs/man/xhtml/glVertexAttribDivisor.xml
    glVertexAttribDivisor(0, 0); // particles vertices : always reuse the same 4 vertices -> 0
    glVertexAttribDivisor(1, 1); // positions : one per quad (its center) -> 1
    glVertexAttribDivisor(2, 1); // color : one per quad -> 1

    // Draw the particules !
    // This draws many times a small triangle_strip (which looks like a quad).
    // This is equivalent to :
    // for(i in ParticlesCount) : glDrawArrays(GL_TRIANGLE_STRIP, 0, 4), 
    // but faster.
    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, particlesCount_);

    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
}

void WeatherManager::initialize()
{
    bool ret = shader_.loadFromFile("D:/_school/s5/BP/GreenBerry/src/weather/vertex.shader", "D:/_school/s5/BP/GreenBerry/src/weather/fragment.shader");
    assert(ret);
    
    shader_.bind();

    glGenBuffers(1, &billboard_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &particles_position_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);

    glGenBuffers(1, &particles_color_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW);
}

