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
	virtual cocos2d::Rect getSize() const;
	ObjectType getType() const { return m_Type; }
protected:
	cocos2d::Sprite* m_MainSprite;
	std::map<int, cocos2d::Animation*> m_Animations;
	int m_AnimationNum;
	float m_Width, m_Height;
	ObjectType m_Type;
};