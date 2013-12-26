/* 
 * File:   GameStateMachine.h
 * Author: clark
 *
 * Created on December 24, 2013, 11:17 PM
 */

#pragma once
#include "GameState.h"
#include <vector>
class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
        void update();
	void render();

private:
	std::vector<GameState*> myGameSates;
};

