/*
Renderer >> AED2DRenderer

@Class AED2DRenderer
->D2D�� ������(NN�賦)

@�ۼ���: �迬��
@�ۼ���: 14-8-22
@���� ������: 
@���� ������: 
@���� ��������: 

*/


#pragma once
#pragma comment(lib, "d2d1")

#include "AEInclude.h"

class AED2DRenderer
{
public:
	AED2DRenderer();
	~AED2DRenderer();

	bool					Init();
	bool					Release();

	void					Clear();
	void					Begin();
	void					End();

	ID2D1Factory*			GetD2DFactory() {return m_D2DFactory; }
	ID2D1HwndRenderTarget*	GetHwndRenderTarget() {return m_D2DRenderTarget; }

private:
	ID2D1Factory*			m_D2DFactory;
	ID2D1HwndRenderTarget*	m_D2DRenderTarget;
};

