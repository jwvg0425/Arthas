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
	CD_TOP,
	CD_LEFT,
	CD_BOTTOM,
	CD_RIGHT,
};
typedef int CollisionDirection;

class InteractiveObject : public cocos2d::Node
{
public:
	virtual bool init();

	virtual void collisionOccured(InteractiveObject* enemy, CollisionDirection dir, OUT bool* isRemoving) = 0;

	virtual CollisionDirection collisionCheck(InteractiveObject* enemy,float dTime);
	virtual cocos2d::Rect getRect();
	ObjectType getType() const { return m_Type; }

	cocos2d::Vec2 getVelocity() const;

protected:
	static const float GRAVITY;
	cocos2d::Sprite* m_MainSprite;
	std::map<int, cocos2d::Animation*> m_Animations;
	int m_AnimationNum;
	float m_Width, m_Height;
	ObjectType m_Type;
	float m_Vx, m_Vy;
	bool m_IsOnGravity;

};