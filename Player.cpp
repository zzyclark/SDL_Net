#include "SDLGameObject.h"
#include "InputHandler.h"

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
    m_currentFrame = int (((SDL_GetTicks()/100)%6));
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