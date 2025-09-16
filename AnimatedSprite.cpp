//
// Created by penny on 14/09/25.
//

#include "AnimatedSprite.h"
#include "olcPixelGameEngine.h"
#include "GlobalConstants.h"
#include "GameJamWorld.h"
#include <memory>

AnimatedSprite::AnimatedSprite(const std::shared_ptr<olc::Sprite>& Tiles, const EAnimationType Type, const FAnimSequence& Sequence)
    : SpriteSheet(Tiles), AnimationType(Type), AnimationSequence(const_cast<FAnimSequence&>(Sequence))
{
}

void AnimatedSprite::Draw(float fElapsedTime, const olc::vf2d InPosition) const
{
    const olc::vf2d DrawLocation = { InPosition.x, InPosition.y };
    const olc::vi2d FrameOffset  = { AnimationSequence.FirstFrameOffset.x, AnimationSequence.FirstFrameOffset.y };
    const olc::vi2d Size         = { AnimationSequence.SpriteSize.x,      AnimationSequence.SpriteSize.y      };

    for (int NumberOfTiles = 0; NumberOfTiles < AnimationSequence.SquareTiles * AnimationSequence.SquareTiles; ++NumberOfTiles)
    {
        olc::vi2d UpdatedOffset = {
            FrameOffset.x + (NumberOfTiles % AnimationSequence.SquareTiles) * (AnimationSequence.SpriteSize.x + SpriteSheetGapOffset),
            FrameOffset.y + (NumberOfTiles / AnimationSequence.SquareTiles) * (AnimationSequence.SpriteSize.y + SpriteSheetGapOffset)
        };

        olc::vf2d UpdatedDrawLocation = {
            DrawLocation.x + (NumberOfTiles % AnimationSequence.SquareTiles) * AnimationSequence.SpriteSize.x * PIXEL_SIZE,
            DrawLocation.y + (NumberOfTiles / AnimationSequence.SquareTiles) * AnimationSequence.SpriteSize.y * PIXEL_SIZE
        };

        GameJamWorld::Instance->DrawPartialSprite(UpdatedDrawLocation, SpriteSheet.get(), UpdatedOffset, Size, AnimationSequence.SpriteScale);
    }
}

olc::vi2d AnimatedSprite::GetSpriteSize() const
{
    const olc::vi2d ReturnVector = {
        AnimationSequence.SpriteSize.x * AnimationSequence.SpriteScale * AnimationSequence.SquareTiles + (AnimationSequence.SquareTiles - SpriteSheetGapOffset),
        AnimationSequence.SpriteSize.y * AnimationSequence.SpriteScale * AnimationSequence.SquareTiles + (AnimationSequence.SquareTiles - SpriteSheetGapOffset)
    };
    return ReturnVector;
}

void AnimatedSprite::EditAnimSequence(const olc::vi2d& NewOffset, const olc::vi2d& NewSize, const int NewNumFrames, const float NewDuration) const
{
    AnimationSequence.FirstFrameOffset = NewOffset;
    AnimationSequence.SpriteSize       = NewSize;
    AnimationSequence.NumberOfFrames   = NewNumFrames;
    AnimationSequence.Duration         = NewDuration;
}

void AnimatedSprite::EditAnimSequence(const olc::vi2d& NewOffset) const
{
    AnimationSequence.FirstFrameOffset = NewOffset;
}
