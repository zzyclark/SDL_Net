/* 
 * File:   GameObject.h
 * Author: clark
 *
 * Created on December 22, 2013, 12:27 AM
 */

#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
	virtual void draw(){};
	virtual void update(){};
	virtual void clean(){};
protected:
	GameObject(const LoaderParams* myParams){}
	virtual ~GameObject(void){}
};