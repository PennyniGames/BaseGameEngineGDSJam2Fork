//
// Created by penny on 14/09/25.
//

#ifndef ACTOR_H
#define ACTOR_H
#include "AnimatedSprite.h"
#include "olcPixelGameEngine.h"
#include "TVector2D.h"


class Actor
{
public:

    Actor();
    virtual ~Actor()
    {
        delete Sprite;
    }
    virtual void Tick(float fElapsedTime) = 0;
    virtual void Collide(Actor* Other) = 0;
    virtual void Draw(float fElapsedTime, olc::vf2d<float> InLocation) = 0;
    TVector2D<float> GetPosition() const;
    virtual TVector2D<int> GetSpriteSize() const;

protected:
    TVector2D<float> Position = { 0,0 };
    std::shared_ptr<AnimatedSprite> Sprite = nullptr;
};



#endif //ACTOR_H
