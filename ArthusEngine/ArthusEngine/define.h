#pragma once
#include <iostream>
#include <math.h>
#include "Point.h"
#include "Rect.h"

/* 
데이터 타입들은 헤더파일에서도 자유롭게 쓰고싶은데 그러면
메크로같은 상위 헤더에 포함시켜두고 다른 헤더들이 인클루드 시켜면 편하지 않을까?
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