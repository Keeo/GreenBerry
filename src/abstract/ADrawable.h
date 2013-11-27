/* 
 * File:   ADrawable.h
 * Author: Keo
 *
 * Created on 24. listopad 2013, 15:51
 */

#ifndef ADRAWABLE_H
#define	ADRAWABLE_H

#include <gl/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ADrawable 
{
public:
    ADrawable();
    ADrawable(const ADrawable& orig);
    virtual ~ADrawable();
    
    void setVAO();
    void setVB();
    void setColor();

    void draw();
private:
    
    
    GLuint _vertexArrayID = -1;
    GLuint _vertexBufferID = -1;
    
    GLuint _colorbuffer;
    
    GLfloat g_vertex_buffer_data[108] = {
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
    };
    
    GLfloat g_color_buffer_data[108] = {
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f,
        0.100f,  0.100f,  0.100f,
        0.600f,  0.600f,  0.600f
    };
};

#endif	/* ADRAWABLE_H */

