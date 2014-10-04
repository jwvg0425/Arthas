#pragma once
#include "Character.h"

class Monster : public Character
{
public:
	virtual bool init();

	virtual bool collisionOccured(Character* enemy);

private:
};