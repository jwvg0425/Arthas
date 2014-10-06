#include "View.h"
#include "GameLayer.h"

USING_NS_CC;


void View::setViewPort( GameLayer* scene , cocos2d::Point standardPoint , cocos2d::Point anchorPoint )
{
	Rect mapRect = scene->getMapRect();
	float anchorX = Director::getInstance()->getWinSize().width * anchorPoint.x;
	float anchorY = Director::getInstance()->getWinSize().height * anchorPoint.y;



	float moveX = anchorX - standardPoint.x;
	float moveY = anchorY - standardPoint.y;



	scene->setPosition(moveX, moveY);
}



void View::setViewPort( GameLayer* scene , cocos2d::Rect rect , Point anchorPoint )
{
	float nodeWidth = scene->getContentSize().width;
	float nodeHeight = scene->getContentSize().height;
	
	float centerX = nodeWidth / 2;
	float centerY = nodeHeight / 2;
	
	float moveX = centerX - rect.origin.x;
	float moveY = centerY - rect.origin.y;

	scene->setPosition(moveX,moveY);

	return;

}

void View::setViewPortWithHighlight()
{
	return;
}

