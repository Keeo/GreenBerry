/* 
 * File:   ADrawable.cpp
 * Author: Keo
 * 
 * Created on 24. listopad 2013, 15:51
 */

#include "ADrawable.h"

ADrawable::ADrawable()
{
}

ADrawable::ADrawable(const ADrawable& orig)
{
}

ADrawable::~ADrawable()
{
}


void ADrawable::setVAO()
{
    glGenVertexArrays(1, &_vertexArrayID);
    glBindVertexArray(_vertexArrayID);
    
    if (_vertexArrayID == -1) std::cout<<"_vertexArrayID still -1?"<<std::endl;
}

void ADrawable::setVB()
{
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &_vertexBufferID);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
    if (_vertexBufferID == -1) std::cout<<"_vertexBufferID still -1?"<<std::endl;
}

void ADrawable::draw()
{
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glVertexAttribPointer(
       0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    //glUniformMatrix4fv(10, 1, GL_FALSE, glm::value_ptr(glm::vec3(1.f,0.f,1.f)));
    
    
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

    glDisableVertexAttribArray(0);
}