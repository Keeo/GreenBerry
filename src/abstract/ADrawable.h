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
    ADrawable(sf::Vector3i);
    ADrawable();
    ADrawable(const ADrawable& orig);
    virtual ~ADrawable();
    
    void init();
    void moveToGpu();
    void printVBD();
    
    void draw();

protected:
    
    unsigned int gvbd_pointer = 0;
    GLfloat* g_vertex_buffer_data = 0;
    
private:

    glm::mat4 _model;
    
    GLuint _vertexArrayID = -1;
    GLuint _vertexBufferID = -1;
    
    
};

#endif	/* ADRAWABLE_H */

