#include "Monster.h"

bool Monster::init()
{
	if (!InteractiveObject::init())
	{
		return false;
	}

	return true;
}

void Monster::collisionOccured(InteractiveObject* enemy, Directions dir)
{

}
