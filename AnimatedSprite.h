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
    TVector2D<int> FirstFrameOffset = { 0,0 };
    TVector2D<int> SpriteSize = { SpriteSizeConst , SpriteSizeConst };
    int NumberOfFrames = 4;
    float Duration = 4.f;
    int SpriteScale = 2;
    int SquareTiles = 1;
};

class AnimatedSprite
{
public:
    AnimatedSprite(const std::shared_ptr<olc::Sprite>& Tiles, EAnimationType Type, const FAnimSequence& Sequence);
    void Draw(float fElapsedTime, TVector2D<float> InPosition);
    TVector2D<int> GetSpriteSize() const;
    void EditAnimSequence(TVector2D<int>& NewOffset, TVector2D<int>& NewSize, int NewNumFrames, float NewDuration);
    void EditAnimSequence(TVector2D<int>& NewOffset);

protected:
    const std::shared_ptr<olc::Sprite>& TileSet;
    EAnimationType AnimationType;
    FAnimSequence& AnimationSequence;
    float AnimStartTime = 0.f;
    int PreviousFrame = 0;
};

#endif //ANIMATEDSPRITE_H
