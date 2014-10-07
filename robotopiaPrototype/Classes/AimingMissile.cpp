#include "AimingMissile.h"
#include <math.h>

USING_NS_CC;

bool AimingMissile::init()
{
	if (!Missile::init())
	{
		return false;
	}
	

	//this->addChild(Sprite);
	this->scheduleUpdate();
}



void AimingMissile::setMoveAttribute(bool m_IsPlayerMissile, float velocity, Point myPos, Point targetPos)
{

	if (velocity < 0)
	{
		m_MainSprite->setFlippedX(true);
	}

	float distance = sqrt((myPos.x - targetPos.x)*(myPos.x - targetPos.x) + (myPos.y - targetPos.y) * (myPos.y - targetPos.y));

	if (distance != 0)
	{
		m_Vx = ((myPos.x - targetPos.x) / distance) * velocity;
		m_Vy = ((myPos.x - targetPos.x) / distance) * velocity;
	}
	else
	{
		m_Vx = velocity;
		m_Vy = 0;
	}
}

void AimingMissile::update(float dTime)
{
	Point pos = this->getPosition();

	pos.x += m_Vx;
	pos.y += m_Vy;

	this->setPosition(pos);
}

