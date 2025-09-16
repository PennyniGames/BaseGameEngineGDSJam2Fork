//
// Created by penny on 16/09/25.
//

#ifndef SNAKEPLAYER_H
#define SNAKEPLAYER_H
#include "../Character.h"
#include "../AnimatedSprite.h"
#include "olcPixelGameEngine.h"

struct FAnimSequence;

class SnakePlayer final : public Character
{
public:
    SnakePlayer();
    SnakePlayer(const std::shared_ptr<olc::Sprite>& InTileset, const FAnimSequence& InSequence);
    void Collide(Actor *Other) override;

    void Move(float fElapsedTime) override;

    void BounceOff() override;

    void Tick(float fElapsedTime) override;

private:
    void ChangeDirection(int InDirection);

    int Direction = 0;
    float MoveSpeed = 0.f;
};

#endif //SNAKEPLAYER_H
