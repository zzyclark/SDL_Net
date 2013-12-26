/* 
 * File:   SDLGameObject.cpp
 * Author: clark
 * 
 * Created on December 22, 2013, 12:32 AM
 */

#include "SDLGameObject.h"



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

Player::Player(const LoaderParams* myParams) : SDLGameObject(myParams)
{
}

void Player::draw()
{
	SDLGameObject::draw(); 
}
void Player::update()
{
	hanleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}
void Player::clean()
{
}

void Player::hanleInput()
{
	Vector2D* target = MyInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}

Enemy::Enemy(const LoaderParams* myParams):SDLGameObject(myParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
}