/* 
 * File:   EventMessagingSystem.cpp
 * Author: Keo
 * 
 * Created on 26. říjen 2013, 21:54
 */

#include "EventMessagingSystem.h"

EventMessagingSystem::EventMessagingSystem()
{
    
}

void EventMessagingSystem::clearAll()
{
    for (int i = 0; i < Events::EVENT_COUNT; ++i)
        _events[i].clear();
}

int EventMessagingSystem::eventCount(Events eEvent)
{
    return _events[eEvent].size();
}

void EventMessagingSystem::Post(Events eEvent, void* pData, unsigned int uiSize)
{
    for (std::vector<EveCall>::iterator it = _events[eEvent].begin(); it != _events[eEvent].end(); ++it) 
    {
        IEventMessagingSystem& e = *(*it).pObj;
        Callback call = (*it).pFunc;
        (e.*call)(pData);
    }
}

void EventMessagingSystem::Register(Events eEvent, IEventMessagingSystem* pObj, Callback pFunc)
{
    EveCall ec = {pObj, pFunc};
    _events[eEvent].push_back(ec);
}

void EventMessagingSystem::UnRegister(Events eEvent, IEventMessagingSystem* pObj, Callback pFunc)
{
    for (std::vector<EveCall>::iterator it = _events[eEvent].begin(); it != _events[eEvent].end(); ++it) 
    {
        if ((*it).pObj==pObj && (*it).pFunc==pFunc)
        {
            _events[eEvent].erase(it);
            return;
        }
    }
}

EventMessagingSystem& EventMessagingSystem::getInstance()
{
    static EventMessagingSystem instance;
    return instance;
}