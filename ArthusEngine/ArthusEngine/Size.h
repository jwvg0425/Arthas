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
<<<<<<< HEAD
#include "define.h"
class Rect;
=======
#include "Rect.h"
>>>>>>> origin/master

class Size
{
public:
	Size();
	Size( double _width , double _height );
	Size( const Size& _size );
	Size( const Rect& _rt );
	~Size();

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
	bool	operator==( const Size& _size );
	bool	operator>( const Size& _size );
	bool	operator<( const Size& _size );
	Size	operator+( const Size& _size );
	Size	operator-( const Size& _size );
	void	operator=( const Size& _size );


private:
	double	m_Width;
	double	m_Height;
};

