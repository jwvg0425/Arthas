#pragma once
#include "InteractiveObject.h"
#include "Utils.h"

class Villager : public InteractiveObject
{
public:
	OVERRIDE bool	init();
	OVERRIDE void	collisionOccured( InteractiveObject* enemy , Directions dir );
	void			update( float dTime );
	cocos2d::Rect	getRect();

	CREATE_FUNC( Villager );
private:

};