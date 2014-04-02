/* 
 * File:   EventMessagingSystem.h
 * Author: Keo
 *
 * Created on 26. říjen 2013, 21:54
 */

#ifndef EVENTMESSAGINGSYSTEM_H
#define	EVENTMESSAGINGSYSTEM_H

#include "IEventMessagingSystem.h"
#include <unordered_map>
#include <vector>

struct EveCall
{
    IEventMessagingSystem * pObj;
    Callback pFunc;
};

class EventMessagingSystem
{
public:
    static EventMessagingSystem& getInstance();
    void Post		(Events eEvent, void * pData = 0, unsigned int uiSize = 0);
    void Register	(Events eEvent, IEventMessagingSystem * pObj, Callback pFunc);
    void UnRegister	(Events eEvent, IEventMessagingSystem * pObj, Callback pFunc);
    int eventCount      (Events eEvent);
    void clearAll       ();
private:
    
    std::vector<EveCall> _events[Events::EVENT_COUNT];

    EventMessagingSystem();
    EventMessagingSystem(EventMessagingSystem const&);
    void operator=(EventMessagingSystem const&); 
};

#endif	/* EVENTMESSAGINGSYSTEM_H */

