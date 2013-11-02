/* 
 * File:   main.cpp
 * Author: Keo
 *
 * Created on 26. říjen 2013, 20:39
 */

#include <cstdlib>
#include <iostream>

#include "model/MapNoise.h"
#include "model/MapGenerator.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    MapGenerator mg("efvgybuhnjmk");
    mg.generateMap(sf::Vector3i(1,0,0));
    
    
    
    return 0;
}


void printMapNoise()
{
    MapNoise mn;
    mn.setScale(256);
    int* field = mn.getHeightField(0, 0);
    
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            std::cout << field[i + 32*j] << ' ';
        }
        std::cout << std::endl;
    }
}

