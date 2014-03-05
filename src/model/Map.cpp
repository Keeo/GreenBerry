/* 
 * File:   Map.cpp
 * Author: Keo
 * 
 * Created on 2. listopad 2013, 19:33
 */

#include "Map.h"

Map::Map(sf::Vector3i position) : grid(boost::extents[9][9][9])
{
    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            for (int k = 0; k != 9; ++k) {
                sf::Vector3i p = position + sf::Vector3i(i, j, k) - sf::Vector3i(4, 4, 4);
                grid[i][j][k] = generateChunk(p);
            }
        }
    }

    for (int i = 1; i != 8; ++i) {
        for (int j = 1; j != 8; ++j) {
            for (int k = 1; k != 8; ++k) {
                connectChunk(sf::Vector3i(i, j, k));
            }
        }
    }

    for (int i = 1; i != 8; ++i) {
        for (int j = 1; j != 8; ++j) {
            for (int k = 1; k != 8; ++k) {
                std::cout << "i:" << i << " j:" << j << " k:" << k;
                grid[i][j][k]->buildMesh();
                grid[i][j][k]->init();
                grid[i][j][k]->moveToGpu();
                std::cout << " -- done" << std::endl;
            }
        }
    }
    
    EventMessagingSystem::getInstance().Register(Events::eveDeleteCube, this, (Callback) & Map::deleteCube);
    EventMessagingSystem::getInstance().Register(Events::evePlayerChangedChunk, this, (Callback) & Map::moveMap);
}

void Map::deleteCube(void* data)
{
    glm::vec3 **p = (glm::vec3**) data;
    glm::vec3 position = *p[0];
    std::cout << "Input position: " << glm::to_string(position) << std::endl;

    Chunk* c = getChunk(position);
    Block b = c->placeBlock(position, Block::AIR);
    if (b != Block::AIR) {
        c->buildMesh();
        c->moveToGpu();
    }
}

Chunk* Map::getChunk(glm::vec3 position)
{
    int x = position.x / SIZE + 4;
    int y = position.y / SIZE + 4;
    int z = position.z / SIZE + 4;
    std::cout << "Chunk position: x:" << x << " y:" << y << " z:" << z << std::endl;
    return grid[x][y][z];
}

Chunk* Map::generateChunk(sf::Vector3i position)
{
    Chunk* chunk = new Chunk(position);
    int* field = _mn.getHeightField(position.x, position.z);

    for (int i = 0; i < 32; ++i) {//x
        for (int j = 0; j < 32; ++j) {//z
            for (int k = 0; k < 32; ++k) { //y
                Block b = k + position.y * SIZE < field[i + j * 32] ? Block::GRASS : Block::AIR;
                sf::Vector3i p = sf::Vector3i(i, k, j);
                chunk->placeBlock(p, b);
            }
        }
    }

    return chunk;
}

void Map::connectChunk(sf::Vector3i pos)
{
    const int x = pos.x;
    const int y = pos.y;
    const int z = pos.z;

    Chunk* chunk = grid[x][y][z];

    chunk->u = grid[x][y + 1][z];
    chunk->d = grid[x][y - 1][z];

    chunk->n = grid[x + 1][y][z];
    chunk->w = grid[x - 1][y][z];

    chunk->e = grid[x][y][z + 1];
    chunk->s = grid[x][y][z - 1];
}

void Map::draw()
{
    for (int i = 1; i < 8; ++i) { //x
        for (int j = 1; j < 8; ++j) { //z
            for (int k = 1; k < 8; ++k) { //y
                grid[i][j][k]->draw();
}
        }
    }
}

void Map::moveMap(void* data)
{
    std::cout << "sd";
}

void Map::moveMapPointer(sf::Vector3i dir)
{
    
}