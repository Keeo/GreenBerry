/*
 * File:   TestBoostSerializeClass.cpp
 * Author: Keo
 *
 * Created on 31.10.2013, 21:48:38
 */

#include "TestBoostSerializeClass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TestBoostSerializeClass);

TestBoostSerializeClass::TestBoostSerializeClass()
{
}

TestBoostSerializeClass::~TestBoostSerializeClass()
{
}

void TestBoostSerializeClass::setUp()
{
}

void TestBoostSerializeClass::tearDown()
{
}

void TestBoostSerializeClass::testBoost()
{
    std::ofstream ofs("testFile.dat", std::ios::binary);
    std::ifstream ifs("testFile.dat", std::ios::binary);
    
    TestClass g(7,2,3,6);
    {
        boost::archive::binary_oarchive oa(ofs);
        oa << g;
    }
    
    TestClass gg;
    {
        boost::archive::binary_iarchive ia(ifs);
        ia >> gg;
    }
    CPPUNIT_ASSERT_EQUAL(7,gg.data[0]);
    CPPUNIT_ASSERT_EQUAL(2,gg.data[1]);
    CPPUNIT_ASSERT_EQUAL(3,gg.data[2]);
    CPPUNIT_ASSERT_EQUAL(6,gg.data[3]);
}

