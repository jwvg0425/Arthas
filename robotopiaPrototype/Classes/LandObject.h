#pragma once
#include "cocos2d.h"
#include "InteractiveObject.h"

class LandObject : public InteractiveObject
{
public:
	OVERRIDE bool			init();
	//OVERRIDE cocos2d::Rect	getRect();
	virtual void			collisionOccured(InteractiveObject* enemy , Directions dir , OUT bool * isRemoving) {};
	ObjectType				getType() const { return m_Type; };

protected:
	enum ZOrder
	{
		LZ_PIECE = 0,
		LZ_MAIN,
	};
	cocos2d::Sprite*		m_PieceSprite;
};
