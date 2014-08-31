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

	//�ٸ� ������ �Ÿ��� ����
	float	GetDistance( const AEPoint& _point );
	//�ٸ� ������ ������ ����
	AEPoint	GetCenter( const AEPoint& _point );
	//�ٸ� ������ ����(����)�� ����
	float	GetAngleRadian( const AEPoint& _point );
	//�ٸ� ������ ����(Degree)�� ����
	float	GetAngleDegree( const AEPoint& _point );


private:
	float m_PointX;
	float m_PointY;
};
