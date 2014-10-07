#include "UILayer.h"
#include "Utils.h"
#include "GameLayer.h"

USING_NS_CC;

bool UILayer::init()
{
	auto gameLayer = ((WorldScene*)this->getParent())->getGameLayer();

	cocos2d::Rect winSize = gameLayer->getWinRect();
	int winHeight = winSize.size.height;
	
	auto sprHPContainer = Sprite::create("Container_HP.png");
	sprHPContainer->setZOrder(10);
	Point pHP;
	pHP.x = 20;
	pHP.y = 20;
	sprHPContainer->setPosition(pHP);
	this->addChild(sprHPContainer);
	
	auto sprSTEContainer = Sprite::create("Container_STE.png");
	sprSTEContainer->setZOrder(10);
	Point pSTE;
	pSTE.x = 20;
	pSTE.y = 80;
	sprSTEContainer->setPosition(pSTE);
	this->addChild(sprSTEContainer);

	m_Player = gameLayer->getPlayer();
	
	this->scheduleUpdate();
	return true;
}

void UILayer::update(float dTime)
{

}

