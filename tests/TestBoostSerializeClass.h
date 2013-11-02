/*
 * File:   TestBoostSerializeClass.h
 * Author: Keo
 *
 * Created on 31.10.2013, 21:48:38
 */

#ifndef TESTBOOSTSERIALIZECLASS_H
#define	TESTBOOSTSERIALIZECLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <iostream>
#include <fstream>

class TestClass
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & data;
    }
    
public:
    int data[4];
    
    TestClass(){}
    TestClass(int a,int b,int c,int d)
    {
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }
};

class TestBoostSerializeClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestBoostSerializeClass);

    CPPUNIT_TEST(testBoost);

    CPPUNIT_TEST_SUITE_END();

public:
    TestBoostSerializeClass();
    virtual ~TestBoostSerializeClass();
    void setUp();
    void tearDown();

private:
    void testBoost();
};

#endif	/* TESTBOOSTSERIALIZECLASS_H */

