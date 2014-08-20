#include "AEApplication.h"


AEApplication* AEApplication::m_Instance = nullptr;

AEApplication::AEApplication() 
	: m_hInstance(nullptr), m_hWnd(nullptr), m_Running(false)
{

}

AEApplication::~AEApplication()
{

}


AEApplication* AEApplication::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new AEApplication();
	}

	return m_Instance;
}

void AEApplication::ReleaseInstance()
{
	if (m_Instance != nullptr)
	{
		delete m_Instance;
		m_Instance = nullptr;
	}
}

LRESULT CALLBACK AEApplication::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void AEApplication::Run()
{
	MSG message;

	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				return;
			}

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			//TODO: GameLoop ¿€º∫
		}
	}
}

bool AEApplication::Init(TCHAR* title, int width, int height)
{
	m_hInstance = GetModuleHandle(0);
	m_Running = true;

	CreateWindow_(title, width, height);

	ShowWindow(m_hWnd, SW_SHOWNORMAL);
	
	return true;
}

bool AEApplication::CreateWindow_(TCHAR* title, int width, int height)
{
	WNDCLASS WndClass;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = m_hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = _T("AEAPPLICATION");
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	m_hWnd = CreateWindow(_T("AEAPPLICATION"), title, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		width, height, NULL, (HMENU)NULL, m_hInstance, NULL);

	return true;
}