#pragma once

#include "cocos2d.h"
#include "TileObject.h"

#define MAX_DATA_SIZE 1024*10

class Player;

class MapLayer : public cocos2d::Layer
{
public:
	virtual bool				init();
	void						update(float dTime);
	void						collisionCheck(float dTime);
	void						initMap(char* mapData);
	void						setViewPosition();
	void						addTile(TileType type, int posX, int posY);
	void						addTilePiece( int posX , int posY );
	CREATE_FUNC( MapLayer );

private:
	cocos2d::Rect					m_MapRect;
	cocos2d::Size					m_BoxSize;
	int								m_BoxWidthNum, m_BoxHeightNum;
	std::string						m_MapRawData;
	std::map<int, int>				m_MapData;
	std::vector<InteractiveObject*> m_InteractiveObjects;
	std::vector<InteractiveObject*> m_RemoveObjects;
	Player*							m_Player;
};