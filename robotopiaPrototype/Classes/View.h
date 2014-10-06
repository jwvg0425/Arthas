#pragma once

#include "cocos2d.h"
class WorldScene;

class View
{
public:
	

	// standardPoint로 기준점이 되는 점을 넘겨라, anchorPoint(0~1)
	static void setViewPort(WorldScene* scene, cocos2d::Point standardPoint, cocos2d::Point anchorPoint);
	//
	static void setViewPort(WorldScene* inputScene, cocos2d::Rect stadardRect, cocos2d::Point anchorPoint);

	//몇 배로 크게 해줘라 
	static void setViewPortWithHighlight();

	
private:
	

};