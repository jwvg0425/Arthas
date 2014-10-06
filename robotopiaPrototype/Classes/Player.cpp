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
}

