#include "GameScene.h"
#include "Player.h"
#include "LinearBullet.h"

USING_NS_CC;


bool Player::init()
{
	m_Type = PLAYER;
	m_Velocity = 3;
	m_Direction = 0;
	m_AttackDelay = 0;
	m_AfterAttackDelay = 0;
	m_AttackSpeed = 0.7;
	m_IsAttacking = false;
	m_UnbeatableTime = 2;
	m_IsUnbeatable = false;
	m_CollisionKind = ENEMY | BULLET;

	initStand();
	initAttack();

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

	m_StandSprite= Sprite::createWithSpriteFrameName("player1.png");
	m_StandSprite->setAnchorPoint(Point(0.5, 0.5));
	m_StandSprite->setFlippedX(true);

	m_StandAnimation = Animation::create();
	m_StandAnimation->setDelayPerUnit(0.2);

	for (int i = 0; i < 5; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format(
			"player%d.png", i + 1));

		m_StandAnimation->addSpriteFrame(frame);
	}

	auto animate = Animate::create(m_StandAnimation);
	m_StandSprite->runAction(RepeatForever::create(animate));

	this->addChild(m_StandSprite);

	m_NowSprite = m_StandSprite;
}

void Player::initAttack()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("player_attack.plist");

	m_AttackSprite = Sprite::createWithSpriteFrameName("attack1.png");
	m_AttackSprite->setAnchorPoint(Point(0.5, 0.5));
	m_AttackSprite->setFlippedX(true);

	m_AttackAnimation = Animation::create();
	m_AttackAnimation->setDelayPerUnit(m_AttackSpeed/7);
	m_AttackAnimation->retain();

	for (int i = 0; i < 7; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->
			getSpriteFrameByName(StringUtils::format(
			"attack%d.png", i + 1));

		m_AttackAnimation->addSpriteFrame(frame);
	}

	m_AttackSprite->setVisible(false);

	this->addChild(m_AttackSprite);
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
		if (m_Status != ATTACK)
		{
			m_AttackDelay = 0;
			m_AfterAttackDelay = 0;
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
	m_AttackDelay += delta;
	m_AfterAttackDelay += delta;

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

	

	if (m_AttackDelay >= m_AttackSpeed/2 && m_Status == ATTACK)
	{
		m_AttackDelay -= m_AttackSpeed;

		auto bullet = LinearBullet::create();

		bullet->setMoveAttribute(true, 4, 0);
		bullet->setPosition(this->getPosition());

		((GameScene*)this->getParent())->addCharacter(bullet);
	}

	if (m_AfterAttackDelay >= m_AttackSpeed)
	{
		if (!m_IsAttacking)
		{
			changeStatus(STAND);
		}
		m_AfterAttackDelay = 0;
	}
}

cocos2d::Rect Player::getSize()
{
	float x = this->getPositionX();
	float y = this->getPositionY();

	return Rect(x - m_Width / 2, y - m_Height / 2, m_Width, m_Height);
}

void Player::changeStatus(Status status)
{
	m_Status = status;
	switch (status)
	{
	case STAND:
		m_NowSprite = m_StandSprite;
		m_AttackSprite->stopAllActions();
		m_AttackSprite->setVisible(false);
		m_StandSprite->setVisible(true);
		break;
	case ATTACK:
		m_NowSprite = m_AttackSprite;
		m_StandSprite->setVisible(false);
		m_AttackSprite->setVisible(true);
		m_AttackSprite->runAction(RepeatForever::create(Animate::create(m_AttackAnimation)));
		break;
	}
}

bool Player::collisionOccured(Character* enemy)
{
	if ((enemy->getCollisionKind() & PLAYER) && !isUnbeatable())
	{
		startUnbeatableState();
	}
	return false;
}

bool Player::isUnbeatable()
{
	return m_IsUnbeatable;
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
