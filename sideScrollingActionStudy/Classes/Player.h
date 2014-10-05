#pragma once

#include"InteractiveObject.h"

class Player : public InteractiveObject
{
public:
	virtual bool init();

	virtual void collisionOccured(InteractiveObject* enemy, CollisionDirection dir, OUT bool* isRemoving);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void update(float dTime);
	virtual cocos2d::Rect getRect();

	CREATE_FUNC(Player);

private:
	typedef int KeyState;
	float m_MoveSpeed;

	enum State
	{
		PL_STAND,
		PL_WALK,
		PL_JUMP_READY,
		PL_JUMP_UP,
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
	void endAnimation(cocos2d::Ref* sender);
};