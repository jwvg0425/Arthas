#include "Bullet.h"

USING_NS_CC;

bool Bullet::init()
{
	this->setAnchorPoint(Point(0.5, 0.5));

	return true;
}

void Bullet::setType(Type t)
{
	type = t;
	Sprite* spr;
	Action* act;

	switch (t)
	{
	case PLAYER:
		spr = Sprite::create("player_bullet.png");
		act = MoveBy::create(2, Point(640, 0));
		break;
	case ENEMY:
		spr = Sprite::create("enemy_bullet.png");
		act = MoveBy::create(2, Point(-640, 0));
		break;
	}

	spr->setAnchorPoint(Point(0.5, 0.5));
	width = spr->getContentSize().width;
	height = spr->getContentSize().height;

	this->addChild(spr);
	this->runAction(act);
}

bool Bullet::hitCheck(Rect rect)
{
	float x = this->getPosition().x;
	float y = this->getPosition().y;
	bool isHit = false;

	isHit = rect.containsPoint(Point(x, y))
		 || rect.containsPoint(Point(x + width, y))
		 || rect.containsPoint(Point(x, y + height))
		 || rect.containsPoint(Point(x + width, y + height));

	return isHit;
}
