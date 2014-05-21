/* 
 * File:   PlayState.cpp
 * Author: clark
 * 
 * Created on December 24, 2013, 11:19 PM
 */

#include "PlayState.h"
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Game.h"
#include "MenuButton.h"
#include "PauseState.h"
#include "GameOverState.h"
#include <iostream>
const std::string PlayState::myPlayID = "PLAY";

void PlayState::update()
{
    if (MyInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        MyGame::Instance()->getStateMachine()->pushState(new PauseState());
    }
    if (m_loadingComplete && !myGameObjects.empty() && !m_exiting)
    {

	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->update();
	}
    }
    
    if(checkCollision(dynamic_cast<SDLGameObject*>(myGameObjects[0]), dynamic_cast<SDLGameObject*>(myGameObjects[1])))
    {
        MyGame::Instance()->getStateMachine()->changeState(new GameOverState());
    }
}

void PlayState::render()
{
	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!MyTextureManager::Instance()->load("assets/helicopter.png", "helicopter", MyGame::Instance()->getRenderer()))
	{
		return false;
	}
        if(!MyTextureManager::Instance()->load("assets/helicopter2.png", "helicopter2", MyGame::Instance()->getRenderer()))
        {
            return false;
        }
        GameObject* player1 = new Player(new LoaderParams(500, 100, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2"));
        myGameObjects.push_back(enemy);
        myGameObjects.push_back(player1);
	std::cout << "entering PlayState\n";
        m_loadingComplete = true;
	return true;
}

bool PlayState::onExit()
{
	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->clean();
	}
	myGameObjects.clear();
	MyTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	m_exiting = true;
        return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();
    
    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();
    
    if(bottomA <= topB){return false;}
    if(topA >= bottomB){return false;}
    if(rightA <= leftB){return false;}
    if(leftA >= rightB){return false;}
    
    return true;
}