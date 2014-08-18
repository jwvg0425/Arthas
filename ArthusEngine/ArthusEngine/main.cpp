#include <windows.h>
#include "AEDefine.h"
#include "AEApplication.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{

	AEApplication::GetInstance();
	AEApplication::ReleaseInstance();

	return 0;
}