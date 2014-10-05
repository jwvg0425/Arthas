#pragma once
#include "Bullet.h"


class AimingBullet : public Bullet
{
public:
	virtual bool init();
	void setMoveAttribute(bool isPlayersBullet, float velocity, cocos2d::Point myPos, cocos2d::Point targetPos);
	virtual cocos2d::Rect getSize() const;

	CREATE_FUNC(AimingBullet);

	void update(float delta);

private:
	float vx, vy;
	float m_Velocity;
	cocos2d::Sprite* m_Sprite;
};