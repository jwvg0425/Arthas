#include "AERect.h"

AERect::AERect()
	:m_Left(0.f) , m_Top(0.f) , m_Right(0.f) , m_Bottom(0.f)
{
}

AERect::AERect( double _pointX , double _pointY , double _width , double _height )
{
	SetRect( _pointX , _pointY , _width , _height );
}

AERect::AERect( const AEPoint& _point , const AESize& _size )
{
	SetRect( _point , _size );
}

AERect::AERect( const AERect& _rect )
{
	SetRect( _rect );
}

AERect::~AERect()
{
}

void AERect::SetRect( double _pointX , double _pointY , double _width , double _height )
{
	SetLeft( _pointX );
	SetTop( _pointY );
	SetRight( m_Left + _width );
	SetBottom( m_Top + _height );
}

void AERect::SetRect( const AEPoint& _point , const AESize& _size )
{
	SetLeft( _point.GetPosX() );
	SetTop( _point.GetPosY() );
	SetRight( m_Left + _size.GetWidth() );
	SetBottom( m_Top + _size.GetHeigth() );
}

void AERect::SetRect( const AERect& _rect )
{
	m_Left = _rect.GetLeft();
	m_Right = _rect.GetRight();
	m_Top = _rect.GetTop();
	m_Bottom = _rect.GetBottom();
}

bool AERect::Contains( double _pointX , double _pointY )
{
	return ( m_Left <= _pointX && m_Right >= _pointX &&
			 m_Top <= _pointY && m_Bottom >= _pointY );
}

bool AERect::Contains( const AEPoint& _point )
{
	return ( m_Left <= _point.GetPosX() && m_Right >= _point.GetPosX() &&
			 m_Top <= _point.GetPosY() && m_Bottom >= _point.GetPosY() );
}

bool AERect::Contains( const AERect& _rect )
{
	return ( m_Left <= _rect.GetLeft() && m_Top <= _rect.GetTop() &&
			 m_Right >= _rect.GetRight() && m_Bottom >= _rect.GetBottom() );
}

void AERect::operator=( const AERect& _rect )
{
	SetRect( _rect );
}

bool AERect::operator==( const AERect& _rect )
{
	return ( m_Left == _rect.GetLeft() && m_Top == _rect.GetTop() &&
			 m_Right == _rect.GetRight() && m_Bottom == _rect.GetBottom() );
}


