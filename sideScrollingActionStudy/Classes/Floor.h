#pragma once
#include "cocos2d.h"
#include"TileObject.h"

class Floor : public TileObject
{
public:
	virtual bool			init();
	virtual void			collisionOccured( InteractiveObject* enemy , CollisionDirection dir , OUT bool* isRemoving );
	virtual void			update( float dTime ){};
	void					addPieces();
	CREATE_FUNC( Floor );
private:
	TileType				m_TileType;
};