/*
Resource >> AEBitmap (�̸� ������)

@Class AEBitmap
->��Ʈ�� ���ҽ� ���� Ŭ����

@�ۼ���: �迬��
@�ۼ���: 14-8-22
@���� ������:
@���� ������:
@���� ��������:

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

