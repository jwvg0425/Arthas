#pragma once

#include "cocos2d.h"
#include "Character.h"


class Bullet : public Character
{
public:
	virtual bool init();
	bool IsPlayersBullet(){ return m_IsPlayersBullet; }
	virtual bool collisionOccured(const Character* enemy);
protected:
	bool m_IsPlayersBullet;
	
};