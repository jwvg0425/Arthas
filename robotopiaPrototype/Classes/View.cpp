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


	
	if (standardPoint.x + anchorX > mapRect.size.width)
	{
		anchorX = standardPoint.x -(mapRect.size.width - windowWidth);
	}
	if (standardPoint.x - anchorX < 0)
	{
		anchorX = standardPoint.x;
		//만약에 0으로하면 왼쪽 빈 공간이 보이지 않는다. 
		//anchorX = 0;
	}
	if (standardPoint.y + anchorY > mapRect.size.height)
	{
		anchorY = standardPoint.y - (mapRect.size.height - windowHeight);
	}
	if (standardPoint.y - anchorY < 0)
	{
		anchorY = standardPoint.y;
	}

	
	scene->setPosition(anchorX - standardPoint.x, anchorY - standardPoint.y);
}



void View::setViewPortWithHighlight(GameLayer* scene, cocos2d::Rect standardRect)
{
	float ratioX = Director::getInstance()->getWinSize().width / standardRect.size.width;
	float ratioY = Director::getInstance()->getWinSize().height / standardRect.size.height;


	setViewPort(scene, standardRect.origin, Point(0.5, 0.5));
	scene->setScale(ratioX, ratioY);

	return;
}

void View::setViewPortWithHighlight(GameLayer* Scene, cocos2d::Point standardPoint, cocos2d::Size size)
{
	Rect rect = Rect(standardPoint.x,standardPoint.y, size.width, size.height);
	setViewPortWithHighlight(Scene, rect);

}

