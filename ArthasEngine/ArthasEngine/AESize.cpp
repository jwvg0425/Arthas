#include "AESize.h"

AESize::AESize()
	:m_Width(0) , m_Height(0)
{
}

AESize::AESize( float _width , float _height )
{
	SetWidth( _width );
	SetHeigth( _height );
}

AESize::AESize( const AESize& _size )
{
	SetWidth( _size.GetWidth() );
	SetHeigth( _size.GetHeigth() );
}

AESize::AESize( const AERect& _rect )
{
}


AESize::~AESize()
{
}

void AESize::operator=( const AESize& _size )
{
	SetSize( _size.GetWidth() , _size.GetHeigth() );
}

bool AESize::operator>( const AESize& _size )
{
	return ( GetSquare() > _size.GetSquare() );
}

bool AESize::operator<( const AESize& _size )
{
	return ( GetSquare() < _size.GetSquare() );
}

bool AESize::operator==( const AESize& _size )
{
	return ( m_Width == _size.GetWidth() && 
			 m_Height == _size.GetHeigth() );
}

AESize AESize::operator+( const AESize& _size )
{
	AESize resultSize;
	resultSize.SetSize( m_Width + _size.GetWidth() , 
						m_Height + _size.GetHeigth() );
	return resultSize;
}

AESize AESize::operator-( const AESize& _size )
{
	AESize resultSize;
	resultSize.SetSize( m_Width - _size.GetWidth() , 
						m_Height - _size.GetHeigth() );
	return resultSize;
}
