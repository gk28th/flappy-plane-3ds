#include "tower.h"
#include <cstdlib>

constexpr int screenWidth{400};
constexpr int screenHeight{240};
constexpr int spriteWidth{47};
constexpr int spriteHeight{240};

Tower::Tower(C2D_Sprite* sprite1, C2D_Sprite* sprite2, int offset)
    : m_spriteTop{sprite1}
	, m_spriteBottom{sprite2}
	, m_towerGap{100}
    , m_towerSpeed{1}
     
{
    m_spriteTop->params.pos.x += offset;
    m_spriteBottom->params.pos.x = m_spriteTop->params.pos.x;
    srand(time(NULL));
}

void Tower::generateTower()
{
    if ((m_spriteTop->params.pos.x <= -spriteWidth || m_spriteBottom->params.pos.x <= -spriteWidth) || (m_spriteTop->params.pos.x >= 400 || m_spriteBottom->params.pos.x >= 400))
    {
        m_spriteTop->params.pos.y = -(rand() % 190 + 50);
        m_spriteBottom->params.pos.y = m_spriteTop->params.pos.y + spriteHeight + m_towerGap;
    }    
}

void Tower::moveTower()
{
    if (m_spriteTop->params.pos.x <= -spriteWidth)
    {
        m_spriteTop->params.pos.x = 493;
        m_spriteBottom->params.pos.x = m_spriteTop->params.pos.x;
    }
    else
    {
    m_spriteTop->params.pos.x -= m_towerSpeed;
    m_spriteBottom->params.pos.x = m_spriteTop->params.pos.x;
    }
}