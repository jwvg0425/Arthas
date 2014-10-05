#pragma once

#include"InteractiveObject.h"

class Player : public InteractiveObject
{
public:
	virtual bool init();

	virtual bool collisionOccured(InteractiveObject* enemy);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void update(float dTime);

	CREATE_FUNC(Player);
private:
	typedef int KeyState;
	enum State
	{
		PL_STAND,
		PL_WALK,
		PL_JUMP_READY,
		PL_JUMP_UP,
		PL_JUMP_HIGH,
		PL_JUMP_DOWN,
		PL_LAND,
		PL_STATE_NUM,
	};

	enum KeyStateBit
	{
		KS_LEFT = 1,
		KS_RIGHT = 2,
	};

	KeyState m_KeyState;
	bool m_IsRightDirection;
	State m_State;

	void changeState(State state);
};