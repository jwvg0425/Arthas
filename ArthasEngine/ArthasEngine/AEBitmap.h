/*
Resource >> AEBitmap (이름 구린듯)

@Class AEBitmap
->비트맵 리소스 단위 클래스

@작성자: 김연우
@작성일: 14-8-22
@최종 수정자:
@최종 수정일:
@최종 수정사유:

*/


#pragma once
#include "AEInclude.h"
class AEBitmap
{
public:
	AEBitmap();
	AEBitmap( std::wstring bitmapPath );
	~AEBitmap();

	void Release();
private:
	static IWICImagingFactory*	m_WICFactory;
	ID2D1Bitmap*				m_D2DBitmap;
	IWICFormatConverter*		m_FmtConverter;
	std::wstring				m_Path;
};

