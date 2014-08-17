#include "Rect.h"
#include "Point.h"

Rect::Rect()
{
	Point stdPos( 0.f , 0.f );
	SetRect( stdPos , stdPos );
}

Rect::Rect( Point _head , Point _tail )
{
	SetRect( _head , _tail );
}

Rect::Rect( const Rect& that )
{
	SetRect( that.GetHead() , that.GetTail() );
}

Rect::~Rect()
{
}

void Rect::SetRect( const Point& _head , const Point& _tail )
{
	SetHead( _head );
	SetTail( _tail );
}

Point Rect::GetCenter()
{
	return m_Head.GetCenter( m_Tail );
}

double Rect::GetSquare()
{
	return abs(( m_Tail.GetPosX() - m_Head.GetPosX() )
				*( m_Tail.GetPosY() - m_Head.GetPosY() ));
}

bool Rect::IsIn( const Point& pos )
{
	return (
		pos.GetPosX() > m_Head.GetPosX() &&
		pos.GetPosX() < m_Tail.GetPosX() &&
		pos.GetPosY() > m_Head.GetPosY() &&
		pos.GetPosY() < m_Tail.GetPosY()
		);
}

bool Rect::IsOverLaped( const Rect& rt )
{
	return (
		rt.GetHead().GetPosX() < m_Tail.GetPosX() &&
		rt.GetHead().GetPosX() > m_Head.GetPosX() &&
		rt.GetTail().GetPosY() < m_Tail.GetPosY() &&
		rt.GetTail().GetPosY() > m_Head.GetPosY()
		);
}

