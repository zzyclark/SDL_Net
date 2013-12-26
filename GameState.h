/* 
 * File:   GameState.h
 * Author: clark
 *
 * Created on December 24, 2013, 11:18 PM
 */

#pragma once

#include <string>

class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	
	virtual std::string getStateID() const = 0;
protected:
    
    GameState() : m_loadingComplete(false), m_exiting(false)
    {
        
    }
    
    bool m_loadingComplete;
    bool m_exiting;
    
};

