/* 
 * File:   Game.cpp
 * Author: clark
 * 
 * Created on December 22, 2013, 12:06 AM
 */

#include "Game.h"


Game* Game::myInstance = NULL;

Game::Game(void)
{
	myWindow = NULL;
	myRenderer = NULL;
}


Game::~Game(void)
{
}

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout<< "SDL init success\n";
		//init window
		myWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if(myWindow != NULL)
		{
			std::cout<<"window init success\n";
			//create renderer
			myRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED);
			if(myRenderer != NULL)
			{
				std::cout<<"render init success\n";
				SDL_SetRenderDrawColor(myRenderer, 0, 0, 0, 255);
				if(!MyTextureManager::Instance()->load("assets/animate-alpha.png", "animate", myRenderer))
				{
					return false;
				}
                                myGameStateMachine = new GameStateMachine();
                                myGameStateMachine->changeState(new MenuState());
				//myGameObjectList.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
				//myGameObjectList.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
			}else{
				std::cout<<"render init fail\n";
				return false;
			}
		}else{
			std::cout<<"window init fail\n";
			return false;
		}
	}else
	{
		std::cout<<"SDL Can't initialize\n";
		return false;
	}
	std::cout<<"Everything init success\n";
	myRunning = true;//Every thing init successfully, start the loop.
	return true;
}

void Game::render()
{
	//clear render to the draw color
	SDL_RenderClear(myRenderer);
	myGameStateMachine->render();
	//draw to the screen
	SDL_RenderPresent(myRenderer);
}

bool Game::running()
{
	return myRunning;
}

void Game::update()
{
    myGameStateMachine->update();
}

void Game::handleEvents()
{
	MyInputHandler::Instance()->update();
}

void Game::clean()
{
	MyInputHandler::Instance()->clean();
	std::cout << "Cleaning game\n";
	SDL_DestroyWindow(myWindow);
	SDL_DestroyRenderer(myRenderer);
	SDL_Quit();
}

