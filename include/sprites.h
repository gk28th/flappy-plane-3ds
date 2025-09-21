#pragma once
#ifndef SPRITES_H
#define SPRITES_H

#include <citro2d.h>

namespace sprites
{
    extern C2D_SpriteSheet spriteSheet;
    extern C2D_Sprite planeSprite;
    extern C2D_Sprite towerSprite[5];
    extern C2D_Sprite bgSprite[2];
    extern constexpr int towerWidth{47};
    extern constexpr int towerHeight{240};
    extern constexpr int planeWidth{47};
    extern constexpr int planeHeight{240};
    
    void initSpriteSheet();
    void initSprites();
    void drawSprites();
    void scrollBg();
}

#endif
