#include "GameScene.h"
#include "Player.h"
#include "Bat.h"
#include "Bullet.h"
#include "BackgroundLayer.h"
#include "Effect.h"
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
	if ( !LayerColor::initWithColor(Color4B(255,255,255,0)) )
	{
		return false;
	}

	auto backgroundLayer = BackgroundLayer::create();

	this->addChild(backgroundLayer, -1);
	
	auto player = Player::create();
	mobSpawnTime = 1;
	mobSpawnDelay = 0;

	player->setPosition(Point(200, 200));
	this->addCharacter(player, 5, PLAYER_TAG);

	auto effectManager = EffectManager::create();

	this->addChild(effectManager, 1, EFFECT_MANAGER_TAG);

	srand(time(NULL));

	this->schedule(schedule_selector(GameScene::update));
	return true;
}

void GameScene::update(float delta)
{
	cocos2d::Vector<Character*> removeCharacters;
	Player* player = (Player*)this->getChildByTag(PLAYER_TAG);

	//화면 밖에 나간 몬스터 처리
	for (auto character : m_Characters)
	{
		if (character->isOutOfScreen())
		{
			removeCharacters.pushBack(character);
		}
	}

	for (auto character : removeCharacters)
	{
		m_Characters.eraseObject(character);
		this->removeChild(character);
	}
	removeCharacters.clear();

	//몹 생성
	mobSpawnDelay += delta;
	if (mobSpawnDelay > mobSpawnTime)
	{
		mobSpawnDelay = 0;

		auto bat = Bat::create();

		bat->setPosition(Point(640, rand() % 480));

		this->addCharacter(bat);
	}

	std::vector<CollisionData> data;

	for (auto iter = m_Characters.begin(); iter != m_Characters.end(); ++iter)
	{
		for (auto iter2 = iter + 1; iter2 != m_Characters.end(); ++iter2 )
		{
			Character* character1 = *iter;
			Character* character2 = *iter2;

			if (character1->getCollisionKind() & character2->getType())
			{
				if (character1->hitCheck(character2->getSize()))
				{
					data.push_back(CollisionData(character1, character2));
					data.push_back(CollisionData(character2, character1));
				}
			}
		}
	}

	for (auto datum : data)
	{
		if (m_Characters.contains(datum.character1))
		{
			datum.character1->collisionOccured(datum.character2);
		}
		if (m_Characters.contains(datum.character2))
		{
			datum.character2->collisionOccured(datum.character1);
		}
	}

}

void GameScene::addCharacter(Character* character)
{
	m_Characters.pushBack(character);
	this->addChild(character);
}

void GameScene::addCharacter(Character* character, int zOrder, int tag)
{
	m_Characters.pushBack(character);
	this->addChild(character, zOrder, tag);
}

bool GameScene::removeCharacter(Character* character)
{
	if (m_Characters.contains(character))
	{
		m_Characters.eraseObject(character);
		this->removeChild(character);
		return true;
	}
	
	return false;
}
