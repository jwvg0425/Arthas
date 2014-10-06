﻿#pragma once

#include "cocos2d.h"
#include "Utils.h"

class InteractiveObject : public cocos2d::Node
{
public:
	OVERRIDE bool			init();

	ABSTRACT void			collisionOccured(InteractiveObject* enemy, Direction dir, OUT bool * isRemoving) = 0;
	ABSTRACT Direction		collisionCheck(InteractiveObject* enemy, float dTime);

	ABSTRACT cocos2d::Rect	getRect();
	ObjectType				getType() const { return m_Type; }
	cocos2d::Vec2			getVelocity() const;
	bool					isOnGravity() { return m_IsOnGravity; }

protected:
	cocos2d::Sprite*						m_MainSprite;
	std::map < int, cocos2d::Animation*>	m_Animations;
	int										m_AnimationNum;
	float									m_Width, m_Height;
	ObjectType								m_Type;
	cocos2d::Vec2							m_Velocity;
	bool									m_IsOnGravity;
	float									m_MoveSpeed;
	bool									m_IsDestroyed;
};