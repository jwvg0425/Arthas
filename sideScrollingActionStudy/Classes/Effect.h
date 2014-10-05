#pragma once
#include "cocos2d.h"

class EffectManager : public cocos2d::Node
{
public:
	enum Type
	{
		BULLET_EFFECT,
		BAT_DIE,
		GHOST_DIE,
	};
	virtual bool init();

	void createEffect(Type t, cocos2d::Point pos);

	void removeEffect(cocos2d::Ref* sender);

	CREATE_FUNC(EffectManager);
private:
};