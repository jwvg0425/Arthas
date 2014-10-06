#pragma once
#include "cocos2d.h"
#include "InteractiveObject.h"

class LandObject : public InteractiveObject
{
public:
	OVERRIDE bool			init();
	virtual void			collisionOccured(InteractiveObject* enemy , Direction dir , OUT bool * isRemoving) {};
	ObjectType				getType() const { return m_Type; };

protected:
	enum ZOrder
	{
		LZ_PIECE = 0,
		LZ_MAIN,
	};
	cocos2d::Sprite*		m_PieceSprite;
	LandType				m_LandType;
};
