#include "Monster.h"
#include "Bullet.h"
#include "GameScene.h"
#include <time.h>

USING_NS_CC;

bool Monster::init()
{
	int t = time(NULL);
	auto spr = Sprite::create("monster.png");
	auto act = MoveBy::create(3, Point(-640, 240 * ((t % 3) - 1)));

	width = spr->getContentSize().width;
	height = spr->getContentSize().height;

	spr->setAnchorPoint(Point(0.5, 0.5));

	this->setPosition(Point(640, (t * 70) % 480));

	this->addChild(spr);

	this->schedule(schedule_selector(Monster::update));

	this->runAction(act);

	attackDelay = 0;

	return true;
}

void Monster::update(float delta)
{
	attackDelay += delta;

	if (attackDelay > 0.4)
	{
		attackDelay = 0;

		auto bullet = Bullet::create();
		auto position = this->getPosition();

		position.x -= 15;
		bullet->setType(Bullet::Type::ENEMY);
		bullet->setPosition(position);

		((GameScene*)this->getParent())->addBullet(bullet);
	}
}

cocos2d::Rect Monster::getSize()
{
	float x = this->getPosition().x;
	float y = this->getPosition().y;
	return Rect(x - width / 2, y - height / 2, width, height);
}
