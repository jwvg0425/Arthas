#include "AEApplication.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{

	AEApplication::GetInstance()->Init(_T("abc"), 500, 500);
	AEApplication::GetInstance()->Run();
	AEApplication::ReleaseInstance();

	return 0;
}