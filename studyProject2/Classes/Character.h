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

	CharacterType getType() const { return m_Type; }
	void setType(CharacterType t){ m_Type = t; }
	
	virtual cocos2d::Rect getSize() const = 0;

	bool hitCheck(cocos2d::Rect enemyRect);
	bool isOutOfScreen();
	bool isUnbeatable(){ return m_IsUnbeatable; }
	virtual bool collisionOccured(const Character* enemy);

protected:
	CharacterType m_Type;
	float m_Width, m_Height;
	bool m_IsUnbeatable;
	int m_Hp;

};