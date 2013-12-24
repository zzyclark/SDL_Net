/* 
 * File:   PlayState.cpp
 * Author: clark
 * 
 * Created on December 24, 2013, 11:19 PM
 */

#include "PlayState.h"
#include <iostream>
const std::string PlayState::myPlayID = "PLAY";

void PlayState::update()
{
}

void PlayState::render()
{
}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}
