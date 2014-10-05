#include "UtilFunction.h"

USING_NS_CC;

Animation* UtilFunction::makeAnimation(const char* animationName, int startIdx, size_t size, float delay)
{
	auto animation = Animation::create();
	animation->setDelayPerUnit(delay);

	for (size_t i = 0; i < size; ++i)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format("%s%d.png", animationName, i + startIdx));
		animation->addSpriteFrame(frame);
	}
	return animation;
}

CollisionDirection UtilFunction::getReverseDirection(CollisionDirection dir)
{
	switch (dir)
	{
	case CD_TOP:
		return CD_BOTTOM;
	case CD_BOTTOM:
		return CD_TOP;
	case CD_LEFT:
		return CD_RIGHT;
	case CD_RIGHT:
		return CD_LEFT;
	}
	return CD_NONE;
}
