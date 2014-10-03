#pragma once;
#include "cocos2d.h"

class Monster : public cocos2d::Node
{
public:
	virtual bool init();

	void update(float delta);

	cocos2d::Rect getSize();

	CREATE_FUNC(Monster);
private:
	float attackDelay;
	float width, height;
};