#include "MapLayer.h"
#include "Player.h"

USING_NS_CC;

bool MapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
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
	m_BoxSize.setSize( 32 , 32 );
	m_MapRect.setRect( 0, 0, 32*m_BoxWidthNum, 32*m_BoxHeightNum );
	this->addChild(m_Player);
	this->scheduleUpdate();

	return true;
}

void MapLayer::update(float dTime)
{
	setViewPosition();
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
	for( int y = m_BoxHeightNum - 1; y >= 0; y-- )
	{
		for( int x = 0; x < m_BoxWidthNum; x++ )
		{
			value = atoi( rawValue );
			m_MapData[m_BoxWidthNum*y + x] = value;

			rawValue = strtok( nullptr , " \n" );
		}
	}

	for( int y = 0; y < m_BoxHeightNum; y++ )
	{
		for( int x = 0; x < m_BoxWidthNum; x++ )
		{
			Sprite* sprite = nullptr;
			switch( m_MapData[y*m_BoxWidthNum + x] )
			{
				case 0:
					if( m_MapData[( y - 1 )*( m_BoxWidthNum ) + x - 1] == 1 ) 
					{
						if( m_MapData[( y - 1 )*( m_BoxWidthNum  ) + x] == 1 )
						{
							if( m_MapData[y*( m_BoxWidthNum ) + x - 1] == 1 ) //(x, y) 박스 밑에 1 박스 왼쪽 아래 1, 박스 왼쪽 1
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
							if( m_MapData[y*( m_BoxWidthNum ) + x - 1] == 1 )  //(x, y) 박스 밑에 0 박스 왼쪽 아래 1, 박스 왼쪽 1
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
						if( m_MapData[( y - 1 )*( m_BoxWidthNum) + x] == 1 ) //(x, y) 박스 밑에 1 박스 왼쪽 아래 0,
						{
							sprite = Sprite::createWithSpriteFrameName( "tile_back_corner.png" );
						}
						else if( m_MapData[y*( m_BoxWidthNum ) + x - 1] == 1 ) //(x, y) 박스 왼쪽 1 박스 왼쪽 아래 0,
						{
							sprite = Sprite::createWithSpriteFrameName( "tile_side_corner.png" );
						}
					}
					break;
				case 1:
					sprite = Sprite::createWithSpriteFrameName( "tile.png" );
					break;
			}
			if( sprite != nullptr )
			{
				sprite->setAnchorPoint( Point::ZERO );
				sprite->setPosition( Point( x * 32 , y * 32 ) );
				this->addChild( sprite );
			}
		}
	}
}
