#include "Missile.h"


bool Missile::init()
{
	if (!InteractiveObject::init())
	{
		return false;
	}

	//Ÿ�� �߰� �Ǹ� ���� Ȱ��ȭ
	m_Type = OT_MISSILE;
	m_Degree = 0;
	m_Vx = 0; 
	m_Vy = 0;


	return true;
}



