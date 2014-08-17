#include "Point.h"
#include <iostream>
#include <math.h>

Point::Point()
	:m_PosX(0.f) , m_PosY(0.f)
{
}

Point::Point( double _x , double _y )
{
	SetPosX( _x );
	SetPosY( _y );
}

Point::Point( const Point& point )
{
	SetPosX( point.GetPosX() );
	SetPosY( point.GetPosY() );
}


Point::~Point()
{
}

void Point::SetPosX( double _x )
{
	if( _x > 0 )
	{
		m_PosX = _x;
	}
	else
	{
		std::cout << "setPosX Error!" << std::endl;
	}
}

void Point::SetPosY( double _y )
{
	if( _y > 0 )
	{
		m_PosY = _y;
	}
	else
	{
		std::cout << "setPosY Error!" << std::endl;
	}
}

Point Point::operator+( const Point& that )
{
	Point resultPoint;

	resultPoint.SetPosX( that.GetPosX() + m_PosX );
	resultPoint.SetPosY( that.GetPosY() + m_PosY );

	return resultPoint;
}

void Point::operator=( const Point& that )
{
	SetPosX( that.GetPosX() );
	SetPosY( that.GetPosY() );
}

bool Point::operator==( const Point& that )
{
	return ( that.GetPosX == m_PosX && that.GetPosY() == m_PosY );
}

double Point::GetDistance( Point& that )
{
	return sqrt( pow( m_PosX - that.GetPosX() , 2 ) + pow( m_PosY - that.GetPosY() , 2 ) );
}
