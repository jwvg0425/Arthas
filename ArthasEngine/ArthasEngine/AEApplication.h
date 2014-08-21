/*
AEApplication.h

@Class AEApplication
->���ø����̼� Ŭ����

@�ۼ���: ������
@�ۼ���: 14-8-20
@���� ������: �迬��
@���� ������: 14-8-21
@���� ��������:	RENDERER���鶧 GetHWND �ʿ��ؼ� �־��� 
				Ȥ�� ���� GetHinstance����

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

