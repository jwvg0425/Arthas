#include "LandObject.h"

USING_NS_CC;

bool LandObject::init()
{
	if( !InteractiveObject::init() )
	{
		return false;
	}
	m_IsOnGravity = false;
	m_PieceSprite = nullptr;
	return true;
}



