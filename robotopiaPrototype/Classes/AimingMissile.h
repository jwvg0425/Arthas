#pragma once

#include "cocos2d.h"
#include "Missile.h"

class AimingMissile : public Missile
{
public:
	OVERRIDE bool init();
	void		  setMoveAttribute(bool m_IsPlayerMissile, float velocity, cocos2d::Point myPos, cocos2d::Point targetPos);
	void		  update(float dTime);
private:
	
};
