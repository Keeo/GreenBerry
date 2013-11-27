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
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
    if (_vertexBufferID == -1) std::cout<<"_vertexBufferID still -1?"<<std::endl;
}

void ADrawable::setColor()
{
    glGenBuffers(1, &_colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
    if (_colorbuffer == -1) std::cout<<"_colorbuffer still -1?"<<std::endl;
}

void ADrawable::draw()
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glVertexAttribPointer(
       0,
       3,
       GL_FLOAT,
       GL_FALSE,
       0,
       (void*)0
    );
    
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, _colorbuffer);
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );


    
    //glUniform3fv(10, 1, glm::value_ptr(glm::vec3(1.f,0.f,1.f)));
    
    
    glDrawArrays(GL_TRIANGLES, 0, 12*3);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}