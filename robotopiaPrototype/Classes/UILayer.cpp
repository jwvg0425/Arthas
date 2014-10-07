#include "UILayer.h"
#include "Utils.h"
#include "GameLayer.h"

USING_NS_CC;

bool UILayer::init()
{
	Size winSize = Director::getInstance()->getWinSize();
	int winHeight = winSize.height;
	
	auto sprHPContainer = Sprite::create("Container_HP.png");
	Point pHP;
	pHP.x = 20;
	pHP.y = winHeight - 20;
	sprHPContainer->setPosition(pHP);
	this->addChild(sprHPContainer, 10);
	
	auto sprSTEContainer = Sprite::create("Container_STE.png");
	Point pSTE;
	pSTE.x = 20;
	pSTE.y = winHeight - 80;
	sprSTEContainer->setPosition(pSTE);
	this->addChild(sprSTEContainer, 10);

	this->scheduleUpdate();
	return true;
}

void UILayer::update(float dTime)
{
	auto gameLayer = ((WorldScene*)this->getParent())->getGameLayer();
	m_Player = gameLayer->getPlayer();
}

