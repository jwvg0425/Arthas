#include "LinearMissile.h"

bool LinearMissile::init()
{
	if (!Missile::init())
	{
		return false;
	}

	return true;
}

void LinearMissile::collisionOccured(InteractiveObject* enemy, Directions dir)
{

	return;
}

