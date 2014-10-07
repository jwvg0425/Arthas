#include "Monster.h"

class RushMonster : public Monster
{
public:
	OVERRIDE bool			init();

	OVERRIDE void			collisionOccured(InteractiveObject* enemy, Directions dir);

	CREATE_FUNC(RushMonster);

private:
	enum State
	{
		RM_STAND,
		RM_MOVE,
		RM_RUSH,
		RM_STATE_NUM,
	};

	void		changeState(State state);
	void		endAnimation(cocos2d::Ref* sender);
	void		update(float dTime);
	
	float		m_DelayTime;
	State		m_State;
	bool		m_IsRightDirection;
};