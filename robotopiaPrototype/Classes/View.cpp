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


	//�̰����� ����� �ؾߵ�. 
	// ����? �̵��ϸ� ȭ�鿡 ©�� �� 
	if (standardPoint.x + anchorX > mapRect.size.width)
	{
		anchorX = standardPoint.x -(mapRect.size.width - windowWidth);
	}
	if (standardPoint.x - anchorX < 0)
	{
		anchorX = standardPoint.x;
		//���࿡ 0�����ϸ� ���� ���� ������ �ʴ´�. 
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

	CCLOG("%d", (anchorX - standardPoint.x));
	scene->setPosition(anchorX - standardPoint.x, anchorY - standardPoint.y);
}



void View::setViewPortWithHighlight(GameLayer* Scene, cocos2d::Rect standardRect)
{


	return;
}

