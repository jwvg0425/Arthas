#include "LandFloor.h"

USING_NS_CC;

bool LandFloor::init()
{
	if( !LandObject::init() )
	{
		return false;
	}

	m_MainSprite = Sprite::createWithSpriteFrameName( "floor.png" );
	m_MainSprite->setAnchorPoint( Point::ZERO );
	this->addChild( m_MainSprite, 10 );
	m_PieceSprite = Sprite::createWithSpriteFrameName( "floorPiece.png" );
	m_PieceSprite->setAnchorPoint( Point::ZERO );
	this->addChild( m_PieceSprite , 0);

	m_Type = OT_FLOOR;
	m_Width = m_MainSprite->getContentSize().width;
	m_Height = m_MainSprite->getContentSize().height;

	return true;
}

