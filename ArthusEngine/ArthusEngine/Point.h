/*
	DataType >> Point 

	@Class Point
	->좌표계 데이터 클래스 정의

	@작성자: 김연우
	@작성일: 14-8-17
	@최종 수정자: 
	@최종 수정일: 
	@최종 수정사유:

*/

#pragma once
#include "define.h"

class Point
{
public:
	Point();
	Point(double _x, double _y);
	Point( const Point& that );
	~Point();
	
	double	GetPosX() const {return m_PosX;}
	double	GetPosY() const {return m_PosY;}
	void	SetPosX( double _x );
	void	SetPosY( double _y );
	void	SetPoint( double _x , double _y );

	Point	operator+( const Point& that );
	void	operator=( const Point& that );
	bool	operator==( const Point& that );

	//다른 점과의 거리를 리턴
	double	GetDistance( const Point& that );

	//다른 점과의 중점을 리턴
	Point	GetCenter( const Point& that );

private:
	double m_PosX;
	double m_PosY;
};

