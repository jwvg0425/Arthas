#include "AimingBullet.h"
#include <math.h>

USING_NS_CC;


bool AimingBullet::init()
{
	Bullet::init();
	vx = 0;
	vy = 0;

	this->scheduleUpdate();
	return true;
}

void AimingBullet::setMoveAttribute(bool isPlayersBullet, float velocity, Point myPos, Point targetPos)
{
	m_Velocity = velocity;
	if (isPlayersBullet == false)
	{
		m_Velocity = -m_Velocity;
		m_Sprite = Sprite::create("enemy_bullet.png");
		m_CollisionKind = PLAYER;
	}
	else
	{
		m_Sprite = Sprite::create("bullet.png");
		m_Sprite->setFlippedX(true);
		m_CollisionKind = ENEMY;
	}

	float d = sqrt((myPos.x - targetPos.x)*(myPos.x - targetPos.x) + (myPos.y - targetPos.y)*(myPos.y - targetPos.y));

	if (d != 0)
	{
		vx = (myPos.x - targetPos.x) / d*m_Velocity;
		vy = (myPos.y - targetPos.y) / d*m_Velocity;
	}
	else
	{
		vx = m_Velocity;
		vy = 0;
	}

	m_Width = m_Sprite->getContentSize().width;
	m_Height = m_Sprite->getContentSize().height;

	this->addChild(m_Sprite);
}

cocos2d::Rect AimingBullet::getSize()
{
	float x = this->getPositionX();
	float y = this->getPositionY();

	return Rect(x - m_Width / 2, y - m_Height / 2, m_Width, m_Height);
}

void AimingBullet::update(float delta)
{
	Point pos = this->getPosition();

	pos.x += vx;
	pos.y += vy;

	this->setPosition(pos);
}
