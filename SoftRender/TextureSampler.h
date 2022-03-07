#pragma once
#include "DDSTextureLoader11.h"

#include <memory>
#include <DirectXTex.h>

class PixelColor
{
public:
	union
	{
		int c;
		struct
		{
			unsigned char b;
			unsigned char g;
			unsigned char r;
			unsigned char a;
		};
	};
};

class TextureSampler
{
public:
	void LoadDDSTexture(const wchar_t* filename);
	~TextureSampler();
	PixelColor* rawData;
	int width;
	int height;
private:
	DirectX::Image img;
	std::unique_ptr<DirectX::ScratchImage> image;
	
	
};
