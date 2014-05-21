/* 
 * File:   SDLGameObject.cpp
 * Author: clark
 * 
 * Created on December 22, 2013, 12:32 AM
 */

#include "SDLGameObject.h"
#include "Game.h"


SDLGameObject::SDLGameObject(const LoaderParams* myParams):GameObject(myParams), m_position(myParams->getX(), myParams->getY()), m_velocity(0, 0), m_acceleration(0, 0)
{
	m_width = myParams->getWidth();
	m_height = myParams->getHeight();
	m_textureID = myParams->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw()
{
	if (m_velocity.getX() > 0)
	{
		MyTextureManager::Instance()->drawframe(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, MyGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}else
	{
		MyTextureManager::Instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, MyGame::Instance()->getRenderer());
	}
}

void SDLGameObject::clean()
{
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;	
}
