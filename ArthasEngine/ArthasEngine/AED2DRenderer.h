/*
Renderer >> AED2DRenderer

@Class AED2DRenderer
->D2D용 렌더러(NN배낌)

@작성자: 김연우
@작성일: 14-8-22
@최종 수정자: 
@최종 수정일: 
@최종 수정사유: 

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

