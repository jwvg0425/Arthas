#pragma once

#include "cocos2d.h"
class WorldScene;

class View
{
public:
	

	// standardPoint�� �������� �Ǵ� ���� �Ѱܶ�, anchorPoint(0~1)
	static void setViewPort(WorldScene* scene, cocos2d::Point standardPoint, cocos2d::Point anchorPoint);
	//
	static void setViewPort(WorldScene* inputScene, cocos2d::Rect stadardRect, cocos2d::Point anchorPoint);

	//�� ��� ũ�� ����� 
	static void setViewPortWithHighlight();

	
private:
	

};