//
// Created by penny on 16/09/25.
//

#ifndef GAMEJAMWORLD_H
#define GAMEJAMWORLD_H
#include "AnimatedSprite.h"
#include "GameWorld.h"
#include "SnakeGame.h"


class GameJamWorld final : public GameWorld
{
public:
    GameJamWorld();

    static GameJamWorld* Instance;

    bool OnUserCreate() override;

    void DrawBoundaryLines(olc::Pixel BoundaryPixel);

    bool OnUserUpdate(float fElapsedTime) override;

private:
    std::unique_ptr<SnakeGame> SnakeGamePtr = {};
    std::shared_ptr<olc::Sprite> Tileset = {};

    const olc::vi2d SnakePlayerSpriteOffset =  {1, 1};

    FAnimSequence PlayerAnimSequence = {};
};



#endif //GAMEJAMWORLD_H
