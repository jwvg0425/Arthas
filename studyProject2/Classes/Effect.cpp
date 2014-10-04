#include "Effect.h"


USING_NS_CC;


bool EffectManager::init()
{
	return true;
}

void EffectManager::createEffect(Type t,Point pos)
{
	Sprite* sprite;

	switch (t)
	{
	case BULLET_EFFECT:
		if (true)
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bullet_effect.plist");

			sprite = Sprite::createWithSpriteFrameName("bullet_effect1.png");
			

			auto animation = Animation::create();
			animation->setDelayPerUnit(0.1);

			for (int i = 0; i < 7; i++)
			{
				auto frame = SpriteFrameCache::getInstance()->
					getSpriteFrameByName(StringUtils::format(
					"bullet_effect%d.png", i + 1));

				animation->addSpriteFrame(frame);
			}
			auto animate = Animate::create(animation);
			auto callback = CallFuncN::create(CC_CALLBACK_1(EffectManager::removeEffect, this));

			sprite->runAction(Sequence::create(animate,callback,NULL));

			
		}
		break;
	}
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(pos);
	this->addChild(sprite);
}

void EffectManager::removeEffect(Ref* sender)
{
	this->removeChild((Node*)sender);
}

