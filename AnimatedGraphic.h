/* 
 * File:   AnimatedGraphic.h
 * Author: omnitoons
 *
 * Created on May 19, 2014, 5:38 PM
 */

#ifndef ANIMATEDGRAPHIC_H
#define	ANIMATEDGRAPHIC_H

#include "SDLGameObject.h"


class AnimatedGraphic : public SDLGameObject
{
    public:
        AnimatedGraphic(LoaderParams* const myParams, int animSpeed);
        virtual ~AnimatedGraphic(void){};
        
        virtual void draw();
        virtual void update();
        virtual void clean();
        
    private:
        int m_animSpeed;
        int m_frameCount;
};

#endif	/* ANIMATEDGRAPHIC_H */

