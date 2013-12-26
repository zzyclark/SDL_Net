/* 
 * File:   InputHandler.cpp
 * Author: clark
 * 
 * Created on December 22, 2013, 12:39 AM
 */

#include "InputHandler.h"

InputHandler* InputHandler::myInstance = NULL;

InputHandler::InputHandler(void):myMousePosition(new Vector2D(0,0)), myKeystate(NULL)
{
	for (int i = 0; i < 3; i++)
	{
		myMouseButtonStates.push_back(false);
	}
}


InputHandler::~InputHandler(void)
{
	delete myMousePosition;
	delete myKeystate;
}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			MyGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}

void InputHandler::clean()
{
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		myMouseButtonStates[LEFT] = false;
		break;
	case SDL_BUTTON_MIDDLE:
		myMouseButtonStates[MIDDLE] = false;
		break;
	case SDL_BUTTON_RIGHT:
		myMouseButtonStates[RIGHT] = false;
		break;
	default:
		break;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		myMouseButtonStates[LEFT] = true;
		break;
	case SDL_BUTTON_MIDDLE:
		myMouseButtonStates[MIDDLE] = true;
		break;
	case SDL_BUTTON_RIGHT:
		myMouseButtonStates[RIGHT] = true;
		break;
	default:
		break;
	}
}

void InputHandler::onMouseMove(SDL_Event& event)
{
	myMousePosition->setX(event.motion.x);
	myMousePosition->setY(event.motion.y);
}

void InputHandler::onKeyDown()
{
	myKeystate = SDL_GetKeyboardState(NULL);
}

void InputHandler::onKeyUp()
{
	myKeystate = SDL_GetKeyboardState(NULL);
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if(myKeystate != NULL)
	{
		if(myKeystate[key] == 1)
		{
			return true;
		}else
		{
			return false;
		}
	}
	return false;
}

void InputHandler::reset()
{
    myMouseButtonStates[LEFT] = false;
    myMouseButtonStates[MIDDLE] = false;
    myMouseButtonStates[RIGHT] = false;
}

