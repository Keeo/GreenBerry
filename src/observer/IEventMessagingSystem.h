/* 
 * File:   IEventMessagingSystem.h
 * Author: Keo
 *
 * Created on 26. říjen 2013, 21:59
 */

#ifndef IEVENTMESSAGINGSYSTEM_H
#define	IEVENTMESSAGINGSYSTEM_H

#include <iostream>
#include "../util/Helper.h"
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
    eveLoadNewChunk,
    
    // Delete cube
    eveDeleteCube,
    
    // When player move and changes chunk
    evePlayerChangedChunk,
    
    // Put position, view and projection matrix into shader
    eveCameraDrawWorld,
    eveCameraDrawWeather,
    eveCameraGetPositionPointer, // gets camera pointer to position glm::vec3
    
    // return block in provided position {get vec3,ret block}
    eveGetBlock,
    
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
	void Post			(Events eEvent, sf::Vector3i vector, unsigned int uiSize);
        void testFunction               (void* data);

protected:
    static EventMessagingSystem& _ems;
};



#endif	/* IEVENTMESSAGINGSYSTEM_H */

