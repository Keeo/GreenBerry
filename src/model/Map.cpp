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
                sf::Vector3i p = position + sf::Vector3i(i - 4, j - 4, k - 4);
                grid[i][j][k] = generateChunk(p);
            }
        }
    }

    _connectAll();

    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            for (int k = 0; k != 9; ++k) {
                std::cout << "i:" << i << " j:" << j << " k:" << k;
                grid[i][j][k]->buildMesh();
                grid[i][j][k]->init();
                grid[i][j][k]->moveToGpu();
                std::cout << " -- done" << std::endl;
            }
        }
    }
    _consistencyCheck();
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
    //Log::getInstance().info("chunk", "Generuji chunk pro pozici: " + Helper::toString(position));
    for (int i = 0; i < 32; ++i) {//x
        for (int j = 0; j < 32; ++j) {//z
            for (int k = 0; k < 32; ++k) { //y
                //Block b = k + position.y * SIZE < field[i + j * 32] ? Block::GRASS : Block::AIR;
                Block b = k + position.y * SIZE < 1 ? Block::GRASS : Block::AIR;
                sf::Vector3i p = sf::Vector3i(i, k, j);
                chunk->placeBlock(p, b);
            }
        }
    }
    delete[] field;
    return chunk;
}
#define nmod(x) ((x % 9) + 9) % 9
void Map::connectChunk(sf::Vector3i gridPos)
{
    const int x = nmod(gridPos.x);
    const int y = nmod(gridPos.y);
    const int z = nmod(gridPos.z);

    Chunk* chunk = grid[x][y][z];

    chunk->u = grid[x][nmod(y + 1)][z];
    chunk->d = grid[x][nmod(y - 1)][z];

    chunk->n = grid[nmod(x + 1)][y][z];
    chunk->w = grid[nmod(x - 1)][y][z];

    chunk->e = grid[x][y][nmod(z + 1)];
    chunk->s = grid[x][y][nmod(z - 1)];
}

void Map::draw()
{
    for (int i = _centerGrid.x - 4; i <= _centerGrid.x + 4; ++i) {
        for (int j = _centerGrid.y - 4; j <= _centerGrid.y + 4; ++j) {
            for (int k = _centerGrid.z - 4; k <= _centerGrid.z + 4; ++k) {
                grid[nmod(i)][nmod(j)][nmod(k)]->draw();
            }
        }
    }
}

void Map::moveMap(void* data)
{
    sf::Vector3i dir = *(sf::Vector3i*) data;
    Helper::print(dir, "Moved by: ");
    if (dir.y !=0 ) return;
    
    Log::getInstance().info("chunk", "Posouvam center o " + Helper::toString(dir));
    for (int x = abs(dir.x); x != 0; --x) {
        sf::Vector3i t(Helper::sgn(dir.x), 0, 0);
        Log::getInstance().info("chunk", "Krok o " + Helper::toString(t));
        moveCenter(t);
    }
        
    for (int y = abs(dir.y); y != 0; --y) {
        sf::Vector3i t(0, Helper::sgn(dir.y), 0);
        Log::getInstance().info("chunk", "Krok o " + Helper::toString(t));
        moveCenter(t);
    }
    
    for (int z = abs(dir.z); z != 0; --z) {
        sf::Vector3i t(0, 0, Helper::sgn(dir.z));
        Log::getInstance().info("chunk", "Krok o " + Helper::toString(t));
        moveCenter(t);
    }
}

void Map::moveCenter(sf::Vector3i dir)
{
    Log::getInstance().infonl("chunk", "MoveCenter");
    _consistencyCheck();
    std::cout<<"MoveCenter"<<std::endl;
    _centerGrid.x = nmod(_centerGrid.x + dir.x);
    _centerGrid.y = nmod(_centerGrid.y + dir.y);
    _centerGrid.z = nmod(_centerGrid.z + dir.z);
    _centerGlob += dir;
    
    if (dir.x != 0){
        int x = nmod(_centerGrid.x + 4 * dir.x);
        std::cout<<"Generating"<<std::endl;
        Log::getInstance().info("chunk", "Generuji...");
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                Chunk* td = grid[x][j][k];
                sf::Vector3i newPosition = _centerGlob + sf::Vector3i(4 * dir.x, (j-4), (k-4));
                grid[x][j][k] = generateChunk(newPosition);
                Log::getInstance().info("chunk", "Generating chunk for gridPos "+ Helper::toString(sf::Vector3i(x, j, k)) +" globPos"+Helper::toString(newPosition));
                delete td;
            }       
        }
        
        _connectAll();
        
        std::cout<<"Meshing"<<std::endl;
        for (int y = _centerGrid.y - 4; y <= _centerGrid.y + 4; y++) {
            for (int z = _centerGrid.z - 4; z <= _centerGrid.z + 4; z++) {
                grid[nmod(x)][nmod(y)][nmod(z)]->buildMesh();
                grid[nmod(x)][nmod(y)][nmod(z)]->init();
                grid[nmod(x)][nmod(y)][nmod(z)]->moveToGpu();
            }       
        }
        
        Helper::print(_centerGrid, "CenterGrid");
        Helper::print(_centerGlob, "CenterGlob");
        std::cout<<std::endl;
    }

    if (dir.y != 0){
        int y = nmod(_centerGrid.y + 4 * dir.y);
        std::cout<<"Generating"<<std::endl;
        Log::getInstance().info("chunk", "Generuji...");
        for (int i = 0; i < 9; i++) {
            for (int k = 0; k < 9; k++) {
                Chunk* td = grid[i][y][k];
                sf::Vector3i newPosition = _centerGlob + sf::Vector3i((i-4), 4 * dir.y, (k-4));
                grid[i][y][k] = generateChunk(newPosition);
                Log::getInstance().info("chunk","Generating chunk for gridPos "+ Helper::toString(sf::Vector3i(i, y, k)) +" globPos"+Helper::toString(newPosition));
                delete td;
            }       
        }
        
        _connectAll();
        
        std::cout<<"Meshing"<<std::endl;
        for (int x = _centerGrid.x - 4; x <= _centerGrid.x + 4; x++) {
            for (int z = _centerGrid.z - 4; z <= _centerGrid.z + 4; z++) {
                grid[nmod(x)][nmod(y)][nmod(z)]->buildMesh();
                grid[nmod(x)][nmod(y)][nmod(z)]->init();
                grid[nmod(x)][nmod(y)][nmod(z)]->moveToGpu();
            }       
        }
        std::cout<<std::endl;
        Helper::print(_centerGrid, "CenterGrid");
        Helper::print(_centerGlob, "CenterGlob");
        std::cout<<std::endl;
    }
    
    if (dir.z != 0){
        int z = nmod(_centerGrid.z + 4 * dir.z);
        std::cout<<"Generating"<<std::endl;
        Log::getInstance().info("chunk", "Generuji...");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                Chunk* td = grid[i][j][z];
                sf::Vector3i newPosition = _centerGlob + sf::Vector3i((i-4), (j-4), 4 * dir.z);
                grid[i][j][z] = generateChunk(newPosition);
                Log::getInstance().info("chunk","Generating chunk for gridPos "+ Helper::toString(sf::Vector3i(i, j, z)) +" globPos"+Helper::toString(newPosition));
                delete td;
            }       
        }
        
        _connectAll();
        
        std::cout<<"Meshing"<<std::endl;
        for (int x = _centerGrid.x - 4; x <= _centerGrid.x + 4; x++) {
            for (int y = _centerGrid.y - 4; y <= _centerGrid.y + 4; y++) {
                grid[nmod(x)][nmod(y)][nmod(z)]->buildMesh();
                grid[nmod(x)][nmod(y)][nmod(z)]->init();
                grid[nmod(x)][nmod(y)][nmod(z)]->moveToGpu();
            }       
        }
        
        Helper::print(_centerGrid, "CenterGrid");
        Helper::print(_centerGlob, "CenterGlob");
        std::cout<<std::endl;
    }
    _consistencyCheck();
    Log::getInstance().info("chunk","//MoveCenter");
}

void Map::_connectAll()
{
    std::cout<<"Connecting"<<std::endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                connectChunk(sf::Vector3i(i, j, k));
            }       
        }
    }
}

bool Map::_consistencyCheck()
{
    bool ret = true;
    Log::getInstance().info("Map", "Consitentcy check begin");
    for (int x = _centerGlob.x - 4; x <= _centerGlob.x + 4; x++) {
        for (int y = _centerGlob.y - 4; y <= _centerGlob.y + 4; y++) {
            for (int z = _centerGlob.z - 4; z <= _centerGlob.z + 4; z++) {
                sf::Vector3i ex = sf::Vector3i(x, y, z);
                sf::Vector3i centerGrid(nmod(x), nmod(y), nmod(z));
                sf::Vector3i pos = grid[centerGrid.x][centerGrid.y][centerGrid.z]->getPosition();
                
                if (pos != ex) {
                    Log::getInstance().info("chunk", "Consistency check failed Grid[" + Helper::toString(centerGrid) + "] Actual[" + Helper::toString(pos) + "] Expected[" + Helper::toString(ex) + "]");
                    ret = false;
                }
            }
        }
    }
    Log::getInstance().info("map", "Consitentcy check end");
    std::cout<<"check return val:"<<ret<<std::endl;
    return ret;
}