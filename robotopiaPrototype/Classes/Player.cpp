#include "Player.h"

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
	m_Animations[PS_STAND] = UtilFunctions::createAnimation("player_stand", 1, 4, 0.1f);
	m_Animations[PS_WALK] = UtilFunctions::createAnimation("player_walk", 1, 8, 0.1f);
	m_Animations[PS_JUMP] = UtilFunctions::createAnimation("player_jump", 1, 1, 0.1f);
	m_Animations[PS_ATTACK] = UtilFunctions::createAnimation("player_attack", 1, 5, 0.1f);
	m_IsRightDirection = true;

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

void Player::collisionOccured(InteractiveObject* enemy, Direction dir, OUT bool * isRemoving)
{

}

void Player::update(float dTime)
{
	Point pos = this->getPosition();

	pos.x += m_Velocity.x*dTime;
	pos.y += m_Velocity.y*dTime;

	
	//키 상태에 따른 처리
	KeyState leftState = KeyStateManager::getKeyState(KC_LEFT);
	KeyState rightState = KeyStateManager::getKeyState(KC_RIGHT);

	if (leftState == KS_HOLD)
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

}
