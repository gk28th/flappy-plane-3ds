#include "plane.h"
#include <citro2d.h>

Plane::Plane(C2D_Sprite* sprite) // defualt values
	: m_sprite {sprite}
	, m_jump_force {8.0f}
	, m_gravity_force {0.5f}
	, m_max_velocity {12.0f}
{
}
void Plane::planeJump()
{
    hidScanInput();
	u32 kDown = hidKeysDown();
		
	if((kDown & KEY_B) && !m_rising && m_sprite->params.pos.y > -50)
	{
		m_rising = true;
		m_yVelocity = -m_jump_force;
	} 		
	m_rising = false;
			
	// velocity when decending
	if(m_sprite->params.pos.y < 200 && !m_rising) 
		if (m_yVelocity < m_max_velocity) 
			m_yVelocity += m_gravity_force;
			
	// in case something unexpected happens
	if(m_sprite->params.pos.y > 200)
	{
		m_sprite->params.pos.y = 200;
		m_rising = false;
		m_yVelocity = 0.0f;
	} 
		
	// add velocity to y pos of the sprite
	m_sprite->params.pos.y += m_yVelocity;
}