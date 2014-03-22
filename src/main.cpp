/* 
 * File:   main.cpp
 * Author: Keo
 *
 * Created on 26. říjen 2013, 20:39
 */

#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include "noise/MapNoise.h"
#include "model/Map.h"
#include "view/Window.h"
#include "control/Game.h"
#include "util/Log.h"
#include "util/Ddm.h"
#include "glm/ext.hpp"
#include <SFML/System.hpp>
/*
 * 
 */
int main(int argc, char** argv)
{
    //Map map(sf::Vector3i(0,0,0));
    
    Game g;
    g.run();
    
    /*glm::vec3 pos(0.1, 0.1, 0.1);
    glm::vec3 dir(0.001, -1, -1);
    sf::Vector3i* p = Ddm::traverse(pos, dir);
    std::cout<<std::endl;
    for (int i=0;i<30;++i)
    {
        Helper::print(p[i]);
    }*/

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

