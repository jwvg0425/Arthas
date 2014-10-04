#include "Monster.h"
#include "GameScene.h"
#include "Bullet.h"

USING_NS_CC;


bool Monster::init()
{
	Character::init();
	m_Type = ENEMY;
	m_Hp = 1;

	return true;
}

bool Monster::collisionOccured(const Character* enemy)
{
	if (enemy->getType() == BULLET)
	{
		Bullet* bullet = (Bullet*)enemy;

		if (bullet->IsPlayersBullet())
		{
			m_Hp--;
			if (m_Hp <= 0)
			{
				return true;
			}
		}
	}

	return false;
}
