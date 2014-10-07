//Monster.h
//
// 모든 몬스터들의 최상위 클래스.
//
//작성자 : 남현욱
//
#pragma once
#include "InteractiveObject.h"

class Monster : public InteractiveObject
{
public:
	OVERRIDE bool			init();
	ABSTRACT void			collisionOccured(InteractiveObject* enemy, Directions dir) = 0;

private:
};