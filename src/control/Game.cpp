/* 
 * File:   Game.cpp
 * Author: Keo
 * 
 * Created on 24. listopad 2013, 15:38
 */

#include "Game.h"

Game::Game()
{
}

Game::Game(const Game& orig)
{
}

Game::~Game()
{
}

void Game::run()
{
    while (true)
    {
        _window.update();
        _window.draw();
    }
}