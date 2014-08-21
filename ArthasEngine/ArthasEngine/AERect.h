/*
DataType >> Rect

@Class Rect
->Rect ������ Ŭ���� ����

@�ۼ���: �迬��
@�ۼ���: 14-8-17
@���� ������: ������
@���� ������: 14-8-17
@���� ��������: ��� ���� ���� ����

*/

#pragma once
#include "AEInclude.h"
#include "AEPoint.h"
#include "AESize.h"

class AERect
{
public:
	AERect();
	AERect( double _pointX , double _pointY , 
		  double _width , double _height );
	AERect( const AEPoint& _point , const AESize& _size );
	AERect( const AERect& _rect );
	~AERect();

	double	GetLeft() const { return m_Left; }
	double	GetRight() const { return m_Right; }
	double	GetTop() const { return m_Top; }
	double	GetBottom() const { return m_Bottom; }
	double	GetWidth() const { return abs(m_Right - m_Left); }
	double	GetHeight() const { return abs(m_Bottom - m_Top); }
	AEPoint	GetPoint() const { return AEPoint(m_Left, m_Top); } //���� Point
	AEPoint GetCenter() const { return AEPoint((m_Left+m_Right)/2, (m_Top+ m_Bottom)/2); }
	AESize	GetSize() const { return AESize(GetWidth(), GetHeight()); } //������
	double	GetSquare() const { return GetHeight()*GetWidth(); } //����

	void	SetLeft(double _left) { m_Left = _left; }
	void	SetRight(double _right) { m_Right = _right; }
	void	SetTop(double _top) { m_Top = _top; }
	void	SetBottom(double _bottom) { m_Bottom = _bottom; }
	
	void	SetRect( double _pointX , double _pointY ,
					 double _width , double _height );
	void	SetRect( const AEPoint& _point , const AESize& _size );
	void	SetRect( const AERect& _rect );

	bool	IsEmpty() { return (GetWidth() == 0 && GetHeight() == 0); }
	bool	Contains( double _pointX , double _pointY );
	bool	Contains( const AEPoint& _point );
	bool	Contains( const AERect& _rect );
	void	operator=( const AERect& _rect );
	bool	operator==( const AERect& _rect );

private:
	double	m_Left;
	double	m_Top;
	double	m_Right;
	double	m_Bottom;
};

