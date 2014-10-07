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
	m_Type = OT_NONE;
	m_Velocity = Vec2(0, 0);
	m_IsOnGravity = true;
	m_MoveSpeed = 0;
	m_IsDestroyed = false;
	m_IsFlying = false;

	return true;
}

Directions InteractiveObject::collisionCheck(InteractiveObject* enemy, float dTime)
{
	float vertTime = dTime + 1;
	float horzTime = dTime + 1;

	Directions collisionDir = DIR_NONE;

	Rect myAfterRect = this->getRect();
	Rect enemyAfterRect = enemy->getRect();

	myAfterRect.origin.x += this->getVelocity().x*dTime;
	enemyAfterRect.origin.x += enemy->getVelocity().x*dTime;


	myAfterRect.origin.y += this->getVelocity().y*dTime;
	enemyAfterRect.origin.y += enemy->getVelocity().y*dTime;



	//일단 충돌이 일어나는지 여부부터 확인
	if (myAfterRect.intersectsRect(enemyAfterRect))
	{
		//아래쪽 면 검사
		float gap = this->getRect().origin.y - (enemy->getRect().origin.y + enemy->getRect().size.height);
		float afterGap = myAfterRect.origin.y - (enemyAfterRect.origin.y + enemyAfterRect.size.height);

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
		afterGap = myAfterRect.origin.y + myAfterRect.size.height - enemyAfterRect.origin.y;

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

		//왼쪽면

		gap = this->getRect().origin.x - (enemy->getRect().origin.x + enemy->getRect().size.width);
		afterGap = myAfterRect.origin.x - (enemyAfterRect.origin.x + enemyAfterRect.size.width);

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
		afterGap = myAfterRect.origin.x + myAfterRect.size.width - enemyAfterRect.origin.x;

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

	if (collisionDir != DIR_NONE && !enemy->isOnGravity())
	{
		Point changePos = this->getPosition();
		Point pos = this->getPosition();
		Directions rowDir = collisionDir;

		
		if (collisionDir&DIR_LEFT || collisionDir&DIR_RIGHT)
		{
			changePos.x = pos.x + horzTime*this->getVelocity().x;
		}
		if (collisionDir&DIR_UP || collisionDir&DIR_DOWN)
		{
			changePos.y = pos.y + vertTime*this->getVelocity().y;
		}

		if (collisionDir & DIR_LEFT &&this->getVelocity().x != 0)
		{
			changePos.x += m_MoveSpeed * 0.0001;
		}

		if (collisionDir & DIR_RIGHT && this->getVelocity().x != 0)
		{
			changePos.x -= m_MoveSpeed * 0.0001;
		}

		if (collisionDir & DIR_DOWN && this->isOnGravity())
		{
			changePos.y += GRAVITY*0.0001;
		}

		if (collisionDir & DIR_DOWN || collisionDir & DIR_UP)
		{
			if (collisionDir & DIR_LEFT && changePos.y == pos.y)
			{
				collisionDir &= ~DIR_LEFT;
			}

			if (collisionDir & DIR_RIGHT && changePos.y == pos.y)
			{
				collisionDir &= ~DIR_RIGHT;
			}
		}

		if (collisionDir & DIR_RIGHT || collisionDir & DIR_LEFT)
		{
			if (collisionDir & DIR_DOWN && changePos.x == pos.x)
			{
				collisionDir &= ~DIR_DOWN;
			}
			if (collisionDir & DIR_UP && changePos.x == pos.x)
			{
				collisionDir &= ~DIR_UP;
			}
		}
		

		if (this->getType() == OT_PLAYER)
		{
			CCLOG("dir : %d -> %d", rowDir, collisionDir);
		}
		
		if (collisionDir & DIR_DOWN || collisionDir & DIR_UP)
		{
			changePos.x = pos.x;
		}

		if (collisionDir & DIR_RIGHT || collisionDir & DIR_LEFT)
		{	
			changePos.y = pos.y;
		}

		this->setPosition(changePos);
	}
	
	return collisionDir;
}

cocos2d::Rect InteractiveObject::getRect()
{
	Point pos = this->getPosition();
	Point Anchor = this->getAnchorPoint();
	float width =  m_MainSprite->getContentSize().width;
	float height = m_MainSprite->getContentSize().height;

	if (m_MainSprite == nullptr)
	{
		return Rect(pos.x - Anchor.x*m_Width, pos.y - Anchor.y*m_Height, m_Width, m_Height);
	}
	else
	{
		return Rect(pos.x - Anchor.x*width, pos.y - Anchor.y*height, width, height);
	}
}

cocos2d::Vec2 InteractiveObject::getVelocity() const
{
	return m_Velocity;
}
