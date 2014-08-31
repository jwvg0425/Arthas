#include <stdio.h>
#include <tchar.h>
#include <windows.h>

bool MakeWndClass( HINSTANCE _hInstance , WNDCLASS* _wndClass );
bool CreateWnd( HWND& _hWnd , const WNDCLASS& _wndClass , int nCmdShow );
LRESULT CALLBACK WndProc( HWND , UINT , WPARAM , LPARAM );
int APIENTRY WinMain( HINSTANCE hInstance ,		//HINSTANCE 프로세스가 저장된 실제 메모리에 대한 핸들
					  HINSTANCE hPrevInstance , //무 쓸모
					  LPSTR lpszCmdParam ,		//전달받은 인자 argv
					  int nCmdShow )			//프로그램이 실행되는 형태
{
	HWND hWnd;
	WNDCLASS WndClass;
	MSG Message;

	MakeWndClass( hInstance , &WndClass );
	CreateWnd( hWnd , WndClass , nCmdShow );

	while( GetMessage( &Message , NULL , 0 , 0 ) ) //메시지를 받아서 Message에 저장 
	{
		TranslateMessage( &Message ); //저장된 메시지를 쉽게 번역
		DispatchMessage( &Message );  //저장된 메시지를 WndProc에 전달
	}

	return 0;
}


bool MakeWndClass( HINSTANCE _hInstance , WNDCLASS* _wndClass )
{
	_wndClass->cbClsExtra = 0;									//일단 0
	_wndClass->cbWndExtra = 0;									//일단 0
	_wndClass->hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 );	//윈도우 배경
	_wndClass->hCursor = LoadCursor( NULL , IDC_ARROW );		//커서모양
	_wndClass->hIcon = LoadIcon( NULL , IDI_APPLICATION );		//아이콘 모양
	_wndClass->hInstance = _hInstance;							//이 윈도우가 올라가는 실제 인스턴스
	_wndClass->lpfnWndProc = WndProc;							//적용될 윈도우 프로세스
	_wndClass->lpszClassName = _T( "AEAPPLICATION" );			//윈도우 클래스 이름
	_wndClass->lpszMenuName = NULL;								//윈도우 메뉴(리소스)
	_wndClass->style = CS_HREDRAW | CS_VREDRAW;					//윈도우 속성
	RegisterClass( _wndClass );
	return true;
}

bool CreateWnd( HWND& _hWnd , const WNDCLASS& _wndClass , int nCmdShow )
{
	_hWnd = CreateWindow( _wndClass.lpszClassName ,			//사용할 윈도우 클래스 이름
						  _wndClass.lpszClassName ,			//윈도우 타이틀 바에 올라갈 문자열
						  WS_OVERLAPPEDWINDOW ,				//윈도우 형태지정
						  CW_USEDEFAULT , CW_USEDEFAULT ,	//위치 X, Y
						  CW_USEDEFAULT , CW_USEDEFAULT ,	//크기 Width, Heigh
						  NULL , ( HMENU )NULL ,			//잘모름 (부모 핸들, 메뉴 핸들)
						  _wndClass.hInstance , NULL );		//윈도우가 올라가는 실제 인스턴스와 잘 모르는것
	ShowWindow( _hWnd , nCmdShow );
	return true;
}

LRESULT CALLBACK WndProc( HWND hWnd , UINT iMessage , WPARAM wParam , LPARAM lParam )
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt = { 0 , 0 , 1000 , 1000 };
	static int posX = 100;
	static int posY = 100;
	switch( iMessage )
	{
		case WM_CREATE:			
			//SetTimer( hWnd ,1, 100, NULL);
			return 0;

		case WM_KEYDOWN:
			switch(wParam)
			{
				case VK_LEFT:
					posX -= 10;
					break;
				case VK_RIGHT:
					posX += 10;
					break;
				case VK_DOWN:
					posY += 10;
					break;
				case VK_UP:
					posY -= 10;
					break;
			}
			InvalidateRect(hWnd, &rt, true);

		case WM_PAINT:							//윈도우 그리기할때 이거 실행
		{
			hdc = BeginPaint( hWnd , &ps );
			Ellipse( hdc , posX - 20 , posY - 20 , posX + 20 , posY + 20 );
			EndPaint( hWnd , &ps );
			return 0;
		}

		case WM_TIMER:

			return 0;

		case WM_DESTROY:						//윈도우 파괴될때 이거 실행
			PostQuitMessage( 0 );
			return 0;

	}


	return ( DefWindowProc( hWnd , iMessage , wParam , lParam ) );
}