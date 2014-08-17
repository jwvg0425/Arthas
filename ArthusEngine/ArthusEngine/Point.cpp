#include "Point.h"
#include "define.h"

Point::Point()
	:m_PointX(0.f) , m_PointY(0.f)
{
}

Point::Point( double _x , double _y )
{
	SetPosX( _x );
	SetPosY( _y );
}

Point::Point( const Point& _point )
{
	SetPosX( _point.GetPosX() );
	SetPosY( _point.GetPosY() );
}


Point::~Point()
{
}

void Point::SetPosX( double _x )
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

void Point::SetPosY( double _y )
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


void Point::SetPoint( double _x , double _y )
{
	SetPosX( _x );
	SetPosY( _y );
}


Point Point::operator+( const Point& _point )
{
	Point resultPoint;

	resultPoint.SetPosX( m_PointX + _point.GetPosX() );
	resultPoint.SetPosY( m_PointY + _point.GetPosY() );

	return resultPoint;
}

void Point::operator=( const Point& _point )
{
	SetPoint( _point.GetPosX() ,_point.GetPosY() );
}

bool Point::operator==( const Point& _point )
{
	return ( m_PointX == _point.GetPosX() && m_PointY == _point.GetPosY() );
}

double Point::GetDistance( const Point& _point )
{
	return sqrt( pow( m_PointX - _point.GetPosX() , 2 ) + pow( m_PointY - _point.GetPosY() , 2 ) );
}

Point Point::GetCenter( const Point& _point )
{
	Point resultPoint;
	resultPoint.SetPoint(
		( m_PointX + _point.GetPosX() ) / 2 ,
		( m_PointY + _point.GetPosY() ) / 2
		);
	return resultPoint;
}

double Point::GetAngleRadian( const Point& _point )
{
	return atan2(
		( _point.GetPosY() - m_PointY ) , 
		( _point.GetPosX() - m_PointX )
		);
}

double Point::GetAngleDegree( const Point& _point )
{
	return GetAngleRadian( _point ) * 180 / M_PI;
}
