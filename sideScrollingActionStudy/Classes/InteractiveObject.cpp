#include "InteractiveObject.h"

USING_NS_CC;

const float InteractiveObject::GRAVITY = 98;

bool InteractiveObject::init()
{
	return true;
}

cocos2d::Rect InteractiveObject::getRect()
{
	Point pos = this->getPosition();

	return Rect(pos.x - m_Width / 2, pos.y - m_Height / 2, m_Width, m_Height);
}

cocos2d::Vec2 InteractiveObject::getVelocity() const
{
	return Vec2(m_Vx, m_Vy);
}

CollisionDirection InteractiveObject::collisionCheck(InteractiveObject* enemy,float dTime)
{

	//dTime만큼 움직여서 충돌이 일어났으므로 최소시간이 dTime+1보다 큰 경우는 절대 없음
	float minTime = dTime + 1;

	CollisionDirection dir = CD_NONE;
	Rect myAfterRect = this->getRect();
	Rect enemyAfterRect = enemy->getRect();

	myAfterRect.origin.x += this->getVelocity().x*dTime;
	myAfterRect.origin.y += this->getVelocity().y*dTime;

	enemyAfterRect.origin.x += enemy->getVelocity().x*dTime;
	enemyAfterRect.origin.y += enemy->getVelocity().y*dTime;

	//위쪽 면 충돌 검사

	//우선 위쪽 면이 충돌했을 가능성이 있는지 여부부터 조사.
	if (enemyAfterRect.containsPoint(myAfterRect.origin) ||
		enemyAfterRect.containsPoint(Point(myAfterRect.origin.x + myAfterRect.size.width, myAfterRect.origin.y)))
	{
		//가능성이 있는 경우 실제 충돌여부 검사
		float gap = this->getRect().origin.y - (enemy->getRect().origin.y+enemy->getRect().size.height);
		float afterGap = myAfterRect.origin.y - (enemyAfterRect.origin.y + enemyAfterRect.size.height);

		if (gap*afterGap < 0)
		{
			float length = abs(this->getRect().origin.y + this->getRect().size.height / 2
				- (enemy->getRect().origin.y + enemy->getRect().size.height / 2))
				- this->getRect().size.height / 2 - enemy->getRect().size.height / 2;

			float velocity = abs(this->getVelocity().y - enemy->getVelocity().y);

			float time = length / velocity;

			if (time < minTime)
			{
				minTime = time;
				dir = CD_TOP;
			}
		}
	}

	//아래쪽 면 충돌 검사

	if (enemyAfterRect.containsPoint(Point(myAfterRect.origin.x,myAfterRect.origin.y+myAfterRect.size.height)) || 
		enemyAfterRect.containsPoint(Point(myAfterRect.origin.x + myAfterRect.size.width, myAfterRect.origin.y + myAfterRect.size.height)))
	{
		float gap = this->getRect().origin.y + this->getRect().size.height - enemy->getRect().origin.y;
		float afterGap = myAfterRect.origin.y + myAfterRect.size.height - enemyAfterRect.origin.y;

		if (gap*afterGap < 0)
		{
			float length = abs(this->getRect().origin.y + this->getRect().size.height / 2
				- (enemy->getRect().origin.y + enemy->getRect().size.height / 2))
				- this->getRect().size.height / 2 - enemy->getRect().size.height / 2;

			float velocity = abs(this->getVelocity().y - enemy->getVelocity().y);

			float time = length / velocity;

			if (time < minTime)
			{
				minTime = time;
				dir = CD_BOTTOM;
			}
		}
	}

	//왼쪽 면 충돌 검사

	if (enemyAfterRect.containsPoint(myAfterRect.origin) ||
		enemyAfterRect.containsPoint(Point(myAfterRect.origin.x, myAfterRect.origin.y + myAfterRect.size.height)))
	{
		float gap = this->getRect().origin.x - (enemy->getRect().origin.x + enemy->getRect().size.width);
		float afterGap = myAfterRect.origin.x - (enemyAfterRect.origin.x + enemyAfterRect.size.width);

		if (gap*afterGap < 0)
		{
			float length = abs(this->getRect().origin.x + this->getRect().size.width / 2
				- (enemy->getRect().origin.x + enemy->getRect().size.width / 2))
				- this->getRect().size.width / 2 - enemy->getRect().size.width / 2;

			float velocity = abs(this->getVelocity().x - enemy->getVelocity().x);

			float time = length / velocity;

			if (time < minTime)
			{
				minTime = time;
				dir = CD_LEFT;
			}
		}
	}

	//오른쪽 면 충돌 검사

	if (enemyAfterRect.containsPoint(Point(myAfterRect.origin.x + myAfterRect.size.width, myAfterRect.origin.y)) ||
		enemyAfterRect.containsPoint(Point(myAfterRect.origin.x + myAfterRect.size.width, myAfterRect.origin.y + myAfterRect.size.height)))
	{
		float gap = this->getRect().origin.x + this->getRect().size.width - enemy->getRect().origin.x;
		float afterGap = myAfterRect.origin.x + myAfterRect.size.width - enemyAfterRect.origin.x;

		if (gap*afterGap < 0)
		{
			float length = abs(this->getRect().origin.x + this->getRect().size.width / 2
				- (enemy->getRect().origin.x + enemy->getRect().size.width / 2))
				- this->getRect().size.width / 2 - enemy->getRect().size.width / 2;

			float velocity = abs(this->getVelocity().x - enemy->getVelocity().x);

			float time = length / velocity;

			if (time < minTime)
			{
				minTime = time;
				dir = CD_RIGHT;
			}
		}
	}

	if (dir != CD_NONE)
	{
		auto pos = this->getPosition();

		pos.x = pos.x + minTime*this->getVelocity().x;
		pos.y = pos.y + minTime*this->getVelocity().y;

		this->setPosition(pos);
	}
	return dir;
}
