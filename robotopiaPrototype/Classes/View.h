#pragma once

#include "cocos2d.h"
class GameLayer;

class View
{
public:
	

	// standardPoint�� �������� �Ǵ� ���� �Ѱܶ�, anchorPoint(0~1)
	static void setViewPort( GameLayer* scene , cocos2d::Point standardPoint , cocos2d::Point anchorPoint );
	
	static void setViewPortWithHighlight(GameLayer* Scene, cocos2d::Rect standardRect);

	
private:
	

};