#include "AE2DSprite.h"
#include "AEBitmap.h"
#include "AED2DRenderer.h"

AE2DSprite::AE2DSprite()
	:m_Renderer( nullptr ) , m_Bitmap( nullptr )
{
}

AE2DSprite::AE2DSprite( std::wstring path )
{
	m_Bitmap = new AEBitmap( path );
	m_Width = m_Bitmap->GetD2D1Bitmap()->GetSize().width;
	m_Height = m_Bitmap->GetD2D1Bitmap()->GetSize().height;
}



AE2DSprite::~AE2DSprite()
{
	Clear();
}

void AE2DSprite::Render()
{
	m_Renderer->GetHwndRenderTarget()->
		DrawBitmap(
		m_Bitmap->GetD2D1Bitmap() , 
		D2D1::RectF( 0.f , 0.f , m_Width , m_Height ) 
		);
}

void AE2DSprite::Clear()
{
	m_Bitmap->Release();
	m_Renderer = nullptr;
}


