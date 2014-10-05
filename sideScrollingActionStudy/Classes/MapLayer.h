#pragma once

#include "cocos2d.h"

class Player;

class MapLayer : public cocos2d::Layer
{
public:
	virtual bool	init();
	void			update(float dTime);
	void			initMap(char* mapData);

	CREATE_FUNC( MapLayer );

private:
	cocos2d::Rect		m_MapRect;
	cocos2d::Size		m_BoxSize;
	int					m_BoxWidthNum, m_BoxHeightNum;
	std::string			m_MapRawData;
	std::vector<int>	m_MapData;
	Player*				m_Player;
};