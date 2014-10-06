#pragma once
#include "cocos2d.h"

#define ABSTRACT virtual
#define OVERRIDE virtual

enum ObjectType
{
	OT_OBJECT,
	OT_PLAYER,
};

enum Direction
{
	DIR_NONE,
	DIR_LEFT = 1,
	DIR_UP = 2,
	DIR_RIGHT = 4,
	DIR_DOWN = 8,
};

enum KeyState
{
	NONE, // 뗀 상태
	PRESS, //딱 누름
	HOLD, //꾹 누르는 중
	RELEASE, // 딱 뗌
};

class KeyStateManager
{
	friend class KeyStateSentinel;

public:
	KeyState getKeyboardState(cocos2d::EventKeyboard::KeyCode keyCode);
	static void receiveKeyboardData(cocos2d::Layer* layer); //layer에서 호출하면 이제 그 레이어에서는 키보드 정보가 자동으로 업데이트됨.
private:
	static std::map<cocos2d::EventKeyboard::KeyCode, KeyState> m_KeyStates;
	static std::map<cocos2d::EventKeyboard::KeyCode, KeyState> m_PrevKeyStates;
	static std::map<cocos2d::EventKeyboard::KeyCode, KeyState> m_FinalKeyStates;
};

//키보드 누르는 정보를 송신해줌.
class KeyStateSentinel : public cocos2d::Node
{
	friend class KeyStateManager;

public:
	OVERRIDE bool	init();

	void			onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void			onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void			update(float dTime);

	CREATE_FUNC(KeyStateSentinel);
private:
};