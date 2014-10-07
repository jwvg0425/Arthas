#include "Player.h"
#include "GameLayer.h"
#include "LinearMissile.h"

USING_NS_CC;

bool Player::init()
{
	if (!InteractiveObject::init())
	{
		return false;
	}

	m_Type = OT_PLAYER;
	m_MoveSpeed = 100;
	m_AnimationNum = PS_STATE_NUM;
	m_Animations[PS_STAND] = UtilFunctions::createAnimation("player_stand", 1, 4, 0.05f);
	m_Animations[PS_WALK] = UtilFunctions::createAnimation("player_walk", 1, 8, 0.05f);
	m_Animations[PS_JUMP] = UtilFunctions::createAnimation("player_jump", 1, 1, 0.1f);
	m_Animations[PS_ATTACK] = UtilFunctions::createAnimation("player_attack", 1, 5, 0.05f);
	m_IsRightDirection = true;

	m_MaxHp = 100;
	m_Hp = m_MaxHp;

	m_MaxSteam = 100;
	m_Steam = m_MaxSteam;

	for (int i = 0; i < PS_STATE_NUM; i++)
	{
		m_Animations[i]->retain();
	}

	m_MainSprite = Sprite::create();

	changeState(PS_STAND);

	this->addChild(m_MainSprite);
	this->scheduleUpdate();

	return true;
}

void Player::collisionOccured(InteractiveObject* enemy, Directions dir)
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

void Player::update(float dTime)
{
	Point pos = this->getPosition();


	//좌표 변경 처리
	pos.x += m_Velocity.x*dTime;
	pos.y += m_Velocity.y*dTime;

	
	//키, 상태 처리
	KeyState leftState = KeyStateManager::getKeyState(KC_LEFT);
	KeyState rightState = KeyStateManager::getKeyState(KC_RIGHT);
	
	if (m_IsFlying)
	{
		changeState(PS_JUMP);

		if (leftState == KS_HOLD)
		{
			m_Velocity.x = -m_MoveSpeed;
			m_IsRightDirection = false;
			m_MainSprite->setFlippedX(true);

		}
		else if (rightState == KS_HOLD)
		{
			m_Velocity.x = m_MoveSpeed;
			m_IsRightDirection = true;
			m_MainSprite->setFlippedX(false);
		}
		else
		{
			m_Velocity.x = 0;
		}
	}
	else
	{
		if (KeyStateManager::getKeyState(KC_ATTACK) && (m_State == PS_STAND || m_State == PS_WALK))
		{
			changeState(PS_ATTACK);
			m_Velocity.x = 0;
		}

		if (m_State != PS_ATTACK)
		{
			if (KeyStateManager::getKeyState(KC_JUMP))
			{
				m_Velocity.y = 400;
			}
			else if (leftState == KS_HOLD)
			{
				changeState(PS_WALK);
				m_Velocity.x = -m_MoveSpeed;
				m_IsRightDirection = false;
				m_MainSprite->setFlippedX(true);

			}
			else if (rightState == KS_HOLD)
			{
				changeState(PS_WALK);
				m_Velocity.x = m_MoveSpeed;
				m_IsRightDirection = true;
				m_MainSprite->setFlippedX(false);
			}
			else
			{
				changeState(PS_STAND);
				m_Velocity.x = 0;
			}
		}

		if (m_State == PS_ATTACK)
		{
		}
	}

	m_Velocity.y -= GRAVITY*dTime;
	m_IsFlying = true;

	this->setPosition(pos);
}

void Player::changeState(State state)
{
	//이미 해당 상태인 경우 아무 처리도 하지 않는다.
	if (m_State == state)
	{
		return;
	}
	m_State = state;
	m_MainSprite->stopAllActions();

	auto animate = Animate::create(m_Animations[state]);
	auto callfunc = CallFuncN::create(CC_CALLBACK_1(Player::endAnimation, this));
	auto sequence = Sequence::create(animate, callfunc, NULL);

	m_MainSprite->runAction(RepeatForever::create(sequence));
}

void Player::endAnimation(cocos2d::Ref* sender)
{
	if (m_State == PS_ATTACK)
	{
		auto gameLayer = (GameLayer*)this->getParent();

		auto object = (LinearMissile*)gameLayer->addObject(OT_LINEAR_MISSILE, this->getPosition());

		if (m_IsRightDirection)
		{	
			object->setMoveAttribute(true, 200, 0);
		}
		else
		{
			object->setMoveAttribute(true, -200, 0);
		}
		changeState(PS_STAND);
	}
}

cocos2d::Rect Player::getRect()
{
	m_Width = m_MainSprite->getContentSize().width;
	m_Height = m_MainSprite->getContentSize().height;

	return InteractiveObject::getRect();
}
