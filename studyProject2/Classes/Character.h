#pragma once

#include "cocos2d.h"

enum CharacterType
{
	PLAYER = 1,
	ENEMY = 2,
	BULLET = 4,
};


class Character : public cocos2d::Node
{
public:

	virtual bool init();

	CharacterType getType(){ return m_Type; }
	void setType(CharacterType t){ m_Type = t; }
	
	virtual cocos2d::Rect getSize() = 0;

	bool hitCheck(cocos2d::Rect enemyRect);
	bool isOutOfScreen();
	void setCollisionKind(CharacterType kind){ m_CollisionKind = kind; }
	int getCollisionKind(){ return m_CollisionKind; }
	virtual bool collisionOccured(Character* enemy);

protected:
	CharacterType m_Type;
	int m_CollisionKind;
	float m_Width, m_Height;
};