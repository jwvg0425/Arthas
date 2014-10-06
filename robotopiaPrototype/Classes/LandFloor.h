#pragma once
#include "cocos2d.h"
#include "LandObject.h"

class LandFloor : public LandObject
{
public:
	OVERRIDE bool		init();
	virtual void		collisionOccured(InteractiveObject* enemy , Direction dir , OUT bool * isRemoving) {};

	CREATE_FUNC( LandFloor );
};
