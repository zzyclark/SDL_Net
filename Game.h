/* 
 * File:   Game.h
 * Author: clark
 *
 * Created on December 22, 2013, 12:06 AM
 */

#pragma once
#include "SDL2/SDL.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include <iostream>
#include <vector>


class Game
{
public:

	static Game* Instance()
	{
		if(myInstance == NULL)
		{
			myInstance = new Game();
			return myInstance;
		}
		return myInstance;
	};

	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running();
	void quit(){myRunning = false;};
	SDL_Renderer* getRenderer() const {return myRenderer;};

private:

	Game();
	~Game();
	SDL_Window* myWindow;
	SDL_Surface* mySurface;
        SDL_Renderer* myRenderer;

	bool myRunning;
	static Game* myInstance;
	std::vector<GameObject*> myGameObjectList;
};

typedef Game MyGame;




