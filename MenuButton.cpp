/* 
 * File:   MenuButton.cpp
 * Author: clark
 * 
 * Created on December 26, 2013, 7:54 PM
 */

#include "MenuButton.h"
#include "InputHandler.h"


MenuButton::MenuButton(const LoaderParams* myParams, void (*callback)()) : SDLGameObject(myParams), m_callback(callback)
{
	m_currentFrame = MOUSE_OUT;
	//better to initialize the release status to false at the begining.
	m_bReleased = false;
}

void MenuButton::draw()
{
	SDLGameObject::draw();
}

void MenuButton::update()
{
	Vector2D* myMousePos = MyInputHandler::Instance()->getMousePosition();
	if (myMousePos->getX() < m_position.getX() + m_width
		&& myMousePos->getX() > m_position.getX()
		&& myMousePos->getY() < m_position.getY() + m_height
		&& myMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;

		if(MyInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
		}else if (!MyInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}