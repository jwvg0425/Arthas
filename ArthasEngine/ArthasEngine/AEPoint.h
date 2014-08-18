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

	//�ٸ� ������ �Ÿ��� ����
	double	GetDistance( const AEPoint& _point );
	//�ٸ� ������ ������ ����
	AEPoint	GetCenter( const AEPoint& _point );
	//�ٸ� ������ ����(����)�� ����
	double	GetAngleRadian( const AEPoint& _point );
	//�ٸ� ������ ����(Degree)�� ����
	double	GetAngleDegree( const AEPoint& _point );


private:
	double m_PointX;
	double m_PointY;
};

