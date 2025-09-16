//
// Created by penny on 16/09/25.
//

#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include "TVector2D.h"


class SnakeGame
{
public:
    SnakeGame() = default;
    SnakeGame(int InLength, int InScore);
    TVector2D<float> GetPosition() const;
    int GetLength() const;
    int GetScore() const;

private:
    TVector2D<float> Position = { 0,0 };
    int Length = 0;
    int Score = 0;
};



#endif //SNAKEGAME_H
