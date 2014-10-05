#pragma once

#include "cocos2d.h"

enum ObjectType
{
	PLAYER,
};

class InteractiveObject : public cocos2d::Node
{
public:
	virtual bool init();

	virtual bool collisionOccured(InteractiveObject* enemy) = 0;
	virtual cocos2d::Rect getRect();
	ObjectType getType() const { return m_Type; }

	cocos2d::Vec2 getVelcotiy() const;

	virtual void setOuterForce(cocos2d::Vec2 OuterForce);

protected:
	cocos2d::Sprite* m_MainSprite;
	std::map<int, cocos2d::Animation*> m_Animations;
	int m_AnimationNum;
	float m_Width, m_Height;
	ObjectType m_Type;
	float m_Vx, m_Vy;

	cocos2d::Vec2 m_PrevOuterForce;
};