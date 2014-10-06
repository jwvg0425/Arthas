#include "cocos2d.h"
#include "InteractiveObject.h"

class LandObject : public InteractiveObject
{
public:
	OVERRIDE bool init();
	OVERRIDE void update();

	virtual void			collisionOccured(InteractiveObject* enemy , Direction dir , OUT bool * isRemoving) {};
	virtual Direction		collisionCheck(InteractiveObject* enemy, float dTime);
	ObjectType				getType() const { return m_Type; };

};
