#pragma once

#include "cocos2d.h"
class GameLayer;

class View
{
public:
	// standardPoint로 기준점이 되는 점을 넘겨라, anchorPoint(0~1)
	static void setViewPort( GameLayer* scene , cocos2d::Point standardPoint , cocos2d::Point anchorPoint );
	
	//구현 덜됐음
	static void setViewPortWithHighlight(GameLayer* Scene, cocos2d::Rect standardRect);
	static void setViewPortWithHighlight(GameLayer* Scene, cocos2d::Point standardPoint, cocos2d::Size size);
	
	

};