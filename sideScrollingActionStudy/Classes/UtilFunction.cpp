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