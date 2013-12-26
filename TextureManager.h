/* 
 * File:   TextureManager.h
 * Author: clark
 *
 * Created on December 22, 2013, 12:36 AM
 */

#pragma once
#include <string>
#include <map>
#include "SDL2/SDL.h"

class TextureManager
{
public:
	static TextureManager* Instance()
	{
		if(s_Instance == NULL)
		{
			s_Instance = new TextureManager();
			return s_Instance;
		}
		return s_Instance;
	};

	bool load(std::string fileName, std::string id, SDL_Renderer*);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* myRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawframe(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* myRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void clearFromTextureMap(std::string id);
private:
	TextureManager(void);
	~TextureManager(void);
	static TextureManager* s_Instance;
	std::map<std::string, SDL_Texture*> myTextureMap;
};

typedef TextureManager MyTextureManager;




