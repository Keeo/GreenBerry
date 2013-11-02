/* 
 * File:   MapNoise.h
 * Author: Keo
 *
 * Created on 2. listopad 2013, 16:51
 */

#ifndef MAPNOISE_H
#define	MAPNOISE_H

#include "SimplexNoise.h"

/**
 * Decorative class for specific setting over noise generator
 */
class MapNoise : protected SimplexNoise
{
public:
    void setScale(double scale);
    
    int getHeight(int x,int y);
    int* getHeightField(int x,int y);
private:
    double _scale = 256;
};

#endif	/* MAPNOISE_H */

