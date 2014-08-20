/*
AEApplication.h

@Class AEApplication
->���ø����̼� Ŭ����

@�ۼ���: ������
@�ۼ���: 14-8-20
@���� ������:
@���� ������: 
@���� ��������:

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

