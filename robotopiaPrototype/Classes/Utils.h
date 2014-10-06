#pragma once
#define ABSTRACT virtual
#define OVERRIDE virtual

enum ObjectType
{
	OT_PLAYER,
};

enum Direction
{
	DIR_NONE,
	DIR_LEFT = 1,
	DIR_UP = 2,
	DIR_RIGHT = 4,
	DIR_DOWN = 8,
};