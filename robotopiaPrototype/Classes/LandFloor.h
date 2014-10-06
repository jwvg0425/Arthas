#include "cocos2d.h"
#include "LandObject.h"

class LandFloor : public LandObject
{
public:
	OVERRIDE bool init();
	OVERRIDE void update();

	virtual void			collisionOccured(InteractiveObject* enemy , Direction dir , OUT bool * isRemoving) {};
};
