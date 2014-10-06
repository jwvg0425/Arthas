#include "WorldScene.h"
#include "GameLayer.h"
#include "BackgroundLayer.h"

USING_NS_CC;


bool WorldScene::init()
{
	if( !Scene::init() )
	{
		return false;
	}

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile( "Robotopia.plist" );
	m_GameLayer = GameLayer::create();
	m_BackgroundLayer = BackgroundLayer::create();
	m_GameLayer->setAnchorPoint( Point::ZERO );
	m_BackgroundLayer->setPosition( Point::ZERO );
	this->addChild( m_GameLayer , WorldScene::ZOrder::GAMELAYER );
	this->addChild( m_BackgroundLayer , WorldScene::ZOrder::BACKGROUND );
	//m_GameLayer->addChild(m_BackgroundLayer->getFrontSprite(), -1);
	return true;
}