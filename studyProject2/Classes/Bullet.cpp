#include "Bullet.h"
#include "GameScene.h"
#include "Effect.h"
#include "Player.h"

USING_NS_CC;

bool Bullet::init()
{
	m_Type = BULLET;
	return true;
}

bool Bullet::collisionOccured(Character* enemy)
{
	if (enemy->getType() & this->getCollisionKind())
	{
		if (enemy->getType() == PLAYER)
		{
			if (((Player*)enemy)->isUnbeatable())
			{
				return false;
			}
		}

		EffectManager* effectManager = (EffectManager*)this->getParent()->getChildByTag(EFFECT_MANAGER_TAG);

		effectManager->createEffect(EffectManager::BULLET_EFFECT,this->getPosition());
		((GameScene*)this->getParent())->removeCharacter(this);
		
		return true;
	}
	
	return false;
}
