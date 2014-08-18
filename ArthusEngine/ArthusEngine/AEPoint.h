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
#include "AEDefine.h"

class AEPoint
{
public:
	AEPoint();
	AEPoint(double _x, double _y);
	AEPoint( const AEPoint& _point );
	~AEPoint();
	
	double	GetPosX() const {return m_PointX;}
	double	GetPosY() const {return m_PointY;}
	void	SetPosX( double _x );
	void	SetPosY( double _y );
	void	SetPoint( double _x , double _y );

	AEPoint	operator+( const AEPoint& _point );
	void	operator=( const AEPoint& _point );
	bool	operator==( const AEPoint& _point );

	//다른 점과의 거리를 리턴
	double	GetDistance( const AEPoint& _point );
	//다른 점과의 중점을 리턴
	AEPoint	GetCenter( const AEPoint& _point );
	//다른 점과의 각도(라디안)를 리턴
	double	GetAngleRadian( const AEPoint& _point );
	//다른 점과의 각도(Degree)를 리턴
	double	GetAngleDegree( const AEPoint& _point );


private:
	double m_PointX;
	double m_PointY;
};

