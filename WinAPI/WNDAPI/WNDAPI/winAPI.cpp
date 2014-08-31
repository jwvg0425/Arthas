#include <stdio.h>
#include <tchar.h>
#include <windows.h>

bool MakeWndClass( HINSTANCE _hInstance , WNDCLASS* _wndClass );
bool CreateWnd( HWND& _hWnd , const WNDCLASS& _wndClass , int nCmdShow );
LRESULT CALLBACK WndProc( HWND , UINT , WPARAM , LPARAM );
int APIENTRY WinMain( HINSTANCE hInstance ,		//HINSTANCE ���μ����� ����� ���� �޸𸮿� ���� �ڵ�
					  HINSTANCE hPrevInstance , //�� ����
					  LPSTR lpszCmdParam ,		//���޹��� ���� argv
					  int nCmdShow )			//���α׷��� ����Ǵ� ����
{
	HWND hWnd;
	WNDCLASS WndClass;
	MSG Message;

	MakeWndClass( hInstance , &WndClass );
	CreateWnd( hWnd , WndClass , nCmdShow );

	while( GetMessage( &Message , NULL , 0 , 0 ) ) //�޽����� �޾Ƽ� Message�� ���� 
	{
		TranslateMessage( &Message ); //����� �޽����� ���� ����
		DispatchMessage( &Message );  //����� �޽����� WndProc�� ����
	}

	return 0;
}


bool MakeWndClass( HINSTANCE _hInstance , WNDCLASS* _wndClass )
{
	_wndClass->cbClsExtra = 0;									//�ϴ� 0
	_wndClass->cbWndExtra = 0;									//�ϴ� 0
	_wndClass->hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 );	//������ ���
	_wndClass->hCursor = LoadCursor( NULL , IDC_ARROW );		//Ŀ�����
	_wndClass->hIcon = LoadIcon( NULL , IDI_APPLICATION );		//������ ���
	_wndClass->hInstance = _hInstance;							//�� �����찡 �ö󰡴� ���� �ν��Ͻ�
	_wndClass->lpfnWndProc = WndProc;							//����� ������ ���μ���
	_wndClass->lpszClassName = _T( "AEAPPLICATION" );			//������ Ŭ���� �̸�
	_wndClass->lpszMenuName = NULL;								//������ �޴�(���ҽ�)
	_wndClass->style = CS_HREDRAW | CS_VREDRAW;					//������ �Ӽ�
	RegisterClass( _wndClass );
	return true;
}

bool CreateWnd( HWND& _hWnd , const WNDCLASS& _wndClass , int nCmdShow )
{
	_hWnd = CreateWindow( _wndClass.lpszClassName ,			//����� ������ Ŭ���� �̸�
						  _wndClass.lpszClassName ,			//������ Ÿ��Ʋ �ٿ� �ö� ���ڿ�
						  WS_OVERLAPPEDWINDOW ,				//������ ��������
						  CW_USEDEFAULT , CW_USEDEFAULT ,	//��ġ X, Y
						  CW_USEDEFAULT , CW_USEDEFAULT ,	//ũ�� Width, Heigh
						  NULL , ( HMENU )NULL ,			//�߸� (�θ� �ڵ�, �޴� �ڵ�)
						  _wndClass.hInstance , NULL );		//�����찡 �ö󰡴� ���� �ν��Ͻ��� �� �𸣴°�
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

		case WM_PAINT:							//������ �׸����Ҷ� �̰� ����
		{
			hdc = BeginPaint( hWnd , &ps );
			Ellipse( hdc , posX - 20 , posY - 20 , posX + 20 , posY + 20 );
			EndPaint( hWnd , &ps );
			return 0;
		}

		case WM_TIMER:

			return 0;

		case WM_DESTROY:						//������ �ı��ɶ� �̰� ����
			PostQuitMessage( 0 );
			return 0;

	}


	return ( DefWindowProc( hWnd , iMessage , wParam , lParam ) );
}