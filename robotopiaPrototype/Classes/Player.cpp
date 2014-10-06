#include "Player.h"

USING_NS_CC;

bool Player::init()
{
	if (!InteractiveObject::init())
	{
		return false;
	}

	m_Type = OT_PLAYER;
	m_MoveSpeed = 300;
	m_AnimationNum = PS_STATE_NUM;
	m_Animations[PS_STAND] = UtilFunctions::createAnimation("player_stand", 1, 4, 0.1f);
	m_Animations[PS_WALK] = UtilFunctions::createAnimation("player_walk", 1, 8, 0.1f);
	m_Animations[PS_JUMP] = UtilFunctions::createAnimation("player_jump", 1, 1, 0.1f);
	m_Animations[PS_ATTACK] = UtilFunctions::createAnimation("player_attack", 1, 5, 0.1f);

	this->scheduleUpdate();

	return true;
}

void Player::collisionOccured(InteractiveObject* enemy, Direction dir, OUT bool * isRemoving)
{

}

void Player::update(float dTime)
{
	Point pos = this->getPosition();
	//키 상태에 따른 처리

	if (KeyStateManager::getKeyState(KC_RIGHT) == KS_HOLD)
	{
		pos.x += m_MoveSpeed*dTime;
	}
	else if (KeyStateManager::getKeyState(KC_LEFT) == KS_HOLD)
	{
		pos.x -= m_MoveSpeed*dTime;
	}

	this->setPosition(pos);
}

