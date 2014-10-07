#include "LandBlock.h"

USING_NS_CC;

bool LandBlock::init()
{
	if( !LandObject::init() )
	{
		return false;
	}

	m_MainSprite = Sprite::createWithSpriteFrameName( "block.png" );
	m_MainSprite->setAnchorPoint( Point::ZERO );
	this->addChild( m_MainSprite , 10 );
	m_PieceSprite = Sprite::createWithSpriteFrameName( "blockPiece.png" );
	m_PieceSprite->setAnchorPoint( Point::ZERO );
	this->addChild( m_PieceSprite , 0 );

	m_Type = OT_BLOCK;
	m_Width = m_MainSprite->getContentSize().width;
	m_Height = m_MainSprite->getContentSize().height;

	return true;
}

