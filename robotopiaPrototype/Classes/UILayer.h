#pragma once
#include "cocos2d.h"
#include "WorldScene.h"
#include "Player.h"

class UILayer : public WorldScene
{
public:
	static cocos2d::Scene*	createScene();
	virtual bool			init();
	CREATE_FUNC(UILayer);

	void update(float dTime);

private:
	const Player* m_Player;


};