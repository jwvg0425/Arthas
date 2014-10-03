#pragma once

#include "cocos2d.h"

class Bullet : public cocos2d::Node
{
public:
	enum Type
	{
		PLAYER,
		ENEMY,
	};

	virtual bool init();

	CREATE_FUNC(Bullet);

	void setType(Type t);
	Type getType()
	{
		return type;
	}
	bool hitCheck(cocos2d::Rect rect);

private:
	Type type;
	float width;
	float height;
};