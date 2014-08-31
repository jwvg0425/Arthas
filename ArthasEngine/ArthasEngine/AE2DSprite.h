#pragma once
#include "AEObject.h"
#include "AEInclude.h"

class AEBitmap;
class AED2DRenderer;

class AE2DSprite :
	public AEObject
{
public:
	AE2DSprite();
	AE2DSprite( std::wstring path );
	~AE2DSprite();

	void Init(){};
	void Update(){};
	void Render();
	void Clear();


private:
	float m_Width;
	float m_Height;

	AEBitmap* m_Bitmap;
	AED2DRenderer* m_Renderer;
};

