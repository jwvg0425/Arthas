#pragma once

#include "cocos2d.h"

class Player;

class MapLayer : public cocos2d::Layer
{
public:
	virtual bool	init();
	void			update(float dTime);
	void			initMap(char* mapData);
	bool			checkAvailablePosition(cocos2d::Point position);
	bool			checkAvailableRect( cocos2d::Rect rect );
	cocos2d::Vec2	calculateOuterForce( cocos2d::Vec2 objectVelocity , cocos2d::Rect objectRect, float dTime);

	CREATE_FUNC( MapLayer );

private:
	cocos2d::Rect		m_MapRect;
	cocos2d::Size		m_BoxSize;
	float				m_Gravity;
	int					m_BoxWidthNum, m_BoxHeightNum;
	std::string			m_MapRawData;
	std::map<int, int>	m_MapData;
	Player*				m_Player;
};