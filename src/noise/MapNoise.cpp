/* 
 * File:   MapNoise.cpp
 * Author: Keo
 * 
 * Created on 2. listopad 2013, 16:51
 */

#include "MapNoise.h"

int MapNoise::getHeight(int x, int y)
{
    float xx = x / _smoothness;
    float yy = y / _smoothness;

    int u = (int)xx;
    int v = (int)yy;
    float fractionX = xx-u, fractionZ = yy-u;
    
    float n = lerp(lerp(noise(u, v), noise(u+1, v), fractionX),
            lerp(noise(u, v+1), noise(u+1, v+1), fractionX),
            fractionZ);
    
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

float MapNoise::lerp(float x, float y, float fraction)
{
	return x+(y-x)*fraction;
}