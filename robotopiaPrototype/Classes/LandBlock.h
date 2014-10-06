#pragma once
#include "cocos2d.h"
#include "LandObject.h"

class LandBlock : public LandObject
{
public:
	OVERRIDE bool		init();
	virtual void		collisionOccured( InteractiveObject* enemy , Directions dir ){};

	CREATE_FUNC( LandBlock );
};
