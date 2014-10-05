#include "Player.h"
#include "UtilFunction.h"

USING_NS_CC;


bool Player::init()
{
	InteractiveObject::init();

	m_IsRightDirection = false;
	m_KeyState = 0;
	m_State = PL_STAND;

	m_AnimationNum = PL_STATE_NUM;

	m_Animations[PL_STAND] = UtilFunction::makeAnimation("stand", 1, 9, 0.1f);
	m_Animations[PL_WALK] = UtilFunction::makeAnimation("walk", 1, 12, 0.1f);
	m_Animations[PL_JUMP_READY] = UtilFunction::makeAnimation("jump_ready", 1, 4, 0.1f);
	m_Animations[PL_JUMP_UP] = UtilFunction::makeAnimation("jump_up", 1, 1, 0.1f);
	m_Animations[PL_JUMP_HIGH] = UtilFunction::makeAnimation("jump_high", 1, 3, 0.1f);
	m_Animations[PL_JUMP_DOWN] = UtilFunction::makeAnimation("jump_down", 1, 1, 0.1f);
	m_Animations[PL_LAND] = UtilFunction::makeAnimation("land", 1, 4, 0.1f);

	for (int i = 0; i < PL_STATE_NUM; i++)
	{
		m_Animations[i]->retain();
	}

	m_MainSprite = Sprite::create();
	m_MainSprite->setAnchorPoint(Point(0.5, 0.5));
	m_MainSprite->runAction(RepeatForever::create(Animate::create(m_Animations[PL_STAND])));
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
	bool isMoving = false;

	if (m_IsRightDirection)
	{
		m_MainSprite->setFlippedX(true);
	}
	else
	{
		m_MainSprite->setFlippedX(false);
	}

	if (m_KeyState & KS_RIGHT)
	{
		if (m_IsRightDirection)
		{
			pos.x += 6;
			isMoving = true;
		}
		else if (!(m_KeyState & KS_LEFT))
		{
			m_IsRightDirection = true;
		}
	}
	if (m_KeyState & KS_LEFT)
	{
		if (!m_IsRightDirection)
		{
			pos.x -= 6;
			isMoving = true;
		}
		else if (!(m_KeyState & KS_RIGHT))
		{
			m_IsRightDirection = false;
		}
	}

	if (m_State == PL_STAND && isMoving)
	{
		changeState(PL_WALK);
	}

	if (m_State == PL_WALK && !isMoving)
	{
		changeState(PL_STAND);
	}

	this->setPosition(pos);
}

bool Player::collisionOccured(InteractiveObject* enemy)
{
	return true;
}

void Player::changeState(State state)
{
	m_State = state;
	m_MainSprite->stopAllActions();
	m_MainSprite->runAction(RepeatForever::create(Animate::create(m_Animations[state])));
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
	}

}

void Player::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_KeyState &= ~KS_LEFT;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_KeyState &= ~KS_RIGHT;
		break;
	}
}
