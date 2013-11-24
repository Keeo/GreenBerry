/*
 * A speed-improved simplex noise algorithm for 2D, 3D and 4D in Java.
 *
 * Based on example code by Stefan Gustavson (stegu@itn.liu.se).
 * Optimisations by Peter Eastman (peastman@drizzle.stanford.edu).
 * Better rank ordering method by Stefan Gustavson in 2012.
 *
 * This could be speeded up even further, but it's useful as it is.
 *
 * Version 2012-03-09
 *
 * This code was placed in the public domain by its original author,
 * Stefan Gustavson. You may use it as you see fit, but
 * attribution is appreciated.
 */
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

    static short perm[512];
    static short permMod12[512];

    static const double F2;
    static const double G2;

    static int fastfloor(double x);

    static double dot(Vector3d g, double x, double y);
};

#endif	/* SIMPLEXNOISE_H */

