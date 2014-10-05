#include "GameScene.h"
#include "MapLayer.h"
#include "Player.h"

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
	if ( !Layer::init() )
	{
		return false;
	}

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("slideTest.plist");

	auto layer = MapLayer::create();

	layer->setAnchorPoint(Point(0.5,0.5));
	layer->setPosition(Point(320,240));
	auto backBackground = Sprite::create( "backGroundBack.png" );
	backBackground->setAnchorPoint( Point::ZERO );
	backBackground->setPosition( Point(0 , 40 ));
	this->addChild( backBackground , ZOrder::ZO_BACKBACKGROUND );
	this->addChild( layer );
	return true;
}