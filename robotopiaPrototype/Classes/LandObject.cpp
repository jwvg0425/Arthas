#include "LandObject.h"

USING_NS_CC;

bool LandObject::init()
{
	if( !InteractiveObject::init() )
	{
		return false;
	}
	m_LandType = LT_OBJECT;
	m_IsOnGravity = false;
	m_PieceSprite = Sprite::create();
	return true;
}

