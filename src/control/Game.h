/* 
 * File:   Game.h
 * Author: Keo
 *
 * Created on 24. listopad 2013, 15:38
 */

#ifndef GAME_H
#define	GAME_H

#include "../view/Window.h"
#include "Camera.h"
#include "../model/World.h"
#include "../observer/IEventMessagingSystem.h"

class Game : IEventMessagingSystem
{
    
public:
    
    Game();
    void run();
    Game(const Game& orig);
    virtual ~Game();
    
    void stopGame();
    
private:
    bool _running = true;
    
    Window _window;
    Camera _camera;
    World _world;
};

#endif	/* GAME_H */

