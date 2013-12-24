/* 
 * File:   PlayState.h
 * Author: clark
 *
 * Created on December 24, 2013, 11:19 PM
 */

#pragma once
#include "GameState.h"
#include <string>
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const{return myPlayID;};
private:
	static const std::string myPlayID;
};
