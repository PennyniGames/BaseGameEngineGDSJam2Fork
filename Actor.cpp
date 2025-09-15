//
// Created by penny on 14/09/25.
//

#include "Actor.h"


Actor::Actor()
{

}

TVector2D<float> Actor::GetPosition() const
{
    return Position;
}

TVector2D<int> Actor::GetSpriteSize() const
{
    if (Sprite == nullptr)
    {
        return { 0, 0 };
    }
    return Sprite->GetSpriteSize();
}