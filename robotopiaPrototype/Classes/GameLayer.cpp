#include "GameLayer.h"
#include "LandFloor.h"
#include "LandBlock.h"
USING_NS_CC;

Scene* GameLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}

bool GameLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	KeyStateManager::receiveKeyboardData( this );
	m_WinRect.size = Director::getInstance()->getVisibleSize();
	m_WinRect.origin = Director::getInstance()->getVisibleOrigin();
	initWorldFromData( MAPDATA );
	this->scheduleUpdate();

	addMovingBackground();

	m_Player = Player::create();
	m_Player->setAnchorPoint( Point( 0.6f , 0.6f ) );
	m_Player->setPosition(Point(100 , 300));
	this->addChild( m_Player , GameLayer::ZOrder::GAME_OBJECT);
	m_InteractiveObjects.push_back( m_Player );

	return true;
}

bool GameLayer::initWorldFromData( char* data )
{
	//월드 데이터를 본래는 리소스 메니저에게 키값을 넘겨서 받아와야 한다.
	//받아야 하는 데이터들 BoxSize MapSize MapData(값)
	UserDefault::getInstance()->setIntegerForKey( "mapWidth" , 48 );
	UserDefault::getInstance()->setIntegerForKey( "mapHeight" , 20 );
	UserDefault::getInstance()->setIntegerForKey( "boxWidth" , 32 );
	UserDefault::getInstance()->setIntegerForKey( "boxHeight" , 32 );
	UserDefault::getInstance()->setStringForKey( "mapData" , data );
	m_BoxWidthNum = UserDefault::getInstance()->getIntegerForKey( "mapWidth" );
	m_BoxHeightNum = UserDefault::getInstance()->getIntegerForKey( "mapHeight" );
	m_BoxSize.width = UserDefault::getInstance()->getIntegerForKey( "boxWidth" );
	m_BoxSize.height = UserDefault::getInstance()->getIntegerForKey( "boxHeight" );
	m_MapRawData = UserDefault::getInstance()->getStringForKey( "mapData" );
	m_MapRect.setRect( 0 , 0 , m_BoxSize.width * m_BoxWidthNum , m_BoxSize.height * m_BoxHeightNum );

	char* rawValue;
	char rawData[MAX_DATA_SIZE];

	strcpy( rawData , m_MapRawData.c_str() );

	rawValue = strtok( rawData , " \n" );
	int value;
	for( int yIdx = m_BoxHeightNum - 1; yIdx >= 0; yIdx-- )
	{
		for( int xIdx = 0; xIdx < m_BoxWidthNum; xIdx++ )
		{
			value = atoi( rawValue );
			m_MapData[m_BoxWidthNum*yIdx + xIdx] = (ObjectType)value;
			rawValue = strtok( nullptr , " \n" );
		}
	}

	for( int yIdx = 0; yIdx < m_BoxHeightNum; yIdx++ )
	{
		for( int xIdx = 0; xIdx < m_BoxWidthNum; xIdx++ )
		{
			addObjectByMapdata( xIdx , yIdx );
		}
	}
	return true;
}


void GameLayer::addObjectByMapdata( ObjectType type , int xIdx , int yIdx )
{
	if( type == ObjectType::OT_FLOOR )
	{
		auto floor = LandFloor::create();
		floor->setPosition( Point( xIdx * m_BoxSize.width , yIdx * m_BoxSize.height ) );
		m_InteractiveObjects.push_back( floor );
		this->addChild( floor , GameLayer::ZOrder::LAND_OBJECT );
	}
	if( type == ObjectType::OT_BLOCK )
	{
		auto block = LandBlock::create();
		block->setPosition( Point( xIdx * m_BoxSize.width , yIdx * m_BoxSize.height ) );
		m_InteractiveObjects.push_back( block );
		this->addChild( block , GameLayer::ZOrder::LAND_OBJECT );
	}

}

void GameLayer::addObjectByMapdata( int xIdx , int yIdx )
{
	addObjectByMapdata( m_MapData[yIdx*m_BoxWidthNum + xIdx] , xIdx , yIdx );
}

void GameLayer::update( float dTime )
{
	View::setViewPort( this , m_Player->getRect().origin , Point(0.5, 0.5) );
	collisionCheck(dTime);
	removeObject();
}

void GameLayer::collisionCheck(float dTime)
{
	std::vector<CollisionInformation> collisionInformations;
	Directions collisionDirections;

	for( auto subjectIter = m_InteractiveObjects.begin(); subjectIter != m_InteractiveObjects.end(); ++subjectIter )
	{
		for( auto objectIter = subjectIter + 1; objectIter != m_InteractiveObjects.end(); ++objectIter )
		{
			auto subject = *subjectIter; //충돌 주체
			auto object = *objectIter;	//충돌당하는 애
			collisionDirections = subject->collisionCheck( object , dTime );
			if( collisionDirections )
			{
				collisionInformations.push_back( CollisionInformation(subject, object, collisionDirections));
			}
			
			collisionDirections = object->collisionCheck( subject , dTime );
			if( collisionDirections )
			{
				collisionInformations.push_back( CollisionInformation( object , subject , collisionDirections ) );
			}
		}
	}

	for( auto collisionInfo : collisionInformations )
	{
		collisionInfo.subject->collisionOccured( collisionInfo.object , collisionInfo.directions );
	}
}

void GameLayer::removeObject()
{
	for( auto objectIter = m_InteractiveObjects.begin(); objectIter != m_InteractiveObjects.end(); )
	{
		auto object = *objectIter;
		if( object->isDestroyed() )
		{
			objectIter = m_InteractiveObjects.erase( objectIter );
			removeChild( object );
		}
		else
		{
			objectIter++;
		}
	}
}

void GameLayer::addMovingBackground()
{
	auto backgroundSprite = Sprite::createWithSpriteFrameName( "background.png" );
	Size spriteSize = backgroundSprite->getContentSize();
	int xSpriteNum = ( m_MapRect.size.width / spriteSize.width );
	int ySpriteNum = ( m_MapRect.size.height / spriteSize.height );
	for( int yIdx = 0; yIdx <= ySpriteNum; ++yIdx )
	{
		for( int xIdx = 0; xIdx <= xSpriteNum; ++xIdx )
		{
			backgroundSprite = Sprite::createWithSpriteFrameName( "background.png" );
			backgroundSprite->setPosition( xIdx*spriteSize.width, yIdx*spriteSize.height );
			backgroundSprite->setAnchorPoint( Point::ZERO );
			this->addChild( backgroundSprite , GameLayer::ZOrder::BACKGROUND);
		}
	}
}

cocos2d::Vec2 GameLayer::PositionToIdxOfMapData( cocos2d::Point position )
{
	Vec2 curPosIdx = Vec2(-1 , -1); 
	if( m_MapRect.containsPoint( position ) )
	{
		curPosIdx.x = position.x / m_BoxSize.width;
		curPosIdx.y = position.y / m_BoxSize.height;
	}
	_ASSERT( curPosIdx == Vec2( -1 , -1 ) ); //맵안에 있지 않은 위치
	return curPosIdx;
}

ObjectType GameLayer::getMapData( int xIdx , int yIdx )
{
	return m_MapData[yIdx*m_BoxHeightNum + xIdx];
}

ObjectType GameLayer::getMapData( cocos2d::Point position )
{
	int xIdx = PositionToIdxOfMapData( position ).x;
	int yIdx = PositionToIdxOfMapData( position ).y;
	return getMapData( xIdx , yIdx );
}

