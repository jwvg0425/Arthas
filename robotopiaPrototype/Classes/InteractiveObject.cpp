#include "InteractiveObject.h"

USING_NS_CC;

bool InteractiveObject::init()
{
	if (!Node::init())
	{
		return false;
	}

	m_MainSprite = nullptr;
	m_AnimationNum = 0;
	m_Width = 0;
	m_Height = 0;
	m_Type = OT_OBJECT;
	m_Velocity = Vec2(0, 0);
	m_IsOnGravity = true;
	m_MoveSpeed = 0;

	return true;
}

Direction InteractiveObject::collisionCheck(InteractiveObject* enemy, float dTime)
{

	return DIR_NONE;
}

cocos2d::Rect InteractiveObject::getRect()
{
	Point pos = this->getPosition();
	Point Anchor = this->getAnchorPoint();

	return Rect(pos.x - Anchor.x*m_Width, pos.y - Anchor.y*m_Height, m_Width, m_Height);
}

cocos2d::Vec2 InteractiveObject::getVelocity() const
{
	return m_Velocity;
}
