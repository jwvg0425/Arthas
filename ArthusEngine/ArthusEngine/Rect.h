/*
DataType >> Rect

@Class Rect
->Rect 데이터 클래스 정의

@작성자: 김연우
@작성일: 14-8-17
@최종 수정자: 남현욱
@최종 수정일: 14-8-17
@최종 수정사유: 헤더 꼬임 문제 수정

*/

#pragma once
<<<<<<< HEAD
#include "define.h"
=======
>>>>>>> origin/master
#include "Point.h"
#include "Size.h"

class Rect
{
public:
	Rect();
	Rect( double _pointX , double _pointY , 
		  double _width , double _height );
	Rect( const Point& _point , const Size& _size );
	Rect( const Rect& _rect );
	~Rect();

	double	GetLeft() const { return m_Left; }
	double	GetRight() const { return m_Right; }
	double	GetTop() const { return m_Top; }
	double	GetBottom() const { return m_Bottom; }
	double	GetWidth() const { return abs(m_Right - m_Left); }
	double	GetHeight() const { return abs(m_Bottom - m_Top); }
	Point	GetPoint() const { return Point(m_Left, m_Top); } //최초 Point
	Size	GetSize() const { return Size(GetWidth(), GetHeight()); } //사이즈
	double	GetSquare() const { return GetHeight()*GetWidth(); } //넓이

	void	SetLeft(double _left) { m_Left = _left; }
	void	SetRight(double _right) { m_Right = _right; }
	void	SetTop(double _top) { m_Top = _top; }
	void	SetBottom(double _bottom) { m_Bottom = _bottom; }
	
	void	SetRect( double _pointX , double _pointY ,
					 double _width , double _height );
	void	SetRect( const Point& _point , const Size& _size );
	void	SetRect( const Rect& _rect );

	bool	IsEmpty() { return (GetWidth() == 0 && GetHeight() == 0); }
	bool	Contains( double _pointX , double _pointY );
	bool	Contains( const Point& _point );
	bool	Contains( const Rect& _rect );
	void	operator=( const Rect& _rect );
	bool	operator==( const Rect& _rect );

private:
	double	m_Left;
	double	m_Top;
	double	m_Right;
	double	m_Bottom;
};

