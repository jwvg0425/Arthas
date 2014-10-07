//Player.h
//
//게임 주인공 캐릭터의 조작 및 충돌 처리등을 구현. 
//
//작성자 : 남현욱
//
#pragma once

#include "InteractiveObject.h"

class Player : public InteractiveObject
{
public:
	OVERRIDE bool			init();
	CREATE_FUNC(Player);

	OVERRIDE void			collisionOccured(InteractiveObject* enemy, Directions dir);

	OVERRIDE cocos2d::Rect	getRect();

	void					update(float dTime);

	int						getHp() const { return m_Hp; }
	int						getSteam() const { return m_Steam; }
	int						getMaxHp() const { return m_MaxHp; }
	int						getMaxSteam() const { return m_MaxSteam; }
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
	int			m_Hp;
	int			m_Steam;
	int			m_MaxHp;
	int			m_MaxSteam;

	void		changeState(State state);
	void		endAnimation(cocos2d::Ref* sender);
};