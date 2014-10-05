#pragma once

#include "cocos2d.h"

class Player;

class MapLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(MapLayer);

	void update(float dTime);
private:
	int m_Width, m_Height;
	std::string m_MapRawData;
	std::vector<int> m_MapData;
	Player* m_Player;
};