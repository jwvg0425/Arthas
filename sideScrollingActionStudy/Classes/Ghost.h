#pragma once
#include "Monster.h"

class Ghost : public Monster
{
public:
	virtual bool init();
	virtual bool collisionOccured(const Character* enemy);
	virtual cocos2d::Rect getSize() const;

	void update(float delta);

	CREATE_FUNC(Ghost);
private:
	cocos2d::Sprite* m_Sprite;
	int m_CreateTime;
	float m_AttackDelay;
	float m_AttackTime;
	int m_AttackType;
};