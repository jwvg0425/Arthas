#include "LinearMissile.h"
#include "Utils.h"
#include <math.h>
#define PIE 3.141592

USING_NS_CC;

bool LinearMissile::init()
{
	if (!Missile::init())
	{
		return false;
	}

	m_Type = OT_LINEAR_MISSILE;
	
	m_MainSprite = Sprite::create();
	auto animation = UtilFunctions::createAnimation("LinearMissile", 0, 10, 0.1);
	m_Animations[0] = animation;
	m_MainSprite->runAction(RepeatForever::create(Animate::create(m_Animations[0])));
	
	this->addChild(m_MainSprite);

	this->scheduleUpdate();
	return true;
}

void LinearMissile::collisionOccured(InteractiveObject* enemy, Directions dir)
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

void LinearMissile::setMoveAttribute(bool m_IsPlayerMissile, float velocity, float degree)
{
	if (velocity < 0)
	{
		m_MainSprite->setFlippedX(true);
	}
	m_Degree = degree;
	m_Velocity.x = cos(PIE / 180 * degree)*velocity;
	m_Velocity.y = sin(PIE / 180 * degree)*abs(velocity);
}

void LinearMissile::update(float dTime)
{
	Point pos = this->getPosition();
	pos.x += m_Velocity.x * dTime;
	pos.y += m_Velocity.y * dTime;

	this->setPosition(pos);
}

