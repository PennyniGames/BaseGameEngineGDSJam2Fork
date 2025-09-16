//
// Created by penny on 16/09/25.
//

#include "GameJamWorld.h"

#include "EActorType.h"
#include "MiniGamePlayers/SnakePlayer.h"

GameJamWorld* GameJamWorld::Instance = nullptr;

GameJamWorld::GameJamWorld()
{
    Instance = this;
}

bool GameJamWorld::OnUserCreate()
{
    SetPixelMode(olc::Pixel::ALPHA);
    Tileset = std::make_shared<olc::Sprite>("../GameJameSprites01.png");

    PlayerAnimSequence.FirstFrameOffset = SnakePlayerSpriteOffset;
    PlayerAnimSequence.SpriteScale      = 4;

    EverythingCollidableThatMoves.push_back(std::make_shared<SnakePlayer>(Tileset, PlayerAnimSequence));

    return true;
}

bool GameJamWorld::OnUserUpdate(float fElapsedTime)
{
    const olc::Pixel ClearPixel = olc::DARK_BLUE;
    const olc::Pixel BoundaryPixel = olc::DARK_RED;

    Clear(ClearPixel);

    DrawBoundaryLines(BoundaryPixel);

    GameWorld::TickEverything(fElapsedTime);

    return true;
}

void GameJamWorld::DrawBoundaryLines(const olc::Pixel BoundaryPixel)
{
    constexpr int DistanceFromEdge = 10;

    DrawLine(DistanceFromEdge, DistanceFromEdge, ScreenWidth() - DistanceFromEdge, DistanceFromEdge, BoundaryPixel);
    DrawLine(DistanceFromEdge, DistanceFromEdge, DistanceFromEdge, ScreenHeight() - DistanceFromEdge, BoundaryPixel);
    DrawLine(ScreenWidth() - DistanceFromEdge, DistanceFromEdge, ScreenWidth() - DistanceFromEdge, ScreenHeight() - DistanceFromEdge, BoundaryPixel);
    DrawLine(DistanceFromEdge, ScreenHeight() - DistanceFromEdge, ScreenWidth() - DistanceFromEdge, ScreenHeight() - DistanceFromEdge, BoundaryPixel);
}