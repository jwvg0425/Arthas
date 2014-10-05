#pragma once
#include "cocos2d.h"

class UtilFunction
{
public:
	static cocos2d::Animation* makeAnimation(const char* animationName, int startIdx, size_t size, float delay);
};