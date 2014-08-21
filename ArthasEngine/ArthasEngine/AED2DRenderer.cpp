#include "AED2DRenderer.h"
#include "AEApplication.h"

AED2DRenderer::AED2DRenderer()
	:m_D2DFactory( nullptr ) , m_D2DRenderTarget( nullptr )
{
}


AED2DRenderer::~AED2DRenderer()
{
}

bool AED2DRenderer::Init()
{
	HRESULT hr;
	hr = D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED ,
							&m_D2DFactory );
	if( hr != S_OK )
	{
		return false;
	}

	HWND hWnd = AEApplication::GetInstance()->GetHWND();
	RECT rt;
	GetClientRect( hWnd , &rt );
	D2D1_SIZE_U size = D2D1::SizeU( rt.right = rt.left , rt.bottom - rt.top );

	hr = m_D2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties() ,
		D2D1::HwndRenderTargetProperties
		( hWnd , size , D2D1_PRESENT_OPTIONS_IMMEDIATELY ) ,
		&m_D2DRenderTarget );

	if( hr != S_OK )
	{
		return false;
	}

	return true;
}

bool AED2DRenderer::Release()
{
	if( m_D2DFactory != nullptr )
	{
		delete m_D2DFactory;
		m_D2DFactory = nullptr;
	}
	if( m_D2DRenderTarget != nullptr )
	{
		delete m_D2DRenderTarget;
		m_D2DRenderTarget = nullptr;
	}

	return true;
}

void AED2DRenderer::Clear()
{
	m_D2DRenderTarget->Clear( D2D1::ColorF( D2D1::ColorF::White ) );
}

void AED2DRenderer::Begin()
{
	m_D2DRenderTarget->BeginDraw();
}

void AED2DRenderer::End()
{
	m_D2DRenderTarget->EndDraw();
}


