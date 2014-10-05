#include "LinearBullet.h"
#include <math.h>
#define PIE 3.141592


USING_NS_CC;

bool LinearBullet::init()
{
	Bullet::init();
	vx = 0;
	vy = 0;
	m_Velocity = 0;
	m_Degree = 0;

	this->scheduleUpdate();
	return true;
}

void LinearBullet::setMoveAttribute(bool isPlayersBullet, float velocity, float degree)
{
	m_Velocity = velocity;
	m_IsPlayersBullet = isPlayersBullet;

	if (isPlayersBullet == false)
	{
		m_Velocity = -m_Velocity;
		m_Sprite = Sprite::create("enemy_bullet.png");
	}
	else
	{
		m_Sprite = Sprite::create("bullet.png");
		m_Sprite->setFlippedX(true);
	}

	m_Degree = degree;
	m_Sprite->setAnchorPoint(Point(0.5, 0.5));
	m_Width = m_Sprite->getContentSize().width;
	m_Height = m_Sprite->getContentSize().height;
	vx = cos(PIE / 180 * degree)*m_Velocity;
	vy = sin(PIE / 180 * degree)*abs(m_Velocity);

	this->addChild(m_Sprite);
}

cocos2d::Rect LinearBullet::getSize() const
{
	float x = this->getPositionX();
	float y = this->getPositionY();

	return Rect(x - m_Width/2, y - m_Height/2, m_Width , m_Height);
}

void LinearBullet::update(float delta)
{
	Point pos = this->getPosition();

	pos.x += vx;
	pos.y += vy;

	this->setPosition(pos);
}
