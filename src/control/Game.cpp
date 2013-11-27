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
    _camera.init();
    while (true)
    {
        _camera.update();
        _window.update();
        _camera.draw();
        _window.draw();
    }
}