//
// Created by penny on 14/09/25.
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <memory>

#include "GlobalConstants.h"
#include "olcPixelGameEngine.h"
#include "TVector2D.h"

enum class EAnimationType
{
    STILL,
    LOOP_ONCE,
    LOOP_FOREVER
};

struct FAnimSequence
{
    olc::vi2d FirstFrameOffset = { 0,0 };
    olc::vi2d SpriteSize = { SpriteSizeConst , SpriteSizeConst };
    int NumberOfFrames = 4;
    float Duration = 4.f;
    int SpriteScale = 2;
    int SquareTiles = 1;
};

class AnimatedSprite
{
public:
    AnimatedSprite(const std::shared_ptr<olc::Sprite>& Tiles, EAnimationType Type, const FAnimSequence& Sequence);
    void Draw(float fElapsedTime, olc::vf2d InPosition) const;
    olc::vi2d GetSpriteSize() const;
    void EditAnimSequence(const olc::vi2d& NewOffset, const olc::vi2d& NewSize, int NewNumFrames, float NewDuration) const;
    void EditAnimSequence(const olc::vi2d& NewOffset) const;

protected:
    const std::shared_ptr<olc::Sprite>& SpriteSheet;
    EAnimationType AnimationType;
    FAnimSequence& AnimationSequence;
    float AnimStartTime = 0.f;
    int PreviousFrame = 0;
};

#endif //ANIMATEDSPRITE_H
