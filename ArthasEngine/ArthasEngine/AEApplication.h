/*
AEApplication.h

@Class AEApplication
->어플리케이션 클래스

@작성자: 남현욱
@작성일: 14-8-20
@최종 수정자: 김연우
@최종 수정일: 14-8-21
@최종 수정사유:	RENDERER만들때 GetHWND 필요해서 넣어줌 
				혹시 몰라서 GetHinstance만듬

*/

#pragma once
#include "AEInclude.h"

class AEApplication
{
public:
	static AEApplication* GetInstance();
	static void ReleaseInstance();
	void Run();
	bool Init(TCHAR* title, int width, int height);
	HWND GetHWND() {return m_hWnd;}
	HINSTANCE GetHInstance() {return m_hInstance;}

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	bool CreateWindow_(TCHAR* title, int width, int height);

	AEApplication();
	~AEApplication();

private:
	static AEApplication* m_Instance;
	bool m_Running;
	HWND m_hWnd;
	HINSTANCE m_hInstance;
};

