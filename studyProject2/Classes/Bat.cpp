#include "Bat.h"
#include "AimingBullet.h"
#include "GameScene.h"

USING_NS_CC;


bool Bat::init()
{
	Monster::init();

	m_CreateTime = time(NULL);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bat.plist");

	m_Sprite = Sprite::createWithSpriteFrameName("bat1.png");
	m_Sprite->setAnchorPoint(Point(0.5, 0.5));

	auto animation = Animation::create();
	
	animation->setDelayPerUnit(0.15);

	for (int i = 0; i < 5; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format(
			"bat%d.png", i + 1));

		animation->addSpriteFrame(frame);
	}

	auto animate = Animate::create(animation);
	m_Sprite->runAction(RepeatForever::create(animate));

	this->addChild(m_Sprite);

	m_Width = m_Sprite->getContentSize().width;
	m_Height = m_Sprite->getContentSize().height;

	this->scheduleUpdate();

	if (rand() % 2)
	{
		vy = 2;
		vvy = -0.1;
	}
	else
	{
		vy = -2;
		vvy = 0.1;
	}

	m_AttackTime = 1.2;
	m_AttackDelay = 0;

	return true;
}

cocos2d::Rect Bat::getSize()
{
	float x = this->getPositionX();
	float y = this->getPositionY();

	return Rect(x - m_Width / 2, y - m_Height / 2, m_Width, m_Height);
}

void Bat::update(float delta)
{
	m_Width = m_Sprite->getContentSize().width;
	m_Height = m_Sprite->getContentSize().height;

	Point pos = this->getPosition();

	pos.x -= 2;
	pos.y += vy;

	vy += vvy;

	if (vy <= -2 || vy >=2)
		vvy = -vvy;

	this->setPosition(pos);

	m_AttackDelay += delta;

	if (m_AttackDelay >= m_AttackTime)
	{
		m_AttackDelay = 0;

		auto bullet = AimingBullet::create();

		if (this->getParent()->getChildByTag(PLAYER_TAG))
		{
			bullet->setMoveAttribute(false, 4, this->getPosition(), this->getParent()->getChildByTag(PLAYER_TAG)->getPosition());
		}
		else
		{
			bullet->setMoveAttribute(false, 4, this->getPosition(), this->getPosition());
		}
		bullet->setPosition(this->getPosition());

		((GameScene*)this->getParent())->addCharacter(bullet);
	}
}