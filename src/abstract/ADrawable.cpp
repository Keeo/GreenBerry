/* 
 * File:   ADrawable.cpp
 * Author: Keo
 * 
 * Created on 24. listopad 2013, 15:51
 */

#include "ADrawable.h"

ADrawable::ADrawable(sf::Vector3i pos, int size) 
{
    g_vertex_buffer_data.reserve(size);
    _model = glm::translate(pos.x, pos.y, pos.z);
}

ADrawable::ADrawable(sf::Vector3i pos)
{
    _model = glm::translate(pos.x, pos.y, pos.z);
}

ADrawable::ADrawable()
{
}

ADrawable::ADrawable(const ADrawable& orig)
{
}

ADrawable::~ADrawable()
{
}

void ADrawable::moveToGpu()
{
    glBindVertexArray(_vertexArrayID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * g_vertex_buffer_data.size(), g_vertex_buffer_data.data(), GL_STATIC_DRAW);
    glDisableVertexAttribArray(0);
}

void ADrawable::draw()
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(5);
    assert(_vertexBufferID!=-1);

    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glVertexAttribPointer(
       0,
       3,
       GL_FLOAT,
       GL_FALSE,
       8 * sizeof(GLfloat),
       (void*)0
    );

    glVertexAttribPointer(
        1,                 // attribute
        2,                 // number of elements per vertex
        GL_FLOAT,          // the type of each element
        GL_FALSE,          // take our values as-is
        8 * sizeof(GLfloat),// no extra data between each position
        (GLvoid*)(3*sizeof(GLfloat))// offset of first element
    );
    
    glVertexAttribPointer(
        5,                 // attribute
        3,                 // number of elements per vertex
        GL_FLOAT,          // the type of each element
        GL_FALSE,          // take our values as-is
        8 * sizeof(GLfloat),// no extra data between each position
        (GLvoid*)(5*sizeof(GLfloat))// offset of first element
    );
    
    //glUniform3fv(10, 1, glm::value_ptr(glm::vec3(1.f,0.f,1.f)));
    
    glUniformMatrix4fv(2, 1, GL_FALSE, glm::value_ptr(_model));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        glDrawArrays(GL_LINES, 0, g_vertex_buffer_data.size() / 3 );
    } else {
        glDrawArrays(GL_TRIANGLES, 0, g_vertex_buffer_data.size() / 3);
    }
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
}

void ADrawable::init()
{
    glGenVertexArrays(1, &_vertexArrayID);
    assert(_vertexArrayID != -1);
    
    glGenBuffers(1, &_vertexBufferID);
    assert(_vertexBufferID != -1);
}

void ADrawable::printVBD()
{
    std::cout<<"VBDPrint: ";
    for (int i=0;i<g_vertex_buffer_data.size();++i)
        std::cout<<g_vertex_buffer_data[i]<<' ';
    std::cout<<"__end"<<std::endl;
}