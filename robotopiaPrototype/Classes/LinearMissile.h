#pragma once

#include "cocos2d.h"
#include "Missile.h"

class LinearMissile : public Missile
{
public:
	OVERRIDE bool init();
	OVERRIDE void collisionOccured(InteractiveObject* enemy, Directions dir);
	void		  update(float dTime);
	void		  setMoveAttribute(bool m_IsPlayerMissile, float velocity, float degree);

	CREATE_FUNC(LinearMissile);

private:
	float	m_Degree;
	float	m_Vx, m_Vy;
};