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

	//WICFactory�� ���� �� �𸣰ھ��.
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

	//1.�ϴ� ���ڴ��� �����.

	IWICBitmapDecoder* bitmapDecoder = nullptr;
	//��Ʈ�� ���ڴ��� WIC���丮���� ���´�.
	hr = m_WICFactory->CreateDecoderFromFilename(
		bitmapPath.c_str() ,			//���ڵ���� �̹�������
		nullptr ,						//�ǵ��� ����
		GENERIC_READ ,					//���� ���� ���
		WICDecodeMetadataCacheOnDemand ,//�ʿ��Ҷ� �� ĳ�� ��Ÿ������(?)
		&bitmapDecoder					//����� ���
		);

	//���ڴ����� �̹����� ù��° �������� �޾ƿ´�.
	IWICBitmapFrameDecode* bitmapFrameDecode = nullptr;
	if( SUCCEEDED( hr ) )
	{
		bitmapDecoder->GetFrame( 0 , &bitmapFrameDecode );
	}


	//2.��Ʈ�� �ҽ��� 32bppPBGRA(???)�� ��ȯ

	//���̷�ƮX�� �̹����������� 32~~pixel format���� ��ȯ�Ѵٰ���.
	//�̹��� ������ ��ȯ�ϱ����ؼ��� IWICFormatConvert ��ü�� �ʿ���.
	//�ѹ� ����� �̴ϼȶ����� �޼ҵ� ����ؼ� ��ȯ�� �Ҽ� �ֽ�

	if( SUCCEEDED( hr ) )
	{
		hr = m_WICFactory->CreateFormatConverter( &m_FmtConverter );
	}
	if( SUCCEEDED( hr ) )
	{
		hr = m_FmtConverter->Initialize
			(
			bitmapFrameDecode ,				//��ȯ�� ��Ʈ�� �ٵ� �� �������� ����?
			GUID_WICPixelFormat32bppPBGRA ,	//��ȯ�� ����
			WICBitmapDitherTypeNone ,		//��ü���� dither(����?)����
			NULL ,							//Ư�� �ȷ�Ʈ�� ����
			0.f ,							//���� threshold(����)
			WICBitmapPaletteTypeCustom		//�ȷ�Ʈ(palette) ��ȯ Ÿ��
			);
	}

	//3.ID2D1RenderTarget���� CreateBitmapFromWicBitmap�̰��ϸ�
	//ID2D1Bitmap ��ü�� ���� �� �ִ�.(�ϼ� �Ф�)
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
