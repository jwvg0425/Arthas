#pragma once
#include "Bullet.h"


class LinearBullet : public Bullet
{
public:
	virtual bool init();
	void setMoveAttribute(bool isPlayersBullet, float velocity, float degree);
	virtual cocos2d::Rect getSize();

	CREATE_FUNC(LinearBullet);

	void update(float delta);

private:
	float m_Velocity;
	float m_Degree;
	float vx, vy;
	cocos2d::Sprite* m_Sprite;
};