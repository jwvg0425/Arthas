#include "Monster.h"

class RushMonster : public Monster
{
public:
	OVERRIDE bool			init();

	OVERRIDE void			collisionOccured(InteractiveObject* enemy, Directions dir);

	CREATE_FUNC(RushMonster);

private:

};