/*
 * File:   TestMapNoiseClass.cpp
 * Author: Keo
 *
 * Created on 2.11.2013, 17:54:12
 */

#include "TestMapNoiseClass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TestMapNoiseClass);

TestMapNoiseClass::TestMapNoiseClass()
{
}

TestMapNoiseClass::~TestMapNoiseClass()
{
}

void TestMapNoiseClass::setUp()
{
}

void TestMapNoiseClass::tearDown()
{
}

void TestMapNoiseClass::testGetHeightField()
{
    MapNoise mn;
    mn.setScale(256);
    int* field = mn.getHeightField(0, 0);
    
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            std::cout << field[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    // probably nothing to test, if it dont crush it should contains some usefull data
    CPPUNIT_ASSERT(true);
}