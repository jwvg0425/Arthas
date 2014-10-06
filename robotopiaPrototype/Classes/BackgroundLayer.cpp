#include "BackgroundLayer.h"

USING_NS_CC;

bool BackgroundLayer::init()
{
	if( !Layer::init() )
	{
		return false;
	}

	m_BackSprite = Sprite::createWithSpriteFrameName( "BackBackground.png" );
	m_BackSprite->setAnchorPoint( Point::ZERO );
	this->addChild( m_BackSprite );
// 	m_FrontSprite = Sprite::createWithSpriteFrameName( "FrontBackground.png" );
// 	m_FrontSprite->setAnchorPoint( Point::ZERO );

	return true;
}

