/* 
 * File:   Chunk.cpp
 * Author: Keo
 * 
 * Created on 26. říjen 2013, 21:12
 */
#include <stdlib.h>

#include "Chunk.h"

Chunk::Chunk(sf::Vector3i position) : _pos(position), ADrawable(position * SIZE, 100000)
{
}

Chunk::Chunk(){}

Chunk::~Chunk()
{
}

Block& Chunk::getBlock(sf::Vector3i position)
{
    return _data[position.x][position.y][position.z];
}

void Chunk::dummyGenerate()
{
    for (int i=0; i<SIZE; ++i )
    {
        for (int j=0; j<SIZE; ++j )
        {
            for (int k=0; k<SIZE; ++k )
            {
                _data[i][j][k] = i + j + k < 16 ? GRASS : AIR;
            }
        }
    }
}

void Chunk::randGenerate()
{
    for (int i=0; i<SIZE; ++i )
    {
        for (int j=0; j<SIZE; ++j )
        {
            for (int k=0; k<SIZE; ++k )
            {
                _data[i][j][k] = static_cast<Block>(rand() % 2);
            }
        }
    }
}

Block Chunk::placeBlock(glm::vec3 position, Block replacement)
{
    sf::Vector3i l;
    l.x = fmodf(fmodf(position.x, SIZE) + SIZE, SIZE);
    l.y = fmodf(fmodf(position.y, SIZE) + SIZE, SIZE);
    l.z = fmodf(fmodf(position.z, SIZE) + SIZE, SIZE);
    return placeBlock(l, replacement);
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
    g_vertex_buffer_data.clear();
    
    sf::Clock clock;
    #define EDGE 1
    for (int i = 0 + EDGE; i < SIZE - EDGE; ++i)
    {
        for (int j = 0 + EDGE; j < SIZE - EDGE; ++j)
        {
            for (int k = 0 + EDGE; k < SIZE - EDGE; ++k)
            {
                buildCube(i,j,k);
            }
        }
    }
    
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < SIZE; )
            {
                buildCubeOnEdge(i,j,k);
                if (i == 0 || i == SIZE-1 ||  j ==0 || j == SIZE-1) {
                    ++k;
                } else {
                    k = k==0 ? SIZE - 1 : SIZE;
                }
            }
        }
    }
    std::cout<<"Mesh contains:"<<g_vertex_buffer_data.size()<<"f, and has been build in: "<<clock.getElapsedTime().asMicroseconds()<<"us."<<std::endl;
}

void Chunk::buildCubeOnEdge(int x, int y, int z)
{
    if (_data[x][y][z] == AIR) return;
    
    if (y == SIZE-1){
        if (u->_data[x][0][z] == AIR) {
            buildSquare(x, y, z, UP);
        }
    } else {
        if (_data[x][y+1][z] == AIR) {
            buildSquare(x, y, z, UP);
        }
    }
    
    if (x == SIZE-1){
        if (e->_data[0][y][z] == AIR) {
            buildSquare(x, y, z, RIGHT);
        }
    } else {
        if (_data[x+1][y][z] == AIR) {
            buildSquare(x, y, z, RIGHT);
        }
    }
    
    if (z == SIZE-1){
        if (n->_data[x][y][0] == AIR) {
            buildSquare(x, y, z, BACKWARD);
        }
    } else {
        if (_data[x][y][z+1] == AIR) {
            buildSquare(x, y, z, BACKWARD);
        }
    }
        
    
    if (y == 0){
        if (d->_data[x][SIZE-1][z] == AIR) {
            buildSquare(x, y, z, DOWN);
        }
    } else {
        if (_data[x][y-1][z] == AIR) {
            buildSquare(x, y, z, DOWN);
        }
    }
    
    if (x == 0){
        if (w->_data[SIZE-1][y][z] == AIR) {
            buildSquare(x, y, z, LEFT);
        }
    } else {
        if (_data[x-1][y][z] == AIR) {
            buildSquare(x, y, z, LEFT);
        }
    }
    
    if (z == 0){
        if (s->_data[x][y][SIZE-1] == AIR) {
            buildSquare(x, y, z, FORWARD);
        }
    } else {
        if (_data[x][y][z-1] == AIR) {
            buildSquare(x, y, z, FORWARD);
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
    
    if (_data[x][y][z-1] == AIR)
    {
        buildSquare(x, y, z, FORWARD);
    }
    
    if (_data[x][y][z+1] == AIR)
    {
        buildSquare(x, y, z, BACKWARD);
    }
}

void Chunk::buildSquare(float x, float y, float z, Direction d)
{
    const float cm = 1.0f;

    switch (d)
    {
        case UP:
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
                
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            break;
        
        case DOWN:
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            break;
            
        case LEFT:
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            break;
            
        case RIGHT:
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            break;
            
        case FORWARD:
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * -0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            break;
            
        case BACKWARD:
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
             
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * -0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * +0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * -0.5 + x );
            g_vertex_buffer_data.push_back( cm * +0.5 + y );
            g_vertex_buffer_data.push_back( cm * +0.5 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            break;
    }
}

void Chunk::pushNormal(Direction d)
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