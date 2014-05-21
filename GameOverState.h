/* 
 * File:   GameOverState.h
 * Author: omnitoons
 *
 * Created on May 20, 2014, 3:20 PM
 */

#ifndef GAMEOVERSTATE_H
#define	GAMEOVERSTATE_H

#include "GameState.h"
#include "GameObject.h"
#include <vector>


class GameOverState : public GameState
{
public:
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateID() const {return s_gameOverID;};
private:
    static void s_gameOvertoMain();
    static void s_restartPlay();
    
    static const std::string s_gameOverID;
    std::vector<GameObject*> myGameObjects;
};

#endif	/* GAMEOVERSTATE_H */

