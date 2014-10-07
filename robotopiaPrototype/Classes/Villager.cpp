#include "Villager.h"

USING_NS_CC;

bool Villager::init()
{
	if( !InteractiveObject::init() )
	{
		return false;
	}
	m_Type = OT_VILLAGER;
	m_MainSprite = Sprite::createWithSpriteFrameName( "Villager.png" );
	this->addChild( m_MainSprite );
	return true;
}

void Villager::update( float deltaT )
{

}

void Villager::collisionOccured( InteractiveObject* enemy , Directions dir )
{

}

cocos2d::Rect Villager::getRect()
{
	m_Width = m_MainSprite->getContentSize().width;
	m_Height = m_MainSprite->getContentSize().height;

	return InteractiveObject::getRect();
}

