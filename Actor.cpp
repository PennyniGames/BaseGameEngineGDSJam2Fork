//
// Created by penny on 14/09/25.
//

#include "Actor.h"


Actor::Actor()
{

}

olc::vf2d Actor::GetPosition() const
{
    return Position;
}

olc::vi2d Actor::GetSpriteSize() const
{
    if (Sprite == nullptr)
    {
        return { 0, 0 };
    }
    return Sprite->GetSpriteSize();
}