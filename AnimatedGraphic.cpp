#include  "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(LoaderParams * const myParams, int animSpeed):SDLGameObject(myParams), m_animSpeed(animSpeed) {
    m_numFrame = 2;
}

void AnimatedGraphic::draw()
{
    SDLGameObject::draw();
}

void AnimatedGraphic::update()
{
    m_currentFrame = int((SDL_GetTicks()/(1000/m_animSpeed))%m_numFrame);
}

void AnimatedGraphic::clean()
{
    SDLGameObject::clean();
}