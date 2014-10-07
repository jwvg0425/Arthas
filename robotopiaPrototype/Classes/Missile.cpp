#include "Missile.h"


bool Missile::init()
{
	if (!InteractiveObject::init())
	{
		return false;
	}

	//타입 추가 되면 여기 활성화
	m_Type = OT_MISSILE;


	return true;
}



