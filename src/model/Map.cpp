/* 
 * File:   Map.cpp
 * Author: Keo
 * 
 * Created on 2. listopad 2013, 19:33
 */

#include "Map.h"

Map::Map(sf::Vector3i position) : grid(boost::extents[9][9][9]), _centerGlob(position), _centerGrid(4,4,4)
{
    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            for (int k = 0; k != 9; ++k) {
                sf::Vector3i p = position + sf::Vector3i(i, j, k) - sf::Vector3i(4, 4, 4);
                grid[i][j][k] = generateChunk(p);
            }
        }
    }

    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            for (int k = 0; k != 9; ++k) {
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
    delete[] field;
    return chunk;
}
#define nmod(x, diff) ((x + diff) % 9 + 9) % 9
void Map::connectChunk(sf::Vector3i gridPos)
{
    const int x = nmod(gridPos.x, 0);
    const int y = nmod(gridPos.y, 0);
    const int z = nmod(gridPos.z, 0);

    Chunk* chunk = grid[x][y][z];

    chunk->u = grid[x][nmod(y, 1)][z];
    chunk->d = grid[x][nmod(y, -1)][z];

    chunk->n = grid[nmod(x, 1)][y][z];
    chunk->w = grid[nmod(x, -1)][y][z];

    chunk->e = grid[x][y][nmod(z, 1)];
    chunk->s = grid[x][y][nmod(z, -1)];
}

void Map::draw()
{
    for (int i = _centerGrid.x - 3; i < _centerGrid.x + 3; ++i) {
        for (int j = _centerGrid.y - 3; j < _centerGrid.y + 3; ++j) {
            for (int k = _centerGrid.z - 3; k < _centerGrid.z + 3; ++k) {
                grid[nmod(i, 0)][nmod(j, 0)][nmod(k, 0)]->draw();
            }
        }
    }
}

void Map::moveMap(void* data)
{
    sf::Vector3i* dir = (sf::Vector3i*) data;
    Helper::print(*dir, "Moved by: ");
    moveCenter(*dir);
    //moveCenter(sf::Vector3i(-1,0,0));
}

void Map::moveCenter(sf::Vector3i dir)
{
    //if (dir.x == 0) return;
    
    std::cout<<"MoveCenter"<<std::endl;
    _centerGrid.x = nmod(_centerGrid.x + dir.x, 0);
    _centerGrid.y = nmod(_centerGrid.y + dir.y, 0);
    _centerGrid.z = nmod(_centerGrid.z + dir.z, 0);
    _centerGlob += dir;
    
    if (dir.x != 0){
        int x = nmod(_centerGrid.x, 4 * dir.x);
        std::cout<<"Generating"<<std::endl;
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                Chunk* td = grid[x][j][k];
                grid[x][j][k] = generateChunk(_centerGlob + sf::Vector3i(4 * dir.x, (j-4), (k-4)));
                delete td;
            }       
        }
        
        std::cout<<"Connecting"<<std::endl;
        for (int i = 3; i <= 5; ++i) {
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    connectChunk(_centerGrid + sf::Vector3i(i, j, k));
                }       
            }
        }
        
        std::cout<<"Meshing"<<std::endl;
        for (int y = _centerGrid.y - 3; y < _centerGrid.y + 3; y++) {
            for (int z = _centerGrid.z - 3; z < _centerGrid.z + 3; z++) {
                grid[nmod(x, -1 * dir.x)][nmod(y, 0)][nmod(z, 0)]->buildMesh();
                grid[nmod(x, -1 * dir.x)][nmod(y, 0)][nmod(z, 0)]->init();
                grid[nmod(x, -1 * dir.x)][nmod(y, 0)][nmod(z, 0)]->moveToGpu();
            }       
        }
        
        Helper::print(_centerGrid, "CenterGrid");
        Helper::print(_centerGlob, "CenterGlob");
        std::cout<<std::endl;
    }

    if (dir.y != 0){
        int y = nmod(_centerGrid.y, 4 * dir.y);
        std::cout<<"Generating"<<std::endl;
        for (int i = 0; i < 9; i++) {
            for (int k = 0; k < 9; k++) {
                Chunk* td = grid[i][y][k];
                grid[i][y][k] = generateChunk(_centerGlob + sf::Vector3i((i-4), 4 * dir.y, (k-4)));
                delete td;
            }       
        }
        
        std::cout<<"Connecting"<<std::endl;
        for (int i = 0; i < 9; ++i) {
            for (int j = 3; j <= 5; j++) {
                for (int k = 0; k < 9; k++) {
                    connectChunk(_centerGrid + sf::Vector3i(i, j, k));
                }       
            }
        }
        
        std::cout<<"Meshing"<<std::endl;
        for (int x = _centerGrid.x - 3; x < _centerGrid.x + 3; x++) {
            for (int z = _centerGrid.z - 3; z < _centerGrid.z + 3; z++) {
                grid[nmod(x, 0)][nmod(y, -1 * dir.y)][nmod(z, 0)]->buildMesh();
                grid[nmod(x, 0)][nmod(y, -1 * dir.y)][nmod(z, 0)]->init();
                grid[nmod(x, 0)][nmod(y, -1 * dir.y)][nmod(z, 0)]->moveToGpu();
            }       
        }
        
        Helper::print(_centerGrid, "CenterGrid");
        Helper::print(_centerGlob, "CenterGlob");
        std::cout<<std::endl;
    }
    
    if (dir.z != 0){
        int z = nmod(_centerGrid.z, 4 * dir.z);
        std::cout<<"Generating"<<std::endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                Chunk* td = grid[i][j][z];
                grid[i][j][z] = generateChunk(_centerGlob + sf::Vector3i((i-4), (j-4), 4 * dir.z));
                delete td;
            }       
        }
        
        std::cout<<"Connecting"<<std::endl;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; j++) {
                for (int k = 3; k <= 5; k++) {
                    connectChunk(_centerGrid + sf::Vector3i(i, j, k));
                }       
            }
        }
        
        std::cout<<"Meshing"<<std::endl;
        for (int x = _centerGrid.x - 3; x < _centerGrid.x + 3; x++) {
            for (int y = _centerGrid.y - 3; y < _centerGrid.y + 3; y++) {
                grid[nmod(x, 0)][nmod(y, 0)][nmod(z, -1 * dir.z)]->buildMesh();
                grid[nmod(x, 0)][nmod(y, 0)][nmod(z, -1 * dir.z)]->init();
                grid[nmod(x, 0)][nmod(y, 0)][nmod(z, -1 * dir.z)]->moveToGpu();
            }       
        }
        
        Helper::print(_centerGrid, "CenterGrid");
        Helper::print(_centerGlob, "CenterGlob");
        std::cout<<std::endl;
    }
}

void Map::_connectAll()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                connectChunk(sf::Vector3i(i, j, k));
            }       
        }
    }
}