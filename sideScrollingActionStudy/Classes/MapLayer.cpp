#include "MapLayer.h"
#include "Player.h"

USING_NS_CC;

bool MapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	UserDefault::getInstance()->setIntegerForKey("mapWidth",48);
	UserDefault::getInstance()->setIntegerForKey("mapHeight", 20);
	UserDefault::getInstance()->setStringForKey("mapData",
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
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
		"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n");

	m_Width = UserDefault::getInstance()->getIntegerForKey("mapWidth");
	m_Height = UserDefault::getInstance()->getIntegerForKey("mapHeight");
	m_MapRawData = UserDefault::getInstance()->getStringForKey("mapData");

	char* rawValue;
	char rawData[8192];

	strcpy(rawData, m_MapRawData.c_str());

	rawValue = strtok(rawData, " \n");

	for (int y = 0; y <= m_Height + 1; y++)
	{
		for (int x = 0; x <= m_Width + 1; x++)
		{
			if (y == 0 || x == 0 || y == m_Height + 1 || x == m_Width + 1)
			{
				m_MapData.push_back(0);
				continue;
			}

			int value = atoi(rawValue);

			m_MapData.push_back(value);

			rawValue = strtok(nullptr, " \n");
		}
	}

	for (int y = 1; y <= m_Height ; y++)
	{
		for (int x = 1; x <= m_Width+1 ; x++)
		{
			Sprite* sprite = nullptr;
			switch (m_MapData[y*(m_Width+2) + x])
			{
			case 0:
				if (m_MapData[(y + 1)*(m_Width + 2) + x - 1] == 1)
				{
					if (m_MapData[(y + 1)*(m_Width + 2) + x] == 1)
					{
						if (m_MapData[y*(m_Width + 2) + x - 1] == 1)
						{
							sprite = Sprite::createWithSpriteFrameName("tile_side_lowercorner.png");
						}
						else
						{
							sprite = Sprite::createWithSpriteFrameName("tile_back.png");
						}
					}
					else
					{
						if (m_MapData[y*(m_Width + 2) + x - 1] == 1)
						{
							sprite = Sprite::createWithSpriteFrameName("tile_side.png");
						}
						else
						{
							sprite = Sprite::createWithSpriteFrameName("tile_side_uppercorner.png");
						}
					}
				}
				else
				{
					if (m_MapData[(y + 1)*(m_Width + 2) + x] == 1)
					{
						sprite = Sprite::createWithSpriteFrameName("tile_back_corner.png");
					}
					else if (m_MapData[y*(m_Width + 2) + x - 1] == 1)
					{
						sprite = Sprite::createWithSpriteFrameName("tile_side_corner.png");
					}
				}
				break;
			case 1:
				sprite = Sprite::createWithSpriteFrameName("tile.png");
				break;
			}
			if (sprite != nullptr)
			{
				sprite->setAnchorPoint(Point::ZERO);
				sprite->setPosition(Point((x - 1) * 32, (m_Height - y) * 32));
				this->addChild(sprite);
			}
		}
	}
	
	m_Player = Player::create();
	m_Player->setAnchorPoint(Point(0.5, 0.5));
	m_Player->setPosition(Point(0, 200));

	this->addChild(m_Player);

	this->scheduleUpdate();

	return true;
}

void MapLayer::update(float dTime)
{
	Point pos = m_Player->getPosition();

	Point mapPos;

	mapPos.x = 320 - pos.x;
	mapPos.y = 240 - pos.y;

	if (mapPos.x > 0)
	{
		mapPos.x = 0;
	}

	if (mapPos.y > 0)
	{
		mapPos.y = 0;
	}

	if (mapPos.x < -m_Width * 32 + 640)
	{
		mapPos.x = -m_Width * 32 + 640;
	}

	if (mapPos.y < -m_Height * 32 + 480)
	{
		mapPos.y = -m_Height * 32 + 480;
	}


	this->setPosition(mapPos);
}
