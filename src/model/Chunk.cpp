/* 
 * File:   Chunk.cpp
 * Author: Keo
 * 
 * Created on 26. říjen 2013, 21:12
 */
#include <stdlib.h>

#include "Chunk.h"

Chunk::Chunk(sf::Vector3i position) : pos_(position), ADrawable(position * SIZE, 100000), cube_(position * SIZE)
{
    fullAir_ = true;
    cube_.init();
    cube_.moveToGpu();
}

Chunk::Chunk(){}

Chunk::~Chunk()
{
}

void Chunk::draw()
{
    if (!fullAir_) ADrawable::draw();
    if (!fullAir_) cube_.draw();
}

Block& Chunk::getBlock(const glm::vec3& pos)
{
    return getBlock(globToLoc(pos));
}

Block& Chunk::getBlock(const sf::Vector3i& position)
{
    return data_[position.x][position.y][position.z];
}

void Chunk::dummyGenerate()
{
    for (int i=0; i<SIZE; ++i )
    {
        for (int j=0; j<SIZE; ++j )
        {
            for (int k=0; k<SIZE; ++k )
            {
                data_[i][j][k] = i + j + k < 16 ? GRASS : AIR;
            }
        }
    }
    fullAir_ = false;
}

void Chunk::randGenerate()
{
    for (int i=0; i<SIZE; ++i )
    {
        for (int j=0; j<SIZE; ++j )
        {
            for (int k=0; k<SIZE; ++k )
            {
                data_[i][j][k] = static_cast<Block>(rand() % 2);
            }
        }
    }
    fullAir_ = false;
}

Block Chunk::placeBlock(glm::vec3 position, Block replacement)
{
    return placeBlock(globToLoc(position), replacement);
}

Block Chunk::placeBlock(sf::Vector3i position, Block replacement)
{
    if (replacement != Block::AIR) fullAir_ = false;
    Block& b = getBlock(position);
    Block ret = b;
    b = replacement;
    return ret;
}

const sf::Vector3i& Chunk::getPosition()
{
    return pos_;
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

inline sf::Vector3i Chunk::globToLoc(const glm::vec3& position)
{
    sf::Vector3i l;
    l.x = fmodf(fmodf(position.x, SIZE) + SIZE, SIZE);
    l.y = fmodf(fmodf(position.y, SIZE) + SIZE, SIZE);
    l.z = fmodf(fmodf(position.z, SIZE) + SIZE, SIZE);
    return l;
}

void Chunk::buildMesh()
{
    g_vertex_buffer_data.clear();
    if (fullAir_) return;
    
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
    //Log::getInstance().info("chunk", "Mesh contains:" + Helper::toString(g_vertex_buffer_data.size()) + "f, and has been build in: " + Helper::toString(clock.getElapsedTime().asMicroseconds()) + "us.");
}

void Chunk::buildCubeOnEdge(int x, int y, int z)
{
    if (data_[x][y][z] == AIR) return;
    
    if (y == SIZE-1){
        if (u->data_[x][0][z] == AIR) {
            buildSquare(x, y, z, UP);
        }
    } else {
        if (data_[x][y+1][z] == AIR) {
            buildSquare(x, y, z, UP);
        }
    }
    
    if (x == SIZE-1){
        if (e->data_[0][y][z] == AIR) {
            buildSquare(x, y, z, RIGHT);
        }
    } else {
        if (data_[x+1][y][z] == AIR) {
            buildSquare(x, y, z, RIGHT);
        }
    }
    
    if (z == SIZE-1){
        if (n->data_[x][y][0] == AIR) {
            buildSquare(x, y, z, BACKWARD);
        }
    } else {
        if (data_[x][y][z+1] == AIR) {
            buildSquare(x, y, z, BACKWARD);
        }
    }
        
    
    if (y == 0){
        if (d->data_[x][SIZE-1][z] == AIR) {
            buildSquare(x, y, z, DOWN);
        }
    } else {
        if (data_[x][y-1][z] == AIR) {
            buildSquare(x, y, z, DOWN);
        }
    }
    
    if (x == 0){
        if (w->data_[SIZE-1][y][z] == AIR) {
            buildSquare(x, y, z, LEFT);
        }
    } else {
        if (data_[x-1][y][z] == AIR) {
            buildSquare(x, y, z, LEFT);
        }
    }
    
    if (z == 0){
        if (s->data_[x][y][SIZE-1] == AIR) {
            buildSquare(x, y, z, FORWARD);
        }
    } else {
        if (data_[x][y][z-1] == AIR) {
            buildSquare(x, y, z, FORWARD);
        }
    }
}    

void Chunk::buildCube(int x, int y, int z)
{
    if (data_[x][y][z] == AIR) return;
    
    if (data_[x][y+1][z] == AIR)
    {
        buildSquare(x, y, z, UP);
    }
    
    if (data_[x][y-1][z] == AIR)
    {
        buildSquare(x, y, z, DOWN);
    }
    
    if (data_[x-1][y][z] == AIR)
    {
        buildSquare(x, y, z, LEFT);
    }
    
    if (data_[x+1][y][z] == AIR)
    {
        buildSquare(x, y, z, RIGHT);
    }
    
    if (data_[x][y][z-1] == AIR)
    {
        buildSquare(x, y, z, FORWARD);
    }
    
    if (data_[x][y][z+1] == AIR)
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
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
                
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            break;
        
        case DOWN:
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            break;
            
        case LEFT:
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            break;
            
        case RIGHT:
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            break;
            
        case FORWARD:
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 0 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            break;
            
        case BACKWARD:
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
             
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 0 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 0 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 0 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 1 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
            g_vertex_buffer_data.push_back( 1 );
            g_vertex_buffer_data.push_back( 1 );
            pushNormal(d);
            
            g_vertex_buffer_data.push_back( cm * 0 + x );
            g_vertex_buffer_data.push_back( cm * 1 + y );
            g_vertex_buffer_data.push_back( cm * 1 + z );
            
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