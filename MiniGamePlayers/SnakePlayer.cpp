//
// Created by penny on 16/09/25.
//

#include "SnakePlayer.h"

#include "../GameJamWorld.h"
#include <memory>


SnakePlayer::SnakePlayer()
{
    std::cout << "SnakePlayer" << std::endl;
}

SnakePlayer::SnakePlayer(const std::shared_ptr<olc::Sprite>& InTileset, const FAnimSequence &InSequence)
{
    Position = {50, 50};
    Sprite = std::make_shared<AnimatedSprite>(AnimatedSprite{InTileset, EAnimationType::STILL, InSequence});
}

void SnakePlayer::Collide(Actor *Other)
{
}

void SnakePlayer::Move(float fElapsedTime)
{
    switch (Direction)
    {
        case 0:
            Position.y -= MoveSpeed;
            break;
        case 1:
            Position.x += MoveSpeed;
            break;
        case 2:
            Position.y += MoveSpeed;
            break;
        case 3:
            Position.x -= MoveSpeed;
            break;
        default:
            break;
    }
}

void SnakePlayer::BounceOff()
{
}

void SnakePlayer::Tick(const float fElapsedTime)
{
    Character::Tick(fElapsedTime);

    if (GameJamWorld::Instance->GetKey(olc::Key::UP).bHeld
        || GameJamWorld::Instance->GetKey(olc::Key::W).bHeld)
    {
        ChangeDirection(0);
    }
    else if (GameJamWorld::Instance->GetKey(olc::Key::RIGHT).bHeld
             || GameJamWorld::Instance->GetKey(olc::Key::D).bHeld)
    {
        ChangeDirection(1);
    }
    else if (GameJamWorld::Instance->GetKey(olc::Key::DOWN).bHeld
             || GameJamWorld::Instance->GetKey(olc::Key::S).bHeld)
    {
        ChangeDirection(2);
    }
    else if (GameJamWorld::Instance->GetKey(olc::Key::LEFT).bHeld
             || GameJamWorld::Instance->GetKey(olc::Key::A).bHeld)
    {
        ChangeDirection(3);
    }
}

void SnakePlayer::ChangeDirection(const int InDirection)
{
    Direction = InDirection;
}