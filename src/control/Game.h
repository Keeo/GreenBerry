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

class Game
{
    
public:
    
    Game();
    void run();
    Game(const Game& orig);
    virtual ~Game();
    
private:
    Window _window;
    //Camera _camera;
};

#endif	/* GAME_H */

