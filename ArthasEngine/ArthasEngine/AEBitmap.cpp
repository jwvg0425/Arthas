#include "AEBitmap.h"
#include "AEApplication.h"
#include "AED2DRenderer.h"

IWICImagingFactory* AEBitmap::m_WICFactory = nullptr;

AEBitmap::AEBitmap()
	:m_D2DBitmap( nullptr ) , m_FmtConverter( nullptr ) , m_Path()
{
}

AEBitmap::AEBitmap( std::wstring bitmapPath )
{
	HRESULT hr;

	//WICFactory는 정말 잘 모르겠어요.
	if( m_WICFactory == nullptr )
	{
		hr = CoCreateInstance( CLSID_WICImagingFactory ,
							   NULL , CLSCTX_INPROC_SERVER ,
							   IID_PPV_ARGS( &m_WICFactory ) );
		if( hr == REGDB_E_CLASSNOTREG )
		{
			CoCreateInstance( CLSID_WICImagingFactory1 ,
							  NULL , CLSCTX_INPROC_SERVER ,
							  IID_PPV_ARGS( &m_WICFactory ) );
		}
	}

	m_Path = bitmapPath;

	//1.일단 디코더를 만든다.

	IWICBitmapDecoder* bitmapDecoder = nullptr;
	//비트맵 디코더는 WIC팩토리에서 나온다.
	hr = m_WICFactory->CreateDecoderFromFilename(
		bitmapPath.c_str() ,			//디코드당할 이미지파일
		nullptr ,						//건들지 마셈
		GENERIC_READ ,					//파일 읽을 방법
		WICDecodeMetadataCacheOnDemand ,//필요할때 쓸 캐쉬 메타데이터(?)
		&bitmapDecoder					//저장될 장소
		);

	//디코더에서 이미지의 첫번째 프레임을 받아온다.
	IWICBitmapFrameDecode* bitmapFrameDecode = nullptr;
	if( SUCCEEDED( hr ) )
	{
		bitmapDecoder->GetFrame( 0 , &bitmapFrameDecode );
	}


	//2.비트맵 소스를 32bppPBGRA(???)로 변환

	//다이렉트X는 이미지쓰기전에 32~~pixel format으로 변환한다고함.
	//이미지 포멧을 변환하기위해서는 IWICFormatConvert 객체가 필요함.
	//한번 만들면 이니셜라이즈 메소드 사용해서 변환을 할수 있슴

	if( SUCCEEDED( hr ) )
	{
		hr = m_WICFactory->CreateFormatConverter( &m_FmtConverter );
	}
	if( SUCCEEDED( hr ) )
	{
		hr = m_FmtConverter->Initialize
			(
			bitmapFrameDecode ,				//변환할 비트맵 근데 왜 프레임을 받지?
			GUID_WICPixelFormat32bppPBGRA ,	//변환할 포멧
			WICBitmapDitherTypeNone ,		//구체적인 dither(떨림?)패턴
			NULL ,							//특정 팔레트를 선정
			0.f ,							//알파 threshold(몰라)
			WICBitmapPaletteTypeCustom		//팔레트(palette) 변환 타입
			);
	}

	//3.ID2D1RenderTarget에서 CreateBitmapFromWicBitmap이거하면
	//ID2D1Bitmap 객체를 만들 수 있다.(완성 ㅠㅠ)
	AED2DRenderer* renderer = AEApplication::GetInstance()->GetRenderer();

	if( m_FmtConverter != nullptr )
	{
		renderer->GetHwndRenderTarget()->CreateBitmapFromWicBitmap(
			m_FmtConverter , nullptr , &m_D2DBitmap );
	}

	if( bitmapDecoder != nullptr )
	{
		delete bitmapDecoder;
	}
	if( bitmapFrameDecode != nullptr )
	{
		delete bitmapFrameDecode;
	}
}

AEBitmap::~AEBitmap()
{
	Release();
	if( m_WICFactory != nullptr)
	{
		delete m_WICFactory;
	}
}

void AEBitmap::Release()
{
	if( m_D2DBitmap != nullptr )
	{
		delete m_D2DBitmap;
	}
	if( m_FmtConverter != nullptr )
	{
		delete m_FmtConverter;
	}
}
