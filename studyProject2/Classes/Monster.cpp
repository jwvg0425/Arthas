#include "Monster.h"
#include "GameScene.h"
#include "Bullet.h"

USING_NS_CC;


bool Monster::init()
{
	m_Type = ENEMY;
	m_CollisionKind = PLAYER | BULLET;

	return true;
}

bool Monster::collisionOccured(Character* enemy)
{
	switch (enemy->getType())
	{
	case BULLET:
		if (((Bullet*)enemy)->getCollisionKind() & ENEMY)
		{
			((GameScene*)this->getParent())->removeCharacter(this);
			return true;
		}
		break;
	case PLAYER:
		((GameScene*)this->getParent())->removeCharacter(this);
		return true;
	}

	return false;
}
