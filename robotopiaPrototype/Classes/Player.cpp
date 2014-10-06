#include "Player.h"


bool Player::init()
{
	if (!InteractiveObject::init())
	{
		return false;
	}

	this->scheduleUpdate();

	return true;
}

void Player::collisionOccured(InteractiveObject* enemy, Direction dir, OUT bool * isRemoving)
{

}

void Player::update(float dTime)
{

}

