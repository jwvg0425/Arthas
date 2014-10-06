#include "GameLayer.h"
#include "LandFloor.h"
#include "View.h"

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
	m_WinRect.size = Director::getInstance()->getVisibleSize();
	m_WinRect.origin = Director::getInstance()->getVisibleOrigin();
	initWorldFromData( MAPDATA );
	KeyStateManager::receiveKeyboardData( this );
	this->scheduleUpdate();

	m_Player = Player::create();
	m_Player->setAnchorPoint( Point( 0.5 , 0.5 ) );
	m_Player->setPosition(Point(100 , 300));
	this->addChild( m_Player );
	m_InteractiveObjects.push_back( m_Player );

	return true;
}

bool GameLayer::initWorldFromData( char* data )
{
	//월드 데이터를 본래는 리소스 메니저에게 키값을 넘겨서 받아와야 한다.
	//받아야 하는 데이터들 BoxSize MapSize MapData(값)
	UserDefault::getInstance()->setIntegerForKey( "mapWidth" , 48 );
	UserDefault::getInstance()->setIntegerForKey( "mapHeight" , 20 );
	UserDefault::getInstance()->setIntegerForKey( "boxWidth" , 35 );
	UserDefault::getInstance()->setIntegerForKey( "boxHeight" , 35 );
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
			m_MapData[m_BoxWidthNum*yIdx + xIdx] = value;

			rawValue = strtok( nullptr , " \n" );
		}
	}

	for( int yIdx = 0; yIdx < m_BoxHeightNum; yIdx++ )
	{
		for( int xIdx = 0; xIdx < m_BoxWidthNum; xIdx++ )
		{
			Sprite* sprite = nullptr;
			switch( m_MapData[yIdx*m_BoxWidthNum + xIdx] )
			{
				case 0:
					break;
				case 1:
					addLandObject( LT_FLOOR , xIdx , yIdx );
					break;
			}
		}
	}
	return true;
}


void GameLayer::addLandObject( LandType type , int xIdx , int yIdx )
{
	if( type == LT_FLOOR )
	{
		auto floor = LandFloor::create();
		floor->setPosition( Point( xIdx * m_BoxSize.width , yIdx * m_BoxSize.height ) );
		m_InteractiveObjects.push_back( floor );
		this->addChild( floor );
	}

}

void GameLayer::update( float dTime )
{
	View::setViewPort( this , m_Player->getRect().origin , Point(0.5, 0.5) );
	collisionCheck(dTime);
	removeObject();
}

void GameLayer::collisionCheck(float dTime)
{
	Direction collisionDirection;
	for( auto subjectIter = m_InteractiveObjects.begin(); subjectIter != m_InteractiveObjects.end(); ++subjectIter )
	{
		for( auto objectIter = subjectIter + 1; objectIter != m_InteractiveObjects.end(); ++objectIter )
		{
			auto subject = *subjectIter;
			auto object = *objectIter;
			collisionDirection = subject->collisionCheck( object , dTime );
			if( collisionDirection )
			{
				subject->collisionOccured( object , collisionDirection);
			}
			collisionDirection = object->collisionCheck( subject , dTime );
			if( collisionDirection )
			{
				object->collisionOccured( subject , collisionDirection);
			}
		}
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
