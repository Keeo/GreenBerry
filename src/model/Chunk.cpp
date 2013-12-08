/* 
 * File:   Chunk.cpp
 * Author: Keo
 * 
 * Created on 26. říjen 2013, 21:12
 */
#include <stdlib.h>

#include "Chunk.h"

Chunk::Chunk(sf::Vector3i position) : _pos(position), ADrawable(position * 32)
{
}

Chunk::Chunk(){}

Chunk::~Chunk()
{
    delete [] g_vertex_buffer_data;
}

Block& Chunk::getBlock(sf::Vector3i position)
{
    return _data[position.x][position.y][position.z];
}

void Chunk::dummyGenerate()
{
    for (int i=0; i<32; ++i )
    {
        for (int j=0; j<32; ++j )
        {
            for (int k=0; k<32; ++k )
            {
                _data[i][j][k] = j < 16 ? GRASS : AIR;
            }
        }
    }
}

Block Chunk::placeBlock(sf::Vector3i position, Block replacement)
{
    Block& b = getBlock(position);
    Block ret = b;
    b = replacement;
    return ret;
}

const sf::Vector3i& Chunk::getPosition()
{
    return _pos;
}

std::string Chunk::getChunkName(sf::Vector3i& pos)
{
    std::stringstream ss;
    ss << pos.x;
    ss << '-';
    ss << pos.y;
    ss << '-';
    ss << pos.z;
    ss << ".chunk";
    return ss.str();
}

void Chunk::buildMesh()
{
    const int edge = 1;
    for (int i = 0 + edge; i < 32 - edge; ++i )
    {
        for (int j = 0 + edge; j < 32 - edge; ++j )
        {
            for (int k = 0 + edge; k < 32 - edge; ++k )
            {
                buildCube(i,j,k);
            }
        }
    }
}

void Chunk::buildCube(int x, int y, int z)
{
    if (_data[x][y][z] == AIR) return;
    
    if (_data[x][y+1][z] == AIR)
    {
        buildSquare(x, y, z, UP);
    }
    
    if (_data[x][y-1][z] == AIR)
    {
        buildSquare(x, y, z, DOWN);
    }
    
    if (_data[x-1][y][z] == AIR)
    {
        buildSquare(x, y, z, LEFT);
    }
    
    if (_data[x+1][y][z] == AIR)
    {
        buildSquare(x, y, z, RIGHT);
    }
    
    if (_data[x][y][z+1] == AIR)
    {
        buildSquare(x, y, z, FORWARD);
    }
    
    if (_data[x][y][z-1] == AIR)
    {
        buildSquare(x, y, z, BACKWARD);
    }
}

void Chunk::prebuildSquare()
{
    const int meshLength = 3 * 3 * 2 * 6 * 32 * 32 * 32 / 2;
    g_vertex_buffer_data = new GLfloat[meshLength];    
}


void Chunk::buildSquare(float x, float y, float z, Direction d)
{
    const float m = 1;
    const float cm = 0.9f;
    int pStart = gvbd_pointer;
    switch (d)
    {
        case UP:
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            break;
        
        case DOWN:
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            break;
            
        case LEFT:
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            break;
            
        case RIGHT:
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            break;
            
        case FORWARD:
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + z;
            break;
            
        case BACKWARD:
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + x;
            g_vertex_buffer_data[gvbd_pointer++] = cm * -0.5 + y;
            g_vertex_buffer_data[gvbd_pointer++] = cm * +0.5 + z;
            break;
    }
    
    for (int i = pStart; i<gvbd_pointer;++i)
        g_vertex_buffer_data[i]*=m;
}