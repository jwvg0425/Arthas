#include "Bullet.h"
#include "GameScene.h"
#include "Effect.h"
#include "Player.h"

USING_NS_CC;

bool Bullet::init()
{
	Character::init();
	m_Type = BULLET;
	return true;
}

bool Bullet::collisionOccured(const Character* enemy)
{
	if (m_IsPlayersBullet)
	{
		if (enemy->getType() == ENEMY)
		{
			EffectManager* effectManager = (EffectManager*)this->getParent()->getChildByTag(EFFECT_MANAGER_TAG);
			effectManager->createEffect(EffectManager::BULLET_EFFECT, this->getPosition());
			return true;
		}
	}
	else
	{
		if (enemy->getType() == PLAYER)
		{
			EffectManager* effectManager = (EffectManager*)this->getParent()->getChildByTag(EFFECT_MANAGER_TAG);
			effectManager->createEffect(EffectManager::BULLET_EFFECT, this->getPosition());
			return true;
		}
	}
	return false;
}
