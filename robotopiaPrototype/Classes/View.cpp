#include "View.h"
#include "WorldScene.h"

USING_NS_CC;

bool View::init()
{
	m_AnchorX = 0;
	m_AnchorY = 0;
	m_MoveX = 0;
	m_MoveY = 0;
	return true;
}


void View::setViewPort(WorldScene* scene, cocos2d::Point standardPoint, cocos2d::Point anchorPoint)
{
	Rect mapRect = scene->getMapRect();
	float m_AnchorX = Director::getInstance()->getWinSize().width / (1/anchorPoint.x);
	float m_AnchorY = Director::getInstance()->getWinSize().height / (1/anchorPoint.y);



	m_MoveX = m_AnchorX - standardPoint.x;
	m_MoveY = m_AnchorY - standardPoint.y;



	scene->setPosition(m_MoveX, m_MoveY);
}



void View::setViewPort(WorldScene* scene, cocos2d::Rect rect, Point anchorPoint)
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

