#pragma once

#include "cocos2d.h"
#include "InteractiveObject.h"

class Missile : public InteractiveObject
{
public:
	OVERRIDE bool	init();
	bool			IsPlayerMissile(){ return m_IsPlayerMissile; }
	ABSTRACT void	collisionOccured(InteractiveObject* enemy, Directions dir) = 0;
	
protected:
	bool    m_IsPlayerMissile;
	float	m_Degree;
	
};