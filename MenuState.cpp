/* 
 * File:   MenuState.cpp
 * Author: clark
 * 
 * Created on December 24, 2013, 11:20 PM
 */

#include "MenuState.h"
#include <iostream>
#include "Game.h"
#include "MenuButton.h"

const std::string MenuState::myMenuID = "MENU";

void MenuState::update()
{
	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!MyTextureManager::Instance()->load("assets/button.png", "playbutton", MyGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!MyTextureManager::Instance()->load("assets/exit.png", "exitbutton", MyGame::Instance()->getRenderer()))
	{
		return false;
	}

	myGameObjects.push_back(new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay));
	myGameObjects.push_back(new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu));
	std::cout << "entering MenuState\n";
	return	true;
}

bool MenuState::onExit()
{
	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->clean();
		myGameObjects.clear();
		MyTextureManager::Instance()->clearFromTextureMap("playbutton");
		MyTextureManager::Instance()->clearFromTextureMap("exitbutton");
	}
	std::cout << "existing MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";

	//If we don't pop first, there will be memory leak when debuging.
	MyGame::Instance()->getStateMachine()->popState();

	MyGame::Instance()->getStateMachine()->changeState(new PlayState());	
}

void MenuState::s_exitFromMenu()
{
	MyGame::Instance()->quit();
	std::cout << "Exit button clicked\n";
}