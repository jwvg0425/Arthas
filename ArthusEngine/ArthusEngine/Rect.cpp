#include "Rect.h"
#include "define.h"

Rect::Rect()
	:m_Left(0.f) , m_Top(0.f) , m_Right(0.f) , m_Bottom(0.f)
{
}

Rect::Rect( double _pointX , double _pointY , double _width , double _height )
{
	SetRect( _pointX , _pointY , _width , _height );
}

Rect::Rect( const Point& _point , const Size& _size )
{
	SetRect( _point , _size );
}

Rect::Rect( const Rect& _rect )
{
	SetRect( _rect );
}

Rect::~Rect()
{
}

void Rect::SetRect( double _pointX , double _pointY , double _width , double _height )
{
	SetLeft( _pointX );
	SetTop( _pointY );
	SetRight( m_Left + _width );
	SetBottom( m_Top + _height );
}

void Rect::SetRect( const Point& _point , const Size& _size )
{
	SetLeft( _point.GetPosX() );
	SetTop( _point.GetPosY() );
	SetRight( m_Left + _size.GetWidth() );
	SetBottom( m_Top + _size.GetHeigth() );
}

void Rect::SetRect( const Rect& _rect )
{
	m_Left = _rect.GetLeft();
	m_Right = _rect.GetRight();
	m_Top = _rect.GetTop();
	m_Bottom = _rect.GetBottom();
}

bool Rect::Contains( double _pointX , double _pointY )
{
	return ( m_Left <= _pointX && m_Right >= _pointX &&
			 m_Top <= _pointY && m_Bottom >= _pointY );
}

bool Rect::Contains( const Point& _point )
{
	return ( m_Left <= _point.GetPosX() && m_Right >= _point.GetPosX() &&
			 m_Top <= _point.GetPosY() && m_Bottom >= _point.GetPosY() );
}

bool Rect::Contains( const Rect& _rect )
{
	return ( m_Left <= _rect.GetLeft() && m_Top <= _rect.GetTop() &&
			 m_Right >= _rect.GetRight() && m_Bottom >= _rect.GetBottom() );
}

void Rect::operator=( const Rect& _rect )
{
	SetRect( _rect );
}

bool Rect::operator==( const Rect& _rect )
{
	return ( m_Left == _rect.GetLeft() && m_Top == _rect.GetTop() &&
			 m_Right == _rect.GetRight() && m_Bottom == _rect.GetBottom() );
}


