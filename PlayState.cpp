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
        GameObject* player1 = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
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