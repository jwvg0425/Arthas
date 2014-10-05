#include "InteractiveObject.h"

USING_NS_CC;

bool InteractiveObject::init()
{
	return true;
}

cocos2d::Rect InteractiveObject::getRect() const
{
	Point pos = this->getPosition();

	return Rect(pos.x - m_Width / 2, pos.y - m_Height / 2, m_Width, m_Height);
}

void InteractiveObject::setOuterForce(cocos2d::Vec2 OuterForce)
{
	m_Vx += OuterForce.x;
	m_Vy += OuterForce.y;

	m_PrevOuterForce = OuterForce;
}

cocos2d::Vec2 InteractiveObject::getVelcotiy() const
{
	return Vec2(m_Vx, m_Vy);
}
