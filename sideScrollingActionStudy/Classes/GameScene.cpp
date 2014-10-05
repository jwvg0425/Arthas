#include "GameScene.h"
#include "Player.h"
#include "Bat.h"
#include "Ghost.h"
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
	batSpawnTime = 1;
	batSpawnDelay = 0;
	ghostSpawnTime = 10;
	ghostSpawnDelay = 0;

	player->setPosition(Point(200, 200));
	this->addCharacter(player, 5, PLAYER_TAG);

	auto effectManager = EffectManager::create();

	this->addChild(effectManager, 1, EFFECT_MANAGER_TAG);

	srand(time(NULL));

	this->scheduleUpdate();
	return true;
}

void GameScene::update(float delta)
{
	static int prevTime = time(NULL);
	static float height = 30 + rand() % 420;
	cocos2d::Vector<Character*> removeCharacters;
	Player* player = (Player*)this->getChildByTag(PLAYER_TAG);

	//拳搁 观俊 唱埃 阁胶磐 贸府
	for (auto character : m_Characters)
	{
		if (character->isOutOfScreen())
		{
			removeCharacters.pushBack(character);
		}
	}

	for (auto character : removeCharacters)
	{
		removeCharacter(character);
	}
	removeCharacters.clear();

	//各 积己
	if (time(NULL) - prevTime > 3)
	{
		height = 30 + rand() % 420;
		prevTime = time(NULL);
	}
	batSpawnDelay += delta;
	if (batSpawnDelay > batSpawnTime)
	{
		batSpawnDelay = 0;

		auto bat = Bat::create();

		bat->setPosition(Point(640, height));

		this->addCharacter(bat);
	}
	ghostSpawnDelay += delta;
	if (ghostSpawnDelay > ghostSpawnTime)
	{
		ghostSpawnDelay = 0;

		auto ghost = Ghost::create();

		ghost->setPosition(Point(640, 30 + rand() % 420));

		this->addCharacter(ghost);
	}

	//面倒 贸府
	for (auto iter = m_Characters.begin(); iter != m_Characters.end(); ++iter)
	{
		for (auto iter2 = iter + 1; iter2 != m_Characters.end(); ++iter2)
		{
			Character* character = *iter;
			Character* character2 = *iter2;
			
			if (m_RemovingReservedCharacters.contains(character) ||
				m_RemovingReservedCharacters.contains(character2) ||
				character->isUnbeatable() || character2->isUnbeatable())
			{
				continue;  
			}

			if (character->hitCheck(character2->getSize()))
			{
				if (character->collisionOccured(character2))
				{
					reserveRemoving(character);
				}
				if (character2->collisionOccured(character))
				{
					reserveRemoving(character2);
				}
			}
		}
	}

	//昏力 贸府

	for (auto character : m_RemovingReservedCharacters)
	{
		removeCharacter(character);
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

void GameScene::reserveRemoving(Character* character)
{
	m_RemovingReservedCharacters.pushBack(character);
}
