#pragma once
#ifndef TOWER_H
#define TOWER_H

#include <citro2d.h>

class Tower
{
private:
    C2D_Sprite* m_spriteTop{};
    C2D_Sprite* m_spriteBottom{};
    int m_towerGap{};
    int m_towerSpeed{};
    
public:
    Tower(C2D_Sprite* sprite1, C2D_Sprite* sprite2, int offset);
    void generateTower();
    void moveTower();
};

#endif