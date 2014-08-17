#pragma once
#include <iostream>
#include <math.h>
#include "Point.h"
#include "Size.h"
#include "Rect.h"

#define PI 3.14159265358979

template<class Interface>
inline void SafeDelete( Interface **ppInterfaceToRelease )
{
	if( *ppInterfaceToRelease != NULL )
	{
		delete ( *ppInterfaceToRelease );
		( *ppInterfaceToRelease ) = NULL;
	}
}