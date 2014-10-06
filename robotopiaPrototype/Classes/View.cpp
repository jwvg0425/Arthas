#include "View.h"
#include "GameLayer.h"

USING_NS_CC;


void View::setViewPort( GameLayer* scene , Point standardPoint , Point anchorPoint )
{
	Rect mapRect = scene->getMapRect();
	float windowWidth = Director::getInstance()->getWinSize().width;
	float windowHeight = Director::getInstance()->getWinSize().height;
	float anchorX = windowWidth * anchorPoint.x;
	float anchorY = windowHeight * anchorPoint.y;
	
	float moveX = anchorX - standardPoint.x;
	float moveY = anchorY - standardPoint.y;


	//이걸하지 말라고 해야돼. 
	// 언제? 이동하면 화면에 짤릴 때 
	if (standardPoint.x + anchorPoint.x * windowWidth > mapRect.size.width ||
		standardPoint.x - anchorPoint.x * windowWidth < 0||
		standardPoint.y + anchorPoint.y * windowHeight > mapRect.size.height||
		standardPoint.y + anchorPoint.y * windowHeight > mapRect.size.height)
	{
		return;
	}
	else
	{
		scene->setPosition(moveX, moveY);

	}

	
}



void View::setViewPortWithHighlight(GameLayer* inputScene, cocos2d::Rect stadardRect)
{
	return;
}

