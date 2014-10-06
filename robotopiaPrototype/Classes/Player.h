#pragma once

#include "InteractiveObject.h"

class Player : public InteractiveObject
{
public:
	OVERRIDE bool			init();
	CREATE_FUNC(Player);

	OVERRIDE void			collisionOccured(InteractiveObject* enemy, Direction dir, OUT bool * isRemoving);

	void update(float dTime);
private:
	enum State
	{
		PS_STAND,
		PS_WALK,
		PS_JUMP,
		PS_ATTACK,
		PS_STATE_NUM,
	};

	State		m_State;
	bool		m_IsRightDirection;

	void		changeState(State state);
	void		endAnimation(cocos2d::Ref* sender);
};