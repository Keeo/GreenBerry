/* 
 * File:   Cube.cpp
 * Author: Keo
 * 
 * Created on 9. březen 2014, 0:37
 */

#include "Cube.h"

Cube::Cube(sf::Vector3i position, sf::Vector3i vertexes[]) : ADrawable(position * 32)
{
    buildCube(vertexes);
}

Cube::Cube(sf::Vector3i position) : ADrawable(sf::Vector3i(0,0,0), 40)
{
    sf::Vector3i vertexes[8];
    
    const int cm = 32;
    
    vertexes[0] = position + sf::Vector3i(0,0,0) * cm;
    vertexes[1] = position + sf::Vector3i(1,0,0) * cm;
    vertexes[2] = position + sf::Vector3i(1,0,1) * cm;
    vertexes[3] = position + sf::Vector3i(0,0,1) * cm;
    
    vertexes[4] = position + sf::Vector3i(0,1,0) * cm;
    vertexes[5] = position + sf::Vector3i(1,1,0) * cm;
    vertexes[6] = position + sf::Vector3i(1,1,1) * cm;
    vertexes[7] = position + sf::Vector3i(0,1,1) * cm;
    buildCube(vertexes);
}

Cube::Cube() : ADrawable(sf::Vector3i(0,0,0), 40)
{
    buildCube(0);
}

Cube::~Cube()
{
}

void Cube::buildCube(sf::Vector3i ex[])
{
    lines = true;
    /*sf::Vector3i ex[8];
    const int cm = 10;
    ex[0] = sf::Vector3i(0,0,0) * cm;
    ex[1] = sf::Vector3i(1,0,0) * cm;
    ex[2] = sf::Vector3i(1,0,1) * cm;
    ex[3] = sf::Vector3i(0,0,1) * cm;
    ex[4] = sf::Vector3i(0,1,0) * cm;
    ex[5] = sf::Vector3i(1,1,0) * cm;
    ex[6] = sf::Vector3i(1,1,1) * cm;
    ex[7] = sf::Vector3i(0,1,1) * cm;*/

    //case UP:
    g_vertex_buffer_data.push_back(ex[0].x);
    g_vertex_buffer_data.push_back(ex[0].y);
    g_vertex_buffer_data.push_back(ex[0].z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(UP);

    g_vertex_buffer_data.push_back(ex[1].x);
    g_vertex_buffer_data.push_back(ex[1].y);
    g_vertex_buffer_data.push_back(ex[1].z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(UP);

    g_vertex_buffer_data.push_back(ex[3].x);
    g_vertex_buffer_data.push_back(ex[3].y);
    g_vertex_buffer_data.push_back(ex[3].z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(0);
    pushNormal(UP);


    g_vertex_buffer_data.push_back(ex[1].x);
    g_vertex_buffer_data.push_back(ex[1].y);
    g_vertex_buffer_data.push_back(ex[1].z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(UP);

    g_vertex_buffer_data.push_back(ex[2].x);
    g_vertex_buffer_data.push_back(ex[2].y);
    g_vertex_buffer_data.push_back(ex[2].z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(1);
    pushNormal(UP);

    g_vertex_buffer_data.push_back(ex[3].x);
    g_vertex_buffer_data.push_back(ex[3].y);
    g_vertex_buffer_data.push_back(ex[3].z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(UP);

    
    //case DOWN:
    g_vertex_buffer_data.push_back(ex[7].x);
    g_vertex_buffer_data.push_back(ex[7].y);
    g_vertex_buffer_data.push_back(ex[7].z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(0);
    pushNormal(DOWN);

    g_vertex_buffer_data.push_back(ex[5].x);
    g_vertex_buffer_data.push_back(ex[5].y);
    g_vertex_buffer_data.push_back(ex[5].z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(DOWN);

    g_vertex_buffer_data.push_back(ex[4].x);
    g_vertex_buffer_data.push_back(ex[4].y);
    g_vertex_buffer_data.push_back(ex[4].z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(DOWN);


    g_vertex_buffer_data.push_back(ex[7].x);
    g_vertex_buffer_data.push_back(ex[7].y);
    g_vertex_buffer_data.push_back(ex[7].z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(DOWN);

    g_vertex_buffer_data.push_back(ex[6].x);
    g_vertex_buffer_data.push_back(ex[6].y);
    g_vertex_buffer_data.push_back(ex[6].z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(1);
    pushNormal(DOWN);

    g_vertex_buffer_data.push_back(ex[5].x);
    g_vertex_buffer_data.push_back(ex[5].y);
    g_vertex_buffer_data.push_back(ex[5].z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(DOWN);
/*
    //case LEFT:
    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(LEFT);

    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(LEFT);

    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(0);
    pushNormal(LEFT);


    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(LEFT);

    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(1);
    pushNormal(LEFT);

    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(LEFT);

    //case RIGHT:
    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(0);
    pushNormal(RIGHT);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(RIGHT);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(RIGHT);


    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(RIGHT);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(1);
    pushNormal(RIGHT);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(RIGHT);

    //case FORWARD:
    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(FORWARD);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(FORWARD);

    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(0);
    pushNormal(FORWARD);


    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(FORWARD);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(1);
    pushNormal(FORWARD);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * -0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(FORWARD);

    //case BACKWARD:
    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(0);
    pushNormal(BACKWARD);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(BACKWARD);

    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(BACKWARD);


    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * -0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(0);
    pushNormal(BACKWARD);

    g_vertex_buffer_data.push_back(cm * +0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(1);
    g_vertex_buffer_data.push_back(1);
    pushNormal(BACKWARD);

    g_vertex_buffer_data.push_back(cm * -0.5 + x);
    g_vertex_buffer_data.push_back(cm * +0.5 + y);
    g_vertex_buffer_data.push_back(cm * +0.5 + z);

    g_vertex_buffer_data.push_back(0);
    g_vertex_buffer_data.push_back(1);
    pushNormal(BACKWARD);*/
}

void Cube::pushNormal(Direction d)
{
    float x, y, z;
    switch (d) {
        case UP:
            x = 0;
            y = 1;
            z = 0;
            break;
            
        case DOWN:
            x = 0;
            y = -1;
            z = 0;
            break;
            
        case LEFT:
            x = -1;
            y = 0;
            z = 0;
            break;
            
        case RIGHT:
            x = 1;
            y = 0;
            z = 0;
            break;
            
        case FORWARD:
            x = 0;
            y = 0;
            z = -1;
            break;
            
        case BACKWARD:
            x = 0;
            y = 0;
            z = 1;
            break;
    }
    
    g_vertex_buffer_data.push_back(x);
    g_vertex_buffer_data.push_back(y);
    g_vertex_buffer_data.push_back(z);
}