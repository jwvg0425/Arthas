#include "AimingMissile.h"
#include <math.h>

USING_NS_CC;

bool AimingMissile::init()
{
	if (!Missile::init())
	{
		return false;
	}
	m_Type = OT_AIMING_MISSILE;

	m_MainSprite = Sprite::create();
	auto animation = UtilFunctions::createAnimation("AimingMissile", 1, 8, 0.1f);
	m_Animations[0] = animation;
	m_MainSprite->runAction(RepeatForever::create(Animate::create(m_Animations[0])));

	this->addChild(m_MainSprite);

	
	this->scheduleUpdate();

	return true;
}



void AimingMissile::setMoveAttribute(bool m_IsPlayerMissile, float velocity, Point myPos, Point targetPos)
{
	float distance = sqrt((myPos.x - targetPos.x)*(myPos.x - targetPos.x) + (myPos.y - targetPos.y) * (myPos.y - targetPos.y));

	if (distance != 0)
	{
		m_Velocity.x = ((targetPos.x - myPos.x) / distance) * velocity;
		m_Velocity.y = ((targetPos.y - myPos.y) / distance) * velocity;
	
	}
	else
	{
		m_Velocity.x = velocity;
		m_Velocity.y = 0;
	}

	if (m_Velocity.x > 0)
	{
		m_MainSprite->setFlippedX(true);
	}
}

void AimingMissile::update(float dTime)
{
	Point pos = this->getPosition();

	pos.x += m_Velocity.x * dTime;
	pos.y += m_Velocity.y * dTime;

	this->setPosition(pos);
}

void AimingMissile::collisionOccured(InteractiveObject* enemy, Directions dir)
{
	m_IsPlayerMissile = IsPlayerMissile();

	//case는 누구랑 부딪혔는지를 말함

	switch (enemy->getType())
	{
	case OT_PLAYER:
		if (!m_IsPlayerMissile)
		{
			//몬스터가 플레이어 맞춘 효과 넣고 
			m_IsDestroyed = true;
		}
		break;
	case OT_FLOOR:

		m_IsDestroyed = true;
		break;
	case OT_BLOCK:

		m_IsDestroyed = true;
		break;
	case OT_MISSILE:
		break;
	case OT_LINEAR_MISSILE:
		
		break;
	case OT_MONSTER:
		if (m_IsPlayerMissile)
		{

			//플레이어가 몬스터 맞춘 효과 넣고
			m_IsDestroyed = true;
		}
		break;
	case OT_RUSH_MONSTER:
		if (m_IsPlayerMissile)
		{
			//플레이어가 몬스터 맞춘 효과 넣고
			m_IsDestroyed = true;
		}
		break;
	case OT_VILLAGER:

		m_IsDestroyed = true;
		break;
	default:
		break;
	}

	return;
}

