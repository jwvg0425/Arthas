#pragma once

#include "cocos2d.h"

class View
{
public:
	virtual bool init();

	// x,y��ǥ�� �ִ� width, height ũ���� ����� ȭ���� �� ����� ǥ��  
	void centerView(cocos2d::Node* inputNode, cocos2d::Rect inputRect);

	


private:


};