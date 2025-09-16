//
// Created by penny on 14/09/25.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include "Actor.h"


class Character : public Actor
{
public:
    Character();
    void Tick(float fElapsedTime) override;
    void Draw(float fElapsedTime, olc::vf2d InLocation) const override;
    virtual void Move(float fElapsedTime) = 0;
    virtual void BounceOff() = 0;

protected:
    float TimeSinceMoved = 0.f;
    bool FirstFrameFinished = false;
};



#endif //CHARACTER_H
