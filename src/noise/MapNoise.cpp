/* 
 * File:   MapNoise.cpp
 * Author: Keo
 * 
 * Created on 2. listopad 2013, 16:51
 */

#include "MapNoise.h"

int MapNoise::getHeight(int x, int y)
{
    double n = noise(x,y);
    n *= _scale;
    return (int)n;
}

int* MapNoise::getHeightField(int x, int y)
{
    int *array = new int[32 * 32];
    for (int i=0;i<32;++i)
        for (int j=0;j<32;++j)
            array[i + j * 32] = getHeight(i+(x*32), j+(y*32));
    return array;
}

void MapNoise::setScale(double scale)
{
    //_scale = scale;
}


