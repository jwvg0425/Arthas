#include "View.h"
#include "WorldScene.h"


bool View::init()
{
	return true;
}

void View::centerView(cocos2d::Node* inputNode, cocos2d::Rect inputRect)
{
	float nodeWidth = inputNode->getContentSize().width;
	float nodeHeight = inputNode->getContentSize().height;
	
	float centerX = nodeWidth / 2;
	float centerY = nodeHeight / 2;
	
	float moveX = centerX - inputRect.origin.x;
	float moveY = centerY - inputRect.origin.y;

	inputNode->setPosition(moveX,moveY);

	return;

}
