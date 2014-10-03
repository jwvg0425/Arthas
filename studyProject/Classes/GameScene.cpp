#include "GameScene.h"
#include "Character.h"
#include <time.h>

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
	{
		return false;
	}
	srand(time(NULL));

	auto player = Character::create();

	player->setPosition(Point(200, 200));
	this->addChild(player, 0, 1);
	
	bullets.clear();

	this->schedule(schedule_selector(GameScene::update));

	return true;
}

void GameScene::addBullet(Bullet* bullet)
{
	this->addChild(bullet);
	bullets.pushBack(bullet);
}

void GameScene::update(float delta)
{
	bulletUpdate(delta);
	monsterUpdate(delta);
}

void GameScene::bulletUpdate(float delta)
{
	Vector<Bullet*> removeList;

	for (auto bullet : bullets)
	{
		auto point = bullet->getPosition();


		if (point.x <= 0
			|| point.y <= 0
			|| point.y > Director::getInstance()->getWinSize().height
			|| point.x > Director::getInstance()->getWinSize().width)
		{
			removeList.pushBack(bullet);
			this->removeChild(bullet);
			
			continue;
		}

		switch (bullet->getType())
		{
		case Bullet::Type::ENEMY:
			{
				Character* player = (Character*)(this->getChildByTag(1));
				if (bullet->hitCheck(player->getSize()))
				{
					removeList.pushBack(bullet);
					this->removeChild(bullet);
				}
			}
			break;
		case Bullet::Type::PLAYER:
			if (true)
			{
				Monster* removeMonster = nullptr;

				for (auto monster : monsters)
				{
					if (bullet->hitCheck(monster->getSize()))
					{
						removeMonster = monster;
						this->removeChild(monster);
						removeList.pushBack(bullet);
						this->removeChild(bullet);
						break;
					}
				}
				if (removeMonster != nullptr)
				{
					monsters.eraseObject(removeMonster);
				}
			}
			break;
		}
	}

	for (auto bullet : removeList)
	{
		bullets.eraseObject(bullet);
	}

	removeList.clear();
}

void GameScene::monsterUpdate(float delta)
{
	Vector<Monster*> removeList;

	for (auto monster : monsters)
	{
		auto point = monster->getPosition();


		if (point.x <= 0
			|| point.y <= 0
			|| point.y > Director::getInstance()->getWinSize().height
			|| point.x > Director::getInstance()->getWinSize().width)
		{
			removeList.pushBack(monster);
			this->removeChild(monster);
		}
	}

	for (auto monster : removeList)
	{
		monsters.eraseObject(monster);
	}

	removeList.clear();

	static float time = 0;
	time += delta;

	if (time > 0.3)
	{
		time = 0;

		auto monster = Monster::create();

		this->addChild(monster);
		monsters.pushBack(monster);
	}
}
