/*
DataType >> Rect

@Class Rect
->Rect ������ Ŭ���� ����

@�ۼ���: �迬��
@�ۼ���: 14-8-17
@���� ������:
@���� ������:
@���� ��������:

*/

#pragma once
#include "define.h"

class Point;

class Rect
{
public:
	Rect();
	Rect( Point _head , Point _tail );
	Rect( const Rect& rt );
	~Rect();

	Point GetHead() const { return m_Head; }
	Point GetTail() const { return m_Tail; }
	void SetHead(const Point& pos) { m_Head = pos; }
	void SetTail(const Point& pos) { m_Tail = pos; }
	void SetRect( const Point& _head , const Point& _tail );

	void operator=( const Rect& rt );
	bool operator==( const Rect& rt );

	//� Point�� ���� �ȿ� �ִ����� Ȯ��
	bool IsIn(const Point& pos);

	//� Rect�� ������ �����ִ����� Ȯ��
	bool IsOverLaped( const Rect& rt );

	//Rect�� ���̸� ����
	double GetSquare();

	//Rect�� �߽� ��ǥ�� ����
	Point GetCenter();

private:
	Point m_Head;
	Point m_Tail;
};

