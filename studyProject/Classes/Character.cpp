#include "Character.h"
#include "Bullet.h"
#include "GameScene.h"

USING_NS_CC;

bool Character::init()
{
	auto sprite = Sprite::create("player.png");

	attackSpeed = 0.2;

	sprite->setAnchorPoint(Point(0.5, 0.5));

	width = sprite->getContentSize().width;
	height = sprite->getContentSize().height;

	this->addChild(sprite);

	auto keyListener = EventListenerKeyboard::create();

	keyListener->onKeyPressed = CC_CALLBACK_2(Character::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(Character::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	this->schedule(schedule_selector(Character::update));

	return true;
}

void Character::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		direction |= UP;
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		direction |= LEFT;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		direction |= RIGHT;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		direction |= DOWN;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		isAttack = true;
		break;
	}
}

void Character::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		direction &= ~UP;
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		direction &= ~LEFT;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		direction &= ~RIGHT;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		direction &= ~DOWN;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		isAttack = false;
		break;
	}
}

void Character::update(float delta)
{
	static float time = 0;

	time += delta;

	Point p = this->getPosition();

	if (direction & UP)
	{
		p.y += 3;
	}
	else if (direction & DOWN)
	{
		p.y -= 3;
	}

	if (direction & RIGHT)
	{
		p.x += 3;
	}
	else if (direction & LEFT)
	{
		p.x -= 3;
	}

	this->setPosition(p);

	if (time > attackSpeed && isAttack)
	{
		time = 0;

		auto bullet = Bullet::create();
		auto position = this->getPosition();

		position.x += 25;
		bullet->setType(Bullet::Type::PLAYER);
		bullet->setPosition(position);

		((GameScene*)this->getParent())->addBullet(bullet);
	}

	
}

Rect Character::getSize()
{
	float x = this->getPosition().x;
	float y = this->getPosition().y;
	return Rect(x - width/2, y - height/2, width, height);
}
