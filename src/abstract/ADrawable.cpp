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


void ADrawable::loadVAO()
{
    glGenVertexArrays(1, &_vertexArrayID);
    glBindVertexArray(_vertexArrayID);
    
    assert(_vertexArrayID != -1);
}

void ADrawable::loadVB()
{
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);

    assert(_vertexBufferID != -1);
}

void ADrawable::VBDToGpu()
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * gvbd_pointer, g_vertex_buffer_data, GL_STATIC_DRAW);
}

void ADrawable::draw()
{
    glEnableVertexAttribArray(0);
    
    assert(_vertexBufferID!=-1);
    //printVBD();
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glVertexAttribPointer(
       0,
       3,
       GL_FLOAT,
       GL_FALSE,
       0,
       (void*)0
    );
        
    //glUniform3fv(10, 1, glm::value_ptr(glm::vec3(1.f,0.f,1.f)));
    
    
    glDrawArrays(GL_TRIANGLES, 0, gvbd_pointer / 3);
    //glDrawArrays(GL_LINES, 0, gvbd_pointer / 3);

    glDisableVertexAttribArray(0);
}

void ADrawable::init()
{
    loadVAO();
    loadVB();
}

void ADrawable::printVBD()
{
    std::cout<<"VBDPrint: ";
    for (int i=0;i<gvbd_pointer;++i)
        std::cout<<g_vertex_buffer_data[i]<<' ';
    std::cout<<"__end"<<std::endl;
}