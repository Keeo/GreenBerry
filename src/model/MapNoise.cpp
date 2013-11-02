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
    int *array = new int[x * y];
    for (int i=0;i<x;++i)
        for (int j=0;i<y;++y)
            array[i + j * x] = getHeight(x,y);
    return array;
}

void MapNoise::setScale(double scale)
{
    _scale = scale;
}


