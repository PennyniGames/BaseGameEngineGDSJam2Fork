//
// Created by penny on 14/09/25.
//

#ifndef ACTOR_H
#define ACTOR_H
#include "AnimatedSprite.h"
#include "olcPixelGameEngine.h"


class Actor
{
public:

    Actor();
    virtual ~Actor() = default;
    virtual void Tick(float fElapsedTime) = 0;
    virtual void Collide(Actor* Other) = 0;
    virtual void Draw(float fElapsedTime, olc::vf2d InLocation) const = 0;
    olc::vf2d GetPosition() const;
    virtual olc::vi2d GetSpriteSize() const;

protected:
    olc::vf2d Position = { 0,0 };
    std::shared_ptr<AnimatedSprite> Sprite = nullptr;
};

#endif //ACTOR_H
