#pragma once
#include "Monster.h"

class Bat : public Monster
{
public:
	virtual bool init();

	virtual cocos2d::Rect getSize() const;
	virtual bool collisionOccured(const Character* enemy);

	void update(float delta);

	CREATE_FUNC(Bat);
private:
	cocos2d::Sprite* m_Sprite;
	int m_CreateTime;
	float vy;
	float vvy;
	float m_AttackDelay;
	float m_AttackTime;
};