#pragma once

#include "cocos2d.h"
#include "Character.h"


class Bullet : public Character
{
public:
	virtual bool init();

	virtual bool collisionOccured(Character* enemy);
protected:
	
};