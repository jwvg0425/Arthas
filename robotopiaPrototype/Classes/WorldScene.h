#pragma once
#include "cocos2d.h"

class GameLayer;
class BackgroundLayer;
class UILayer;
class WorldScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene*	createScene();
	virtual bool			init();

	GameLayer*				getGameLayer() {return m_GameLayer; }
	UILayer*				getUILayer() {return m_UILayer; }
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
	UILayer*			m_UILayer;
};
