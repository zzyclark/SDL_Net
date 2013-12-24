/* 
 * File:   MenuState.cpp
 * Author: clark
 * 
 * Created on December 24, 2013, 11:20 PM
 */

#include "MenuState.h"
#include <iostream>

const std::string MenuState::myMenuID = "MENU";

void MenuState::update()
{
}

void MenuState::render()
{
}

bool MenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	return	true;
}

bool MenuState::onExit()
{
	std::cout << "existing MenuState\n";
	return true;
}

