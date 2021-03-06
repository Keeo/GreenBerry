/* 
 * File:   IEventMessagingSystem.cpp
 * Author: Keo
 * 
 * Created on 26. říjen 2013, 21:59
 */

#include "IEventMessagingSystem.h"
#include "EventMessagingSystem.h"

EventMessagingSystem& IEventMessagingSystem::_ems = EventMessagingSystem::getInstance();

IEventMessagingSystem::IEventMessagingSystem()
{
    
}

IEventMessagingSystem::~IEventMessagingSystem()
{
    
}

void IEventMessagingSystem::Register(Events eEvent, IEventMessagingSystem* pObj, Callback pFunc)
{
    _ems.Register(eEvent, pObj, pFunc);
}

void IEventMessagingSystem::UnRegister(Events eEvent, IEventMessagingSystem* pObj, Callback pFunc)
{
    _ems.UnRegister(eEvent, pObj, pFunc);
}

void IEventMessagingSystem::Post(Events eEvent, void* pData, unsigned int uiSize)
{
    _ems.Post(eEvent,pData,uiSize);
}

void IEventMessagingSystem::Post(Events eEvent, sf::Vector3i pData, unsigned int uiSize)
{
    Post(eEvent, (void*) & pData, uiSize);
}

void IEventMessagingSystem::testFunction(void* data)
{
    int* d = (int*)data;
    int a = *d;
    int b = *(d+1);
    *(d+2) = a + b;
};