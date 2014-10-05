#include "Character.h"
#include "GameScene.h"


USING_NS_CC;

bool Character::init()
{
	m_IsUnbeatable = false;
	return true;
}

bool Character::hitCheck(cocos2d::Rect enemyRect)
{
	float x = this->getPosition().x;
	float y = this->getPosition().y;
	Rect myRect = Rect(x - m_Width/2, y - m_Height/2, m_Width, m_Height);

	return myRect.intersectsRect(enemyRect);
}

bool Character::isOutOfScreen()
{
	Point pos = this->getPosition();
	if (pos.x + m_Width / 2 < 0 || pos.x - m_Width / 2 > Director::getInstance()->getWinSize().width ||
		pos.y + m_Height / 2 < 0 || pos.y - m_Height / 2 > Director::getInstance()->getWinSize().height)
	{
		return true;
	}

	return false;
}

bool Character::collisionOccured(const Character* enemy)
{
	return false;
}
