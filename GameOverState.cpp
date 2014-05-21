/* 
 * File:   GameOverState.cpp
 * Author: omnitoons
 * 
 * Created on May 20, 2014, 3:20 PM
 */

#include "GameOverState.h"
#include "Game.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOvertoMain()
{
    MyGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
    MyGame::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter()
{
    if(!MyTextureManager::Instance()->load("assets/gameover.png", "gameovertext", MyGame::Instance()->getRenderer()))
    {
        return false;
    }
    if(!MyTextureManager::Instance()->load("assets/main.png", "mainbutton", MyGame::Instance()->getRenderer()))
    {
        return false;
    }
    if(!MyTextureManager::Instance()->load("assets/restart.png", "restartbutton", MyGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    myGameObjects.push_back(new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "gameovertext"), 2));
    myGameObjects.push_back(new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"), s_gameOvertoMain));
    myGameObjects.push_back(new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton"), s_restartPlay));
    
    m_loadingComplete = true;
    std::cout << "Entering Pause State\n";
    return true;
}

bool GameOverState::onExit()
{
    for(size_t i = 0; i < myGameObjects.size(); ++i)
    {
        myGameObjects[i]->clean();
    }
    myGameObjects.clear();
    MyTextureManager::Instance()->clearFromTextureMap("gameovertext");
    MyTextureManager::Instance()->clearFromTextureMap("mainbutton");
    MyTextureManager::Instance()->clearFromTextureMap("restartbutton");
    
    m_exiting = true;
    std::cout << "Existing gameover state\n";
    return true;
}

void GameOverState::update()
{
    for(size_t i = 0; i < myGameObjects.size(); ++i)
    {
        if(m_loadingComplete && !myGameObjects.empty() && !m_exiting)
        {
            myGameObjects[i] -> update();
        }
    }
}

void GameOverState::render()
{
    for(size_t i = 0; i < myGameObjects.size(); ++i)
    {
        myGameObjects[i] -> draw();
    }
}