/* 
 * File:   GameStateMachine.cpp
 * Author: clark
 * 
 * Created on December 24, 2013, 11:17 PM
 */

#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pState)
{
	myGameSates.push_back(pState);
	myGameSates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if(!myGameSates.empty())
	{
		if(myGameSates.back()->onExit())
		{
			delete myGameSates.back();
			myGameSates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState* pState)
{
	if(!myGameSates.empty())
	{
		if(myGameSates.back()->getStateID() == pState->getStateID())
		{
			//same state name, no need to change
			return;
		}

		if(myGameSates.back()->onExit())
		{
			delete myGameSates.back();
			myGameSates.pop_back();
		}
	}

	myGameSates.push_back(pState);
	myGameSates.back()->onEnter();
}

void GameStateMachine::update()
{
	if(!myGameSates.empty())
	{
		myGameSates.back()->update();
	}
}

void GameStateMachine::render()
{
	if(!myGameSates.empty())
	{
		myGameSates.back()->render();
	}
}