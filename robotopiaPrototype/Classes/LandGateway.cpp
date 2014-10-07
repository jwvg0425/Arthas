#include "LandGateway.h"
#include "GameLayer.h"
USING_NS_CC;

bool LandGateway::init()
{
	if( !LandObject::init() )
	{
		return false;
	}
	m_MainSprite = Sprite::createWithSpriteFrameName( "Gateway0.png" );
	this->addChild( m_MainSprite );
	m_OpenAnimaion = UtilFunctions::createAnimation( "Gateway" , 0 , 11 , 0.2f );
	m_OpenAnimaion->retain();
	m_isOpen = false;

	return true;
}

void LandGateway::collisionOccured( InteractiveObject* enemy , Directions dir )
{
	if( m_isOpen == false )
	{
		m_isOpen = true;
		auto animate = Animate::create( m_OpenAnimaion );
		auto callfunc = CallFuncN::create( CC_CALLBACK_1( LandGateway::gotoNextLevel , this ) );
		auto action = Sequence::create( animate , callfunc , NULL );
		m_MainSprite->runAction( action );
	}
}

void LandGateway::gotoNextLevel(Ref* sender)
{
	( ( GameLayer* )this->getParent() )->gotoNextWorld();
}

