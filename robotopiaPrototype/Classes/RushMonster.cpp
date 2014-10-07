#include "RushMonster.h"


bool RushMonster::init()
{
	if (!Monster::init())
	{
		return false;
	}

	m_Type = OT_RUSH_MONSTER;

	return true;
}

void RushMonster::collisionOccured(InteractiveObject* enemy, Directions dir)
{

}
