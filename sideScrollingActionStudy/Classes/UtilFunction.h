#pragma once
#include "cocos2d.h"

enum ObjectType
{
	OT_PLAYER,
	OT_FLOOR,
};

enum CollisionDirectionBit
{
	CD_NONE,
	CD_TOP = 1,
	CD_LEFT = 2,
	CD_BOTTOM = 4,
	CD_RIGHT = 8,
};
typedef int CollisionDirection;


class UtilFunction
{
public:
	static cocos2d::Animation*	makeAnimation(const char* animationName, int startIdx, size_t size, float delay);
	static CollisionDirection	getReverseDirection(CollisionDirection dir);
	
};