#pragma once

#include "Character.h"

class Player : public Character
{
public:
	virtual bool init();
	void initStand();
	void initAttack();
	void update(float delta);
	virtual cocos2d::Rect getSize();
	bool isUnbeatable();

	CREATE_FUNC(Player);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	virtual bool collisionOccured(Character* enemy);

private:
	enum Status
	{
		STAND,
		ATTACK,
	};
	
	void changeStatus(Status status);
	
	void startUnbeatableState();
	void endUnbeatableState(cocos2d::Ref* sender);

	cocos2d::Sprite* m_StandSprite;
	cocos2d::Sprite* m_AttackSprite;
	cocos2d::Animation* m_StandAnimation;
	cocos2d::Animation* m_AttackAnimation;
	double m_AttackDelay, m_AfterAttackDelay;
	double m_AttackSpeed;
	bool m_IsAttacking;
	bool m_IsUnbeatable;
	float m_UnbeatableTime;
	cocos2d::Sprite* m_NowSprite;

	enum Direction
	{
		UP = 1,
		RIGHT = 2,
		DOWN = 4,
		LEFT = 8,
	};

	int m_Direction;
	int m_Velocity;
	Status m_Status;
};