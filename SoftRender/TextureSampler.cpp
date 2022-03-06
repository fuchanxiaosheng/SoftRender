#include "TextureSampler.h"

using namespace DirectX;

void TextureSampler::LoadDDSTexture(const wchar_t* filename)
{
	TexMetadata info;
	image = std::make_unique<ScratchImage>();
	ScratchImage srcImage;
	ScratchImage okImage;
	if (LoadFromDDSFile(filename, DDS_FLAGS_NONE, &info, *image) < 0)
	{
		return;
	}
	if (image->GetImages()->format == DXGI_FORMAT_BC1_UNORM)
	{		
		HRESULT hr = Decompress(image->GetImages(), image->GetImageCount(), image->GetMetadata(),
			DXGI_FORMAT_R8G8B8A8_UNORM, srcImage);
		/*hr = Convert(srcImage.GetImages(), srcImage.GetImageCount(), srcImage.GetMetadata(),
			DXGI_FORMAT_R8G8B8A8_UINT, TEX_FILTER_DEFAULT, TEX_THRESHOLD_DEFAULT, okImage);*/
		uint8_t* pixels = srcImage.GetPixels();
		img = *(srcImage.GetImages());
		width = img.width;
		height = img.height;
		rawData = new PixelColor[(width * height)];
		for (int i = 0; i < img.height; i++)
		{
			for (int j = 0; j < img.width; j++)
			{
				rawData[i * img.width + j].r = (int)(*pixels++);
				rawData[i * img.width + j].g = (int)(*pixels++);
				rawData[i * img.width + j].b = (int)(*pixels++);
				rawData[i * img.width + j].a = (int)(*pixels++);
			}
		}
		
	}
	else
	{
		img = *(image->GetImages());
	}
	//memcpy(rawData, img.pixels, img.slicePitch);
}

TextureSampler::~TextureSampler()
{
	delete[] rawData;
}