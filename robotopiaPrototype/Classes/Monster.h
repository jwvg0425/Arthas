#include "InteractiveObject.h"

class Monster : public InteractiveObject
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			collisionOccured(InteractiveObject* enemy, Directions dir);

	CREATE_FUNC(Monster);
private:
};