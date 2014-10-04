#include "Effect.h"


USING_NS_CC;


bool EffectManager::init()
{
	return true;
}

void EffectManager::createEffect(Type t,Point pos)
{
	Sprite* sprite;
	auto callback = CallFuncN::create(CC_CALLBACK_1(EffectManager::removeEffect, this));

	switch (t)
	{
	case BULLET_EFFECT:
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bullet_effect.plist");

			sprite = Sprite::createWithSpriteFrameName("bullet_effect1.png");
			
			auto animation = Animation::create();
			animation->setDelayPerUnit(0.1);

			for (int i = 0; i < 7; i++)
			{
				auto frame = SpriteFrameCache::getInstance()->
					getSpriteFrameByName(StringUtils::format("bullet_effect%d.png", i + 1));

				animation->addSpriteFrame(frame);
			}
			auto animate = Animate::create(animation);
			
			sprite->runAction(Sequence::create(animate,callback,NULL));
		}
		break;
	case BAT_DIE:
		{
			sprite = Sprite::create("bat_die.png");
			auto action = FadeOut::create(0.5);
			sprite->runAction(Sequence::create(action, callback, NULL));
		}
		break;
	case GHOST_DIE:
		if (true)
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ghost_die.plist");

			sprite = Sprite::createWithSpriteFrameName("ghost_die1.png");

			auto animation = Animation::create();
			animation->setDelayPerUnit(0.1);

			for (int i = 0; i < 10; i++)
			{
				auto frame = SpriteFrameCache::getInstance()->
					getSpriteFrameByName(StringUtils::format("ghost_die%d.png", i + 1));

				animation->addSpriteFrame(frame);
			}
			auto animate = Animate::create(animation);

			sprite->runAction(Sequence::create(animate, callback, NULL));
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

