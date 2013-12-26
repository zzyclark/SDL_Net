/* 
 * File:   MenuState.h
 * Author: clark
 *
 * Created on December 24, 2013, 11:20 PM
 */

#pragma once	

#include "GameState.h"
#include "GameObject.h"
#include <vector>
#include "TextureManager.h"

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const {return myMenuID;};

private:
	static const std::string myMenuID;
	std::vector<GameObject*> myGameObjects;
	static void s_menuToPlay();
	static void s_exitFromMenu();
};
