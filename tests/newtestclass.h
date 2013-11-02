/*
 * File:   newtestclass.h
 * Author: Keo
 *
 * Created on 27.10.2013, 14:07:26
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/observer/EventMessagingSystem.h"

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testRegisterSelfPost);
    CPPUNIT_TEST(testUnRegisterSelfPost);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    
    void testRegisterSelfPost();
    void testUnRegisterSelfPost();

};

#endif	/* NEWTESTCLASS_H */

