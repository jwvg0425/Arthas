#pragma once

#include "cocos2d.h"
class GameLayer;

class View
{
public:
	// standardPoint로 기준점이 되는 점을 넘겨라, anchorPoint(0~1)
	static void setViewPort( GameLayer* scene , cocos2d::Point standardPoint , cocos2d::Point anchorPoint );
	
	// Scene 중에 원하는 위치와 Width Height를 넘긴다 그러면 넘긴 위치를 중심으로 잘라낸 크기만큼의 
	//그림이 윈도우 창을 꽉차게 만든다
	static void setViewPortWithHighlight(GameLayer* Scene, cocos2d::Rect standardRect);
	static void setViewPortWithHighlight(GameLayer* Scene, cocos2d::Point standardPoint, cocos2d::Size size);
	
	

};