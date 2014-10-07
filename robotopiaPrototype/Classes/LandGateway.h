#pragma once
#include "cocos2d.h"
#include "LandObject.h"

class LandGateway : public LandObject
{
public:
	OVERRIDE bool		init();
	OVERRIDE void		collisionOccured( InteractiveObject* enemy , Directions dir );
	void				gotoNextLevel( Ref* sender );
	CREATE_FUNC( LandGateway );
private:
	cocos2d::Animation*	m_OpenAnimaion;
	bool m_isOpen;
};
