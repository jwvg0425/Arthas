#include "BackgroundLayer.h"

USING_NS_CC;


bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto background1 = Sprite::create("background.png");
	auto background2 = Sprite::create("background.png");
	background1->setAnchorPoint(Point(0, 0));
	background2->setAnchorPoint(Point(0, 0));
	auto place = Place::create(Point(0, -32));
	auto place2 = Place::create(Point(1024, -32));
	auto move = MoveBy::create(10, Point(-1024, 0));
	auto move2 = MoveBy::create(10, Point(-1024, 0));
	auto action = Sequence::create(place, move, NULL);
	auto action2 = Sequence::create(place2, move2, NULL);

	background1->runAction(RepeatForever::create(action));
	background2->runAction(RepeatForever::create(action2));

	this->addChild(background1);
	this->addChild(background2);

	return true;
}

