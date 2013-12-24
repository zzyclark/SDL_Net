/* 
 * File:   TextureManager.cpp
 * Author: clark
 * 
 * Created on December 22, 2013, 12:36 AM
 */

#include "TextureManager.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

TextureManager* TextureManager::s_Instance = NULL;

TextureManager::TextureManager(void)
{
}


TextureManager::~TextureManager(void)
{
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* myRenderer)
{
	SDL_Surface* tempSurface = IMG_Load(fileName.c_str());

	if(tempSurface == NULL)
	{
		return false;
	}

	SDL_Texture* myTexture = SDL_CreateTextureFromSurface(myRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	//Texture is already rendered, we store it into our list
	if(myTexture != NULL)
	{
		myTextureMap[id] = myTexture;
		return true;
	}
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* myRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(myRenderer, myTextureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawframe(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* myRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width*currentFrame;
	srcRect.y = height*(currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(myRenderer, myTextureMap[id], &srcRect, &destRect, 0, 0, flip);
}




