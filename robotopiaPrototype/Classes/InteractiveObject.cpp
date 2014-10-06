#include "InteractiveObject.h"

USING_NS_CC;

bool InteractiveObject::init()
{
	if (!Node::init())
	{
		return false;
	}

	m_MainSprite = nullptr;
	m_AnimationNum = 0;
	m_Width = 0;
	m_Height = 0;
	m_Type = OT_OBJECT;
	m_Velocity = Vec2(0, 0);
	m_IsOnGravity = true;
	m_MoveSpeed = 0;
	m_IsDestroyed = false;

	return true;
}

Directions InteractiveObject::collisionCheck(InteractiveObject* enemy, float dTime)
{
	float vertTime = dTime + 1;
	float horzTime = dTime + 1;

	Directions collisionDir = DIR_NONE;
	Rect myVertAfterRect = this->getRect();
	Rect enemyVertAfterRect = enemy->getRect();
	Rect myHorzAfterRect = this->getRect();
	Rect enemyHorzAfterRect = enemy->getRect();
	Rect myAfterRect = this->getRect();
	Rect enemyAfterRect = enemy->getRect();

	myAfterRect.origin.x += this->getVelocity().x*dTime;
	enemyAfterRect.origin.x += enemy->getVelocity().x*dTime;
	myHorzAfterRect.origin.x += this->getVelocity().x*dTime;
	enemyHorzAfterRect.origin.x += enemy->getVelocity().x*dTime;

	myAfterRect.origin.y += this->getVelocity().y*dTime;
	enemyAfterRect.origin.y += enemy->getVelocity().y*dTime;
	myVertAfterRect.origin.y += this->getVelocity().y*dTime;
	enemyVertAfterRect.origin.y += enemy->getVelocity().y*dTime;

	//일단 충돌이 일어나는지 여부부터 확인
	if (myAfterRect.intersectsRect(enemyAfterRect))
	{
		//아래쪽 면 검사
		float gap = this->getRect().origin.y - (enemy->getRect().origin.y + enemy->getRect().size.height);
		float afterGap = myVertAfterRect.origin.y - (enemyVertAfterRect.origin.y + enemyVertAfterRect.size.height);

		if (gap*afterGap < 0)
		{
			float length = abs(this->getRect().origin.y + this->getRect().size.height / 2
				- (enemy->getRect().origin.y + enemy->getRect().size.height / 2))
				- this->getRect().size.height / 2 - enemy->getRect().size.height / 2;

			float velocity = abs(this->getVelocity().y - enemy->getVelocity().y);

			float time = length / velocity;

			if (time < vertTime)
			{
				vertTime = time;
			}
			collisionDir |= DIR_DOWN;
		}

		//위쪽 면 검사
		gap = this->getRect().origin.y + this->getRect().size.height - enemy->getRect().origin.y;
		afterGap = myVertAfterRect.origin.y + myVertAfterRect.size.height - enemyVertAfterRect.origin.y;

		if (gap*afterGap < 0)
		{
			float length = abs(this->getRect().origin.y + this->getRect().size.height / 2
				- (enemy->getRect().origin.y + enemy->getRect().size.height / 2))
				- this->getRect().size.height / 2 - enemy->getRect().size.height / 2;

			float velocity = abs(this->getVelocity().y - enemy->getVelocity().y);

			float time = length / velocity;

			if (time < vertTime)
			{
				vertTime = time;
			}
			collisionDir |= DIR_UP;
		}

		gap = this->getRect().origin.x - (enemy->getRect().origin.x + enemy->getRect().size.width);
		afterGap = myHorzAfterRect.origin.x - (enemyHorzAfterRect.origin.x + enemyHorzAfterRect.size.width);

		if (gap*afterGap < 0)
		{
			float length = abs(this->getRect().origin.x + this->getRect().size.width / 2
				- (enemy->getRect().origin.x + enemy->getRect().size.width / 2))
				- this->getRect().size.width / 2 - enemy->getRect().size.width / 2;

			float velocity = abs(this->getVelocity().x - enemy->getVelocity().x);

			float time = length / velocity;

			if (time < horzTime)
			{
				horzTime = time;
			}
			collisionDir |= DIR_LEFT;
		}

		//오른쪽 면


		gap = this->getRect().origin.x + this->getRect().size.width - enemy->getRect().origin.x;
		afterGap = myHorzAfterRect.origin.x + myHorzAfterRect.size.width - enemyHorzAfterRect.origin.x;

		if (gap*afterGap < 0)
		{
			float length = abs(this->getRect().origin.x + this->getRect().size.width / 2
				- (enemy->getRect().origin.x + enemy->getRect().size.width / 2))
				- this->getRect().size.width / 2 - enemy->getRect().size.width / 2;

			float velocity = abs(this->getVelocity().x - enemy->getVelocity().x);

			float time = length / velocity;

			if (time < horzTime)
			{
				horzTime = time;
			}
			collisionDir |= DIR_RIGHT;
		}
	}

	if (collisionDir != DIR_NONE)
	{
		auto pos = this->getPosition();
		float changeX = pos.x, changeY = pos.y;

		if (collisionDir&DIR_LEFT || collisionDir&DIR_RIGHT)
		{
			changeX = pos.x + horzTime*this->getVelocity().x;
		}
		if (collisionDir&DIR_UP || collisionDir&DIR_DOWN)
		{
			changeY = pos.y + vertTime*this->getVelocity().y;
		}

		if (collisionDir & DIR_LEFT &&this->getVelocity().x != 0)
		{
			changeX += m_MoveSpeed * 0.0001;
		}

		if (collisionDir & DIR_RIGHT && this->getVelocity().x != 0)
		{
			changeX -= m_MoveSpeed * 0.0001;
		}

		if (collisionDir & DIR_DOWN)
		{
			changeY += GRAVITY*0.0001;
		}

		if (collisionDir & DIR_LEFT && changeX == pos.x)
		{
			collisionDir &= ~DIR_LEFT;
		}

		if (collisionDir & DIR_RIGHT && changeX == pos.x)
		{
			collisionDir &= ~DIR_RIGHT;
		}

		pos.x = changeX;
		pos.y = changeY;

		this->setPosition(pos);

	}
	
	return collisionDir;
}

cocos2d::Rect InteractiveObject::getRect()
{
	Point pos = this->getPosition();
	Point Anchor = this->getAnchorPoint();

	return Rect(pos.x - Anchor.x*m_Width, pos.y - Anchor.y*m_Height, m_Width, m_Height);
}

cocos2d::Vec2 InteractiveObject::getVelocity() const
{
	return m_Velocity;
}
