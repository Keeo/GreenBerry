/* 
 * File:   SimplexNoise.h
 * Author: Keo
 *
 * Created on 1. listopad 2013, 16:43
 */

#ifndef SIMPLEXNOISE_H
#define	SIMPLEXNOISE_H

#include <SFML/System.hpp>
typedef sf::Vector3<double> Vector3d;

class SimplexNoise
{

public:
    SimplexNoise();
    
    double noise(double xin, double yin);

private:

    static Vector3d grad[12];

    static short p[];
    // To remove the need for index wrapping, double the permutation table length
    static short perm[512];
    static short permMod12[512];

    // Skewing and unskewing factors for 2
    static const double F2;
    static const double G2;

    static int fastfloor(double x);

    static double dot(Vector3d g, double x, double y);
};

#endif	/* SIMPLEXNOISE_H */

