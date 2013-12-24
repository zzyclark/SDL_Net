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
	MyTextureManager::Instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, MyGame::Instance()->getRenderer());
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
	/*if(MyInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}*/
	if(MyInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if(MyInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if(MyInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if(MyInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	//Vector2D* vec = MyInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 100;
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