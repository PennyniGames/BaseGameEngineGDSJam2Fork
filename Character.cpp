//
// Created by penny on 14/09/25.
//

#include "Character.h"

Character::Character()
{
    Position = { 0, 0 };
}

void Character::Tick(const float fElapsedTime)
{
    constexpr float MoveRate = 1.f/120.f;

    TimeSinceMoved += fElapsedTime;

    if (TimeSinceMoved > MoveRate)
    {
        Move(TimeSinceMoved);
        TimeSinceMoved = 0.f;
    }
    Draw(TimeSinceMoved, Position);

}

void Character::Draw(const float fElapsedTime, const TVector2D<float> InLocation)
{
    Sprite->Draw(fElapsedTime, InLocation);
}