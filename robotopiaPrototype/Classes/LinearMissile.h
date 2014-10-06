#pragma once

#include "cocos2d.h"
#include "Missile.h"

class LinearMissile : public Missile
{
public:
	OVERRIDE bool init();
	OVERRIDE void collisionOccured(InteractiveObject* enemy, Directions dir);

	CREATE_FUNC(LinearMissile);

private:

};