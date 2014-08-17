/*
DataType >> Rect

@Class Rect
->Rect 데이터 클래스 정의

@작성자: 김연우
@작성일: 14-8-17
@최종 수정자:
@최종 수정일:
@최종 수정사유:

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

	//어떤 Point가 영역 안에 있는지를 확인
	bool IsIn(const Point& pos);

	//어떤 Rect가 영역에 곂쳐있는지를 확인
	bool IsOverLaped( const Rect& rt );

	//Rect의 넓이를 리턴
	double GetSquare();

	//Rect의 중심 좌표를 리턴
	Point GetCenter();

private:
	Point m_Head;
	Point m_Tail;
};

