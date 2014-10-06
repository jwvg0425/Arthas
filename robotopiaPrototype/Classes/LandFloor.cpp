#include "LandFloor.h"

bool LandFloor::init()
{
	if( !LandObject::init() )
	{
		return false;
	}
	m_Type = OT_FLOOR;
	return true;
}

