/*
 * File:   newtestclass.cpp
 * Author: Keo
 *
 * Created on 27.10.2013, 14:07:26
 */

#include "newtestclass.h"

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown()
{
    EventMessagingSystem::getInstance().clearAll();
}

void newtestclass::testRegisterSelfPost()
{
    IEventMessagingSystem iems;
    
    Events e = eveTest1;
    iems.Register(e, &iems, (Callback)&IEventMessagingSystem::testFunction);

    int var [] = { 16, 2, 0 };
    iems.Post(e, (void *)var, 3);

    CPPUNIT_ASSERT_EQUAL(18, *(var+2));
}

void newtestclass::testUnRegisterSelfPost()
{
    IEventMessagingSystem iems;
    
    Events e = eveTest1;
    
    CPPUNIT_ASSERT_EQUAL(0, EventMessagingSystem::getInstance().eventCount(e));
    
    iems.Register(e, &iems, &IEventMessagingSystem::testFunction);
    CPPUNIT_ASSERT_EQUAL(1, EventMessagingSystem::getInstance().eventCount(e));
    
    iems.UnRegister(e, &iems, &IEventMessagingSystem::testFunction);
    CPPUNIT_ASSERT_EQUAL(0, EventMessagingSystem::getInstance().eventCount(e));
    
    int var [] = { 16, 2, 0 };
    iems.Post(e, (void *)var, 3);
    CPPUNIT_ASSERT_EQUAL(0, *(var+2));
}