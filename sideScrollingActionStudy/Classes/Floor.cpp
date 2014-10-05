#include "Floor.h"
USING_NS_CC;

bool Floor::init()
{
	TileObject::init();
	m_Type = OT_FLOOR;
	m_TileType = TT_FLOOR;
	m_MainSprite = Sprite::createWithSpriteFrameName("tile.png");
	m_MainSprite->setAnchorPoint( Point(0.5, 0.5) );
	this->addChild( m_MainSprite );
	m_Width = m_MainSprite->getContentSize().width;
	m_Height = m_MainSprite->getContentSize().height;
	return true;
}

void Floor::collisionOccured( InteractiveObject* enemy , CollisionDirection dir , OUT bool* isRemoving )
{
	*isRemoving = false;
}
