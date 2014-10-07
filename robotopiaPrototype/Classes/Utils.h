//Utils.h
//
//모든 클래스들에서 기본적으로 참조해야하는 값들과 함수들을 정의해둠.
//
//작성자 : 남현욱
//

#pragma once
#include "cocos2d.h"

//상수들
#define ABSTRACT virtual
#define OVERRIDE virtual
#define GRAVITY 980
#define TAG_GAME_LAYER 1

enum ObjectType
{
	OT_NONE,
	OT_PLAYER,
	OT_FLOOR,
	OT_BLOCK,
	OT_MISSILE,
	OT_LINEAR_MISSILE,
	OT_AIMING_MISSILE,
	OT_MONSTER,
	OT_RUSH_MONSTER,
	OT_VILLAGER,
	OT_GATEWAY,
};

enum EffectType
{
	ET_LINEAR_MISSILE_COLLISION,
	ET_AIMING_MISSILE_COLLISION,
	ET_PLAYER_FLOOR_COLLISION,
};

enum Direction
{
	DIR_NONE,
	DIR_LEFT = 1,
	DIR_UP = 2,
	DIR_RIGHT = 4,
	DIR_DOWN = 8,
};
typedef int Directions;

enum KeyState
{
	KS_NONE, // 뗀 상태
	KS_PRESS, //딱 누름
	KS_HOLD, //꾹 누르는 중
	KS_RELEASE, // 딱 뗌
};

enum KeyCode
{
	KC_UP =		cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW,
	KC_RIGHT =	cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW,
	KC_DOWN =	cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW,
	KC_LEFT =	cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW,
	KC_ATTACK = cocos2d::EventKeyboard::KeyCode::KEY_A,
	KC_JUMP =	cocos2d::EventKeyboard::KeyCode::KEY_SPACE,
};

//유틸 함수 모음. 

class UtilFunctions
{
public:
	static cocos2d::Animation* createAnimation(const char* animationName, int startIdx, size_t frameNum, float delay);
};


//키보드 입력 처리 관련 클래스

class KeyStateManager
{
	friend class KeyStateSentinel;

public:
	static KeyState													getKeyState(KeyCode keyCode);
	static void														receiveKeyboardData(cocos2d::Layer* layer); //layer에서 호출하면 이제 그 레이어에서는 키보드 정보가 자동으로 업데이트됨.
private:
	static std::map<cocos2d::EventKeyboard::KeyCode, KeyState>		m_KeyStates;
	static std::map<cocos2d::EventKeyboard::KeyCode, KeyState>		m_PrevKeyStates;
	static std::map<cocos2d::EventKeyboard::KeyCode, KeyState>		m_FinalKeyStates;
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