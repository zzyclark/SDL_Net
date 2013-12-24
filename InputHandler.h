/* 
 * File:   InputHandler.h
 * Author: clark
 *
 * Created on December 22, 2013, 12:39 AM
 */

#pragma once

#include "SDL2/SDL.h"
#include <vector>
#include "Game.h"
#include "Vector2D.h"

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if(myInstance == NULL)
		{
			myInstance = new InputHandler();
		}
		return myInstance;
	};

	void update();
	void clean();
	bool getMouseButtonState(int buttonNumber)
	{
		return myMouseButtonStates[buttonNumber];
	};

	Vector2D* getMousePosition()
	{
		return myMousePosition;
	};

	bool isKeyDown(SDL_Scancode key);
private:
	InputHandler(void);
	~InputHandler(void);

	//handle keyboard event
	void onKeyDown();
	void onKeyUp();

	//handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	static InputHandler* myInstance;
	Vector2D* myMousePosition;
	const Uint8* myKeystate;
	std::vector<bool> myMouseButtonStates;
};

typedef InputHandler MyInputHandler;

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1, 
	RIGHT = 2
};




