#include "TileObject.h"

bool TileObject::init()
{
	InteractiveObject::init();
	m_Vx = 0;
	m_Vy = 0;
	m_IsOnGravity = false;
	return true;
}
