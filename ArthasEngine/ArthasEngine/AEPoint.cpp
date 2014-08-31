#include "AEPoint.h"

AEPoint::AEPoint()
	:m_PointX(0.f) , m_PointY(0.f)
{
}

AEPoint::AEPoint( float _x , float _y )
{
	SetPosX( _x );
	SetPosY( _y );
}

AEPoint::AEPoint( const AEPoint& _point )
{
	SetPosX( _point.GetPosX() );
	SetPosY( _point.GetPosY() );
}


AEPoint::~AEPoint()
{
}

void AEPoint::SetPosX( float _x )
{
	if( _x >= 0.f )
	{
		m_PointX = _x;
	}
	else
	{
		std::cout << "setPosX Error!" << std::endl;
	}
}

void AEPoint::SetPosY( float _y )
{
	if( _y >= 0.f )
	{
		m_PointY = _y;
	}
	else
	{
		std::cout << "setPosY Error!" << std::endl;
	}
}


void AEPoint::SetPoint( float _x , float _y )
{
	SetPosX( _x );
	SetPosY( _y );
}


AEPoint AEPoint::operator+( const AEPoint& _point )
{
	AEPoint resultPoint;

	resultPoint.SetPosX( m_PointX + _point.GetPosX() );
	resultPoint.SetPosY( m_PointY + _point.GetPosY() );

	return resultPoint;
}

void AEPoint::operator=( const AEPoint& _point )
{
	SetPoint( _point.GetPosX() ,_point.GetPosY() );
}

bool AEPoint::operator==( const AEPoint& _point )
{
	return ( m_PointX == _point.GetPosX() && m_PointY == _point.GetPosY() );
}

float AEPoint::GetDistance( const AEPoint& _point )
{
	return sqrt( pow( m_PointX - _point.GetPosX() , 2 ) + pow( m_PointY - _point.GetPosY() , 2 ) );
}

AEPoint AEPoint::GetCenter( const AEPoint& _point )
{
	AEPoint resultPoint;
	resultPoint.SetPoint(
		( m_PointX + _point.GetPosX() ) / 2 ,
		( m_PointY + _point.GetPosY() ) / 2
		);
	return resultPoint;
}

float AEPoint::GetAngleRadian( const AEPoint& _point )
{
	return atan2(
		( _point.GetPosY() - m_PointY ) , 
		( _point.GetPosX() - m_PointX )
		);
}

float AEPoint::GetAngleDegree( const AEPoint& _point )
{
	return GetAngleRadian( _point ) * 180 / PI;
}
