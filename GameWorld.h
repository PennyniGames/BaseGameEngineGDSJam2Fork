//
// Created by penny on 14/09/25.
//

#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "olcPixelGameEngine.h"
#include <memory>
#include <vector>

class Actor;
class Character;

class GameWorld : public olc::PixelGameEngine
{
public:
    virtual void UpdateCollisions();
    virtual void TickEverything(float fElapsedTime);

    // Safe add/remove for collidable actors
    bool AddCollidable(const std::shared_ptr<Actor>& actor);
    bool RemoveCollidable(const std::shared_ptr<Actor>& actor);

    // Safe add/remove for moving collidable characters
    bool AddMovingCollidable(const std::shared_ptr<Character>& character);
    bool RemoveMovingCollidable(const std::shared_ptr<Character>& character);

    // Safe add/remove for non-colliding actors
    bool AddNonColliding(const std::shared_ptr<Actor>& actor);
    bool RemoveNonColliding(const std::shared_ptr<Actor>& actor);

protected:
    std::vector<std::shared_ptr<Actor>> EverythingCollidable = {};
    std::vector<std::shared_ptr<Character>> EverythingCollidableThatMoves = {};
    std::vector<std::shared_ptr<Actor>> NonColliding = {};

    std::shared_ptr<olc::Sprite> Tileset = {};

    static bool CheckCollision(const Character& FirstObject, const Actor& SecondObject);

    static float GetLeft(const Actor& Object);

    static float GetRight(const Actor& Object);

    static float GetUp(const Actor& Object);

    static float GetDown(const Actor& Object);
};

#endif //GAMEWORLD_H