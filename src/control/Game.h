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
#include "../model/Cube.h"
#include "../control/GameTime.h"

class Game : IEventMessagingSystem
{
    
public:
    
    Game();
    void run();
    Game(const Game& orig);
    virtual ~Game();
    
    void stopGame();
    
private:
    bool running_ = true;
    
    Window window_;
    Camera camera_;
    World world_;
};

#endif	/* GAME_H */

