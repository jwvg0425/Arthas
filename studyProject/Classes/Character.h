#pragma once

#include "cocos2d.h"

class Character : public cocos2d::Node
{
public:
	virtual bool init();

	void update(float delta);

	CREATE_FUNC(Character);

	cocos2d::Rect getSize();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
private:
	enum Direction
	{
		UP = 1,
		RIGHT = 2,
		DOWN = 4,
		LEFT = 8,
	};

	int direction = 0;
	bool isAttack = false;
	float attackSpeed = 0.2;
	float width, height;
};