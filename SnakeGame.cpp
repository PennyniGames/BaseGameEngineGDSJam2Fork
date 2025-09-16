//
// Created by penny on 16/09/25.
//

#include "SnakeGame.h"

SnakeGame::SnakeGame(const int InLength, const int InScore) : Length(InLength), Score(InScore)
{
}

TVector2D<float> SnakeGame::GetPosition() const
{
    return Position;
}

int SnakeGame::GetLength() const
{
    return Length;
}

int SnakeGame::GetScore() const
{
    return Score;
}
