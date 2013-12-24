/* 
 * File:   main.cpp
 * Author: clark
 *
 * Created on December 22, 2013, 12:05 AM
 */

#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f/FPS;

int main(int args, char* argv[])
{
	Uint32 frameStart, frameTime;

	std::cout << "game init attempt .....";

	if(MyGame::Instance()->init("Clark", 100, 100, 640, 480, false))
	{
		while (MyGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			MyGame::Instance()->handleEvents();
			MyGame::Instance()->update();
			MyGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if(frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}else
	{
		std::cout << "game init failure -"<<SDL_GetError()<<std::endl;
	}
	
	std::cout <<"game closing..."<<std::endl;
	MyGame::Instance()->clean();
	return 0;
}