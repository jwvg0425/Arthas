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

	Rect myRect = this->getRect();
	Rect enemyRect = enemy->getRect();

	//이미 충돌이 일어난 경우 한 프레임 전으로 돌려서 해결한다.
	if (!(myRect.origin.x + myRect.size.width <= enemyRect.origin.x ||
		myRect.origin.y + myRect.size.height <= enemyRect.origin.y ||
		myRect.origin.x >= enemyRect.origin.x + enemyRect.size.width ||
		myRect.origin.y >= enemyRect.origin.y + enemyRect.size.height))
	{
		myRect.origin.x -= this->getVelocity().x*dTime;
		enemyRect.origin.x -= enemy->getVelocity().x*dTime; 

		myRect.origin.y -= this->getVelocity().y*dTime;
		enemyRect.origin.y -= enemy->getVelocity().y*dTime;
	}



	Rect myAfterRect = myRect;
	Rect enemyAfterRect = enemyRect;

	myAfterRect.origin.x += this->getVelocity().x*dTime;
	enemyAfterRect.origin.x += enemy->getVelocity().x*dTime;


	myAfterRect.origin.y += this->getVelocity().y*dTime;
	enemyAfterRect.origin.y += enemy->getVelocity().y*dTime;


	//일단 충돌이 일어나는지 여부부터 확인
	if (myAfterRect.intersectsRect(enemyAfterRect))
	{
		//아래쪽 면 검사
		float gap = myRect.origin.y - (enemyRect.origin.y + enemyRect.size.height);
		float afterGap = myAfterRect.origin.y - (enemyAfterRect.origin.y + enemyAfterRect.size.height);

		if (gap*afterGap <= 0 )
		{
			float length = abs(myRect.origin.y + myRect.size.height / 2
				- (enemyRect.origin.y + enemyRect.size.height / 2))
				- myRect.size.height / 2 - enemyRect.size.height / 2;

			float velocity = abs(this->getVelocity().y - enemy->getVelocity().y);

			float time = length / velocity;

			if (time < vertTime)
			{
				vertTime = time;
			}
			collisionDir |= DIR_DOWN;
		}

		//위쪽 면 검사
		gap = myRect.origin.y + myRect.size.height - enemyRect.origin.y;
		afterGap = myAfterRect.origin.y + myAfterRect.size.height - enemyAfterRect.origin.y;

		if (gap*afterGap <= 0)
		{
			float length = abs(myRect.origin.y + myRect.size.height / 2
				- (enemyRect.origin.y + enemyRect.size.height / 2))
				- myRect.size.height / 2 - enemyRect.size.height / 2;

			float velocity = abs(this->getVelocity().y - enemy->getVelocity().y);

			float time = length / velocity;

			if (time < vertTime)
			{
				vertTime = time;
			}
			collisionDir |= DIR_UP;
		}

		//왼쪽면

		gap = myRect.origin.x - (enemyRect.origin.x + enemyRect.size.width);
		afterGap = myAfterRect.origin.x - (enemyAfterRect.origin.x + enemyAfterRect.size.width);

		if (gap*afterGap <= 0)
		{
			float length = abs(myRect.origin.x + myRect.size.width / 2
				- (enemyRect.origin.x + enemyRect.size.width / 2))
				- myRect.size.width / 2 - enemyRect.size.width / 2;

			float velocity = abs(this->getVelocity().x - enemy->getVelocity().x);

			float time = length / velocity;

			if (time < horzTime)
			{
				horzTime = time;
			}
			collisionDir |= DIR_LEFT;
		}

		//오른쪽 면


		gap = myRect.origin.x + myRect.size.width - enemyRect.origin.x;
		afterGap = myAfterRect.origin.x + myAfterRect.size.width - enemyAfterRect.origin.x;

		if (gap*afterGap <= 0)
		{
			float length = abs(myRect.origin.x + myRect.size.width / 2
				- (enemyRect.origin.x + enemyRect.size.width / 2))
				- myRect.size.width / 2 - enemyRect.size.width / 2;

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

		if (vertTime == 0)
		{
			collisionDir &= ~DIR_LEFT;
			collisionDir &= ~DIR_RIGHT;
		}

		if (horzTime == 0)
		{
			collisionDir &= ~DIR_UP;
			collisionDir &= ~DIR_DOWN;
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
