#pragma once
#include "cocos2d.h"

#define ABSTRACT virtual
#define OVERRIDE virtual
#define GRAVITY 980

enum ObjectType
{
	OT_OBJECT,
	OT_PLAYER,
	OT_FLOOR,
};

enum LandType
{
	LT_OBJECT,
	LT_FLOOR,
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
	KS_NONE, // 뗀 상태
	KS_PRESS, //딱 누름
	KS_HOLD, //꾹 누르는 중
	KS_RELEASE, // 딱 뗌
};

enum KeyCode
{
	KC_UP = cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW,
	KC_RIGHT = cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW,
	KC_DOWN = cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW,
	KC_LEFT = cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW,
	KC_ATTACK = cocos2d::EventKeyboard::KeyCode::KEY_A,
	KC_JUMP = cocos2d::EventKeyboard::KeyCode::KEY_SPACE,
};

class UtilFunctions
{
public:
	static cocos2d::Animation* createAnimation(const char* animationName, int startIdx, size_t size, float delay);
};


class KeyStateManager
{
	friend class KeyStateSentinel;

public:
	static KeyState getKeyState(KeyCode keyCode);
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