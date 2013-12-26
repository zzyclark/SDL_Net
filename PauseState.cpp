/* 
 * File:   PauseState.cpp
 * Author: clark
 * 
 * Created on December 26, 2013, 9:15 PM
 */

#include "PauseState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "Game.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	//MyGame::Instance()->getStateMachine()->popState();
        MyGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
    std::cout << "test";
	MyGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
    if (m_loadingComplete && !myGameObjects.empty() && !m_exiting) 
    {
	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->update();
	}
    }
}

void PauseState::render()
{
	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	if(!MyTextureManager::Instance()->load("assets/resume.png", "resumebutton", MyGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!MyTextureManager::Instance()->load("assets/main.png", "mainbutton", MyGame::Instance()->getRenderer()))
	{
		return false;
	}

        GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"),s_pauseToMain);
        GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton"),s_resumePlay);
	myGameObjects.push_back(button1);
	myGameObjects.push_back(button2);
        
        m_loadingComplete = true;
	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	for (size_t i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->clean();
	}
	myGameObjects.clear();
	MyTextureManager::Instance()->clearFromTextureMap("mainbutton");
	MyTextureManager::Instance()->clearFromTextureMap("resumebutton");
        //MyInputHandler::Instance()->reset();
        m_exiting = true;
        std::cout << "existing PauseState\n";
        return true;
}

