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
	m_MainSprite->setAnchorPoint(Point(0.5, 0.5));
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


	//착지 모션, 점프일 때는 기타 행동 수행 불가
	if (m_State == PL_LAND || m_State == PL_JUMP_READY)
	{
		return;
	}

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

bool Player::collisionOccured(InteractiveObject* enemy)
{
	return true;
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
		m_Vy = 100;
	}
}


cocos2d::Rect Player::getRect()
{
	switch (m_State)
	{
	case PL_WALK:
		m_Width = 48;
		m_Height = 58;
		break;
	default:
		m_Width = 32;
		m_Height = 62;
		break;
	}
	return InteractiveObject::getRect();
}

bool Player::collisionCheck(InteractiveObject* enemy)
{
	return false;
}
