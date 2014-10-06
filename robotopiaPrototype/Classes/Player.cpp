#include "Player.h"

USING_NS_CC;

bool Player::init()
{
	if (!InteractiveObject::init())
	{
		return false;
	}

	m_Type = OT_PLAYER;

	this->scheduleUpdate();

	return true;
}

void Player::collisionOccured(InteractiveObject* enemy, Direction dir, OUT bool * isRemoving)
{

}

void Player::update(float dTime)
{
	//키 상태에 따른 처리

	if (KeyStateManager::getKeyState(EventKeyboard::KeyCode::KEY_RIGHT_ARROW) == KS_HOLD)
	{
	}
}

