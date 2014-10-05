#include "MapLayer.h"
#include "Player.h"
#include "Floor.h"

USING_NS_CC;

bool MapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_BoxSize.setSize( 32 , 32 );

	initMap( "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
			 "0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0\n"
			 "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n" );

	m_Player = Player::create();
	m_Player->setAnchorPoint(Point(0.5, 0.5));
	m_Player->setPosition(Point(100, 200));
	m_InteractiveObjects.push_back( m_Player );

	m_MapRect.setRect( 0, 0, 32*m_BoxWidthNum, 32*m_BoxHeightNum );
	this->addChild(m_Player);
	this->scheduleUpdate();

	return true;
}

void MapLayer::update(float dTime)
{
	setViewPosition();
	collisionCheck(dTime);
	removeObjects();
}

void MapLayer::collisionCheck( float dTime )
{
	CollisionDirection collisionDirection;
	bool haveToRemove;
	for( auto subjectIter = m_InteractiveObjects.begin(); subjectIter != m_InteractiveObjects.end(); ++subjectIter )
	{
		for( auto objectIter = subjectIter + 1; objectIter != m_InteractiveObjects.end(); ++objectIter )
		{
			auto subject = *subjectIter;
			auto object = *objectIter;
			collisionDirection = subject->collisionCheck( object , dTime );
			if( collisionDirection )
			{
				subject->collisionOccured( object , collisionDirection , &haveToRemove );
				if( haveToRemove )
				{
					m_RemoveObjects.push_back( subject );
				}
			}
			collisionDirection = UtilFunction::getReverseDirection( collisionDirection );
			if( collisionDirection )
			{
				object->collisionOccured( subject , collisionDirection , &haveToRemove );
				if( haveToRemove )
				{
					m_RemoveObjects.push_back( object );
				}
			}
		}
	}
}

void MapLayer::removeObjects()
{
	for( auto removeObject : m_RemoveObjects )
	{

	}
}


void MapLayer::setViewPosition()
{
	Point pos = m_Player->getPosition();
	Point mapPos;
	Size winSize = Director::getInstance()->getWinSize();
	mapPos.x = winSize.width*this->getAnchorPoint().x - pos.x;
	mapPos.y = winSize.height*this->getAnchorPoint().y - pos.y;

	if( mapPos.x > -m_BoxSize.width )
	{
		mapPos.x = -m_BoxSize.width;
	}

	if( mapPos.y > -m_BoxSize.height )
	{
		mapPos.y = -m_BoxSize.height;
	}

	if( mapPos.x < -m_BoxWidthNum * ( m_BoxSize.width - 1 ) + winSize.width )
	{
		mapPos.x = -m_BoxWidthNum * ( m_BoxSize.width - 1 ) + winSize.width;
	}

	if( mapPos.y < -m_BoxHeightNum *  ( m_BoxSize.height - 1 ) + winSize.height )
	{
		mapPos.y = -m_BoxHeightNum *  ( m_BoxSize.height - 1 ) + winSize.height;
	}

	this->setPosition( mapPos );
}


void MapLayer::initMap(char* mapData)
{
	UserDefault::getInstance()->setIntegerForKey( "mapWidth" , 48 );
	UserDefault::getInstance()->setIntegerForKey( "mapHeight" , 20 );
	UserDefault::getInstance()->setStringForKey( "mapData" , mapData);
	m_BoxWidthNum = UserDefault::getInstance()->getIntegerForKey( "mapWidth" );
	m_BoxHeightNum = UserDefault::getInstance()->getIntegerForKey( "mapHeight" );
	m_MapRawData = UserDefault::getInstance()->getStringForKey( "mapData" );

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
					addTilePiece(xIdx, yIdx);
					break;
				case 1:
					addTile( TT_FLOOR , xIdx , yIdx );
					break;
			}
		}
	}
}

void MapLayer::addTile( TileType type , int xIdx , int yIdx )
{
	if(type == TT_FLOOR)
	{
		auto tile = Floor::create();
		tile->setAnchorPoint( Point::ZERO );
		tile->setPosition( Point( xIdx * m_BoxSize.width , yIdx * m_BoxSize.height ) );
		m_InteractiveObjects.push_back( tile );
		this->addChild( tile );
	}
	
}

void MapLayer::addTilePiece(int xIdx, int yIdx)
{
	Sprite* sprite = nullptr;
	if( m_MapData[( yIdx - 1 )*( m_BoxWidthNum )+xIdx - 1] == 1 )
	{
		if( m_MapData[( yIdx - 1 )*( m_BoxWidthNum )+xIdx] == 1 )
		{
			if( m_MapData[yIdx*( m_BoxWidthNum )+xIdx - 1] == 1 ) //(x, y) 박스 밑에 1 박스 왼쪽 아래 1, 박스 왼쪽 1
			{
				sprite = Sprite::createWithSpriteFrameName( "tile_side_lowercorner.png" );
			}
			else //(x, y) 박스 밑에 1 박스 왼쪽 아래 1, 박스 왼쪽 0
			{
				sprite = Sprite::createWithSpriteFrameName( "tile_back.png" );
			}
		}
		else
		{
			if( m_MapData[yIdx*( m_BoxWidthNum )+xIdx - 1] == 1 )  //(x, y) 박스 밑에 0 박스 왼쪽 아래 1, 박스 왼쪽 1
			{
				sprite = Sprite::createWithSpriteFrameName( "tile_side.png" );
			}
			else //(x, y) 박스 밑에 0 박스 왼쪽 아래 1, 박스 왼쪽 0	
			{
				sprite = Sprite::createWithSpriteFrameName( "tile_side_uppercorner.png" );
			}
		}
	}
	else
	{
		if( m_MapData[( yIdx - 1 )*( m_BoxWidthNum )+xIdx] == 1 ) //(x, y) 박스 밑에 1 박스 왼쪽 아래 0,
		{
			sprite = Sprite::createWithSpriteFrameName( "tile_back_corner.png" );
		}
		else if( m_MapData[yIdx*( m_BoxWidthNum )+xIdx - 1] == 1 ) //(x, y) 박스 왼쪽 1 박스 왼쪽 아래 0,
		{
			sprite = Sprite::createWithSpriteFrameName( "tile_side_corner.png" );
		}
	}
	if( sprite != nullptr )
	{
		sprite->setAnchorPoint( Point::ZERO );
		sprite->setPosition( Point( xIdx * m_BoxSize.width , yIdx * m_BoxSize.height ) );
		this->addChild( sprite );
	}
}

