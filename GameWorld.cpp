#include "GameWorld.h"
#include "Character.h"
#include "Actor.h"

// Local helpers to manage vectors by raw-pointer identity
namespace {
    template <class T>
    bool addUniqueByAddress(std::vector<std::shared_ptr<T>>& vec, const std::shared_ptr<T>& item)
    {
        if (!item) return false;
        T* const addr = item.get();
        auto it = std::find_if(vec.begin(), vec.end(),
                               [addr](const std::shared_ptr<T>& x) { return x.get() == addr; });
        if (it != vec.end()) return false;
        vec.push_back(item);
        return true;
    }

    template <class T>
    bool removeByAddress(std::vector<std::shared_ptr<T>>& vec, const std::shared_ptr<T>& item)
    {
        if (!item) return false;
        T* const addr = item.get();
        const auto oldSize = vec.size();
        vec.erase(std::remove_if(vec.begin(), vec.end(),
                                 [addr](const std::shared_ptr<T>& x) { return x.get() == addr; }),
                  vec.end());
        return vec.size() != oldSize;
    }
}


void GameWorld::UpdateCollisions()
{
    const auto movers = EverythingCollidableThatMoves;
    const auto collidables = EverythingCollidable;

    // Movers vs. all collidables
    for (const auto& mover : movers)
    {
        if (!mover) continue;

        for (const auto& obj : collidables)
        {
            if (!obj) continue;

            // Compare as Actor* to avoid Character* vs Actor* mismatch
            if (static_cast<const Actor*>(mover.get()) == obj.get())
                continue;

            if (CheckCollision(*mover, *obj))
            {
                mover->Collide(obj.get());
                obj->Collide(mover.get());
            }
        }
    }

    // Movers vs. movers (unique unordered pairs)
    for (std::size_t i = 0; i < movers.size(); ++i)
    {
        const auto& left = movers[i];
        if (!left) continue;

        for (std::size_t j = i + 1; j < movers.size(); ++j)
        {
            const auto& right = movers[j];
            if (!right) continue;

            if (left.get() == right.get())
                continue;

            if (CheckCollision(*left, *right))
            {
                left->Collide(right.get());
                right->Collide(left.get());
            }
        }
    }
}

void GameWorld::TickEverything(float fElapsedTime)
{
    for (const auto& actor : NonColliding)
    {
        if (actor)
            actor->Tick(fElapsedTime);
    }

    for (const auto& actor : EverythingCollidable)
    {
        if (actor)
            actor->Tick(fElapsedTime);
    }

    for (const auto& character : EverythingCollidableThatMoves)
    {
        if (character)
            character->Tick(fElapsedTime);
    }
}

bool GameWorld::CheckCollision(const Character &FirstObject, const Actor &SecondObject)
{
    const bool FirstRightOfSecond = GetLeft(FirstObject) > GetRight(SecondObject);
    const bool FirstLeftOfSecond = GetRight(FirstObject) < GetLeft(SecondObject);
    const bool FirstAboveSecond = GetDown(FirstObject) < GetUp(SecondObject);
    const bool FirstBelowSecond = GetUp(FirstObject) > GetDown(SecondObject);

    return !(FirstRightOfSecond || FirstLeftOfSecond || FirstAboveSecond || FirstBelowSecond);
}

float GameWorld::GetLeft(const Actor& Object)
{
    return Object.GetPosition().x;
}

float GameWorld::GetRight(const Actor& Object)
{
    return Object.GetPosition().x + Object.GetSpriteSize().y;
}

float GameWorld::GetUp(const Actor& Object)
{
    return Object.GetPosition().y;
}

float GameWorld::GetDown(const Actor& Object)
{
    return Object.GetPosition().y + Object.GetSpriteSize().y;
}

bool GameWorld::AddCollidable(const std::shared_ptr<Actor>& actor)
{
    return addUniqueByAddress(EverythingCollidable, actor);
}

bool GameWorld::RemoveCollidable(const std::shared_ptr<Actor>& actor)
{
    return removeByAddress(EverythingCollidable, actor);
}

bool GameWorld::AddMovingCollidable(const std::shared_ptr<Character>& character)
{
    return addUniqueByAddress(EverythingCollidableThatMoves, character);
}

bool GameWorld::RemoveMovingCollidable(const std::shared_ptr<Character>& character)
{
    return removeByAddress(EverythingCollidableThatMoves, character);
}

bool GameWorld::AddNonColliding(const std::shared_ptr<Actor>& actor)
{
    return addUniqueByAddress(NonColliding, actor);
}

bool GameWorld::RemoveNonColliding(const std::shared_ptr<Actor>& actor)
{
    return removeByAddress(NonColliding, actor);
}