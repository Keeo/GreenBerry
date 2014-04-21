/* 
 * File:   Game.cpp
 * Author: Keo
 * 
 * Created on 24. listopad 2013, 15:38
 */

#include "Game.h"

Game::Game()
{
    Register(Events::eveShutdown, this, (Callback)&Game::stopGame);
}

Game::Game(const Game& orig)
{
}

Game::~Game()
{
}

void Game::stopGame()
{
    running_ = false;
}

void Game::run()
{
    sf::Clock clock;
    GameTime gameTime;
    
    camera_.init();
    while (running_)
    {
        gameTime.time = clock.restart();
        
        camera_.update(gameTime);
        window_.update();
        world_.update(gameTime);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Why am i clearing it here?
        world_.draw();
        window_.draw();
    }
}