/* 
 * File:   MenuButton.h
 * Author: clark
 *
 * Created on December 26, 2013, 7:54 PM
 */

#pragma once
#include "SDLGameObject.h"
class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams* myParams, void (*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();

	void (*m_callback)();
private:
	bool m_bReleased;
};

enum button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};


