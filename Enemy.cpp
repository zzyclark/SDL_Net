#include "SDLGameObject.h"

Enemy::Enemy(const LoaderParams* myParams) : SDLGameObject(myParams)
{
    m_velocity.setX(0.1);
    m_velocity.setY(2);
    m_numFrame = 6;
}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    m_currentFrame = int (((SDL_GetTicks()/100)%m_numFrame));
    
    if(m_position.getY() < 0)
    {
        m_velocity.setY(2);
    }else if(m_position.getY()>400)
    {
        m_velocity.setY(-2);
    }
    
    SDLGameObject::update();
}

void Enemy::clean()
{
    
}

