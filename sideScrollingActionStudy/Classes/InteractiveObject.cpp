#include "InteractiveObject.h"

USING_NS_CC;

bool InteractiveObject::init()
{
	return true;
}

cocos2d::Rect InteractiveObject::getSize() const
{
	Point pos = this->getPosition();

	return Rect(pos.x - m_Width / 2, pos.y - m_Height / 2, m_Width, m_Height);
}
