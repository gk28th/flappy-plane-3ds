#include <citro2d.h>

#ifndef PLANE_H
#define PLANE_H

class Plane
{
private:
    C2D_Sprite* m_sprite{};
    float m_jump_force{};
    float m_gravity_force{};
    float m_max_velocity{};
    bool m_rising{};
    float m_yVelocity{};

public:
    Plane(C2D_Sprite* sprite);
    void planeJump();
};

#endif