/*
AEApplication.h

@Class AEApplication
->어플리케이션 클래스

@작성자: 남현욱
@작성일: 14-8-20
@최종 수정자: 김연우
@최종 수정일: 14-8-21
@최종 수정사유:	RENDERER만들때 GetHWND 필요해서 넣어줌 
				혹시 몰라서 GetHInstance만듬
				
				비트맵 리소스작업하는데 렌더타겟이 여기저기 필요해서
				App init에 렌더러도 init시키고 그 정보를 싱글톤 App
				에게 renderTarget받아올 수 있게 멤버변수 m_renderer만듬
				(사실 NN따라함)
				

*/

#pragma once
#include "AEInclude.h"
#include "AED2DRenderer.h"

class AEApplication
{
public:
	static AEApplication*	GetInstance();
	static void				ReleaseInstance();
	void					Run();
	bool					Init(TCHAR* title, int width, int height);

	HWND					GetHWND() {return m_hWnd;}
	HINSTANCE				GetHInstance() {return m_hInstance;}
	AED2DRenderer*			GetRenderer() {return m_Renderer; }

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	bool					CreateWindow_(TCHAR* title, int width, int height);

	AEApplication();
	~AEApplication();

private:
	static AEApplication*	m_Instance;
	bool					m_Running;
	HWND					m_hWnd;
	HINSTANCE				m_hInstance;
	AED2DRenderer*			m_Renderer;
};

