#pragma once
#include "cocos2d.h"

class GameLayer;
class BackgroundLayer;
class WorldScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC( WorldScene );

private:
	enum ZOrder
	{
		BACKGROUND ,
		GAMELAYER ,
		UILAYER ,
	};
	GameLayer*			m_GameLayer;
	BackgroundLayer*	m_BackgroundLayer;
};
