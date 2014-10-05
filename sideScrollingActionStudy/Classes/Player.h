#pragma once

#include "Character.h"

class Player : public Character
{
public:
	virtual bool init();
	void initStand();
	void initAttack();
	void initAttacked();
	void update(float delta);
	virtual cocos2d::Rect getSize() const;
	virtual bool collisionOccured(const Character* enemy);

	CREATE_FUNC(Player);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);


private:
	enum Status
	{
		STAND,
		ATTACK,
		ATTACKED,
		STATE_NUM,
	};
	
	void changeStatus(Status status);
	
	void startUnbeatableState();
	void endUnbeatableState(cocos2d::Ref* sender);
	cocos2d::Sprite* m_Sprites[STATE_NUM];
	cocos2d::Animation* m_Animation[STATE_NUM];

	double m_MotionDelay, m_AfterMotionDelay;
	double m_AttackSpeed;
	double m_AttackedTime;
	bool m_IsAttacking;
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