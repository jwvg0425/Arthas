/*
	DataType >> Point 

	@Class Point
	->��ǥ�� ������ Ŭ���� ����

	@�ۼ���: �迬��
	@�ۼ���: 14-8-17
	@���� ������: 
	@���� ������: 
	@���� ��������:

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

	//�ٸ� ������ �Ÿ��� ����
	double	GetDistance( const Point& that );

	//�ٸ� ������ ������ ����
	Point	GetCenter( const Point& that );

private:
	double m_PosX;
	double m_PosY;
};

