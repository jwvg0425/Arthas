/*
	DataType >> Point 

	@Class Point
	->��ǥ�� ������ Ŭ���� ����

	@�ۼ���: �迬��
	@�ۼ���: 14-8-17
	@���� ������: ������
	@���� ������: 14-8-17
	@���� ��������: ��� ���� ���� ����

*/

#pragma once
#include "define.h"

class Point
{
public:
	Point();
	Point(double _x, double _y);
	Point( const Point& _point );
	~Point();
	
	double	GetPosX() const {return m_PointX;}
	double	GetPosY() const {return m_PointY;}
	void	SetPosX( double _x );
	void	SetPosY( double _y );
	void	SetPoint( double _x , double _y );

	Point	operator+( const Point& _point );
	void	operator=( const Point& _point );
	bool	operator==( const Point& _point );

	//�ٸ� ������ �Ÿ��� ����
	double	GetDistance( const Point& _point );
	//�ٸ� ������ ������ ����
	Point	GetCenter( const Point& _point );
	//�ٸ� ������ ����(����)�� ����
	double	GetAngleRadian( const Point& _point );
	//�ٸ� ������ ����(Degree)�� ����
	double	GetAngleDegree( const Point& _point );


private:
	double m_PointX;
	double m_PointY;
};

