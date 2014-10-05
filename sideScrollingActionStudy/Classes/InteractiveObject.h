﻿#pragma once

#include "cocos2d.h"
#include "UtilFunction.h"

class InteractiveObject : public cocos2d::Node
{
public:
	virtual bool				init();

	virtual void				collisionOccured(InteractiveObject* enemy, CollisionDirection dir, OUT bool* isRemoving) = 0;

	virtual CollisionDirection	collisionCheck(InteractiveObject* enemy,float dTime);
	virtual cocos2d::Rect		getRect();
	ObjectType					getType() const { return m_Type; }

	cocos2d::Vec2				getVelocity() const;

	bool IsOnGravity() { return m_IsOnGravity; }

protected:
	static const float					GRAVITY;
	cocos2d::Sprite*					m_MainSprite;
	std::map<int, cocos2d::Animation*>	m_Animations;
	int									m_AnimationNum;
	float								m_Width, m_Height;
	ObjectType							m_Type;
	float								m_Vx, m_Vy;
	bool								m_IsOnGravity;

};