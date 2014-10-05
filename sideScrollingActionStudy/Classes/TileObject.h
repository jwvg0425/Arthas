#pragma once
#include"InteractiveObject.h"

enum TileType
{
	TT_FLOOR,
};
class TileObject : public InteractiveObject
{
public:
	virtual bool			init();
	virtual void			collisionOccured( InteractiveObject* enemy , CollisionDirection dir , OUT bool* isRemoving ){};
	virtual void			update( float dTime )
	{
	};

	CREATE_FUNC( TileObject );

private:
	TileType				m_TileType;
};