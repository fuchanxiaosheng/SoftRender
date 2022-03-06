#pragma once
#include "DDSTextureLoader11.h"

#include <memory>
#include <DirectXTex.h>

class PixelColor
{
public:
	union
	{
		int x;
		struct
		{
			unsigned char r;
			unsigned char g;
			unsigned char b;
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
