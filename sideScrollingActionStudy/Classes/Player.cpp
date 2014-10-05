#include "Player.h"
#include "UtilFunction.h"

USING_NS_CC;


bool Player::init()
{
	InteractiveObject::init();

	m_IsRightDirection = false;
	m_KeyState = 0;
	m_MoveSpeed = 300;
	m_Vx = 0;
	m_Vy = 0;
	m_Type = OT_PLAYER;
	m_IsFlying = true;
	m_IsOnGravity = true;

	m_AnimationNum = PL_STATE_NUM;

	m_Animations[PL_STAND] = UtilFunction::makeAnimation("stand", 1, 9, 0.1f);
	m_Animations[PL_WALK] = UtilFunction::makeAnimation("walk", 1, 12, 0.1f);
	m_Animations[PL_JUMP_READY] = UtilFunction::makeAnimation("jump_ready", 1, 4, 0.1f);
	m_Animations[PL_JUMP_UP] = UtilFunction::makeAnimation("jump_up", 1, 1, 0.1f);
	m_Animations[PL_JUMP_DOWN] = UtilFunction::makeAnimation("jump_down", 1, 1, 0.1f);
	m_Animations[PL_LAND] = UtilFunction::makeAnimation("land", 1, 4, 0.1f);

	for (int i = 0; i < PL_STATE_NUM; i++)
	{
		m_Animations[i]->retain();
	}

	m_MainSprite = Sprite::create();
	m_MainSprite->setAnchorPoint(Point(0.35, 0.35));
	changeState(PL_STAND);
	this->addChild(m_MainSprite);

	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	this->scheduleUpdate();

	return true;
}

void Player::update(float dTime)
{
	Point pos = this->getPosition();

	if (m_IsRightDirection)
	{
		m_MainSprite->setFlippedX(true);
	}
	else
	{
		m_MainSprite->setFlippedX(false);
	}

	pos.x += m_Vx * dTime;
	pos.y += m_Vy * dTime;

	this->setPosition(pos);

	CCLOG("X = %f, Y= %f, Vx = %f, Vy = %f",pos.x, pos.y, m_Vx, m_Vy);

	//jump중
	if (m_Vy!=0)
	{
		if (m_Vy < 0)
		{
			changeState(PL_JUMP_DOWN);
		}
		else
		{
			changeState(PL_JUMP_UP);
		}

		//공중에선 좌우 이동 조금 느림
		if (m_IsRightDirection && m_KeyState & KS_RIGHT)
		{
			m_Vx = m_MoveSpeed/2;
		}
		else if (!m_IsRightDirection && m_KeyState & KS_LEFT)
		{
			m_Vx = -m_MoveSpeed/2;
		}
		else
		{
			m_Vx = 0;
		}
	}
	else
	{
		//착지 모션, 점프 준비 모션일 때는 기타 행동 수행 불가
		if (!(m_State == PL_LAND || m_State == PL_JUMP_READY))
		{

			if (m_IsRightDirection && m_KeyState & KS_RIGHT)
			{
				changeState(PL_WALK);
				m_Vx = m_MoveSpeed;
			}
			else if (!m_IsRightDirection && m_KeyState & KS_LEFT)
			{
				changeState(PL_WALK);
				m_Vx = -m_MoveSpeed;
			}
			else
			{
				m_Vx = 0;
				changeState(PL_STAND);
			}
		}
		else
		{
			m_Vx = 0;
		}
	}

	m_Vy -= GRAVITY*dTime;
	m_IsFlying = true;
}

void Player::collisionOccured(InteractiveObject* enemy, CollisionDirection dir, OUT bool* isRemoving)
{
	switch (enemy->getType())
	{
	case OT_FLOOR:
		switch (dir)
		{
		case CD_BOTTOM:
			m_IsFlying = false;
			if (m_State == PL_JUMP_UP || m_State == PL_JUMP_DOWN)
			{
				changeState(PL_LAND);
			}
		case CD_TOP:
			m_Vy = 0;
			break;
		case CD_LEFT:
		case CD_RIGHT:
			m_Vx = 0;
			break;
		}
		break;
	}
	*isRemoving = false;
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

void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_KeyState |= KS_LEFT;
		m_IsRightDirection = false;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_KeyState |= KS_RIGHT;
		m_IsRightDirection = true;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		if (m_State == PL_STAND || m_State == PL_WALK || m_State == PL_LAND)
		{
			changeState(PL_JUMP_READY);
		}
		break;
	}
}

void Player::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		if (m_KeyState & KS_RIGHT)
		{
			m_IsRightDirection = true;
		}
		m_KeyState &= ~KS_LEFT;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		if (m_KeyState & KS_LEFT)
		{
			m_IsRightDirection = false;
		}
		m_KeyState &= ~KS_RIGHT;
		break;
	}
}

void Player::endAnimation(Ref* sender)
{
	if (m_State == PL_LAND)
	{
		changeState(PL_STAND);
	}

	if (m_State == PL_JUMP_READY)
	{
		changeState(PL_JUMP_UP);
		m_Vy = 400;
	}
}


cocos2d::Rect Player::getRect()
{
	m_Width = 32;
	m_Height = 62;
	
	return InteractiveObject::getRect();
}