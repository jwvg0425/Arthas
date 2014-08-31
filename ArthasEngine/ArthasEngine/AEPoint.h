/*
	DataType >> Point 

	@Class Point
	->좌표계 데이터 클래스 정의

	@작성자: 김연우
	@작성일: 14-8-17
	@최종 수정자: 남현욱
	@최종 수정일: 14-8-17
	@최종 수정사유: 헤더 꼬임 문제 수정

*/

#pragma once
#include "AEInclude.h"

class AEPoint
{
public:
	AEPoint();
	AEPoint(float _x, float _y);
	AEPoint( const AEPoint& _point );
	~AEPoint();
	
	float	GetPosX() const {return m_PointX;}
	float	GetPosY() const {return m_PointY;}
	void	SetPosX( float _x );
	void	SetPosY( float _y );
	void	SetPoint( float _x , float _y );

	AEPoint	operator+( const AEPoint& _point );
	void	operator=( const AEPoint& _point );
	bool	operator==( const AEPoint& _point );

	//다른 점과의 거리를 리턴
	float	GetDistance( const AEPoint& _point );
	//다른 점과의 중점을 리턴
	AEPoint	GetCenter( const AEPoint& _point );
	//다른 점과의 각도(라디안)를 리턴
	float	GetAngleRadian( const AEPoint& _point );
	//다른 점과의 각도(Degree)를 리턴
	float	GetAngleDegree( const AEPoint& _point );


private:
	float m_PointX;
	float m_PointY;
};
