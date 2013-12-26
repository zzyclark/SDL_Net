/* 
 * File:   PauseState.h
 * Author: clark
 *
 * Created on December 26, 2013, 9:15 PM
 */

#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <string>
#include <vector>

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const {return s_pauseID;};
private:
	static void s_pauseToMain();
	static void s_resumePlay();

	static const std::string s_pauseID;

	std::vector<GameObject*> myGameObjects;
};


