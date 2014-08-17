#include "Size.h"

Size::Size()
	:m_Width(0) , m_Height(0)
{
}

Size::Size( double _width , double _height )
{
	SetWidth( _width );
	SetHeigth( _height );
}

Size::Size( const Size& _size )
{
	SetWidth( _size.GetWidth() );
	SetHeigth( _size.GetHeigth() );
}

Size::Size( const Rect& _rect )
{
}


Size::~Size()
{
}

void Size::operator=( const Size& _size )
{
	SetSize( _size.GetWidth() , _size.GetHeigth() );
}

bool Size::operator>( const Size& _size )
{
	return ( GetSquare() > _size.GetSquare() );
}

bool Size::operator<( const Size& _size )
{
	return ( GetSquare() < _size.GetSquare() );
}

bool Size::operator==( const Size& _size )
{
	return ( m_Width == _size.GetWidth() && 
			 m_Height == _size.GetHeigth() );
}

Size Size::operator+( const Size& _size )
{
	Size resultSize;
	resultSize.SetSize( m_Width + _size.GetWidth() , 
						m_Height + _size.GetHeigth() );
	return resultSize;
}

Size Size::operator-( const Size& _size )
{
	Size resultSize;
	resultSize.SetSize( m_Width - _size.GetWidth() , 
						m_Height - _size.GetHeigth() );
	return resultSize;
}
