/* 
 * File:   IEventMessagingSystem.h
 * Author: Keo
 *
 * Created on 26. říjen 2013, 21:59
 */

#ifndef IEVENTMESSAGINGSYSTEM_H
#define	IEVENTMESSAGINGSYSTEM_H

#include <SFML/System.hpp>

// none of events can be numeritize
enum Events {
    
    // Testing events
    eveTest1,
    eveTest2,
    
    // Core events
    eveShutdown,
    
    // Chunk events
    eveChunkGet,
    eveChunkOnLoad,
    
    // this element has to be the last one, due to its use as a eventc counter
    EVENT_COUNT
};

class IEventMessagingSystem;
class EventMessagingSystem;

typedef void (IEventMessagingSystem::*Callback)(void *pData);

class IEventMessagingSystem
{
public:
	IEventMessagingSystem		();
	~IEventMessagingSystem		();
	void Register                   (Events eEvent, IEventMessagingSystem * pObj, Callback pFunc);
	void UnRegister                 (Events eEvent, IEventMessagingSystem * pObj, Callback pFunc);
	void Post			(Events eEvent, void * pData, unsigned int uiSize);
        void testFunction               (void* data);

protected:
    static EventMessagingSystem& _ems;
};



#endif	/* IEVENTMESSAGINGSYSTEM_H */

