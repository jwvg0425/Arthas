#pragma once

#include "cocos2d.h"

class View
{
public:
	virtual bool init();

	// x,y좌표에 있는 width, height 크기의 대상을 화면의 정 가운데로 표시  
	void centerView(cocos2d::Node* inputNode, cocos2d::Rect inputRect);

	


private:


};