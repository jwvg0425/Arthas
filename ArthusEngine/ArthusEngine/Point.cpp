#include "Point.h"

Point::Point()
	:m_PosX(0.f) , m_PosY(0.f)
{
}

Point::Point( double _x , double _y )
{
	SetPosX( _x );
	SetPosY( _y );
}

Point::Point( const Point& that )
{
	SetPosX( that.GetPosX() );
	SetPosY( that.GetPosY() );
}


Point::~Point()
{
}

void Point::SetPosX( double _x )
{
	if( _x >= 0.f )
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
	if( _y >= 0.f )
	{
		m_PosY = _y;
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


Point Point::operator+( const Point& that )
{
	Point resultPoint;

	resultPoint.SetPosX( m_PosX + that.GetPosX() );
	resultPoint.SetPosY( m_PosY + that.GetPosY() );

	return resultPoint;
}

void Point::operator=( const Point& that )
{
	SetPoint( that.GetPosX() ,that.GetPosY() );
}

bool Point::operator==( const Point& that )
{
	return ( m_PosX == that.GetPosX() && m_PosY == that.GetPosY() );
}

double Point::GetDistance( const Point& that )
{
	return sqrt( pow( m_PosX - that.GetPosX() , 2 ) + pow( m_PosY - that.GetPosY() , 2 ) );
}

Point Point::GetCenter( const Point& that )
{
	Point resultPoint;
	resultPoint.SetPoint(
		( m_PosX + that.GetPosX() ) / 2 ,
		( m_PosY + that.GetPosY() ) / 2
		);
	return resultPoint;
}
