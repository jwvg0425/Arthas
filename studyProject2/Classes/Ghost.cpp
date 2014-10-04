#include "Ghost.h"
#include "Effect.h"
#include "GameScene.h"
#include "LinearBullet.h"

USING_NS_CC;

bool Ghost::init()
{
	Monster::init();

	m_AttackType = 5;
	m_AttackTime = 0.4;
	m_AttackDelay = 0;
	m_Hp = 2;

	m_CreateTime = time(NULL);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ghost.plist");

	m_Sprite = Sprite::createWithSpriteFrameName("ghost1.png");
	m_Sprite->setAnchorPoint(Point(0.5, 0.5));

	auto animation = Animation::create();

	animation->setDelayPerUnit(0.15);

	for (int i = 0; i < 4; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format(
			"ghost%d.png", i + 1));

		animation->addSpriteFrame(frame);
	}

	auto animate = Animate::create(animation);
	m_Sprite->runAction(RepeatForever::create(animate));

	this->addChild(m_Sprite);

	m_Width = m_Sprite->getContentSize().width;
	m_Height = m_Sprite->getContentSize().height;

	this->scheduleUpdate();

	return true;
}

void Ghost::update(float delta)
{
	int t = time(NULL);
	m_AttackDelay += delta;

	if (t - m_CreateTime < 3)
	{
		auto pos = this->getPosition();
		pos.x -= 1;
		this->setPosition(pos);
	}
	else if (t - m_CreateTime < 8)
	{
		if (m_AttackType == 0)
		{
			if (m_AttackDelay >= 1)
			{
				m_AttackDelay = 0;
				m_AttackType = 5;
			}
		}
		else
		{
			if (m_AttackDelay >= m_AttackTime)
			{
				m_AttackDelay = 0;
				if (m_AttackType == 1)
				{
					auto bullet = LinearBullet::create();

					bullet->setMoveAttribute(false, 3, 0);
					bullet->setPosition(this->getPosition());

					((GameScene*)this->getParent())->addCharacter(bullet);
				}
				else
				{
					float delta = 80 / (m_AttackType - 1);

					for (int i = 0; i < m_AttackType; i++)
					{
						auto bullet = LinearBullet::create();

						bullet->setMoveAttribute(false, 3, -40 + i*delta);
						bullet->setPosition(this->getPosition());

						((GameScene*)this->getParent())->addCharacter(bullet);
					}
				}
				m_AttackType--;
			}
		}
	}
	else
	{
		auto pos = this->getPosition();
		pos.x -= 3;
		this->setPosition(pos);
	}
}

bool Ghost::collisionOccured(const Character* enemy)
{
	if (Monster::collisionOccured(enemy))
	{
		EffectManager* effectManager = (EffectManager*)this->getParent()->getChildByTag(EFFECT_MANAGER_TAG);
		effectManager->createEffect(EffectManager::GHOST_DIE, this->getPosition());
		return true;
	}
	return false;
}

cocos2d::Rect Ghost::getSize() const
{
	float x = this->getPositionX();
	float y = this->getPositionY();

	return Rect(x - m_Width / 2, y - m_Height / 2, m_Width, m_Height);
}
