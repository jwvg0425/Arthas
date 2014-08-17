#pragma once
#include <iostream>
#include <math.h>
#include "Point.h"  // ���� ������ Ÿ�� �׳� ��Ŭ����ص��ǳ�??

/* 
������ Ÿ�Ե��� ������Ͽ����� �����Ӱ� ��������� �׷���
��ũ�ΰ��� ���� ����� ���Խ��ѵΰ� �ٸ� ������� ��Ŭ��� ���Ѹ� ������ ������?
*/

template<class Interface>
inline void SafeDelete( Interface **ppInterfaceToRelease )
{
	if( *ppInterfaceToRelease != NULL )
	{
		delete ( *ppInterfaceToRelease );
		( *ppInterfaceToRelease ) = NULL;
	}
}