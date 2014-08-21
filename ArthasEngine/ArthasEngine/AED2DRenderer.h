#pragma once
#pragma comment(lib, "d2d1")

#include "AEInclude.h"

class AED2DRenderer
{
public:
	AED2DRenderer();
	~AED2DRenderer();

	bool Init();
	bool Release();

	void Clear();
	void Begin();
	void End();

private:
	ID2D1Factory* m_D2DFactory;
	ID2D1HwndRenderTarget* m_D2DRenderTarget;
};

