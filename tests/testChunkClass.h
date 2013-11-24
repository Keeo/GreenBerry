/*
 * File:   testChunkClass.h
 * Author: Keo
 *
 * Created on 27.10.2013, 18:39:26
 */

#ifndef TESTCHUNKCLASS_H
#define	TESTCHUNKCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/model/ChunkEntity.h"

class testChunkClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(testChunkClass);

    CPPUNIT_TEST(testChunk);
    CPPUNIT_TEST(testSaveAndLoad);
    CPPUNIT_TEST(testPlaceBlock);
    CPPUNIT_TEST(testName);
    CPPUNIT_TEST(testDummyGenerate);

    CPPUNIT_TEST_SUITE_END();

public:
    testChunkClass();
    virtual ~testChunkClass();
    void setUp();
    void tearDown();

private:
    void testChunk();
    void testName();
    void testSaveAndLoad();
    void testPlaceBlock();
    void testDummyGenerate();

};

#endif	/* TESTCUNKCLASS_H */

