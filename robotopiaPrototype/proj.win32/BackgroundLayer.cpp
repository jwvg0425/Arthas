#include "BackgroundLayer.h"

USING_NS_CC;

bool BackgroundLayer::init()
{
	if( !Layer::init() )
	{
		return false;
	}

	m_BackSprite = Sprite::createWithSpriteFrameName( "BackBackground" );
	m_BackSprite->setAnchorPoint( Point::ZERO );
	this->addChild( m_BackSprite );

	return true;
}

