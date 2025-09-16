//
// Created by penny on 16/09/25.
//
#define OLC_PGE_APPLICATION
#include "GameJamWorld.h"
#include "GlobalConstants.h"

int main()
{

    std::cout << "Hello World!" << std::endl;

    if (GameJamWorld Game; Game.Construct(SCREEN_WIDTH, SCREEN_HEIGHT, PIXEL_SIZE, PIXEL_SIZE))
    {
        Game.Start();
    }
    return 0;
}