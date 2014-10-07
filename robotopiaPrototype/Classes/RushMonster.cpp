#include "RushMonster.h"

USING_NS_CC;

bool RushMonster::init()
{
	if (!Monster::init())
	{
		return false;
	}

	m_Type = OT_RUSH_MONSTER;

	m_Animations[RM_STAND] = UtilFunctions::createAnimation("rushMonster_stand", 1, 4, 0.1f);
	m_Animations[RM_MOVE] = UtilFunctions::createAnimation("rushMonster_move", 1, 4, 0.1f);
	m_Animations[RM_RUSH] = UtilFunctions::createAnimation("rushMonster_rush", 1, 4, 0.1f);
	
	for (int i = 0; i < RM_STATE_NUM; i++)
	{
		m_Animations[i]->retain();
	}

	m_MainSprite = Sprite::create();

	this->addChild(m_MainSprite);

	changeState(RM_STAND);

	m_DelayTime = rand() % 3 + 4;
	m_MoveSpeed = 30;
	m_IsOnGravity = true;

	this->scheduleUpdate();

	return true;
}

void RushMonster::collisionOccured(InteractiveObject* enemy, Directions dir)
{
	switch (enemy->getType())
	{
	case OT_FLOOR:
		if (dir & DIR_DOWN)
		{
			m_IsFlying = false;
			m_Velocity.y = 0;
		}
		break;
	case OT_BLOCK:
		if (dir & DIR_DOWN)
		{
			m_IsFlying = false;
			m_Velocity.y = 0;
		}
		if (dir&DIR_LEFT || dir&DIR_RIGHT)
		{
			m_Velocity.x = 0;
		}
		if (dir&DIR_UP)
		{
			m_Velocity.y = 0;
		}
		break;
	}
}

void RushMonster::changeState(State state)
{
	//이미 해당 상태인 경우 아무 처리도 하지 않는다.
	if (m_State == state)
	{
		return;
	}
	m_State = state;
	m_MainSprite->stopAllActions();

	auto animate = Animate::create(m_Animations[state]);
	auto callfunc = CallFuncN::create(CC_CALLBACK_1(RushMonster::endAnimation, this));
	auto sequence = Sequence::create(animate, callfunc, NULL);

	m_MainSprite->runAction(RepeatForever::create(sequence));
}

void RushMonster::endAnimation(cocos2d::Ref* sender)
{
}

void RushMonster::update(float dTime)
{
	m_DelayTime -= dTime;

	Point pos = this->getPosition();

	pos.x += m_Velocity.x*dTime;
	pos.y += m_Velocity.y*dTime;

	this->setPosition(pos);

	if (m_DelayTime < 0)
	{
		if (m_State == RM_STAND)
		{
			m_IsRightDirection = rand() % 2;
			m_MainSprite->setFlippedX(m_IsRightDirection);
			m_DelayTime = 2;
			m_Velocity.x = m_MoveSpeed;
			if (!m_IsRightDirection)
			{
				m_Velocity.x = -m_Velocity.x;
			}

			changeState(RM_MOVE);
		}
		else if (m_State == RM_MOVE)
		{
			m_DelayTime = 4 + rand() % 3;
			changeState(RM_STAND);
			m_Velocity.x = 0;
		}
	}

	m_Velocity.y -= GRAVITY*dTime;
	m_IsFlying = true;
}

cocos2d::Rect RushMonster::getRect()
{
	m_Width = m_MainSprite->getContentSize().width;
	m_Height = m_MainSprite->getContentSize().height;

	return InteractiveObject::getRect();
}
