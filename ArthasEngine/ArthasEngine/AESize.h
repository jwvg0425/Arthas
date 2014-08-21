/*
DataType >> Size

@Class Size
->Rect ������ Ŭ���� ����

@�ۼ���: �迬��
@�ۼ���: 14-8-17
@���� ������: ������
@���� ������: 14-8-17
@���� ��������: ��� ���� ���� ����

*/

#pragma once
#include "AEInclude.h"
class AERect;

class AESize
{
public:
	AESize();
	AESize( double _width , double _height );
	AESize( const AESize& _size );
	AESize( const AERect& _rt );
	~AESize();

	double	GetWidth() const {return m_Width; }
	double	GetHeigth() const {return m_Height;}
	double	GetSquare() const {return m_Height * m_Width;}

	void	SetWidth(double _width) 
	{
		if( _width < 0 )
		{
			std::cout << "Set Width Error!" << std::endl;
		}
		else
		{
			m_Width = _width;
		}
	}
	void	SetHeigth( double _height )
	{
		if( _height < 0 )
		{
			std::cout << "Set Height Error!" << std::endl;
		}
		else
		{
			m_Height = _height;
		}
	}
	void	SetSize( double _width , double _height )
	{
		SetWidth( _width );
		SetHeigth( _height );
	}

	bool	IsEmpty(){ return ( m_Width == 0 && m_Height == 0 ); }
	bool	operator==( const AESize& _size );
	bool	operator>( const AESize& _size );
	bool	operator<( const AESize& _size );
	AESize	operator+( const AESize& _size );
	AESize	operator-( const AESize& _size );
	void	operator=( const AESize& _size );


private:
	double	m_Width;
	double	m_Height;
};
