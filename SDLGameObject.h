/* 
 * File:   SDLGameObject.h
 * Author: clark
 *
 * Created on December 22, 2013, 12:32 AM
 */

#pragma once
#include "Vector2D.h"
#include "GameObject.h"
#include "TextureManager.h"
//#include "InputHandler.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* myParams);
	
	virtual void draw();
	virtual void update();
	virtual void clean();
        
        Vector2D getPosition(){return m_position;};
        int getHeight() const{return m_height;};
        int getWidth() const{return m_width;};
        
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;
        int m_numFrame;

	std::string m_textureID;
};

//Player Object
class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void hanleInput();
};

//Enemy Object
class Enemy : public SDLGameObject
{
	public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};





