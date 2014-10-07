#include "WorldScene.h"
#include "GameLayer.h"
#include "BackgroundLayer.h"
#include "UILayer.h"

USING_NS_CC;

Scene* WorldScene::createScene()
{
	WorldScene* scene = WorldScene::create();
	return scene;
}

bool WorldScene::init()
{
	if( !Scene::init() )
	{
		return false;
	}

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile( "Robotopia.plist" );

	m_GameLayer = GameLayer::create();
	m_GameLayer->setAnchorPoint( Point::ZERO );
	m_BackgroundLayer = BackgroundLayer::create();
	m_BackgroundLayer->setPosition( Point::ZERO );
	m_UILayer = UILayer::create();
	m_UILayer->setPosition( Point::ZERO );

	this->addChild( m_GameLayer , WorldScene::ZOrder::GAMELAYER , TAG_GAME_LAYER );
	this->addChild( m_BackgroundLayer , WorldScene::ZOrder::BACKGROUND , "TAG_BACKGROUND_LAYER" );
	this->addChild( m_UILayer , WorldScene::ZOrder::UILAYER , "TAG_UI_LAYER" );

	return true;
}

