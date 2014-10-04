#include "GameScene.h"
#include "Player.h"
#include "LinearBullet.h"

USING_NS_CC;


bool Player::init()
{
	Character::init();

	m_Type = PLAYER;
	m_Velocity = 4;
	m_Direction = 0;
	m_MotionDelay = 0;
	m_AfterMotionDelay = 0;
	m_AttackSpeed = 0.5;
	m_IsAttacking = false;
	m_UnbeatableTime = 2;
	m_AttackedTime = 0.4;

	initStand();
	initAttack();
	initAttacked();

	auto keyListener = EventListenerKeyboard::create();

	keyListener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	this->scheduleUpdate();

	return true;
}

void Player::initStand()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("player_stand.plist");

	m_Sprites[STAND]= Sprite::createWithSpriteFrameName("player1.png");
	m_Sprites[STAND]->setAnchorPoint(Point(0.5, 0.5));
	m_Sprites[STAND]->setFlippedX(true);

	m_Animation[STAND] = Animation::create();
	m_Animation[STAND]->setDelayPerUnit(0.2);
	m_Animation[STAND]->retain();

	for (int i = 0; i < 5; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format(
			"player%d.png", i + 1));

		m_Animation[STAND]->addSpriteFrame(frame);
	}

	this->addChild(m_Sprites[STAND]);

	m_NowSprite = m_Sprites[STAND];
}

void Player::initAttack()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("player_attack.plist");

	m_Sprites[ATTACK] = Sprite::createWithSpriteFrameName("attack1.png");
	m_Sprites[ATTACK]->setAnchorPoint(Point(0.5, 0.5));
	m_Sprites[ATTACK]->setFlippedX(true);

	m_Animation[ATTACK] = Animation::create();
	m_Animation[ATTACK]->setDelayPerUnit(m_AttackSpeed/7);
	m_Animation[ATTACK]->retain();

	for (int i = 0; i < 7; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format(
			"attack%d.png", i + 1));

		m_Animation[ATTACK]->addSpriteFrame(frame);
	}

	m_Sprites[ATTACK]->setVisible(false);

	this->addChild(m_Sprites[ATTACK]);
}

void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_Direction |= UP;
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_Direction |= LEFT;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_Direction |= RIGHT;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		m_Direction |= DOWN;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		if (m_Status == STAND)
		{
			changeStatus(ATTACK);
		}
		m_IsAttacking = true;
		break;
	}
}

void Player::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_Direction &= ~UP;
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		m_Direction &= ~LEFT;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_Direction &= ~RIGHT;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		m_Direction &= ~DOWN;
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		m_IsAttacking = false;
		break;
	}
}

void Player::update(float delta)
{
	m_MotionDelay += delta;
	m_AfterMotionDelay += delta;

	m_Width = m_NowSprite->getContentSize().width;
	m_Height = m_NowSprite->getContentSize().height;

	Point pos = this->getPosition();

	if (m_Direction & UP)
	{
		pos.y += m_Velocity;
	}
	else if (m_Direction & DOWN)
	{
		pos.y -= m_Velocity;
	}

	if (m_Direction & LEFT)
	{
		pos.x -= m_Velocity;
	}
	else if (m_Direction & RIGHT)
	{
		pos.x += m_Velocity;
	}

	if (!(pos.x - m_Width/2 <0 || pos.x + m_Width/2 > Director::getInstance()->getWinSize().width ||
		pos.y - m_Height/2 <0 || pos.y + m_Height/2> Director::getInstance()->getWinSize().height))
	{
		this->setPosition(pos);
	}

	if (m_MotionDelay >= m_AttackedTime && m_Status == ATTACKED)
	{
		if (m_IsAttacking)
		{
			changeStatus(ATTACK);
		}
		else
		{
			changeStatus(STAND);
		}
	}

	if (m_MotionDelay >= m_AttackSpeed/2 && m_Status == ATTACK)
	{
		m_MotionDelay -= m_AttackSpeed;

		auto bullet = LinearBullet::create();

		bullet->setMoveAttribute(true, 6, 0);
		bullet->setPosition(this->getPosition());

		((GameScene*)this->getParent())->addCharacter(bullet);
	}

	if (m_AfterMotionDelay >= m_AttackSpeed)
	{
		if (!m_IsAttacking)
		{
			changeStatus(STAND);
		}
		m_AfterMotionDelay = 0;
	}
}

cocos2d::Rect Player::getSize() const
{
	float x = this->getPositionX();
	float y = this->getPositionY();

	return Rect(x - m_Width / 2, y - m_Height / 2, m_Width, m_Height);
}

void Player::changeStatus(Status status)
{
	m_MotionDelay = 0;
	m_AfterMotionDelay = 0;
	m_Status = status;
	m_NowSprite = m_Sprites[status];

	for (int i = 0; i < STATE_NUM; i++)
	{
		if (i == status)
		{
			m_Sprites[i]->setVisible(true);
			m_Sprites[i]->runAction(RepeatForever::create(Animate::create(m_Animation[i])));
		}
		else
		{
			m_Sprites[i]->setVisible(false);
			m_Sprites[i]->stopAllActions();
		}
	}
}

void Player::startUnbeatableState()
{
	if (!m_IsUnbeatable)
	{
		m_IsUnbeatable = true;
		auto action = Blink::create(m_UnbeatableTime, m_UnbeatableTime * 5);
		auto callback = CallFuncN::create(CC_CALLBACK_1(Player::endUnbeatableState, this));

		this->runAction(Sequence::create(action, callback, NULL));
	}
}

void Player::endUnbeatableState(Ref* sender)
{
	m_IsUnbeatable = false;
}

bool Player::collisionOccured(const Character* enemy)
{
	if (enemy->getType() == BULLET)
	{
		Bullet* bullet = (Bullet*)enemy;

		if (!bullet->IsPlayersBullet())
		{
			changeStatus(ATTACKED);
			startUnbeatableState();
		}
	}

	return false;
}

void Player::initAttacked()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("player_attacked.plist");

	m_Sprites[ATTACKED] = Sprite::createWithSpriteFrameName("attacked1.png");
	m_Sprites[ATTACKED]->setAnchorPoint(Point(0.5, 0.5));
	m_Sprites[ATTACKED]->setFlippedX(true);

	m_Animation[ATTACKED] = Animation::create();
	m_Animation[ATTACKED]->setDelayPerUnit(m_AttackedTime/3);
	m_Animation[ATTACKED]->retain();

	for (int i = 0; i < 3; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format(
			"attacked%d.png", i + 1));

		m_Animation[ATTACKED]->addSpriteFrame(frame);
	}

	m_Sprites[ATTACKED]->setVisible(false);

	this->addChild(m_Sprites[ATTACKED]);
}
