#pragma once

#include "cocos2d.h"
class WorldScene;

class View
{
public:
	virtual bool init();

	// x,y
	void setViewPort(WorldScene* scene, cocos2d::Point standardPoint, cocos2d::Point anchorPoint);
	//
	void setViewPort(WorldScene* inputScene, cocos2d::Rect stadardRect, Point anchorPoint);

	//�� ��� ũ�� ����� 
	void setViewPortWithHighlight();

	
private:
	float m_AnchorX, m_AnchorY;
	float m_MoveX, m_MoveY;

};