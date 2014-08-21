#pragma once
#include <iostream>
#include <math.h>


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

//ÀÌ»óÇÑ°Å °Çµå¸®±â
//²ô¾Ç²ô¾Ç