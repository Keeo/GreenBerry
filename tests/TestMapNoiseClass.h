/*
 * File:   TestMapNoiseClass.h
 * Author: Keo
 *
 * Created on 2.11.2013, 17:54:12
 */

#ifndef TESTMAPNOISECLASS_H
#define	TESTMAPNOISECLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/model/MapNoise.h"

class TestMapNoiseClass : public CPPUNIT_NS::TestFixture {

    CPPUNIT_TEST_SUITE(TestMapNoiseClass);

    CPPUNIT_TEST(testGetHeightField);

    CPPUNIT_TEST_SUITE_END();

public:
    TestMapNoiseClass();
    virtual ~TestMapNoiseClass();
    void setUp();
    void tearDown();

private:
    void testGetHeightField();
};

#endif	/* TESTMAPNOISECLASS_H */

