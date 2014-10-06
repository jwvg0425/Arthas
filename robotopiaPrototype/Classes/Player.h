#pragma once

#include "InteractiveObject.h"

class Player : public InteractiveObject
{
public:
	OVERRIDE bool			init();
	CREATE_FUNC(Player);

	OVERRIDE void			collisionOccured(InteractiveObject* enemy, Direction dir, OUT bool * isRemoving);

	void update(float dTime);
private:
};