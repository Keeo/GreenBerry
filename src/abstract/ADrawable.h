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

    void draw();
private:
    
    
    GLuint _vertexArrayID = -1;
    GLuint _vertexBufferID = -1;
    
    GLfloat g_vertex_buffer_data[9] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
};

#endif	/* ADRAWABLE_H */

